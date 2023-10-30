/*Write a program in C to remove characters from a string except alphabets.*/

#include <stdio.h>
#include <string.h>

void remove_characters_except_alphabets(char *str);

int main()
{
    char str[50];
    printf("Enter the string: ");
    scanf("%[^\n]s",str);
    remove_characters_except_alphabets(str);
    printf("str = %s\n",str);
    return 0;
}

void remove_characters_except_alphabets(char *str)
{
    int len,i,j;
    len = strlen(str);
    while(str[i] != '\0')
    {
        if(str[i] < 65 || str[i] > 90 && str[i] < 97 || str[i] > 122)
        {
            for(j=i; j<len; j++)
            {
                str[j] = str[j+1];            
            }
            len--;
        }
        i++;
    }
}