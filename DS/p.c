#include<stdio.h>
#include<string.h>

#define MAX 50
#include<conio.h>

int main()
{
    char exp[MAX];
    int i,count1=0,count2=0;
    printf("enter an expression");
    gets(exp);
    for(i=0;i<=strlen(exp);i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            count1++;
        if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
			count2++;
	}
    if(count1==count2)
        printf("\n valid expression");
    else
        printf("\ninvalid expression");
}