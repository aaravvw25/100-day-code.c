// Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

/*
Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char date[12]; 
    printf("Enter a date (dd/04/yyyy): ");
    fgets(date, sizeof(date), stdin);

    if (date[2] == '/' && date[5] == '/')
    {
        char year[5];
        strncpy(year, &date[6], 4);
        year[4] = '\0';

        date[2] = '-';
        date[3] = 'A';
        date[4] = 'p';
        date[5] = 'r';
        date[6] = '-';

        strcpy(&date[7], year);

        printf("Formatted date: %s\n", date);
    }
    else
    {
        printf("Invalid date format.\n");
    }

    return 0;
}
