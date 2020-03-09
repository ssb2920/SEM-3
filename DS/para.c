#include<stdio.h>
#define MAX 10
#include<conio.h>
#include<string.h>
void push(char st[],char val,int *top)
{
	if(*top==MAX-1)
	printf("STACK OVERFLOW");

	else
	{*top=*top+1;
	st[*top]=val;
	}

}
char pop(char st[], int *top)
{   int val;
       	val=st[*top];
		*top=*top-1;
        return val;

}
int main()
{
    char exp[MAX],temp,st[MAX];
    int i,flag=1,top=-1;
    printf("enter an expression");
    gets(exp);
    for(i=0;i<=strlen(exp);i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            push(st,exp[i],&top);
        if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
            if(top==-1)
            flag=0;
        else
        {
            temp=pop(st,&top);
            if(exp[i]==')'&&(temp=='{'||temp=='['))
                flag=0;
            if(exp[i]=='}'&&(temp=='('||temp=='['))
                flag=0;
            if(exp[i]==']'&&(temp=='('||temp=='{'))
                flag=0;
        }
        }
if(top>=0)
    flag=0;
    if(flag==1)
        printf("\n valid expression");
    else
        printf("\ninvalid expression");
}