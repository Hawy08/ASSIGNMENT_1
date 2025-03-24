#include <stdio.h>
#include "studentdata.h"

void printStudentData(const StudentData *student) {
    printf("\nStudent Data:\n"); // Add newline for separation
    printf("------------------------\n");
    printf("Registration: %s\n", student->student_reg);
    printf("Name: %s\n", student->student_name);
    printf("School: %s\n", student->student_school);
    printf("Department: %s\n", student->student_department);
    printf("Course Code: %s\n", student->course_code);
    printf("Course Name: %s\n", student->course_name);
    printf("------------------------\n\n"); // Add extra newline
}

void printStudentScores(const StudentScores *scores) {
    printf("\nStudent Scores:\n");
    printf("------------------------\n");
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Unit Code: %s\n", scores->unit_grades[i].unit_code);
        printf("Grade: %s\n", scores->unit_grades[i].grade);
        printf("------------------------\n");
    }
    float average = calculateAverage((StudentScores*)scores);
    printf("Average Grade : %.2f\n\n", average);
}