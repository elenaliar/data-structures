//askisi 4 protis ergasias
//filanme: main.c

#include "Header.h"

int main(void){
    FILE *fp;
    int x;
    char str[200];
    fp = fopen("palindromes.txt", "rb");
    while(fgets(str, 200, fp)){
        char *token;
        token = strtok(str, "\n");
        x=checkPalindrome(token);
    }
    return 0;
}

