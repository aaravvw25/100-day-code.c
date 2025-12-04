//Q120: Write a program to take a string input. Change it to sentence case.

/*
Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.

*/
#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    int capitalizeNext = 1; 
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            capitalizeNext = 1; 
        } else if (capitalizeNext && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - ('a' - 'A');
            }
            capitalizeNext = 0; 
            capitalizeNext = 0;
        }
        i++;
    }

    printf("Sentence Case: %s", str);
    return 0;

}

//Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

/*
Sample Test Cases:
Input 1:
Name: Rahul, Age: 23
Output 1:
File created successfully! Data written to info.txt

*/
#include <stdio.h>

int main() {
    FILE *file;
    char name[100]; 
    int age;    
    printf("Enter your name: ");    
    fgets(name, sizeof(name), stdin);   
    printf("Enter your age: "); 
    scanf("%d", &age);  
    file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "Name: %sAge: %d\n", name, age);  
    fclose(file);
    printf("File created successfully! Data written to info.txt\n");    
                                                       
    return 0;
}
/Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

/*
Sample Test Cases:
Input 1:
File: sample.txt (Content: Hello world\nThis is C programming)
Output 1:
Characters: 31
Words: 5
Lines: 2

*/
#include <stdio.h>

int main() {
    FILE *file;
    char filename[100]; 
    printf("Enter the filename: ");
    scanf("%s", filename);  
                
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    int characters = 0, words = 0, lines = 0;
    char ch;    
    int inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }
    if (characters > 0) {
        lines++; 
    }
    fclose(file);
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);   
                            
    return 0;
}
//Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

/*
Sample Test Cases:
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt

*/
#include <stdio.h>

int main() {
    char sourceFilename[100], destFilename[100];
    printf("Enter the source filename: ");
    scanf("%s", sourceFilename);
    printf("Enter the destination filename: "); 
    scanf("%s", destFilename);  
    FILE *sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Could not open source file %s\n", sourceFilename);
        return 1;
    }
    FILE *destFile = fopen(destFilename, "w");
    if (destFile == NULL) {
        printf("Could not open destination file %s\n", destFilename);
        fclose(sourceFile);
        return 1;
    }
    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    fclose(sourceFile);
    fclose(destFile);
    printf("File copied successfully to %s\n", destFilename);
                           
    return 0;
}
/Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

/*
Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.

*/
#include <stdio.h>

int main() {
    char filename[100];
    char newLine[256];  
    printf("Enter the filename to append text: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "a");
    if (file == NULL) { 
        printf("Could not open file %s\n", filename);
        return 1;   
    }       
    printf("Enter the text to append: ");   
    getchar();  
    fgets(newLine, sizeof(newLine), stdin); 
    fputs(newLine, file);       
    fclose(file);   
    printf("File updated successfully with appended text.\n");
                        
       return 0;
}
//Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.

/*
Sample Test Cases:
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully.
(Displays file content)

Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!

*/
#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter the filename to check: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File does not exist!\n");
        return 1;
    }
    printf("File opened successfully.\n");
    char ch;    
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);  
    return 0;
}
//Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.

/*
Sample Test Cases:
Input 1:
File: text.txt (Content: Welcome to C language)
Output 1:
Vowels: 8
Consonants: 10

*/
#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "text.txt";   
    char ch;    
    int vowels = 0, consonants = 0;
    file = fopen(filename, "r");    
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char lowerCh = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; 
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    fclose(file);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants); 
                                        
    return 0;
}   
//Q129: A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.

/*
Sample Test Cases:
Input 1:
File: numbers.txt (Content: 10 20 30 40 50)
Output 1:
Sum = 150
Average = 30.00

*/
#include <stdio.h>

int main() {
    FILE *file = fopen("numbers.txt", "r");     
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }       
    int number;             
    int sum = 0;    
    int count = 0;  
    while (fscanf(file, "%d", &number) == 1) {         
        sum += number;         
        count++;     
    }   
    fclose(file);
    if (count == 0) {
        printf("No numbers found in the file.\n");
        return 1;
    }
    double average = (double)sum / count;5
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
                                                                                               
    return 0;
}
// Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

/*
Sample Test Cases:
Input 1:
Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92

*/
#include <stdio.h>

int main()
{
   
    FILE *file = fopen("students.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }   
    fprintf(file, "Asha %d %d\n", 101, 85);
    fprintf(file, "Ravi %d %d\n", 102, 92);
    fclose(file);
    file = fopen("students.txt", "r");  
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }
    char name[50];
    int roll, marks;
    while (fscanf(file, "%s %d %d", name, &roll, &marks) == 3)
    {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }   
    fclose(file);
                                
    return 0;
}