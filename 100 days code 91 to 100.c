//Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.

/*
Sample Test Cases:
Input 1:
Name: Asha
Roll: 101
Marks: 90
Output 1:
Name: Asha | Roll: 101 | Marks: 90

*/
#include <stdio.h>

int main() {
    struct Student {
        char name[50];
        int roll_no;
        int marks;
    };
    struct Student s;   
    printf("Name: ");
    scanf("%s", s.name);
    printf("Roll: ");   
    scanf("%d", &s.roll_no);
    printf("Marks: ");
    scanf("%d", &s.marks);
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
    return 0;
}
//Q142: Store details of 5 students in an array of structures and print all.

/*
Sample Test Cases:
Input 1:
Details of 5 students (Name, Roll, Marks)
Output 1:
Tabular list of all 5 students with their details

*/
#include <stdio.h>
int main() {
    struct Student {
        char name[50];
        int roll_no;
        int marks;
    };  
    struct Student students[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }
    printf("\nDetails of all students:\n");
    printf("Name\tRoll No\tMarks\n");
    for (int i = 0; i < 5; i++) {
    printf("%s\t%d\t%d\n", students[i].name, students[i].roll_no, students[i].marks);
    }                                                                                                                                                       
    return 0;
}
//Q143: Find and print the student with the highest marks.

/*
Sample Test Cases:
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)

*/
#include <stdio.h>

int main() {
    struct Student {
        char name[50];
        int roll_no;
        int marks;
    };
    struct Student students[3]; 
    for (int i = 0; i < 3; i++) {
        printf("Enter details for student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }
    struct Student topper = students[0];    
    for (int i = 1; i < 3; i++) {
        if (students[i].marks > topper.marks) {
            topper = students[i];
        }
    }
    printf("\nTopper: %s (Marks: %d)\n", topper.name, topper.marks);
           
    return 0;
}
//Q145: Return a structure containing top student's details from a function.

/*
Sample Test Cases:
Input 1:
3 students: Riya 101 89, Karan 102 96, Meena 103 92
Output 1:
Top Student: Karan | Roll: 102 | Marks: 96

*/
#include <stdio.h>

int main() {
    struct Student {
        char name[50];
        int roll;
        int marks;
    };
    struct Student getTopStudent(struct Student students[], int n) {
        struct Student topStudent = students[0];
        for (int i = 1; i < n; i++) {
            if (students[i].marks > topStudent.marks) {
                topStudent = students[i];
            }
        }
        return topStudent;
    }
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll number and marks of student %d: ", i + 1);
        scanf("%s %d %d", students[i].name, &students[i].roll, &students[i].marks);
    }
    struct Student topStudent = getTopStudent(students, n);
    printf("Top Student: %s | Roll: %d | Marks: %d\n", topStudent.name, topStudent.roll, topStudent.marks);
                
    return 0;
}   
// Q146: Create Employee structure with nested Date structure for joining date and print details.

/*
Sample Test Cases:
Input 1:
Employee: Raj | ID: 11 | Joining Date: 12 05 2020
Output 1:
Name: Raj | ID: 11 | Joining Date: 12/05/2020

*/
#include <stdio.h>

int main()
{
    struct Date
    {
        int day;
        int month;
        int year;
    };
    struct Employee
    {
        char name[50];
        int id;
        struct Date joiningDate;
    };
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter name, ID and joining date (DD MM YYYY) of employee %d: ", i + 1);
        scanf("%s %d %d %d %d", employees[i].name, &employees[i].id, &employees[i].joiningDate.day, &employees[i].joiningDate.month, &employees[i].joiningDate.year);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n", employees[i].name, employees[i].id, employees[i].joiningDate.day, employees[i].joiningDate.month, employees[i].joiningDate.year);
    }

    return 0;
}
//Q147: Store employee data in a binary file using fwrite() and read using fread().

/*
Sample Test Cases:
Input 1:
Employee details entered and stored in file.
Output 1:
Displays employee data read from file.

*/
#include <stdio.h>

int main() {
    struct Date
    {
        int day;
        int month;
        int year;
    };  
    struct Employee
    {
        char name[50];
        int id;
        struct Date joiningDate;
    };
    struct Employee emp;
    FILE *file = fopen("employees.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    printf("Enter employee name, ID and joining date (DD MM YYYY): ");
    scanf("%s %d %d %d %d", emp.name, &emp.id, &emp.joiningDate.day, &emp.joiningDate.month, &emp.joiningDate.year);
    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);
    file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    struct Employee readEmp;
    fread(&readEmp, sizeof(struct Employee), 1, file);
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n", readEmp.name, readEmp.id, readEmp.joiningDate.day, readEmp.joiningDate.month, readEmp.joiningDate.year);
    fclose(file);
    return 0;
}
//Take two structs as input and check if they are identical. Input 1: Student1: Asha 101 90 Student2: Asha 101 90

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    struct Student s1, s2;

    // Input for Student 1
    scanf("%s %d %d", s1.name, &s1.roll, &s1.marks);

    // Input for Student 2
    scanf("%s %d %d", s2.name, &s2.roll, &s2.marks);

    // Compare all members
    if (strcmp(s1.name, s2.name) == 0 &&
        s1.roll == s2.roll &&
        s1.marks == s2.marks) 
    {
        printf("Same");
    } else {
        printf("Not Same");
    }

    return 0;
}
//Use malloc() to allocate structure memory dynamically and print details.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    // Dynamically allocate memory for 1 student
    struct Student *s = (struct Student *)malloc(sizeof(struct Student));

    // Check if memory allocated
    if (s == NULL) {
        printf("Memory not allocated\n");
        return 1;
    }
