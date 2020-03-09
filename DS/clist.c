#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{	int data;
	struct node *next;
};
struct node *start=NULL;
void create()
{	struct node *newnode,*ptr;
	int num;
	printf("Enter data or -1 to end list\n");
	scanf("%d",&num);
	while(num!=-1)
	{	newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{	newnode->next=newnode;
			start=newnode;
		}
		else
		{	ptr=start;
			while(ptr->next!=start)
			{	ptr=ptr->next;
			}
			newnode->next=start;
			ptr->next=newnode;
		}
		printf("Enter data\n");
		scanf("%d",&num);
	}
}
void display()
{	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\t",ptr->data);
	printf("\n");
}
void insert_beg()
{	struct node *newnode,*ptr;
	int num;
	printf("Enter data\n");
	scanf("%d",&num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=newnode;
	newnode->next=start;
	start=newnode;
	
}
void insert_end()
{	struct node *newnode,*ptr;
	int num;
	printf("Enter data\n");
	scanf("%d",&num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
	{	ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=start;
}
void insert_before()
{	struct node *newnode,*ptr,*preptr;
	int num,n;
	printf("Enter data before which you want to insert\n");
	scanf("%d",&n);
	printf("Enter data\n");
	scanf("%d",&num);	
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=n)
	{	preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
}
void insert_after()
{	struct node *newnode,*ptr,*preptr;
	int num,n;
	printf("Enter data after which you want to insert\n");
	scanf("%d",&n);
	printf("Enter data\n");
	scanf("%d",&num);	
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(preptr->data!=n)
	{	preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
}
void delete_beg()
{	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=start->next;
	free(start);
	start=ptr->next;
}
void delete_end()
{	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=start)
	{	preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=start;
	free(ptr);
}
void delete_node()
{	struct node *ptr,*preptr;
	int num;
	printf("Enter data of node to be deleted\n");
	scanf("%d",&num);
	ptr=start;
	if(ptr->data==num)
	{	delete_beg();
	}
	else
	{
		while(ptr->data!=num)
		{	preptr=ptr;
			ptr= ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
}
void delete_after()
{	struct node *ptr,*preptr;
	int num;
	printf("Enter data of node after which you want to delete\n");
	scanf("%d",&num);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=num)
	{	preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}
void count()
{	struct node *ptr;
	int count=0;
	ptr=start;
	while(ptr->next!=start)
	{	count++;
		ptr=ptr->next;
	}
	printf("No. of nodes are %d",count+1);
}
void main()
{	int ch;
	do
	{	printf("\n*****MAIN MENU*****\n");
		printf("1: Create a list\n");
		printf("2: Display the list\n");
		printf("3: Add node at begining\n");
		printf("4: Add node at end\n");
		printf("5: Add node before a given node\n");
		printf("6: Add node after a given node\n");
		printf("7: Delete a node from the begining\n");
		printf("8: Delete a node from the end\n");
		printf("9: Delete a given node\n");
		printf("10: Delete a node after a given node\n");
		printf("11: EXIT\n");
		printf("12.Count\n");
		printf("Enter your option\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: create();
				printf("LINKED LIST CREATED");
				break;
			case 2: display();
				break;
			case 3: insert_beg();
				break;
			case 4: insert_end();
				break;
			case 5: insert_before();
				break;
			case 6: insert_after();
				break;
			case 7: delete_beg();
			        break;
			case 8: delete_end();
				break;
			case 9: delete_node();
				break;
			case 10: delete_after();
				 break;
			case 11: exit(1);
				 break;
			case 12:count();
				break;
			default: printf("WRONG CHOICE"); 
				 break;
		}
	}while(1);
}