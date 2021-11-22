//
// filename: palindromes.c
//  askisi4 protis ergasias

#include "Header.h"

int stringlength(char *str){
    int cnt=0, k=0, length;
    while((str[cnt] != '\n') && (str[cnt] != '\0')){
        if (!((str[cnt]>='a' && str[cnt]<='z') || (str[cnt]>='A' && str[cnt]<='Z')))
            k++;
        cnt++;
    }
    length = strlen(str) - k;
    return length;
}

int checkPalindrome(char *str){
    int length, middle, i, j=0;
    char let;
    length = stringlength(str);
    middle = (strlen(str))/2;
    STACKinit(stringlength(str)/2);
    for(i=0; j<length/2; i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            STACKpush(str[i]);
            j++;
        }
    }
    while (!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))){
        i++;
    }
    if((strlen(str) % 2 != 0) || (stringlength(str)%2 != 0))
        i++;
    if((strlen(str) % 2 != 0) && (stringlength(str)%2 == 0))
        i--;
    if (!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')))
        i++;
    while (i<stringlength(str)){
        let = STACKpop();
        while(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))){
            i++;
        }
        if(str[i]>='a' && str[i]<='z'){
            if (let != str[i] && let!=(str[i]-32)){
                printf("Is not a palindrome: %s\n", str);
                return -1;
            }
        }
        else if((str[i]>='A' && str[i]<='Z')){
            if (let != str[i] && let!=(str[i]+32)){
                printf("Is not a palindrome: %s\n", str);
                return -1;
            }
        }
        i++;
    }
    printf("Is a palindrome: %s\n", str);
    return 1;
}
