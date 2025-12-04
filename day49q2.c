//Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/
#include <stdio.h>

int main() {
    char name[100];
    int i, lastSpaceIndex = -1;
    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);
    if (name[0] != ' ' && name[0] != '\n') {
        printf("%c.", name[0]);
    }
    for (i = 1; name[i] != '\0'; i++) {
        if (name[i] == ' ' && name[i + 1] != ' ' && name[i + 1] != '\n' && name[i + 1] != '\0') {
            printf("%c.", name[i + 1]);
            lastSpaceIndex = i;
        }
    }
    if (lastSpaceIndex != -1) {
        printf(" %s", &name[lastSpaceIndex + 1]);
    } else {
        printf(" %s", name);
    }
    
    return 0;
}