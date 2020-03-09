#include<stdio.h>
void main()
{	int a,*p;
	printf("enter value\n");
	scanf("%d",&a);
	p=&a;
	printf("%u",p);
}