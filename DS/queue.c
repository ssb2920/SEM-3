#include<stdio.h>
#include<stdlib.h>
#define m 5
struct queue
{	int a[m];
	int front,rear;
};
void initqueue(struct queue *p)
{	p->front=p->rear=-1;
}
void enqueue(struct queue *p,int x)
{	if(p->rear==m-1)
		printf("Overflow\n");
	else if((p->front==-1)&&(p->rear==-1))
	{	p->front++;
		p->rear++;
		p->a[p->rear]=x;
	}
	else
	{	p->a[++p->rear]=x;
	}
}
int dequeue(struct queue *p)
{	if((p->front==-1&&p->rear==-1)||(p->front>p->rear))
	{	printf("Underflow\n");
		return;
	}
	else
	{	return p->a[p->front++];
	}
}
void display(struct queue *p)
{	if((p->front==-1&&p->rear==-1)||(p->front>p->rear))
		printf("Queue is empty\n");
	else
	{	for(int i=p->front;i<=p->rear;i++)
		{	printf("%d\t",p->a[i]);
		}
		printf("\n");
	}
}
void main()
{	struct queue s;
	initqueue(&s);
	int ch,x;
	do
	{	printf("Enter\n1.Insert element\n2.Delete element\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{	case 1: printf("Enter element to be inserted\n");
					scanf("%d",&x);
					enqueue(&s,x);
					break;
			case 2: printf("The deleted element is %d",dequeue(&s));
					break;
			case 3: display(&s);
					break;
			case 4: 
					break;
			default:printf("WRONG CHOICE\n");
					break;
		}
	}while(ch!=4);
}
