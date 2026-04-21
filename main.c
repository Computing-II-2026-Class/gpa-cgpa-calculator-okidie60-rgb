/*
Name: OKIDI EMMANUEL OPIRO
Registration Number: 25/U/BIE/01413/PE
*/

#include<stdio.h>
#include<string.h>

#define SEM1_COURSES 8
#define SEM2_COURSES 8

//Grading Scale
double getGradepoint(int score){
   if(score>=80) return 5.0;
   else if(score>=70) return 4.0;
   else if(score>=60) return 3.0;
   else if(score>=50) return 2.0;
   else return 0.0;
}

char*getGradeLetter(int score) {
   if(score>=80) return "A";
   else if(score>=70) return "B";
   else if(score>=60) return "C";
   else if(score>=50) return "D";
   else return "F";
}

//SEMESTER 1 COURSE DATA
const char*sem1_codes[SEM1_COURSES]={
"TEMB 1101","TEMB 1102","TEMB 1103","TEMB 1104","TEMB 1105","TEMB 1106","TEMB 1107","TEMB 1108"
};
const char*sem1_names[SEM1_COURSES]={
"Fundamentals of Engineering Mathematics",
"Biochemistry and Medical Physics",
"Electrical Engineering Science",
"Mechanics 1",
"Computing 1",
"Mechanical Drawing",
"Engineering Profession",
"Functional Anatomy and Physiology 1"
};
const double sem1_credits[SEM1_COURSES]={4,3,3,3,3,3,2,3};

//SEMESTER 2 COURSE DATA
const char*sem2_codes[SEM2_COURSES]={
"TEMB 1201","TEMB 1202","TEMB 1203","TEMB 1204","TEMB 1205","TEMB 1206","TEMB 1207","TEMB 1208"
};
const char*sem2_names[SEM2_COURSES]={
"Further Engineering Mathematics",
"Computing 2",
"Mechatronics Drawing",
"Fluid Mechanics",
"Thermodynamics",
"Workshop Practice",
"Functional Anatomy and Physiology",
"Electronics"
};
const double sem2_credits[SEM2_COURSES]={4,3,3,3,3,3,3,3};

int main(){
   int sem1_scores[SEM1_COURSES];
   int sem2_scores[SEM2_COURSES];
   double sem1_gp[SEM1_COURSES];
   double sem2_gp[SEM2_COURSES];
   double sem1_weighted_sum=0.0, sem2_weighted_sum=0.0;
   double sem1_total_credits=0.0, sem2_total_credits=0.0;
   int i;

   printf("==============================================================================================\n");
   printf("                         YEAR ONE ACADEMIC GPA/CGPA CALCULATOR\n");
   printf("==============================================================================================\n\n");

   //----------------SEMESTER 1 INPUT-----------------------
   printf("-----------------------------SEMESTER 1--------------------------------------------------------\n");
   for(i=0; i<SEM1_COURSES; i++){
    int score;
    do{
        printf("Enter score for %s - %s (0-100): ",sem1_codes[i],sem1_names[i]);
        scanf("%d", &score);
        if(score<0 || score>100)
            printf("Invalid score entered\n");
    }while (score<0 || score>100);
    sem1_scores[i] = score;
    sem1_gp[i]=getGradepoint(score);
    sem1_weighted_sum += sem1_gp[i]*sem1_credits[i];
    sem1_total_credits += sem1_credits[i];
   }

   //---------SEMESTER 2 INPUT--------------------
   printf("\n----------------------SEMESTER 2-------------------\n");
   for(i=0; i<SEM1_COURSES; i++){
    int score;
    do{
        printf("Enter score for %s - %s (0-100): ",sem2_codes[i],sem2_names[i]);
        scanf("%d", &score);
        if(score<0 || score>100)
            printf("Invalid score entered\n");
    }while (score<0 || score>100);
    sem2_scores[i]=score;
    sem2_gp[i]=getGradepoint(score);
    sem2_weighted_sum += sem2_gp[i]*sem2_credits[i];
    sem2_total_credits += sem2_credits[i];
   }

   //FULL ACADEMIC REPORT
   printf("\n\n");
   printf("================================================================================================\n");
   printf("                             FULL ACADEMIC REPORT - YEAR ONE\n");
   printf("=================================================================================================\n");

   //Semester 1 report
   printf("\nSEMESTER 1\n");
   printf("-------------------------------------------------------------------------------------------------\n");
   printf("%-12s %-40s %5s %8s %12s %8s\n","Course Code","Course Name","Credit Units","Score","Grade Pt","Grade");
   printf("---------------------------------------------------------------------------------------------------\n");
   for(i=0; i<SEM1_COURSES; i++){
    printf("%-12s %-40s %5.0f %8d %12.2f %8s\n",sem1_codes[i],sem1_names[i],sem1_credits[i],sem1_scores[i],sem1_gp[i],getGradeLetter(sem1_scores[i]));
   }
   double sem1_gpa=sem1_weighted_sum/sem1_total_credits;
   printf("---------------------------------------------------------------------------------------------------\n");
   printf("Total Credits: %.1f | Weighted Grade Points: %.2f\n",sem1_total_credits,sem1_weighted_sum);
   printf("Semester 1 GPA: %.2f\n",sem1_gpa);

   //Semester 2 Report
   printf("\nSEMESTER 2\n");
   printf("-----------------------------------------------------------------------------------------\n");
   printf("%-12s %-40s %5s %8s %12s %8s\n","Course Code","Course Name","Credit Units","Score","Grade Pt","Grade");
   printf("------------------------------------------------------------------------------------------\n");
   for(i=0; i<SEM2_COURSES; i++){
    printf("%-12s %-40s %5.0f %8d %12.2f %8s\n",sem2_codes[i],sem2_names[i],sem2_credits[i],sem2_scores[i],sem2_gp[i],getGradeLetter(sem2_scores[i]));
   }
   double sem2_gpa=sem2_weighted_sum/sem2_total_credits;
   printf("------------------------------------------------------------------------------------------\n");
   printf("Total Credits: %.1f | Weighted Grade Points: %.2f\n",sem2_total_credits,sem2_weighted_sum);
   printf("Semester 2 GPA: %.2f\n", sem2_gpa);

   //Overall CGPA
   double total_weighted = sem1_weighted_sum+sem2_weighted_sum;
   double total_credits = sem1_total_credits+sem2_total_credits;
   double cgpa = total_weighted/total_credits;

   printf("\n======================================================================================\n");
   printf("Semester 1 GPA: %.2f\n",sem1_gpa);
   printf("Semester 2 GPA: %.2f\n",sem2_gpa);
   printf("CGPA: %.2f\n",cgpa);

   //Final Academic Classification
   printf("Classification: ");
   if(cgpa>=4.40 &&cgpa<=5.00)
    printf("First Class\n");
   else if(cgpa>=3.60)
    printf("Second Class Upper\n");
   else if(cgpa>=2.80)
    printf("Second Class Lower\n");
   else if(cgpa>=2.00)
    printf("Pass\n");
   else
    printf("Fail\n");

   return 0;
}
