#include<stdio.h>
#include<stdlib.h>
struct node
{
    int row,col,info;
    struct node *next;
};
struct node *START=NULL;
void addnode(struct node *newnode)
{
    struct node *ptr;
    ptr=START;
    if(START==NULL)
    {
        START=newnode;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}
void entMatrix(int dimr,int dimc)
{
    int n,val,r,c;
    printf("\nEnter number of non zero terms in matrix\t");
    scanf("%d",&n);
    struct node *ptr;
    ptr=START;
    int i=0;
    while(i<n)
    {
        printf("\nEnter value,row and column\n");
        scanf("%d%d%d",&val,&r,&c);
        if(r>=dimr||c>=dimc)
        {
            printf("\nEnter row and column values within dimensions");
            continue;
        }
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=val;
        newnode->next=NULL;
        newnode->row=r;
        newnode->col=c;
        addnode(newnode);
        i++;
    }
}
void display(int dimr,int dimc)
{
    if(START==NULL)
    {
         printf("\nEmpty matrix");
    }
    else
    {
       struct node *ptr;
       ptr=START;
	int i,j;
       for(i=0;i<dimr;i++)
       {
        printf("\n");
           for(j=0;j<dimc;j++)
           {
               if(ptr->row==i&&ptr->col==j)
               {
                   printf("\t%d",ptr->info);
                   ptr=ptr->next;
               }
               else
               {
                   printf("\t0");
               }
           }
           
        }
    }    
}
void main()
{   
    int option,dimr,dimc;
    do
    {
        printf("\n1.Enter Matrix\n2.Display Matrix\n3.Exit\n");
        scanf("%d",&option);
        switch(option)
       {
         case 1:
            printf("\nEnter dimensions of the matrix\n");
            scanf("%d%d",&dimr,&dimc); 
            entMatrix(dimr,dimc);
		break;
	case 2:
        	display(dimr,dimc);
		break;
	case 3:
        	exit(1);
        	break;
      	default:
            printf("\nInvalid option\n");
        }
       }while(1);
}
