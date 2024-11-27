#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students
{
    char name[20];
    int id;
    float cgpa;
};

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);


    struct students *student = (struct students *)malloc(n * sizeof(struct students));
    if (student == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }


    for (int i = 0; i < n; i++)
    {
        printf("\nEnter information for student %d:\n", i + 1);

        printf("Name: ");
         scanf(" %[^\n]", student[i].name);

        printf("ID: ");
        scanf("%d", &student[i].id);

        printf("CGPA: ");
        scanf("%f", &student[i].cgpa);
    }


    float max_cgpa = student[0].cgpa;
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (student[i].cgpa > max_cgpa)
        {
            max_cgpa = student[i].cgpa;
            maxIndex = i;
        }
    }


    printf("\nThe student with the highest CGPA is: %s\n", student[maxIndex].name);


    free(student);

    return 0;
}
