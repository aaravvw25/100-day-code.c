//Q85: Reverse a string.

/*
Sample Test Cases:
Input 1:
abcd
Output 1:
dcba

*/
 #include <stdio.h>
 
 int main() {
        char str[100], rev[100];
        int i = 0, j, len = 0;
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        while (str[len] != '\0') {
            len++;
        }
        if (len > 0 && str[len - 1] == '\n') {
            len--;
        }
        j = 0;
        for (i = len - 1; i >= 0; i--) {
            rev[j++] = str[i];
        }
        rev[j] = '\0';
        printf("Reversed String: %s\n", rev);
    return 0;
 }