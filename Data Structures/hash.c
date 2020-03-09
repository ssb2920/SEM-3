#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node{
    int data;
    struct node *next;
};

void create(struct node *a[],int hashVal){

  struct node *ptr;
  struct node *temp;

  ptr=(struct node*)malloc(sizeof(struct node));
  ptr->data=hashVal;
  ptr->next=NULL;

  hashVal%=MAX;

  if(a[hashVal]==NULL){

    a[hashVal]=ptr;
  }
  else{

    temp=a[hashVal];
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=ptr;
  }
}

void search(struct node *a[],int val){

  int hashVal;

  hashVal=val%MAX;

  if(a[hashVal]==NULL){
    printf("no such element in list\n");
  }

  else if(a[hashVal]->next==NULL)
  printf("%d\n",a[hashVal]->data);

  else{
    struct node *temp;
    temp=a[hashVal];
    while(temp!=NULL){
    if (temp->data==hashVal) {
      printf("%d\n",temp->data);
      break;
    }
    temp=temp->next;
   }
   if (temp==NULL) {
     printf("no such element in list\n");
   }
  }
}

int main(){
  int i,n,val;
  struct node *a[MAX];

  for(i=1;i<=n;i++){
    a[i]=NULL;
  }

  printf("enter no of elements\n");
  scanf("%d",&n);

  for(i=1;i<=n;i++){

    if(i==1){
    printf("enter the 1st element\n");
    scanf("%d",&val);
    create(a,val);
    }
    else if(i==2){
    printf("enter the 2nd element\n");
    scanf("%d",&val);
    create(a,val);
    }

    else if(i==3){
    printf("enter the 3rd element\n");
    scanf("%d",&val);
    create(a,val);
    }

    else{
    printf("enter the %dth element\n",i);
    scanf("%d",&val);
    create(a,val);
    }
  }

  printf("enter element to be searched\n");
  scanf("%d",&val);
  search(a,val);

  return 0;
}