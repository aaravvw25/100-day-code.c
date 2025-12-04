//Q88: Replace spaces with hyphens in a string.

/*
Sample Test Cases:
Input 1:
hello world
Output 1:
hello-world

*/
 #include <stdio.h>
 
 int main() {
        char str[100];
        int i = 0;
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        while (str[i] != '\0') {
            if (str[i] == ' ') {
            str[i] = '-';
            }
            i++;
        }
        printf("Modified String: %s", str);
    return 0;
 }