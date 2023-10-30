/*Write a program in C to find the number of times a given word 'the' appears in the given string.*/

#include <stdio.h>
#include <string.h>

int count_frequency_of_given_substr(char *str,char *substr);

int main()
{
    char str[50],substr[20];
    printf("Enter the string: ");
    scanf("%[^\n]s",str);
    printf("Enter the substring: ");
    scanf("\n%[^\n]s",substr);
    int count = count_frequency_of_given_substr(str,substr);
    printf("count = %d\n",count);
    return 0;
}

int count_frequency_of_given_substr(char *str,char *substr)
{
    int count = 0,res = 0,len;
    len = strlen(substr);
    char *temp = substr;
    while(*str)
    {
        if(*str == *temp || *str == (*temp + 32) || *str == (*temp - 32))
        {
            while(len != 0)
            {
                if(*str == *temp || *str == (*temp + 32) || *str == (*temp - 32))
                {
                    res = res + 1;
                }
                else
                {
                    res = 0;
                    break;
                }
                str++;
                temp++;
                len--;
            }
        }
        if(res == strlen(substr))
        count++;
        temp = substr;
        str++;
        len = strlen(substr); 
        res = 0;
    }
    return count;
}