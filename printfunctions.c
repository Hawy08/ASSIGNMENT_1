#include <stdio.h>
#include "studentdata.h"

void printStudentData(const StudentData *student) {
    printf("\nStudent Data:\n");
    printf("Registration: %s", student->student_reg);
    printf("Name: %s", student->student_name);
    printf("School: %s", student->student_school);
    printf("Department: %s", student->student_department);
    printf("Course Code: %s", student->course_code);
    printf("Course Name: %s", student->course_name);
}

void printStudentScores(const StudentScores *scores) {
    if (scores == NULL) {
        printf("Error: No student scores available.\n");
        return;
    }

    printf("\nStudent Scores:\n");
    printf("------------------------\n");
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Unit Code: %-10s\n", scores->unit_grades[i].unit_code);
        printf("Grade: %-2s\n", scores->unit_grades[i].grade);
        printf("------------------------\n");
    }
}