#include <stdio.h>
#include "studentdata.h"

void printStudentDataAndScores(StudentData *student, StudentScores *scores) {
    printf("\nWHAT GOES INTO THE PDF:\n");
    printStudentData(student);
    printStudentScores(scores);
}

int main() {
    StudentData student;
    StudentScores scores;

    inputStudentData(&student);
    inputStudentScores(&scores);

    printStudentDataAndScores(&student, &scores);

    // Calculate numScores based on the input
    int numScores = 0;
    for (int i = 0; i < MAX_GRADES; i++) {
        if (scores.unit_grades[i].unit_code[0] != '\0') {
            numScores++;
        } else {
            break; // Stop counting when an empty unit_code is encountered
        }
    }

    generateStudentCsv(&student, &scores, numScores, "student_report.csv");


    printf("CSV generated successfully!\n");

    printf("Hello, world!\n");

    return 0;
}