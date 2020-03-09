#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct queue
{	int data;
	struct queue *next;
	struct queue *front;
	struct queue *rear;
};
void init_queue(struct queue *p)
{	p->front=p->rear=NULL;
}
void insert(struct queue *p)
{	int num;
	struct queue *ptr;
	printf("Enter value\n");
	scanf("%d",&num);
	ptr=(struct queue*)malloc(sizeof(struct queue));
	ptr->data=num;
	if(p->front==NULL)
	{	p->front=p->rear=ptr;
		ptr->next=NULL;
	}
	else
	{	p->rear->next=ptr;
		p->rear=ptr;
		ptr->next=NULL;
	}
}
void delete(struct queue *p)
{	struct queue *ptr;
	ptr=p->front;
	if(p->front==NULL)
	{	printf("EMPTY\n");
	}
	else
	{	printf("deleted data is %d\n",ptr->data);
		p->front=p->front->next;
		free(ptr);
	}
}
void display(struct queue *p)
{	struct queue *ptr;
	ptr=p->front;
	if(ptr == NULL)
	{
		printf("Empty\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}

void main()
{
	struct queue q;
	int op;
	init_queue(&q);
	do
	{
		printf("\nENTER\n1:Insert element 2:Delete element 3:Display elements 4:EXIT\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: 
				insert(&q);
				break;
			case 2: delete(&q);
				break;
			case 3: display(&q);
				break;
			case 4: exit(1);
				break;
			default: printf("WRONG CHOICE");
		}
	}
	while(1);
}
