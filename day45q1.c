// Q89: Count frequency of a given character in a string.

/*
Sample Test Cases:
Input 1:
programming
g
Output 1:
2

*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ch;
    int count = 0;
    scanf("%s", str);
    scanf(" %c", &ch);
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ch)
            count++;
    printf("%d", count);
    return 0;
}
