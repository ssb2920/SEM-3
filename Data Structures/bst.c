#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
int h1,h2;
struct tree
{
    struct node *root;
};
void insert (struct tree *t1,int x)
{
      struct  node *ptr,*newnode,*parent;
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=x;
      newnode->left=NULL;
      newnode->right=NULL;
      if(t1->root==NULL)
      {
          t1->root=newnode;

      }  
      else
      {
          ptr=t1->root;
          while(ptr!=NULL)
          {
              if(x<ptr->data)
              {
                  parent=ptr;
                  ptr=ptr->left;
              }
              else
              {
                  parent=ptr;
                  ptr=ptr->right;
              }
          }
          if(x<parent->data)
          {
              parent->left=newnode;
          }
          else
          {
              parent->right=newnode;
          }
      }
}

void delete(struct tree *t){
	struct node *ptr, *preptr;
	ptr = t->root;
	int val, flag = 0;
	printf("Enter element to be deleted\n");
	scanf("%d", &val);
	if(t->root == NULL){
		printf("Tree is Empty\n");
		return ;
	}
	
	if(t->root->data == val){
		t->root = NULL;
		free(ptr);
		return ;
	}
	while(ptr != NULL){
		
		if(val == ptr->data){
			flag = 1;
			
			break;
		}
		else if(val > ptr->data){
			preptr = ptr;
			ptr = ptr->right;
			
		}
		else{
			preptr = ptr;
			ptr = ptr->left;
		}
	}
	
	if(flag == 0){
		printf("Element not Found\n");
		
	}
	else{
		if(ptr->left == NULL && ptr->right ==NULL){
			if(preptr->left == ptr){
				preptr->left = NULL;
				free(ptr);
			}
			else{
				preptr->right = NULL;
				free(ptr);
			}
		}
		else if(ptr->left == NULL){
			if(preptr->left == ptr){
				preptr->left = ptr->right;
				free(ptr);
			}
			else{
				preptr->right = ptr->right;
				free(ptr);
			}
		}
		else if(ptr->right == NULL){
			if(preptr->left == ptr){
				preptr->left = ptr->left;
				free(ptr);
			}
			else{
				preptr->right = ptr->left;
				free(ptr);
			}
		}
		else{
			struct node *temp, *ptemp;
			temp = ptr;
			temp = temp->left;
			while(temp->right != NULL){
				ptemp = temp;
				temp = temp->right;
			}
			
			if(temp->left == NULL){
				ptr->data = temp->data;
				free(temp);		
			}
			else{
				ptr->data = temp->data;
				ptemp->right = temp->left;
				free(temp);
			}
				
		}
		
	}
}
void Inorder(struct node *t1)
{
    struct node *ptr;
    ptr=t1;
    if( ptr != NULL)
    {
        Inorder(ptr->left);
        printf(" %d ",ptr->data);
        Inorder(ptr->right);
    }
}

void Preorder(struct node *t1)
{
    struct node *ptr;
    ptr=t1;
    if( ptr != NULL)
    {
        printf(" %d ",ptr->data);
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}

void Postorder(struct node *t1)
{
    struct node *ptr;
    ptr=t1;
    if( ptr != NULL)
    {
        Postorder(ptr->left);
        Postorder(ptr->right);
        printf(" %d ",ptr->data);
    }
    
}

int height(struct node *t1)
{
    struct node *ptr;
    ptr=t1;
    if(ptr==NULL)
    {
        return(-1);
    }    
    else if(ptr->left==NULL&&ptr->right==NULL)
    {
        return(0);
    }
    else
    {
        h1=height(ptr->left);
        h2=height(ptr->right);
        if(h1>h2)
        {
            return(h1+1);
        }
        else{
            return(h2+1);
        }
    }
    
}
int main()
{
    struct tree t1;
    struct node p;
    t1.root=NULL;
    int option,x,d,ch,h3;
    do
    {
        printf("------------MENU---------\n");
        printf("1.Insert in the Binary Search Tree \n ");
        printf("2.Delete an element from the Binary Search Tree \n");
        printf("3.Display in Inorder \n");
        printf("4.Display in Preorder \n");
        printf("5.Display in Postorder \n");
        printf("6.Height of the Binary Search Tree\n ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter the Element to be added :");
                    scanf("%d",&x);
                    insert(&t1,x);
                    break;

            case 2: delete(&t1);
                    break;

            case 3:
                   printf("\nBST Traversal in INORDER \n");
                    Inorder(t1.root);
                     printf(" \n");
                    break;
            case 4:
                    printf("\nBST Traversal in PREORDER \n");
                    Preorder(t1.root);
                    printf(" \n");
                    break;
            case 5:
                    printf("\nBST Traversal in POSTORDER \n");
                    Postorder(t1.root);
                    printf(" \n");
                    break;
            case 6: h3=height(t1.root);
                    printf("The height of the tree is : %d \n",h3);

                  

        }
    printf("1.TO CONTINUE 2.TO EXIT THE MENU \n");
    scanf("%d",&ch);    
    }while(ch!=2);
    return(0);
}
