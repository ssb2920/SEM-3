#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct stack
{	int top;
	char a[20];
};
void push(struct stack *p,int x)
{	p->a[++p->top]=x;
}
int pop(struct stack *p)
{	return p->a[p->top--];
}
int isEmpty(struct stack *p)
{	if(p->top==-1)
		return 1;
	else
		return 0;
}
int precedence(char c)
{	if(c=='(')
		return 0;
	else if(c=='+'||c=='-')
		return 1;
	else if(c=='*'||c=='/'||c=='%')
		return 2;
	else 
		return 3;
}
void main()
{	struct stack s;
	s.top=-1;
	char infix[20],postfix[20],x;
	int i,j=0;
	printf("Enter infix expn\n");
	gets(infix);
	for(i=0;i<strlen(infix);i++)
	{	if(isalnum(infix[i]))
		{	postfix[j]=infix[i];
			j++;
		}
		else
		{	if(infix[i]==')')
			{	x=pop(&s);
				while(x!='(')
				{	postfix[j]=x;
					j++;
					x=pop(&s);
				}
			}
			else if(infix[i]=='('||isEmpty(&s)==1||precedence(infix[i])>precedence(s.a[s.top]))
			{	push(&s,infix[i]);
			}
			else
			{	while(isEmpty(&s)!=1&&precedence(infix[i])>=precedence(s.a[s.top]))
				{	postfix[j]=pop(&s);
					j++;
				}
				push(&s,infix[i]);
			}
		}
	}
	while(isEmpty(&s)!=1)
	{	postfix[j]=pop(&s);
		j++;
	}
	postfix[j]='\0';
	printf("Postfix is\n");
	puts(postfix);
}