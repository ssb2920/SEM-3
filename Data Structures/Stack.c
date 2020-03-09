#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{	int top;
	int a[20];
}stack;

void initstack(stack *p)
{	p->top=-1;
}
void push(stack *p)
{	int x;
	printf("Enter element to be pushed\n");
	scanf("%d",&x);
	if(p->top==19)
	{	printf("Overflow\n");
		return;
	}
	else
	{	p->a[++p->top]=x;
	}
}
int pop(stack *p)
{	int x;
	if(p->top==-1)
	{	printf ("Underflow\n");
		return -1;
	}
	else
	{	x=p->a[p->top--];
		return x;
	}
}
void display(stack *p)
{	int i;
	for(i=p->top;i>=0;i--)
	{	printf("%d\t",p->a[i]);
	}
	printf("\n");
}
void main()
{	stack s;
	int ch,e;
	initstack(&s);
	do{	printf("\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{	case 1: push(&s);
				break;
			case 2: e=pop(&s);
				if(e!=-1)
				printf("Popped element is %d\n",e);
				break;
			case 3:	display(&s);
				break;
			case 4: exit(1);
				break;
			default:printf("Wrong Choice\n");
				break;
		}
	}while(1);
}











