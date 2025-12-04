//Q86: Check if a string is a palindrome.

/*
Sample Test Cases:
Input 1:
madam
Output 1:
Palindrome

Input 2:
hello
Output 2:
Not palindrome

*/
 #include <stdio.h>
 
 int main() {
        char str[100];
        int i = 0, j, len = 0, isPalindrome = 1;
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        while (str[len] != '\0') {
            len++;
        }
        if (len > 0 && str[len - 1] == '\n') {
            len--;
        }
        j = len - 1;
        for (i = 0; i < len / 2; i++) {
            if (str[i] != str[j]) {
                isPalindrome = 0;
                break;
            }
            j--;
        }
        if (isPalindrome) {
            printf("Palindrome\n");
        } else {
            printf("Not palindrome\n");
        }
    return 0;
 }