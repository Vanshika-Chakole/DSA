#include<stdio.h>
#include<string.h>

int main(){
    int temp,i;
    char str[30],ln;
    printf("Enter the string:");
    gets(str);
    ln = strlen(str);
    for(i = 0;i <=ln/2; i++){
        temp = str[i];
        str[i] = str[ln-1-i];
        str[ln-1-i] = temp;
    }
    printf("Revers of string: %s",str);
}