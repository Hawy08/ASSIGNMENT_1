#include "studentdata.h"
#include <stdio.h>
#include <string.h>

void inputStudentData(StudentData *student) {
    printf("Enter student registration number: ");
    fgets(student->student_reg, sizeof(student->student_reg), stdin);

    printf("Enter student name: ");
    fgets(student->student_name, sizeof(student->student_name), stdin);

    printf("Enter student school: ");
    fgets(student->student_school, sizeof(student->student_school), stdin);

    printf("Enter student department: ");
    fgets(student->student_department, sizeof(student->student_department), stdin);

    printf("Enter course code: ");
    fgets(student->course_code, sizeof(student->course_code), stdin);

    printf("Enter course name: ");
    fgets(student->course_name, sizeof(student->course_name), stdin);
}


// Predefined valid unit codes
const char *valid_unit_codes[] = {
    "EEE 2301", "EEE 2302", "EEE 2303", "EEE 2304", "EEE 2305", "EEE 2306",
    "SMA 2307", "ICS 2308"
};
const int valid_unit_codes_count = sizeof(valid_unit_codes) / sizeof(valid_unit_codes[0]);

// Predefined valid grades
const char *valid_grades[] = {
    "A", "B", "C", "D", "E", "F"
};
const int valid_grades_count = sizeof(valid_grades) / sizeof(valid_grades[0]);

// Function to check if the unit code is valid
int is_valid_unit_code(const char *input) {
    for (int i = 0; i < valid_unit_codes_count; i++) {
        if (strcmp(input, valid_unit_codes[i]) == 0) {
            return 1; // Valid unit code found
        }
    }
    return 0; // Invalid unit code
}

// Function to check if the grade is valid
int is_valid_grade(const char *input) {
    for (int i = 0; i < valid_grades_count; i++) {
        if (strcmp(input, valid_grades[i]) == 0) {
            return 1; // Valid grade found
        }
    }
    return 0; // Invalid grade
}
// Function to remove newline character if it's present
void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';  // Replace newline with null terminator
}

// Function to input student scores
void inputStudentScores(StudentScores *scores) {
    for (int i = 0; i < MAX_GRADES; i++) {
        int valid_input = 0;

        // Loop to get a valid unit code and its corresponding grade
        while (!valid_input) {
            // Ask for unit code
            printf("Enter unit code (choose from the following):\n");
            for (int j = 0; j < valid_unit_codes_count; j++) {
                printf("%s\n", valid_unit_codes[j]);
            }
            printf("Unit code %d: ", i + 1);
            fgets(scores->unit_grades[i].unit_code, sizeof(scores->unit_grades[i].unit_code), stdin);
            remove_newline(scores->unit_grades[i].unit_code);  // Strip newline from the input

            // Validate the unit code
            if (is_valid_unit_code(scores->unit_grades[i].unit_code)) {
                // Ask for the grade after a valid unit code is entered
                int grade_valid = 0;
                while (!grade_valid) {
                    printf("Enter grade for %s (A, B, C, D, E, F): ", scores->unit_grades[i].unit_code);
                    fgets(scores->unit_grades[i].grade, sizeof(scores->unit_grades[i].grade), stdin);
                    remove_newline(scores->unit_grades[i].grade);  // Strip newline from the input

                    // Validate the grade
                    if (is_valid_grade(scores->unit_grades[i].grade)) {
                        grade_valid = 1;  // Valid grade entered
                    } else {
                        printf("Invalid grade. Please enter a valid grade (A, B, C, D, E, F).\n");
                    }
                }
                valid_input = 1;  // Move to the next unit if valid unit and grade are entered
            } else {
                printf("Invalid unit code. Please try again.\n");
            }
        }
    }
}