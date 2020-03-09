#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{	int data;
	struct node *next,*prev;
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
		{	newnode->next=NULL;
			newnode->prev=NULL;
			start=newnode;
		}
		else
		{	ptr=start;
			while(ptr->next!=NULL)
			{	ptr=ptr->next;
			}
			newnode->next=NULL;
			ptr->next=newnode;
			newnode->prev=ptr;
		}
		printf("Enter data\n");
		scanf("%d",&num);
	}
}
void display()
{	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
void insert_beg()
{	struct node *newnode;
	int num;
	printf("Enter data\n");
	scanf("%d",&num);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=start;
	newnode->prev=NULL;
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
	while(ptr->next!=NULL)
	{	ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=NULL;
	newnode->prev=ptr;
}
void insert_before()
{	struct node *newnode,*ptr;
	int num,n;
	printf("Enter data before which you want to insert\n");
	scanf("%d",&n);
	printf("Enter data\n");
	scanf("%d",&num);	
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=n)
	{	ptr=ptr->next;
	}
	newnode->next=ptr;
	newnode->prev=ptr->prev;
	ptr->prev->next=newnode;
	ptr->prev=newnode;
}
void insert_after()
{	struct node *newnode,*ptr;
	int num,n;
	printf("Enter data after which you want to insert\n");
	scanf("%d",&n);
	printf("Enter data\n");
	scanf("%d",&num);	
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=n)
	{	ptr=ptr->next;
	}
	newnode->next=ptr->next;
	newnode->prev=ptr;
	ptr->next=newnode;
	ptr->next->prev=newnode;
}
void delete_beg()
{	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
}
void delete_end()
{	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{	ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	free(ptr);
}
void delete_node()
{	struct node *ptr;
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
		{	ptr=ptr->next;
		}
		if(ptr->next==NULL)
			delete_end();
		else
		{	ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);
		}
	}
}
void delete_after()
{	struct node *ptr;
	int num;
	printf("Enter data of node after which you want to delete\n");
	scanf("%d",&num);
	ptr=start;
	while(ptr->data!=num)
	{	ptr=ptr->next;
	}
	if(ptr->next==NULL)
	{	printf("Not Possible\n");
		return;
	}
	else
	{	ptr=ptr->next;
		if(ptr->next==NULL)
		{	delete_end();
		}
		else
		{	ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);
		}
	}
}
void sort()
{	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{	ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->data>ptr2->data)
			{	temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	display();
}
void search()
{	struct node *ptr;
	int flag=0;
	int count=0;
	int num;
	printf("Enter data to be searched\n");
	scanf("%d",&num);
	ptr=start;
	do
	{	count++;
		if(ptr->data==num)
		{	flag=1;
			break;
		}
		ptr=ptr->next;
	}while(ptr->next!=NULL);
	if (flag==1)
		printf("Element found at node %d\n",count);
	else if(ptr->data==num)
		printf("Element found at node %d\n",++count);
	else
		printf("Not found\n");
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
		printf("11: Sort the list\n");
		printf("12: Search the element\n");
		printf("13: EXIT\n");
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
			case 11: sort();
				 break;
			case 12: search();
				 break;
			case 13: exit(1);
				 break;
			default: printf("WRONG CHOICE"); 
				 break;
		}
	}while(1);
}
		
