#include <stdio.h>
#include<stdlib.h>
void main()
{	char i;
	bargain:
	printf("Dorammamu I've come to bargain\n");
	printf("Enter 1 to bargain\n");
	scanf("%c",&i);
	if (i!='1')
		goto bargain;
	
	
}