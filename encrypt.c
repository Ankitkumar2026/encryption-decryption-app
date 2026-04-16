#include <stdio.h>
#include <string.h>
#include "encrypt.h"
unsigned char rotate_left (unsigned char ch)
{
    return(ch << 3) | (ch >> 5);
}
unsigned char rotate_right (unsigned char ch)
{
    return(ch >> 3) | (ch  << 5);
}
void processFile( const char *input, const char *output, const char *key, char mode)
{
FILE *f1=fopen(input,"rb");
FILE *f2=fopen(output,"wb");

if(f1 == NULL ||f2 == NULL)
{
    printf("FILE ERROR \n");
    return;
}

int  i=0;
int key_len=strlen(key);
unsigned char ch;
unsigned int checksum = 0;

    
   
     if(mode=='e')

    {
        while(fread(&ch , 1, 1, f1) == 1)
         {
            checksum += ch;
    ch= ch ^ key[i % key_len];
     ch= rotate_right(ch);
     ch = ch+5;
     fwrite(&ch , 1 ,1 ,f2);
     i++;
   }
   fwrite(&checksum ,sizeof(checksum),1, f2);
   printf(" Encrypted  with integrity  check \n");
}
   else if(mode =='d')
{
    fseek(f1 ,0, SEEK_END);
    long size = ftell(f1);
    rewind(f1);
    long data_size =size - sizeof(unsigned int);
    fseek (f1, data_size, SEEK_SET);
    unsigned int stored_checksum;
    fread(&stored_checksum, sizeof(stored_checksum), 1, f1);
    rewind(f1);
    for(long j= 0; j<data_size; j++)
    {
        fread(&ch, 1, 1, f1);
        ch= ch-5;
   ch= rotate_left(ch);
   ch= ch ^key[i % key_len];
   checksum +=ch;
   fwrite( &ch, 1, 1, f2);
   i++;
  
    }
    if(checksum != stored_checksum)
    {
        printf("❌  wrong password or corrupted  file \n");
    }else 
    {
        printf("✅ Decryption successful\n");
    }
    
  
    

}


fclose(f1);
fclose(f2);

}