/* Write a program in C to read a sentence and replace lowercase characters with uppercase and vice versa.*/

#include <stdio.h>
#include <string.h>

void replace_lw_with_up(char *str);

int main()
{
    char str[50];
    printf("Enter the string: ");
    scanf("%[^\n]s",str);
    replace_lw_with_up(str);
    printf("String after replacing lowercase with uppercase and viceversa: %s\n",str);
    return 0;
}

void replace_lw_with_up(char *str)
{
    while(*str)
    {
        if(*str >= 65 && *str <= 90)
        *str = *str + 32;
        else if(*str >= 97 && *str <= 122)
        *str = *str - 32;
        str++;
    }
}