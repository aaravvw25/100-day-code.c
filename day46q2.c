//Q92: Find the first repeating lowercase alphabet in a string.

/*
Sample Test Cases:
Input 1:
stress
Output 1:
s

*/
 #include <stdio.h>
 
 int main() {
    char str[100];
    int freq[26] = {0};
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
        if(freq[str[i] - 'a'] == 2) {
            printf("%c\n", str[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
 }