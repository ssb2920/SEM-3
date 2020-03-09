#include<stdio.h>
#include<stdlib.h>
#define m 50
struct stack
{	int top;
	int a[m];
};
void initstack(struct stack *p)
{	p->top=-1;
}
void push(struct stack*p,int x)
{	if(p->top== m)
		printf("Overflow\n");
	else
		p->a[++p->top]=x;
}
int pop(struct stack *p)
{	if(p->top==-1)
	{	printf("Underflow\n");
		return -1;
	}
	else
		return p->a[p->top--];
}
void display(struct stack *p)
{	int i;
	if(p->top==-1)
		printf("Stack Empty\n");
	else
	{	for(i=p->top;i>=0;i--)
		{	printf("%d\t",p->a[i]);
		}
	printf("\n");
	}
}
int peek(struct stack *p)
{	if(p->top==-1)
	{	printf("Underflow\n");
		return -1;
	}
	else
		return p->a[p->top];
}
void delete(struct stack *p)
{	int num,i,j;
	printf("Enter value to be deleted\n");
	scanf("%d",&num);
	for(i=p->top;i>=0;i--)
	{	if(p->a[i]==num)
			break;
	}
	printf("Index is %d\n",i);
	for(j=i;j<p->top;j++)
	{	p->a[j]=p->a[j+1];
	}
	p->top--;
}
void main()
{	struct stack s;
	initstack(&s);
	int ch,x;
	do
	{	printf("Enter\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Delete element\n6.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{	case 1: printf("Enter element to be pushed\n");
					scanf("%d",&x);
					push(&s,x);
					break;
			case 2: printf("The popped out element is %d\n",pop(&s));
					break;
			case 3: display(&s);
					break;
			case 4: printf("The element at stack top is %d\n",peek(&s));
					break;
			case 5: printf("Stack before deleting is \n");
					display(&s);
					delete(&s);
					printf("Stack after deleting is \n");
					display(&s);
					break;
			case 6:	exit(1);
					break;
			default:printf("Wrong Choice\n");
					break;
		}
	}while(1);
}					