#include <stdio.h>
#include "encrypt.h"
#include "utils.h"

int  main (int argc, char *argv[])
{
    if (argc !=4)
    {
        printf("usage : prog input output password e/d\n");
        return 1;
    }
    char password[100];
    getPassword(password);
    processFile(argv[1],argv[2], password,argv[3][0]);
     
    return 0;
}