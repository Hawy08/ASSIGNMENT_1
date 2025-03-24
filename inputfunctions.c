#include "studentdata.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower

void inputStudentData(StudentData *student) {
    printf("Enter student registration number: ");
    fgets(student->student_reg, sizeof(student->student_reg), stdin);
    remove_newline(student->student_reg);

    printf("Enter student name: ");
    fgets(student->student_name, sizeof(student->student_name), stdin);
    remove_newline(student->student_name);

    printf("Enter student school: ");
    fgets(student->student_school, sizeof(student->student_school), stdin);
    remove_newline(student->student_school);

    printf("Enter student department: ");
    fgets(student->student_department, sizeof(student->student_department), stdin);
    remove_newline(student->student_department);

    printf("Enter course code: ");
    fgets(student->course_code, sizeof(student->course_code), stdin);
    remove_newline(student->course_code);

    printf("Enter course name: ");
    fgets(student->course_name, sizeof(student->course_name), stdin);
    remove_newline(student->course_name);
}

const char *valid_unit_codes[] = {
    "EEE 2301", "EEE 2302", "EEE 2303", "EEE 2304", "EEE 2305", "EEE 2306",
    "SMA 2307", "ICS 2308"
};
const int valid_unit_codes_count = sizeof(valid_unit_codes) / sizeof(valid_unit_codes[0]);

const char *valid_grades[] = {
    "A", "B", "C", "D", "E", "F"
};
const int valid_grades_count = sizeof(valid_grades) / sizeof(valid_grades[0]);

int is_valid_unit_code(const char *input) {
    for (int i = 0; i < valid_unit_codes_count; i++) {
        if (strcmp(input, valid_unit_codes[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_valid_grade(const char *input) {
    for (int i = 0; i < valid_grades_count; i++) {
        if (strcmp(input, valid_grades[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Calculate the GPA by summing the GPA points
// Function to convert letter grades to GPA points
// Convert letter grade to GPA points
float gradeToPoints(char grade) {
    switch (grade) {
        case 'A': return 4.0f;
        case 'B': return 3.0f;
        case 'C': return 2.0f;
        case 'D': return 1.0f;
        case 'E': return 0.5f;
        case 'F': return 0.0f;
        default: return 0.0f; // Invalid grade
    }
}


// Function to calculate the GPA
float calculateAverage(StudentScores *scores) {
    float totalPoints = 0.0f;
    int validGrades = 0;

    // Iterate over the scores and calculate the total GPA points
    for (int i = 0; i < MAX_GRADES; i++) {
        if (scores->unit_grades[i].grade[0] == '\0') {
            break;  // Stop if no more grades are provided
        }

        char grade = toupper(scores->unit_grades[i].grade[0]); // Ensure uppercase
        float points = gradeToPoints(grade);

        // Debug output to verify each grade
        printf("Processing grade for unit %s: %c => %.2f GPA points\n", 
            scores->unit_grades[i].unit_code, grade, points);

        if (points > 0.0f) {  // Valid grade
            totalPoints += points;
            validGrades++;
        }
    }

    // GPA output and return
    printf("Total GPA Points: %.2f\n", totalPoints);
    printf("Number of valid grades: %d\n", validGrades);

    // If there are valid grades, return the GPA, otherwise return 0.0
    if (validGrades > 0) {
        float gpa = totalPoints / validGrades;
        printf("Calculated GPA: %.2f\n", gpa);
        return gpa;
    } else {
        printf("No valid grades found.\n");
        return 0.0f;  // No valid grades
    }
}


void inputStudentScores(StudentScores *scores) {
    for (int i = 0; i < MAX_GRADES; i++) {
        int valid_input = 0;

        while (!valid_input) {
            printf("Enter unit code (choose from the following):\n");
            for (int j = 0; j < valid_unit_codes_count; j++) {
                printf("%s\n", valid_unit_codes[j]);
            }
            printf("Unit code %d: ", i + 1);
            fgets(scores->unit_grades[i].unit_code, sizeof(scores->unit_grades[i].unit_code), stdin);
            remove_newline(scores->unit_grades[i].unit_code);

            int c; // clear buffer
            while ((c = getchar()) != '\n' && c != EOF);

            if (is_valid_unit_code(scores->unit_grades[i].unit_code)) {
                int grade_valid = 0;
                while (!grade_valid) {
                    printf("Enter grade for %s (A, B, C, D, E, F): ", scores->unit_grades[i].unit_code);
                    fgets(scores->unit_grades[i].grade, sizeof(scores->unit_grades[i].grade), stdin);
                    remove_newline(scores->unit_grades[i].grade);

                    while ((c = getchar()) != '\n' && c != EOF); // clear buffer

                    if (is_valid_grade(scores->unit_grades[i].grade)) {
                        grade_valid = 1;
                    } else {
                        printf("Invalid grade. Please enter a valid grade (A, B, C, D, E, F).\n");
                    }
                }
                valid_input = 1;
            } else {
                printf("Invalid unit code. Please try again.\n");
            }
        }
    }
}



