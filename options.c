#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"
int userinput;

extern int mappingA;
extern int mappingB;
extern int mappingC;
extern int mappingD;
extern int size;
void option1(struct Student* students, int size) {
    printf("COMP 348 GRADE SHEET\n\n");

    printf("%-5s %-10s %-10s %-5s %-5s %-5s %-5s %-10s %-10s %-10s\n", "ID", "Last", "First", "A1", "A2", "A3", "Midterm", "Exam", "Total", "Grade");

    printf("%-5s %-10s %-10s %-5s %-5s %-5s %-5s %-10s %-10s %-10s\n", "--", "----", "-----", "--", "--", "--", "-------", "----", "-----", "-----");

    int i = 0;

    while (i < size) {
       
if(students[i].StudentID != 0)
        {
        printf("%-5d %-10s %-10s %-5d %-5d %-5d %-5d %-10d %-10.2f %-10c\n", students[i].StudentID, students[i].lastName, students[i].firstName, students[i].grade1, students[i].grade2, students[i].grade3, students[i].gradeM, students[i].gradeF, students[i].total, students[i].lGrade);
        i++;
        }
        }

}  // option1 end

void option2(struct Student* students, int size) {
    printf("COMP 348 Grade Distribution\n\n");

    char A[100] = "";
    char B[100] = "";
    char C[100] = "";
    char D[100] = "";
    char F[100] = "";

    int i = 0;
    while (i < size) {
        if (students[i].lGrade == 'A') {
            strcat(A, "*");
        } else if (students[i].lGrade == 'B') {
            strcat(B, "*");
        } else if (students[i].lGrade == 'C') {
            strcat(C, "*");
        } else if (students[i].lGrade == 'D') {
            strcat(D, "*");
        } else if (students[i].lGrade == 'F') {
            strcat(F, "*");
        }
        i++;
    }

    // Printing the results.
    printf("A: %s\n", A);
    printf("B: %s\n", B);
    printf("C: %s\n", C);
    printf("D: %s\n", D);
    printf("F: %s\n", F);
}  // option2 end

int comparebyID(const void *x, const void *y)
{
    struct Student* studentA = (struct Student*)x;
    struct Student* studentB = (struct Student*)y;

    return (studentA->StudentID - studentB->StudentID);
}

void sortbyID(struct Student* students, int size)//sort option 1
{
    qsort(students, size, sizeof(struct Student), comparebyID);
}

int compareLastname(const void *x, const void *y)
{
    struct Student* studentA = (struct Student*)x;
    struct Student* studentB = (struct Student*)y;

    return strcmp(studentA->lastName, studentB->lastName);
}
void sortbyLastname(struct Student* students, int size)
{
    qsort(students, size, sizeof(struct Student), compareLastname);//sort option 2
}

int comparegrade(const void* x, const void* y)
{
    int A = ((struct Student*)x)->gradeF;
    int B = ((struct Student*)y)->gradeF;

    return A-B;
}

void sortbygradeF(struct Student* students, int size)
{
    qsort(students, size, sizeof(struct Student), comparegrade);
}

int comparetotal(const void* x, const void* y)
{
   float A = ((struct Student*)x)->total;
   float B = ((struct Student*)y)->total;

    return (A > B) - (A < B);
}

void sortbyTotal(struct Student* students, int size)
{
    qsort(students, size, sizeof(struct Student), comparetotal);
}

void option3(struct Student* students, int size)
{
    printf("Column Options\n"
           "--------------\n"
           "1. Student ID\n"
           "2. Last name\n"
           "3. Exam\n"
           "4. Total\n\n"
           "Sort Column:");

    scanf("%d", &userinput);

    if (userinput == 1) {
        sortbyID(students, size);
    }

    if (userinput == 2)
    {
        sortbyLastname(students, size);
    }

    if (userinput == 3)
    {
        sortbygradeF(students, size);
    }

    if (userinput == 4)
    {
        sortbyTotal(students, size);
    }

    printf("\nSort column updated\n");

}

void option4(struct Student* students, int size)
{
    option1(students,size);

    printf("\nEnter Student ID:");
    scanf("%d", &userinput);
    int i = 0;

    while(i<size)
    {
        if(students[i].StudentID==userinput)
        {
            char updatedLastname[100];
            printf("Enter updated Last Name:");
            scanf("%s", updatedLastname);
           strcpy(students[i].lastName, updatedLastname);
            printf("\nLast name updated.\n");
            return;
        }
    i++;
    }
}

void option5(struct Student* students, int size)
{
    int updatedExam;
     option1(students,size);

    printf("\nEnter Student ID:");
    scanf("%d", &userinput);
    int i = 0;

    while(i<size)
    {
        if(students[i].StudentID==userinput)
        {
            printf("Enter updated Exam grade:");
            scanf("%d", &updatedExam);
            if(updatedExam<13 || updatedExam>39)
            {
                printf("\ninvalid grade.");
                return;
            }
           students[i].gradeF = updatedExam;
            printf("\nExam grade updated.\n");
            return;
        }
    i++;
    }
    int j =0;
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
    }//this while loop is to reset the letter grades for all students.


}//end of option 5.

void option6(struct Student* students, int size)
{
    int newA;
    int newB;
    int newC;
    int newD;
     printf("Current Mapping:");
     printf("\nA: >= %d", mappingA);
     printf("\nB: >= %d", mappingB);
     printf("\nC: >= %d", mappingC);
     printf("\nD: >= %d", mappingD);
     printf("\nF:  < %d", mappingD);

     printf("\n\nEnter new A baseline:");
     scanf("%d", &newA);
    mappingA = newA;
     printf("\nEnter new B baseline:");
     scanf("%d", &newB);
    mappingB = newB;
     printf("\nEnter new C baseline:");
     scanf("%d", &newC);
    mappingC = newC;
     printf("\nEnter new D baseline:");
     scanf("%d", &newD);
    mappingD = newD;

    printf("\n\nNew Mapping:");
     printf("\nA: >= %d", mappingA);
     printf("\nB: >= %d", mappingB);
     printf("\nC: >= %d", mappingC);
     printf("\nD: >= %d", mappingD);
     printf("\nF:  < %d", mappingD);

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
    }//this while loop is to reset the letter grades for all students.

}

void option7(struct Student* students, int x)
{
     option1(students,x);//display menu function.

    printf("\nEnter Student ID:");
    scanf("%d", &userinput);

    int i = 0;
    while(i<size)
    {
        if(students[i].StudentID==userinput)
        {
            int index = i;
            while(index < size - 1)
            {
                students[index] = students[index +1];
            index++;
            }
        size--;
        return;
        }
    i++;
    }
}

void option8(void)
{
    printf("\nThank you for using this program."
           "\nGoodbye!");
    exit(0);
}