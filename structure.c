#include<stdio.h>
struct student
 {
     char name[20];
     int id;
     float cgpa;
 };
 int main()
 {
     struct student s;
     printf("Enter your name:\n ");
     scanf("%s",& s.name);
     printf("Enter your id:\n ");
     scanf("%d",& s.id);
     printf("Enter your CGPA:\n ");
     scanf("%f",& s.cgpa);
     printf("Name: %s ; ID:%d ; CGPA:%f ;", s.name,s.id,s.cgpa);
     return 0;
 }


