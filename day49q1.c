//Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/
#include <stdio.h>

int main() {
    char name[100];
    int i;
    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);
    if (name[0] != ' ' && name[0] != '\n') {
        printf("%c.", name[0]);
    }
    for (i = 1; name[i] != '\0'; i++) {
        if (name[i] == ' ' && name[i + 1] != ' ' && name[i + 1] != '\n' && name[i + 1] != '\0') {
            printf("%c.", name[i + 1]);
        }
    }
    printf("\n");
    
    return 0;
}