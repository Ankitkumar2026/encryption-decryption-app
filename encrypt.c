#include <stdio.h>
#include <string.h>
#include "encrypt.h"
void processFile( const char *input, const char *output, const char *key, char mode)
{
FILE *f1=fopen(input,"rb");
FILE *f2=fopen(output,"wb");

if(f1 == NULL ||f2 == NULL)
{
    printf("FILE ERROR \n");
    return;
}
int ch , i=0;
int key_len=strlen(key);
if(mode=='e')
{
    while((ch =fgetc(f1)) != EOF)
    {
    ch= ch ^ key[i % key_len];
     fprintf(f2, "%02X", ch); 
    i++;

     }
     printf("Encryption done(Hex format) \n");
}else if(mode =='d')
{
    unsigned int value;
    while(fscanf(f1,"%2X",&value)==1)
    {
        ch= value^key[i%key_len];
        fputc(ch,f2);
        i++;
    }
    printf(" Decryption done\n");

}

fclose(f1);
fclose(f2);

}