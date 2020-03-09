#include <stdio.h>
#include <conio.h>

struct Teacher
{
 char Name[30];
 char Qualifications[20];
 int experience_year;
}th[10];

void teacher()
{    
 int t,i;
 printf("Enter how many teachers are in department\n");
 scanf("%d",&t);
 for(i=1;i<=t;i++)
 {       
   printf("Enter name of teacher : ");
   gets(th[i].Name);
   printf("Enter qualification of teacher : ");
   gets(th[i].Qualifications);
   printf("Enter experience_year of teacher : ");
   scanf("%d",&th[i].experience_year);
   getchar();
 }
 for(i=1;i<=t;i++)
 {
   printf("Details of %d teacher\n",i);
   printf(th[i].Name);
   printf(" ");
   printf(th[i].Qualifications);
   printf(" ");
   printf("%d",th[i].experience_year);
   printf("\n");
 }
}   
int main()
 {
   teacher();
   getchar();
   return 0;
 }