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

    while(fread(&ch , 1, 1, f1) == 1)
    {
     if(mode=='e')

    {
    ch= ch ^ key[i % key_len];
     ch= rotate_right(ch);
     ch = ch+5;
   
    

     }else if(mode =='d')
{
   ch= ch-5;
   ch= rotate_left(ch);
   ch= ch ^key[i % key_len];
  
    

}
fwrite(&ch , 1 ,1 ,f2);
i++;

}
   printf(" Done (%c mode)\n",mode);

fclose(f1);
fclose(f2);

}