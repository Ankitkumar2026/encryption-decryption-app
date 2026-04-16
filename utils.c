#include <stdio.h>
#include <conio.h>
#include "utils.h"
void getPassword (char *password)
{
    int i =0;
    char ch;
    printf(" Entr the password : ");
    while((ch =_getch()) != '\r')
    {
        password[i++]=ch;
        printf("*");
    }
    password[i]='\0';
    printf("\n");

}