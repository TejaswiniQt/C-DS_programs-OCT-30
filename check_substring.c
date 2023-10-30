/*Write a C program to check whether a substring is present in a string.*/

#include <stdio.h>
#include <string.h>

int check_substring(char str[],char *substr);

int main()
{
    char str[50], substr[20];
    printf("Enter the string: ");
    scanf("%[^\n]s",str);
    printf("Enter the substring: ");
    scanf("\n%[^\n]s",substr);
    if(check_substring(str,substr))
    printf("substring is present\n");
    else
    printf("Substring is not present\n");
    return 0;
}

int check_substring(char str[],char *substr)
{
    int res = 0;
    int len = strlen(substr);
    while(*str)
    {
        if(*str == *substr)
        {
            while(len != 0)
            {
                if(*str != *substr)
                {   
                    res = 0;
                    break;
                }
                else
                {
                    str++;
                    substr++;
                    res = 1;
                }
                len--;
            }
        }
        str++;
    }
    return res;
}