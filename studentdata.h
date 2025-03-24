#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#define MAX_UNIT_CODE_LENGTH 9   // 8 characters + null terminator
#define MAX_GRADE_LENGTH 2       // 1 character + null terminator
#define MAX_GRADES 8             // Define the maximum number of grades


#include <stdio.h>

// Structure for student personal information
typedef struct {
    char student_reg[20];
    char student_name[100];
    char student_school[100];
    char student_department[100];
    char course_code[20];
    char course_name[100];
} StudentData;

// Structure for unit code and grade
typedef struct {
    char unit_code[MAX_UNIT_CODE_LENGTH];  // Unit code
    char grade[MAX_GRADE_LENGTH];          // Corresponding grade
} UnitGrade;

// StudentScores structure that holds an array of UnitGrade
typedef struct {
    UnitGrade unit_grades[MAX_GRADES];  // Array of UnitGrade structures (8 units with grades)
} StudentScores;

void inputStudentData(StudentData *student);
void printStudentData(const StudentData *student);
void inputStudentScores(StudentScores *scores);
void printStudentScores(const StudentScores *scores);
void outputStudentScores(StudentScores *scores, int numScores, FILE *file);
void outputStudentData(StudentData *student, FILE *file);
void generateStudentCsv(StudentData *student, StudentScores *scores, int numScores, const char *filename);
float gradeToPoints(char grade);
float calculateAverage(StudentScores *scores);


#endif
