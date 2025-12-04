//Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/
 #include <stdio.h>
 
 int main() {
    char str[100], longest[100];
    int maxLen = 0, currentLen = 0, start = 0, longestStart = 0;
    fgets(str, sizeof(str), stdin);
    for(int i = 0; ; i++) {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            currentLen++;
        } else {
            if(currentLen > maxLen) {
                maxLen = currentLen;
                longestStart = start;
            }
            currentLen = 0;
            start = i + 1;
        }
        if(str[i] == '\n' || str[i] == '\0') {
            break;
        }
    }
    for(int i = 0; i < maxLen; i++) {
        longest[i] = str[longestStart + i];
    }
    longest[maxLen] = '\0';
    printf("%s\n", longest);
    return 0;
 }