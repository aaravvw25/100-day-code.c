//Q100: Print all sub-strings of a string.

/*
Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c

*/
#include <stdio.h>

int main() {
    char str[100];
    int i, j, k, len = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            for (k = i; k <= j; k++) {
                putchar(str[k]);
            }
            if (i != len - 1 || j != len - 1) {
                putchar(',');
            }
        }
    }
    putchar('\n');
    
    return 0;
}