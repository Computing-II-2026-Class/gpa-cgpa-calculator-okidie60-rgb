/*
Name: OKIDI EMMANUEL OPIRO
Registration Number: 25/U/BIE/01413/PE
*/

#include <stdio.h>
int getGradePoint(int score){
    if (score >= 80) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else return 0;
}

char getGrade(int score){
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

int main(void) {
    /* Declare variables here */
    const char *sem1_codes[] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"
    };
    const char *sem1_names[] = {  //
        "Fundamentals of Engineering Mathematics",
        "Biochemistry and Medical Physics",
        "Electrical Engineering Science",
        "Mechanics I",
        "Computing I",
        "Mechanical Drawing",
        "Engineering Profession",
        "Functional Anatomy and Physiology I"
    };
    int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};

    const char *sem2_codes[] = {
        "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };
    const char *sem2_names[] = {
        "Further Engineering Mathematics",
        "Computing II",
        "Mechatronics Drawing",
        "Fluid Mechanics",
        "Thermodynamics",
        "Workshop Practice",
        "Functional Anatomy and Physiology II",
        "Electronics I"
    };
    int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};

    int sem1_scores[8], sem2_scores[8];
    int i;

    /* Read 16 scores */
    printf("=== Enter Semester I Scores ===\n");
    for (i = 0; i < 8; i++) {
        printf("Enter score for %s (%s): ", sem1_codes[i], sem1_names[i]);
        scanf("%d", &sem1_scores[i]);
    }

    printf("\n=== Enter Semester two Scores ===\n");
    for (i = 0; i < 8; i++) {
        printf("Enter score for %s (%s): ", sem2_codes[i], sem2_names[i]);
        scanf("%d", &sem2_scores[i]);
    }

    /* Validate input */
    for (i = 0; i < 8; i++) {
        if (sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }
    
    for (i = 0; i < 8; i++) {
        if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }

    /* Determine grades and grade points */

    /* Compute Semester I GPA */
    int sem1_total_credits = 0, sem1_weighted_sum = 0;
    int sem1_gp[8], sem1_weighted[8];
    char sem1_grade[8];

    for (i = 0; i < 8; i++) {
        sem1_gp[i]       = getGradePoint(sem1_scores[i]);
        sem1_grade[i]    = getGrade(sem1_scores[i]);
        sem1_weighted[i] = sem1_gp[i] * sem1_credits[i];
        sem1_total_credits += sem1_credits[i];
        sem1_weighted_sum  += sem1_weighted[i];
    }

    /* Compute Semester II GPA */
    int sem2_total_credits = 0, sem2_weighted_sum = 0;
    int sem2_gp[8], sem2_weighted[8];
    char sem2_grade[8];

    for (i = 0; i < 8; i++) {
        sem2_gp[i]       = getGradePoint(sem2_scores[i]);
        sem2_grade[i]    = getGrade(sem2_scores[i]);
        sem2_weighted[i] = sem2_gp[i] * sem2_credits[i];
        sem2_total_credits += sem2_credits[i];
        sem2_weighted_sum  += sem2_weighted[i];
    }

    /* Compute CGPA */
    int total_credits = sem1_total_credits + sem2_total_credits;
    int total_weighted = sem1_weighted_sum + sem2_weighted_sum;
    double cgpa = (double)total_weighted / total_credits;

    double sem1_gpa = (double)sem1_weighted_sum / sem1_total_credits;
    double sem2_gpa = (double)sem2_weighted_sum / sem2_total_credits;  

    /* Determine classification */
    const char *classification;
    if (cgpa >= 4.40)
        classification = "First Class";
    else if (cgpa >= 3.60)
        classification = "Second Class Upper";
    else if (cgpa >= 2.80)
        classification = "Second Class Lower";
    else if (cgpa >= 2.00)
        classification = "Pass";
    else
        classification = "Fail";

    /* Display full academic report */
    printf("\n");
    printf("**************************************************************\n");
    printf("           KYAMBOGO UNIVERSITY ACADEMIC REPORT             \n");
    printf("                    YEAR ONE - TEMB                       \n");
    printf("**************************************************************\n");

    printf("\n--- SEMESTER I ---\n");
    printf("%-12s %-42s %5s %6s %3s %8s %10s\n",
           "Code", "Course Name", "Score", "Grade", "GP", "Credits", "Weighted");
    printf("........................................................................................\n");
    for (i = 0; i < 8; i++) {
        printf("%-12s %-42s %5d %6c %3d %8d %10d\n",
               sem1_codes[i], sem1_names[i],
               sem1_scores[i], sem1_grade[i],
               sem1_gp[i], sem1_credits[i], sem1_weighted[i]);
    }
    printf("....................................................................................\n");
    printf("Total Credit Units: %d    Weighted Sum: %d\n", sem1_total_credits, sem1_weighted_sum);

    printf("\n--- SEMESTER II ---\n");
    printf("%-12s %-42s %5s %6s %3s %8s %10s\n",
           "Code", "Course Name", "Score", "Grade", "GP", "Credits", "Weighted");
    printf(".....................................................................................\n");
    for (i = 0; i < 8; i++) {
        printf("%-12s %-42s %5d %6c %3d %8d %10d\n",
               sem2_codes[i], sem2_names[i],
               sem2_scores[i], sem2_grade[i],
               sem2_gp[i], sem2_credits[i], sem2_weighted[i]);
    }
    printf("...............................................................................\n");
    printf("Total Credit Units: %d    Weighted Sum: %d\n", sem2_total_credits, sem2_weighted_sum);

    printf("\n..............................................................................\n"); 
    printf("Semester I GPA: %.2f\n", sem1_gpa);
    printf("Semester II GPA: %.2f\n", sem2_gpa);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
    printf(".......................................................................\n");

    return 0;
}
