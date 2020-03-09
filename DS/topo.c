#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int adj[SIZE][SIZE]={0};
int visited[SIZE]={0};
int indeg[SIZE]={0};

struct queue
{
	int a[SIZE];
	int front,rear;
};

void enqueue(struct queue *p,int x)
{
     if(p->rear==SIZE-1)
     {
       	printf("Queue Overflow\n");
     }
     else
     {
      	p->rear++;
     	p->a[p->rear]=x;
     }
}
int dequeue(struct queue *p)
{ 
	int x;
	if(p->front==p->rear)
	{
	       printf("Queue Underflow\n");
	       return 0;	
	}
	else
	{
	       
	       p->front++;
	       x=p->a[p->front];
	       return x;
	}
}
void display(struct queue *q)
{
	while(q->front != q->rear)
	{
		printf("Entered for printing\n");
		printf("%d",q->a[q->front++]);
	}
}

void topo(struct queue *q,int n)
{
	int i,j=0,count=1;
	printf("After topological sort :\n");
	while(count<=n)
	{
		for (i=1;i<=n;i++) 
		{
			if(indeg[i]==1)
				indeg[i]=indeg[i]-1;
			 if((indeg[i]==0) && (visited[i]==0))
				{
					enqueue(q,i);
					printf("%d\t",dequeue(q));
					visited[i]=1;
					break;
				}
		}
		i--;
		for(j=1;j<=n;j++)
		{
			if(adj[i][j]==1)
        	        indeg[j]--; 
		}
		count++;
	}
	display(q);
}
int main()
{
	int v,e,i,s,d,x,j;
	struct queue q;	
	q.front=-1;
	q.rear=-1;
	printf("Enter the number of vertices :");
	scanf("%d",&v);
	printf("Enter the number of edges :");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("Enter the source node value :");
		scanf("%d",&s);
		printf("\n");
		printf("Enter the destination node value :");
		scanf("%d",&d);
		adj[s][d]=1;
		indeg[d]=indeg[d]+1;
	}
	printf("The Matrix is :\n");
	for(i=1;i<=e;i++)
	{
		for(j=1;j<=e;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	topo(&q,e);
	
}	
	