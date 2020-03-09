#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int graph[10][10]={0};

struct queue
{
	int front,rear;
	int a[100];
};

struct stack
{
	int top;
	int a[100];
};

void initstk(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,int x)
{
	if(s->top==SIZE-1)
	{
		printf("Stack overflow\n");
	}
	else 
	{
		s->top=s->top+1;
		s->a[s->top]=x;
	}
}

int pop(struct stack *s)
{
	int x;
	if(s->top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		x=s->a[s->top];
		s->top=s->top-1;
		return x;
	}
}	
int isEmpty(struct queue *q)
{
	if(q->rear==-1)
		return 1;
	else
		return 0;
}

int isEmptystk(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

void init(struct queue *q)
{
	q->front=-1;
	q->rear=-1;
}

void enque(struct queue *q, int x)
{
	if(q->rear==SIZE)
	{
		printf("Queue full\n");
	}
	else if(q->front==-1 && q->rear==-1)
	{
		q->front=0;
		q->rear=0;
		q->a[q->rear]=x;
	}
	else
	{
		q->rear=q->rear+1;
		q->a[q->rear]=x;
	}
}

int deque(struct queue *q)
{
	int x;
	if(q->front==-1)
	{
		printf("Queue empty\n");
	}
	else if(q->front==q->rear)
	{
		x=q->a[q->front];
		q->front=-1;
		q->rear=-1;
		return x;	
	}
	else
	{
		x=q->a[q->front];
		q->front=q->front+1;
		return x;
	}
}  

void bfs(int source,int n)
{	
	int v,i;
	int visited[SIZE]={0};
	struct queue q;
	init(&q);
	enque(&q,source);
	visited[source]=1;
	while(!isEmpty(&q))
	{
		v=deque(&q);
		printf("%d ",v);
		for(i=0;i<n;i++)
		{
			if(graph[v][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				enque(&q,i);
				
			}
		}
	}
}

void dfs(int source,int n)
{
	int x,i;
	int visited[SIZE]={0};	
	struct stack s;
	initstk(&s);
	push(&s,source);
	visited[source]=1;
	while(!isEmptystk(&s))
	{
		x=pop(&s);
		printf("%d ",x);
		
		for(i=0;i<n;i++)
		{
			if(graph[x][i]==1 && visited[i]==0)
			{					
				push(&s,i);
				visited[i]=1;
			}
		}
	}
}
void main()
{
 	int e,s,d,i,j,c,n,source;
 	printf("Enter size of matrix\n");
 	scanf("%d",&n);
 	do
 	{
	 		printf("Enter source & destination\n");
	 		scanf("%d %d",&s,&d);
	 		graph[s][d]=1;
	 		graph[d][s]=1;
 			printf("Enter 1 to stop\n");
 			scanf("%d",&c);
	 }while(c!=1);
	 		
	 	
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			printf("%d ",graph[i][j]);
 		}
 		printf("\n");
 	}
 	printf("Enter source\n");
 	scanf("%d",&source);
 	printf("Breadth first search traversal:\n");
 	bfs(source,n);
	printf("\n");
	printf("Depth first search traversal:\n");
	dfs(source,n);
	printf("\n");
}
