#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
typedef struct node
{
    char data;
    struct node *left,*right;
}node;
struct stack
{
    int top;
    node *arr[MAX];
};
void push(struct stack *q,node *newnode)
{
    if(q->top==MAX-1)
    {
        printf("\nOverflow");
        exit(0);
    }
    else
        q->arr[++q->top]=newnode;
}
node *pop(struct stack *s)
{
    if(s->top==-1)
    {  
        printf("\nUnderflow");
        exit(0); 
    }
    else
        return(s->arr[s->top--]);
}
node * construct(char postfix[])
{
    struct stack s;
    node *x,*y;
    node *newnode,*root;
    s.top=-1;
    int i;
    for(i=0;postfix[i]!='\0';i++)
    {
        newnode = ( node *)malloc(sizeof( node));
	    newnode->data = postfix[i];
	    newnode->left = NULL;
	    newnode->right = NULL;
	    if(isalnum(postfix[i]))
	        push(&s,newnode);
	    else
	    {
	        x=pop(&s);
	        y=pop(&s);
	        newnode->left = y;
	        newnode->right = x;
	        push(&s,newnode);
	    }
	}
     return pop(&s);	
     
}
void inorder(struct node *p){
    if(p != NULL)
    {
    if(p->right!=NULL && p->left!=NULL)
        printf("(");
	
		inorder(p->left);
		printf("%c", p->data);
		inorder(p->right);
	
	if(p->right!=NULL && p->left!=NULL)
        printf( ")");
       }
	
}

void preorder(struct node *p){
	if(p != NULL){
		printf("%d", p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct node *p){
	if(p != NULL){
		postorder(p->left);
		postorder(p->right);
		printf("%d\n", p->data);
	}
}
int main()
{
    node *root=NULL;
    char post[MAX];
    printf("\nEnter postfix expression : \n");
        gets(post);
    root = construct(post);
    printf("The Infix expression is : \n");	
    inorder(root);
    return 0;
}