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
void insertrear(struct queue *p,int x)
{	if((p->rear+1==p->front)||(p->rear==m-1&&p->front==0))
		printf("Overflow\n");
	else if((p->front==-1)&&(p->rear==-1))
	{	p->front++;
		p->rear++;
		p->a[p->rear]=x;
	}
	else if((p->rear==m-1)&&(p->front!=0))
	{	p->rear=0;
		p->a[p->rear]=x;
	}
	else
	{	p->a[++p->rear]=x;
	}
}
void insertfront(struct queue *p,int x)
{	if((p->rear+1==p->front)||(p->rear==m-1&&p->front==0))
		printf("Overflow\n");
	else if((p->front==-1)&&(p->rear==-1))
	{	p->front++;
		p->rear++;
		p->a[p->front]=x;
	}
	else if((p->front==0)&&(p->rear!=m-1))
	{	p->front=m-1;
		p->a[p->front]=x;
	}
	else
	{	p->a[--p->front]=x;
	}
}
int removefront(struct queue *p)
{	int y;
	if(p->front==-1&&p->rear==-1)
	{	printf("Underflow\n");
		return;
	}
	else if(p->rear==p->front)
	{	y=p->a[p->front];
		p->front=p->rear=-1;
		return y;
	}
	else if(p->front==m-1)
	{	y=p->a[p->front];
		p->front=0;
		return y;
	}
	else
	{	return p->a[p->front++];
	}
}
int removerear(struct queue *p)
{	int y;
	if(p->front==-1&&p->rear==-1)
	{	printf("Underflow\n");
		return;
	}
	else if(p->rear==p->front)
	{	y=p->a[p->rear];
		p->front=p->rear=-1;
		return y;
	}
	else if(p->rear==0)
	{	y=p->a[p->rear];
		p->rear=m-1;
	}
	else
	{	return p->a[p->rear--];
	}
}

void display(struct queue *p)
{	int i;
	if(p->front==-1&&p->rear==-1)
		printf("Queue is empty\n");
	else if(p->rear>p->front)
	{	for(i=p->front;i<=p->rear;i++)
		{	printf("%d\t",p->a[i]);
		}
		printf("\n");
	}
	else
	{	for(i=p->front;i<m;i++)
			printf("%d\t",p->a[i]);
		for(i=0;i<=p->rear;i++)
			printf("%d\t",p->a[i]);
		printf("\n");
	}
}
void main()
{	struct queue s;
	initqueue(&s);
	int ch,x;
	do
	{	printf("Enter\n1.Insert rear element\n2.Delete front element\n3.Display\n4.Exit\n5.insert front\n6.remove rear\n");
		scanf("%d",&ch);
		switch(ch)
		{	case 1: printf("Enter element to be inserted\n");
					scanf("%d",&x);
					insertrear(&s,x);
					break;
			case 2: printf("The deleted element is %d",removefront(&s));
					break;
			case 3: display(&s);
					break;
			case 4: exit(1);
					break;
				case 5: printf("Enter element to be inserted\n");
					scanf("%d",&x);
					insertfront(&s,x);
					break;
					case 6: printf("The deleted element is %d",removerear(&s));
					break;
			default:printf("WRONG CHOICE\n");
					break;
		}
	}while(1);
}
