#include<stdio.h>
#include<stdlib.h>
struct node
{
	int pri;
	struct node *next;
	int val;
};
struct node *start=NULL;
void insert()
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	int v;int p;
	v=0;p=0;
	ptr=start;
	printf("Enter value for node\n");
	scanf("%d",&v);
	temp->val=v;
	printf("Enter priority\n");
	scanf("%d",&p);
	temp->pri=p;
	if(start==NULL)
		{
			//printf("in first if");
			start=temp;
		}
	else if(start->pri>temp->pri)
		{
			temp->next=start;
			start=temp;
		}
	else 
	{
	ptr=start;
	while(ptr->next!=NULL && temp->pri>=(ptr->next)->pri)
			ptr=ptr->next;
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n Value= %d  Priority=%d",ptr->val,ptr->pri);
		ptr=ptr->next;
	}
}
void delete()
{
	struct node *ptr;
	if (start==NULL)
		printf("UNDERFLOW");
	else
	{
		ptr=start->next;
		free(start);
		start=ptr;
	}
}
void main()
{
	int ch;
	do
	{
	printf("Enter operation of choice 1. Insertion 2.Deletion 3.Display 4.Exit \n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		insert();
		break;
	case 2:
		delete();
		break;
	case 3:
		display();
		break;
	case 4:
		return;
	}
	
	}while(1);
}