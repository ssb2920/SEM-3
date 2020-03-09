#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int stack[20];
int top=-1;
void push(int x)
{	stack[++top]=x;
}
int pop()
{	return stack[top--];
}
void main()
{	char exp[20],*e;
	int n1,n2,n3,num;
	printf("Enter postfix expression\n");
	scanf("%s",&exp);
	e=exp;
	while(*e!='\0')
	{	if(isdigit(*e))
		{	num=*e-'0';
			push(num);
		}
		else
		{	n1=pop();
			n2=pop();
			switch(*e)
			{	case '+':n3=n2+n1;
						break;
				case '-':n3=n2-n1;
						break;
				case '*':n3=n2*n1;
						break;
				case '/':n3=n2/n1;
						break;
				case '%':n3=n2%n1;
						break;
				default:printf("Invalid operator\n");
						break;
			}push(n3);
		}
		e++;
	}
	printf("The answer of postfix expn %s =%d",exp,pop());
}
