#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"

#define ROW_LENGTH 200
int mappingA = 80;
int mappingB = 70;
int mappingC = 60;
int mappingD = 50;
 int size = 10;//the value of size is chosen arbitrarily to initialize the size of the dynamic array.
int main() {
   char filename[20];

   printf("Student file reader:\n");
   printf("\nEnter the filename:");
    scanf("%s", &filename);

   struct Student* students = malloc(size * sizeof(struct Student));
    FILE *file_ptr = fopen(filename, "r");  // r for reading only

    if (file_ptr == NULL) {
        printf("File not found.\n");
        return 1;
    }

    char row_buffer[ROW_LENGTH];  // Buffer to hold a line from the file
   
    int i = 0;

    // Reading from the file
    while (fgets(row_buffer, ROW_LENGTH, file_ptr) != NULL && i < 100) {
        
        if(i >= size) {
        size *= 2;
        students = realloc(students, size * sizeof(struct Student));}

        sscanf(row_buffer, "%d|%99[^|]|%99[^|]|%d|%d|%d|%d|%d", 
       &students[i].StudentID, students[i].lastName, students[i].firstName, 
       &students[i].grade1, &students[i].grade2, &students[i].grade3, 
       &students[i].gradeM, &students[i].gradeF);

        i++;
    }

    size = i;



    int j = 0;

    while (j<size)
    {
        if(students[j].StudentID != 0)
        {
    students[j].total = ((students[j].grade1 + students[j].grade2 + students[j].grade3) / 120.0) * 100 * 0.25
                    + (students[j].gradeM / 25.0) * 100 * 0.25
                    + (students[j].gradeF / 40.0) * 100 * 0.50;

        if (students[j].total >= mappingA) {
            students[j].lGrade = 'A';
        } else if (students[j].total >= mappingB && students[j].total < mappingA) {
            students[j].lGrade = 'B';
        } else if (students[j].total >= mappingC && students[j].total < mappingB) {
            students[j].lGrade = 'C';
        } else if (students[j].total >= mappingD && students[j].total < mappingC) {
            students[j].lGrade = 'D';
        } else {
            students[j].lGrade = 'F';
        }
        }
        j++;
    }
    int userinput;

    char proceed = 'c';

    do
    {
        printf("\n\nSpreadsheet Menu\n"
           "----------------\n"
           "1. Display Spreadsheet\n"
           "2. Display Histogram\n"
           "3. Set sort column\n"
           "4. Update Last Name\n"
           "5. Update Exam Grade\n"
           "6. Update Grade Mapping\n"
           "7. Delete Student\n"
           "8. Exit\n\n");

     printf("Selection: ");
        scanf("%d", &userinput);


            switch(userinput)
            {
                case 1:
                    option1(students, size);
                    break;
                case 2:
                    option2(students, size);
                    break;
                case 3:
                    option3(students, size);
                    break;
                case 4:
                    option4(students, size);
                    break;
                case 5:
                    option5(students, size);
                    break;
                case 6:
                    option6(students, size);
                    break;
                case 7:
                    option7(students, size);
                    break;
                case 8:
                    option8();
                    break;
                default:
                    {
                        printf("\nInvalid Input.\n");
                    }
                    
            }
            printf("\nPress 'c' or 'C' to continue ");
            scanf(" %c", &proceed);
        
    }while( (proceed == 'c') || (proceed == 'C'));


    fclose(file_ptr);
    return 0;
}
