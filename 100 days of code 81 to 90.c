//Q131: Create an enumeration for days (SUNDAY to SATURDAY) and print each day with its integer value.

/*
Sample Test Cases:
Input 1:
No input
Output 1:
SUNDAY = 0
MONDAY = 1
TUESDAY = 2
WEDNESDAY = 3
THURSDAY = 4
FRIDAY = 5
SATURDAY = 6

*/
#include <stdio.h>

int main() {
    enum Days { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
    printf("SUNDAY = %d\n", SUNDAY);
    printf("MONDAY = %d\n", MONDAY);
    printf("TUESDAY = %d\n", TUESDAY);
    printf("WEDNESDAY = %d\n", WEDNESDAY);
    printf("THURSDAY = %d\n", THURSDAY);
    printf("FRIDAY = %d\n", FRIDAY);
    printf("SATURDAY = %d\n", SATURDAY);
                    

       return 0;
}
//Q133: Create an enum for months and print how many days each month has.

/*
Sample Test Cases:
Input 1:
FEB
Output 1:
28 or 29 days

*/
#include <stdio.h>

int main() {
    enum Months { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    enum Months month = FEB;
    switch (month) {
        case JAN:
            printf("31 days\n");
            break;
        case FEB:
            printf("28 or 29 days\n");
            break;
        case MAR:
            printf("31 days\n");
            break;
        case APR:
            printf("30 days\n");
            break;
        case MAY:
            printf("31 days\n");
            break;
        case JUN:
            printf("30 days\n");
            break;
        case JUL:
            printf("31 days\n");
            break;
        case AUG:
            printf("31 days\n");
            break;
        case SEP:
            printf("30 days\n");
            break;
        case OCT:
            printf("31 days\n");
            break;
        case NOV:
            printf("30 days\n");
            break;
        case DEC:
            printf("31 days\n");
            break;
        default:
            printf("Invalid month\n");
    }
                   
    return 0;
}
/Q135: Assign explicit values starting from 10 and print them.

/*
Sample Test Cases:
Input 1:
No input
Output 1:
A=10
B=11
C=12

*/
#include <stdio.h>

int main() {
    enum Letters { A = 10, B, C };
    printf("A=%d\n", A);    
    printf("B=%d\n", B);    
    printf("C=%d\n", C);  
    return 0;
    //Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

/*
Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30

*/
#include <stdio.h>

int main() {
    enum Menu { ADD, SUBTRACT, MULTIPLY };
    enum Menu choice = ADD;     
    int a = 10, b = 20; 
    switch (choice) {
        case ADD:
            printf("%d\n", a + b);
            break;
        case SUBTRACT:
            printf("%d\n", a - b);
            break;
        case MULTIPLY:
            printf("%d\n", a * b);
            break;
        default:
            printf("Invalid choice\n");
    }

        
    return 0;
}
//Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
/*
Sample Test Cases:
Input 1:
GUEST
Output 1:
Welcome Guest!
*/
#include <stdio.h>
int main() {
    enum     UserRole { ADMIN, USER, GUEST };
    enum UserRole role = GUEST; 
    switch (role) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
        default:
            printf("Unknown role\n");
    }   
    return 0;
}
//Q138: Print all enum names and integer values using a loop.

/*
Sample Test Cases:
Input 1:
No input
Output 1:
RED=0
YELLOW=1
GREEN=2

*/
#include <stdio.h>

int main() {
    enum TrafficLight { RED, YELLOW, GREEN };
    const char* lightNames[] = { "RED", "YELLOW", "GREEN" };    
    int numLights = sizeof(lightNames) / sizeof(lightNames[0]); 
    for (int i = 0; i < numLights; i++) {
        printf("%s=%d\n", lightNames[i], i);
    }   
                                                                                                   
    return 0;
}
//Q139: Show that enums store integers by printing assigned values.

/*
Sample Test Cases:
Input 1:
No input
Output 1:
SUCCESS=0, FAILURE=1, TIMEOUT=2
*/

#include <stdio.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main() {
    enum Status s1 = SUCCESS;
    enum Status s2 = FAILURE;
    enum Status s3 = TIMEOUT;

    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d", s1, s2, s3);

    return 0;
}
//Q140: Define a struct with enum Gender and print person's gender.

/*
Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male

*/
#include <stdio.h>
#include <string.h>

enum Gender { MALE, FEMALE, OTHER };

struct Person {
    enum Gender gender;
};

int main() {
    char input[20];
    struct Person p;

    scanf("%s", input);
    char *value = strchr(input, '=') + 1;

    if (strcmp(value, "MALE") == 0)
        p.gender = MALE;
    else if (strcmp(value, "FEMALE") == 0)
        p.gender = FEMALE;
    else
        p.gender = OTHER;

    switch (p.gender) {
        case MALE:   printf("Male");   break;
        case FEMALE: printf("Female"); break;
        case OTHER:  printf("Other");  break;
    }

    return 0;
}
