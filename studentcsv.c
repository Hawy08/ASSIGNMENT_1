#include "studentdata.h"
#include <stdio.h>
#include <string.h>

// Mapping from Unit Code to Unit Name
const char* getUnitName(const char* unit_code) {
    if (strcmp(unit_code, "EEE 2301") == 0) return "Analogue Electronics";
    if (strcmp(unit_code, "EEE 2302") == 0) return "Digital Electronics";
    if (strcmp(unit_code, "EEE 2303") == 0) return "Power Electronics";
    if (strcmp(unit_code, "EEE 2304") == 0) return "Electrical Machines";
    if (strcmp(unit_code, "EEE 2305") == 0) return "Control Engineering";
    if (strcmp(unit_code, "EEE 2306") == 0) return "Physical Electronics";
    if (strcmp(unit_code, "SMA 2307") == 0) return "Partial Differential Equations";
    if (strcmp(unit_code, "ICS 2308") == 0) return "Computer Programming";
    return "Unknown Unit"; // Return this if the unit code doesn't match any known unit
}

// Function to output student data to the CSV
void outputStudentData(StudentData *student, FILE *file) {
    printf("HELLO IS THIS FILE BEING ACCESSED DURING EXECUTION?\n");
    fprintf(file, "Registration,%s\n", student->student_reg);
    fprintf(file, "Name,%s\n", student->student_name);
    fprintf(file, "School,%s\n", student->student_school);
    fprintf(file, "Department,%s\n", student->student_department);
    fprintf(file, "Course Code,%s\n", student->course_code);
    fprintf(file, "Course Name,%s\n", student->course_name);
    fprintf(file, "\n"); // Add a newline for separation between data and scores
}

// Function to output student scores to the CSV, including unit names
void outputStudentScores(StudentScores *scores, int numScores, FILE *file) {
    fprintf(file, "Unit Code,Unit Name,Grade\n");
    for (int i = 0; i < numScores && i < MAX_GRADES; i++) {
        const char* unit_name = getUnitName(scores->unit_grades[i].unit_code);  // Get the unit name
        fprintf(file, "%s,%s,%s\n", scores->unit_grades[i].unit_code, unit_name, scores->unit_grades[i].grade);
    }
}

// Function to generate the CSV file with student data, scores, GPA, and average grade
void generateStudentCsv(StudentData *student, StudentScores *scores, int numScores, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open file for writing.\n");
        return;
    }

    // Output the student data
    outputStudentData(student, file);

    // Output the student scores (with unit names)
    outputStudentScores(scores, numScores, file);

    // Calculate GPA and Average Grade
    float gpa = calculateAverage(scores);
    printf("Calculated GPA TO CONFIRM !!!: %.2f\n", gpa);  // Debugging: Print GPA
    // GPA is a floating point value, so print it with 2 decimal places
    fprintf(file, "Calculated GPA,%.2f\n", gpa);

    // Calculate the Average Grade (based on the GPA scale)
    // Optionally, you can print this value as a letter grade if needed (example below).
    char averageGrade = 'F'; // Default to 'F' if GPA is 0.0
    if (gpa >= 4.0) averageGrade = 'A';
    else if (gpa >= 3.0) averageGrade = 'B';
    else if (gpa >= 2.0) averageGrade = 'C';
    else if (gpa >= 1.0) averageGrade = 'D';
    else if (gpa >= 0.5) averageGrade = 'E';

    // Print the Average Grade
    fprintf(file, "Average Grade,%c\n", averageGrade);

    fclose(file);
    printf("CSV generated successfully!\n");
}
