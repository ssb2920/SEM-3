#include<stdio.h>
#include<stdlib.h>
#define m 10
struct stack
{	int top1;
	int top2;
	int a[m];
};
void initstack1(struct stack *p)
{	p->top1=-1;
}
void initstack2(struct stack *p)
{	p->top2=m;
}
void push1(struct stack*p,int x)
{	if(p->top1+1==p->top2)
		printf("Overflow\n");
	else
		p->a[++p->top1]=x;
}
void push2(struct stack*p,int x)
{	if(p->top2-1==p->top1)
		printf("Overflow\n");
	else
		p->a[--p->top2]=x;
}
int pop1(struct stack *p)
{	if(p->top1==-1)
	{	printf("Underflow\n");
		return -1;
	}
	else
		return p->a[p->top1--];
}
int pop2(struct stack *p)
{	if(p->top2==m)
	{	printf("Underflow\n");
		return -1;
	}
	else
		return p->a[p->top2++];
}
void display1(struct stack *p)
{	int i;
	if(p->top1==-1)
		printf("Stack Empty\n");
	else
	{	for(i=p->top1;i>=0;i--)
		{	printf("%d\t",p->a[i]);}
	printf("\n");
	}
}
void display2(struct stack *p)
{	int i;
	if(p->top2==m)
		printf("Stack Empty\n");
	else
	{	for(i=p->top2;i<m;i++)
		{	printf("%d\t",p->a[i]);}
	printf("\n");
	}
}
int peek1(struct stack *p)
{	if(p->top1==-1)
	{	printf("Underflow\n");
		return -1;
	}
	else
		return p->a[p->top1];
}
int peek2(struct stack *p)
{	if(p->top2==m)
	{	printf("Underflow\n");
		return -1;
	}
	else
		return p->a[p->top2];
}
void main()
{	struct stack s;
	initstack1(&s);
	initstack2(&s);
	int ch,x;
	do
	{	printf("Enter\n1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Display1\n6.Display2\n7.Peek1\n8.Peek2\n9.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{	case 1: printf("Enter element\n");
					scanf("%d",&x);
					push1(&s,x);
					break;
			case 2: printf("Enter element\n");
					scanf("%d",&x);
					push2(&s,x);
					break;
			case 3: printf("The popped out element is %d\n",pop1(&s));
					break;
			case 4: printf("The popped out element is %d\n",pop2(&s));
					break;
			case 5: display1(&s);
					break;
			case 6: display2(&s);
					break;
			case 7: printf("The element at stack top is %d\n",peek1(&s));
					break;
			case 8: printf("The element at stack top is %d\n",peek2(&s));
					break;
			case 9: exit(1);
					break;
			default:printf("WRONG CHOICE\n");
					break;
		}
	}while(1);
}