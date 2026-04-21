//Name: OKIDI EMMANUEL OPIRO
//Registration Number: 25/U/BIE/01413/PE 
#include <stdio.h>
int main() {
    float scores[16];
    int credits_sem1[8] = {4, 3, 3, 3, 3, 3, 2, 3};
    int credits_sem2[8] = {4, 3, 3, 3, 3, 3, 3, 3};

    char *course_codes_sem1[8] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
        "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"
    };
    char *course_codes_sem2[8] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };
    //READ 16 SCORES
    for(int i = 0; i < 16; i++) {
        if(scanf("%f", &scores[i]) !=1) {
            printf("Invalid score entered\n");
            return 0;
        }
        if(scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        } 
    }
    //Arrays for grades and grade points
    char grades[16][2];
    int grade_points[16];
    for(int i = 0; i < 16; i++) {
        float score = scores[i];
        if(score >= 80) {
            grades[i][0] = 'A'; grades[i][1] = '\0';
            grade_points[i] = 5;
        } else if(score >= 70) {
            grades[i][0] = 'B'; grades[i][1] = '\0';
            grade_points[i] = 4;
        } else if(score >= 60) {
            grades[i][0] = 'C'; grades[i][1] = '\0';
            grade_points[i] = 3;
        } else if(score >= 50) {
            grades[i][0] = 'D'; grades[i][1] = '\0';
            grade_points[i] = 2;
        } else {
            grades[i][0] = 'F'; grades[i][1] = '\0';
            grade_points[i] = 0;
        }
    }
    //Calculate Semester I GPA
    float total_weighted_sem1 = 0.0;
    int total_credits_sem1 = 0;
    for(int i = 0; i < 8; i++) {
        total_weighted_sem1 += grade_points[i] * credits_sem1[i];
        total_credits_sem1 += credits_sem1[i];
    }
    float gpa_sem1 = total_weighted_sem1 / total_credits_sem1;

    ///Calculate Semester II GPA
    float total_weighted_sem2 = 0.0;
    int total_credits_sem2 = 0;
    for(int i = 0; i < 8; i++) {
        total_weighted_sem2 += grade_points[8 + i] * credits_sem2[i];
        total_credits_sem2 += credits_sem2[i];
    }
    float gpa_sem2 = total_weighted_sem2 / total_credits_sem2;

    //Calculate CGPA (Year One)
    float cgpa =(total_weighted_sem1 + total_weighted_sem2) / (total_credits_sem1 + total_credits_sem2);

    //Determine Classification
    char classification[25];
    if(cgpa >= 4.40) {
        sprintf(classification, "First Class");
    } else if(cgpa >= 3.60) {
        sprintf(classification, "Second Class Upper");
    } else if(cgpa >= 2.80) {
        sprintf(classification, "Second Class Lower");
    } else if(cgpa >= 2.00) {
        sprintf(classification, "Pass");
    } else {
        sprintf(classification, "Fail");
    }

    //Display Full Academic Report
    //Semester I
    printf("Year One, Semester I\n");
    printf("---------------------------------------\n");
    for(int i = 0; i < 8; i++) {
        float weighted = grade_points[i] * credits_sem1[i];
        printf("%s\t%.0f\t%s\t%d\t%d\t%.2f\n", 
        course_codes_sem1[i], scores[i], grades[i], grade_points[i],
        credits_sem1[i], weighted);
    }
    printf("Semester I GPA: %.2f\n\n", gpa_sem1);

    //Semester II
    printf("Year One, Semester II\n");
    printf("-------------------------------------------\n");
    for(int i= 0; i < 8; i++) {
        float weighted = grade_points[8 + i] * credits_sem2[i];
        printf("%s\t%.0f\t%s\t%d\t%d\t%.2f\n",
            course_codes_sem2[i], scores[8 + i], grades[8 + i], grade_points[8 + i],
        credits_sem2[i], weighted);
    }
    printf("Semester II GPA: %.2f\n\n", gpa_sem2);

    //summary
    printf("Overall Year One CGPA: %.2f\n\n", cgpa);
    printf("Final Academic Classification: %s\n\n", classification);

    //Required Exact Summary output
    printf("Semester I GPA: %.2f\n", gpa_sem1);
    printf("Semester II GPA: %.2f\n", gpa_sem2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);

    return 0;
}