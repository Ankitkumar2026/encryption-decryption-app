#include <stdio.h>
#include <string.h>
#include "encrypt.h"

int  main (int argc, char *argv[])
{
    if (argc !=5)
    {
        printf("usage : prog input output password\n");
        return 1;
    }
    processFile(argv[1],argv[2],argv[3],argv[4][0]);
printf("operation completed successfully\n");
    
    return 0;
}