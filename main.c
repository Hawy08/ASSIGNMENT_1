#include <stdio.h>
#include "studentdata.h"

int main(){
    StudentData student;
    StudentScores scores;
    inputStudentData(&student);
    printStudentData(&student);
    inputStudentScores(&scores);
    printStudentScores(&scores);
    

    printf("Hello, world!\n");

    return 0;

}