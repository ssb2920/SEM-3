#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct queue
{	int a[10];
	int front;
	int rear;
}*p;

void init_queue(struct queue *p)
{
	p->rear=-1;
	p->front=-1;
}

void enque(struct queue *p,int x)
{	if(p->rear==9)
	{	printf("Overflow\n");
	}
	else if(p->front==-1&&p->rear==-1)
	{	p->front++;
		p->a[++(p->rear)]=x;
	}
	else
	{	p->a[++(p->rear)]=x;
	}
}

int deque(struct queue *p)
{	if(p->front==-1||p->front>p->rear)
	{	printf("Underflow\n");
		return -1;
	}
	else if(p->rear==p->front)
	{	int x=p->a[p->front];
		p->rear=p->front=-1;
		return x;
	}
	else
	return p->a[p->front++];
}	

void display(struct queue *p)
{	int b;
	if(p->front==-1&&p->rear==-1)
	{	printf("Queue is Empty\n");
	}
	for(b=p->front;b<=p->rear;b++)
	printf("%d\t",p->a[b]);
	printf("\n");
}

void isFull(struct queue *p)
{	if(p->rear==9)
	printf("Queue is Full\n");
	else
	printf("Not full\n");
}

void isEmpty(struct queue *p)
{	if((p->front==-1) && (p->rear==-1))
	printf("Queue is empty\n");
	else
	printf("Not empty\n");
}

void main()
{	struct queue p;
	init_queue(&p);
	int a,x;
	do
	{
		printf("Enter 1:Insert element 2:Delete element 3:Display elements 4:Check if full 5:check if empty 6:EXIT\n");
		scanf("%d", &a);
		switch(a)
		{
			case 1: printf("Enter element to be inserted\n");
				scanf("%d", &x);
				enque(&p,x);
				break;
			case 2: deque(&p);
				break;
			case 3: display(&p);
				break;
			case 4: isFull(&p);
				break;
			case 5: isEmpty(&p);
				break;
			case 6: exit(1);
				break;
			default:printf("WRONG CHOICE");
				break;		
		}	
	}
	while(1);
}