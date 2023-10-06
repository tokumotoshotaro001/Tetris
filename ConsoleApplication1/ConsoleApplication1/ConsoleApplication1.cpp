#include<iostream>
#include<string.h>

int main(void)
{
    char str2[] = { 'u','n','s','i','g','n','e','d',' ','l','o','n','g' };
    printf("%d", strnlen(str2, 6));

    return 0;
}