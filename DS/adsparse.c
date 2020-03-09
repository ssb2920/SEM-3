#include<stdio.h>
#include<stdlib.h>
struct node
{
	int row,col,val;
	struct node *next;
};
 struct ad
{
	struct node *start;
};
void create_mat(struct ad *mat1,int terms)
{
	int r,v,c,i;
	struct node *newnode;
	for(i=1;i<=terms;i++)
	{
		printf("enter row column and value \n");
		scanf("%d%d%d",&r,&c,&v);
	
		

		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->val=v;
		newnode->row=r;
		newnode->col=c;
		newnode->next=NULL;

		if(mat1->start==NULL)
		{
			mat1->start=newnode;
		}
		else
		{
			struct node *ptr;
			ptr=mat1->start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
				
			ptr->next=newnode;
		}
	}
}

void display(struct ad *mat1,int totr,int totcol)
{
	int i,flag=0,j;
	struct node *ptr;	
	
	for(i=1;i<=totr;i++)
	{
		for(j=1;j<=totcol;j++)
		{	
			ptr=mat1->start;
			while(ptr->next!=NULL)
			{
				if((ptr->row==i)&&(ptr->col==j))
				{
					flag=1;
					printf("%d\t",ptr->val);
				}
				ptr=ptr->next;
			}	
			if((ptr->row==i)&&(ptr->col==j))
				{
					flag=1;
					printf("%d\t",ptr->val);
				}
			
			if(flag==0)
			{	
				printf("0\t");
			}
			flag=0;
		}
		printf("\n");
	}	
}
void create_res(struct ad *mat3,int rows,int column,int data1,int data2)
{
	struct node *ptr;
	struct node *newnode;
	
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->row=rows;	
	newnode->col=column;
	newnode->next=NULL;
	newnode->val=data1+data2;

	if(mat3->start==NULL)
			{
				mat3->start=newnode;
			}
			else
			{	
				ptr=mat3->start;
				
				while(ptr->next!=NULL)
				ptr=ptr->next;
		
				ptr->next=newnode;
			}	
}
	
void add(struct ad *mat1,struct ad *mat2,int totr,int totcol)
{
	struct node *ptr1;
	struct node *ptr2;
	struct ad mat3;
	struct node *newnode;
	mat3.start=NULL;
	
	ptr1=mat1->start;
	ptr2=mat2->start;
	
	while((ptr1->next!=NULL)&&(ptr2->next!=NULL))
	{	
		if((ptr1->row==ptr2->row)&&(ptr1->col==ptr2->col))
		{
			create_res(&mat3,ptr1->row,ptr1->col,ptr1->val,ptr2->val);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if((ptr1->row)<(ptr2->row))
		{		
			create_res(&mat3,ptr1->row,ptr2->col,ptr1->val,0);
				
			ptr1=ptr1->next;
		}
		else if((ptr1->row)>(ptr2->row))
		{	
			create_res(&mat3,ptr2->row,ptr2->col,0,ptr2->val);
			
			ptr2=ptr2->next;
		}
		else if((ptr1->col)<(ptr2->col))
		{
			create_res(&mat3,ptr1->row,ptr1->col,ptr1->val,0);	
			ptr1=ptr1->next;
		}
		else if((ptr2->col)<(ptr1->col))
		{
			create_res(&mat3,ptr2->row,ptr2->col,0,ptr2->val);
			ptr2=ptr2->next;
		}
		
	}

	if(ptr1->next==NULL&&ptr2->next!=NULL)
	{
		create_res(&mat3,ptr1->row,ptr1->col,ptr1->val,0);	
		while(ptr2->next!=NULL)
		{
			create_res(&mat3,ptr2->row,ptr2->col,0,ptr2->val);
			ptr2=ptr2->next;
		}
		create_res(&mat3,ptr2->row,ptr2->col,0,ptr2->val);
	}

	else if(ptr2->next==NULL&&ptr1->next!=NULL)
	{
		create_res(&mat3,ptr2->row,ptr2->col,0,ptr2->val);
		while(ptr1->next!=NULL)
		{
			create_res(&mat3,ptr1->row,ptr1->col,ptr1->val,0);	
			ptr1=ptr1->next;
		}
		create_res(&mat3,ptr1->row,ptr1->col,ptr1->val,0);
	}
	else
	{
		create_res(&mat3,ptr2->row,ptr2->col,0,ptr2->val);
		create_res(&mat3,ptr1->row,ptr1->col,ptr1->val,0);
	}
	display(&mat3,totr,totcol);
}

int main()
{
	struct ad mat1,mat2,mat3;	
	int totr,totcol,terms;

	mat1.start=NULL;
	mat2.start=NULL;
	mat3.start=NULL;
	
	printf("enter total no. of rows and columns in both sparse matrices\n");
	scanf("%d%d",&totr,&totcol);

	printf("enter no. of non zero terms in 1st sparse matrix\n");
	scanf("%d",&terms);
	
	create_mat(&mat1,terms);
	
	printf("entered matrix is\n");
	display(&mat1,totr,totcol);

	printf("enter no. of non zero terms in 2nd sparse matrix\n");
	scanf("%d",&terms);
	
	create_mat(&mat2,terms);
	
	printf("entered matrix is\n");
	display(&mat2,totr,totcol);
	
	printf("resultant matrix is\n");
	add(&mat1,&mat2,totr,totcol);
	return 0;	
}	
