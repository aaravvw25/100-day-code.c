//Q96: Reverse each word in a sentence without changing the word order.

/*
Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc

*/
#include <stdio.h>

int main() {
    char str[200];
    int i, start, end;
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
       for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == ' ' || str[i] == '\n') {
                end = i - 1;
                start = i - 1;
                while (start >= 0 && str[start] != ' ') {
                    start--;
                }
                start++;
                while (start < end) {
                    char temp = str[start];
                    str[start] = str[end];
                    str[end] = temp;
                    start++;
                    end--;
                }
            }
        }
    printf("Reversed sentence: %s", str);   
    return 0;
}