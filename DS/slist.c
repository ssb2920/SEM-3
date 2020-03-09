#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct stack
{	int data;
	struct stack *next;
};
struct stack *top=NULL;
void push(int x)
{	struct stack *ptr;
	ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data=x;
	if(top==NULL)
	{	ptr->next=NULL;
		top=ptr;
	}
	else
	{	ptr->next=top;
		top=ptr;
	}
}
int pop()
{	struct stack *ptr;
	if(top==NULL)
	{	printf("Underflow\n");
		return -1;
	}
	else
	{	ptr=top;
		top=top->next;
		int x=ptr->data;
		free(ptr);
		return x;
	}
}
void display()
{	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	{	printf("Underflow\n");
	}
	else
	{	while(ptr!=NULL)
		{	printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
void peek()
{
	if(top==NULL)
		return ;
	else
		printf("%d\n",top->data);
}
void main()
{
	int val,op;
	do
	{
		printf("\nENTER\n 1:PUSH\n 2:POP\n 3:DISPLAY\n 4:PEEK\n 5:EXIT\n");
		printf("Enter option\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: printf("Enter value :\n");
				scanf("%d", &val);
				push(val);
				break;
			case 2: val=pop();
					if(val!=-1)
						printf("The popped element is %d",val);
				break;
			case 3: display();
				break;
			case 4: peek();
				break;
			case 5: exit(1);
				break;
			default: printf("WRONG OPTION");
				 break;
		}
	}while(1);
}
		