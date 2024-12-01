#include <stdio.h>
float course_grade(float marks);
float semester_gpa();
float yearly_cgpa(int num_semesters);
float overall_cgpa(int num_years);
int main()
{
    int num_years;
    printf("Enter the number of years you studied: ");
    scanf("%d", &num_years);
    float total_cgpa = overall_cgpa(num_years);
    printf("\nYour Overall CGPA: %.2f\n",total_cgpa);
    return 0;
}
float course_grade(float marks)
{
    if(marks<40)
        return 0.00;
    else if(marks <= 40)
        return 2.00;
    else if(marks <= 45)
        return 2.25;
    else if(marks <= 50)
        return 2.50;
    else if(marks <= 55)
        return 2.75;
    else if(marks <= 60)
        return 3.00;
    else if(marks <= 65)
        return 3.25;
    else if(marks <= 70)
        return 3.50;
    else if(marks <= 75)
        return 3.75;
    else
        return 4.00;
}
float semester_gpa()
{
    int num_courses;
    printf("Enter the number of courses in this semester: ");
    scanf("%d", &num_courses);
    float marks[num_courses], credit[num_courses], total_points = 0, total_credit = 0;
    for (int i=1; i<= num_courses; i++)
    {
        printf("Course %d Marks: ",i);
        scanf("%f", &marks[i]);
        printf("Course %d Credit Hours: ",i);
        scanf("%f",&credit[i]);
        float grade =course_grade(marks[i]);
        total_points+=grade * credit[i];
        total_credit+=credit[i];
    }

    float semester_gpa=total_points/total_credit;
    printf("Semester GPA: %.2f\n", semester_gpa);
    return semester_gpa;
}
float yearly_cgpa(int num_semesters)
{
    float total_points =0,total_credit = 0;

    for (int i=1; i<=num_semesters; i++)
    {
        printf("\nSemester %d:\n",i);
        float semester_points=semester_gpa();
        float semester_credit;
        printf("Enter total credit hours for Semester %d: ",i);
        scanf("%f",&semester_credit);
        total_points +=semester_points*semester_credit;
        total_credit+=semester_credit;
    }
    float yearly_gpa = total_points/total_credit;
    printf("\nYearly CGPA: %.2f\n", yearly_gpa);
    return yearly_gpa;
}
float overall_cgpa(int num_years)
{
    float total_points = 0, total_credit = 0;
    for (int i=1; i <=num_years; i++)
    {
        int num_semesters;
        printf("\nYear %d:\n", i);
        printf("Enter the number of semesters in Year %d: ",i);
        scanf("%d", &num_semesters);
        float year_points = yearly_cgpa(num_semesters);
        float year_credit;
        printf("Enter total credit hours for Year %d: ",i);
        scanf("%f",&year_credit);
        total_points+=year_points*year_credit;
        total_credit+=year_credit;
    }
    return total_points/total_credit;
}
