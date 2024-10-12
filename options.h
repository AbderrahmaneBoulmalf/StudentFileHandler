//student struct header file
#ifndef STUDENT_H
#define STUDENT_H

#define ROW_LENGTH 200

struct Student {
    int StudentID;
    char lastName[100];//first and last names are limited to 100 characters.
    char firstName[100];
    int grade1;
    int grade2;
    int grade3;
    int gradeM;
    int gradeF;
    float total;
    char lGrade;
};  

void option1(struct Student* student, int size);
void option2(struct Student* student, int size);
void option3(struct Student* student, int size);
void option4(struct Student* student, int size);
void option5(struct Student* student, int size);
void option6(struct Student* student, int size);
void option7(struct Student* student, int size);
void option8(void);

#endif