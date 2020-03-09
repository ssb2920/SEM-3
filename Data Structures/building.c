#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 50
struct owner
{
	char Name[m];
	int RoomNumber;
	char Username[m];
	char Password[m];
	int size;
	int monthPrev;
	int yearPrev;
	int maintenance;
	int housetax;
	struct owner *next;
	struct owner *prev;
};
struct owner *start=NULL;
void create_owner()
{
	struct owner *newnode, *ptr;
	int rn,size;
	char nm[m],us[m],ps[m];
	printf("Enter the Owners Details:\n");
	printf("Enter the Owners Name:\n");
	scanf("%s",&nm);
	printf("Enter the Owners Room Number:\n");
	scanf("%d",&rn);
	printf("Enter the Owners Username:\n");
	scanf("%s",&us);
	printf("Enter the Owners Password:\n");
	scanf("%s",&ps);
	choice:
	printf("Enter the Owners flat size in BHK:\n");
	scanf("%d",&size);
	if(size<1||size>4)
	{	printf("Wrong Choice\n");
		goto choice;
	}
		
		newnode=(struct owner*)malloc(sizeof(struct owner));
		newnode->RoomNumber = rn;
		strcpy(newnode->Name,nm);
		strcpy(newnode->Username,us);
		strcpy(newnode->Password,ps);
		newnode->size = size;
		newnode->maintenance=0;
		newnode->housetax=0;
		newnode->monthPrev=1;
		newnode->yearPrev=2017;
		if(start==NULL)
		{
			newnode->prev = NULL;
			newnode->next = NULL;
			start=newnode;
		}
		else
		{	
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next = newnode;
			newnode->next = NULL;
			newnode->prev = ptr;		
		}
	
}

void delete_beg()
{
	struct owner *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	
}

void delete_end()
{
	struct owner *ptr;
	ptr = start;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	free(ptr);
	
}


void delete_owner()
{
	struct owner *newnode,*ptr;
	int rono;
	printf("Enter the Room number of the owner which has to deleted\n");
	scanf("%d", &rono);
	ptr = start;
	if(ptr->RoomNumber == rono)
	{
		delete_beg();
		
	}
	else
	{
		while(ptr->RoomNumber!=rono)
		{
			ptr=ptr->next;
		}
		if(ptr->next == NULL)
		{
			delete_end();
		}
		else
		{
			ptr->next->prev = ptr->prev;
			ptr->prev->next =ptr->next;
			free(ptr);
		}
	}
}
void display()
{
	struct owner *ptr;
	ptr = start;
	while(ptr!=NULL)
	{	
		printf("Name:%s\n",ptr->Name);
 	    	printf("Room Number:%d\n", ptr->RoomNumber);
        	printf("Username:%s\n",ptr->Username);
  		printf("Password:%s\n",ptr->Password);
		printf("Flat size:%dBHK\n", ptr->size);
		printf("Maintenance to be paid:Rs %d\n", ptr->maintenance);
		printf("Housetax to be paid:Rs %d\n", ptr->housetax);
		ptr=ptr->next;
	}
	
}
int Maintenance(int month,int year,struct owner *ptr)
{	int mt,t,y;
	if(ptr->size==1)
			mt=5000;
		else
			mt=5000+2000*(ptr->size-1);
	printf("Your monthly maintenance is : %d\n",mt);
	if(year == ptr->yearPrev)
	{
		t=month-(ptr->monthPrev);
		if(t>=4)
		{	printf("FINE for late payment is Rs.1000 per month\n");
			ptr->maintenance=ptr->maintenance + t*mt+t*1000;
		}
		else
			ptr->maintenance=ptr->maintenance + t*mt;
		printf("Your total maintenance is %d\n",ptr->maintenance);
	}
	else
	{	printf("FINE for late payment is Rs.1000 per month\n");
		t=month-(ptr->monthPrev);
		y= year -(ptr->yearPrev);
		ptr->maintenance = ptr->maintenance +12*y*mt+t*mt+y*12000+t*1000;
		printf("Your total maintenance is %d\n",ptr->maintenance);
	}	
	
	return ptr->maintenance;
}

int payAmount(int mm,int amt)
{
	mm = mm - amt;
	printf("PAID\n");	
	return mm;
}
int Housetax(int year,struct owner *ptr)
{	int mt,y;
	if(ptr->size==1)
		mt=2000;
	else
		mt=2000+1000*(ptr->size-1);
	printf("Your house tax is : %d\n",mt);
	if(year == ptr->yearPrev||year == ptr->yearPrev+1)
	{
		ptr->housetax=ptr->housetax + mt;
		printf("Your total housetax is %d\n",ptr->housetax);
	}	
	else
	{	printf("FINE for late payment is Rs.1000 per year\n");
		y=year -(ptr->yearPrev);
		ptr->housetax=ptr->housetax + y*mt+y*1000;
		printf("Your total housetax is %d\n",ptr->housetax);
	}
	return ptr->housetax;
}				

	
void main()
{
	struct owner *ptr;
	int n,i,op,amt,re,mm,month,year;
	char s[m],us[m],ps[m];
	printf("Enter building name:\n");
	scanf("%s",&s);
	printf("Enter the number of Owners:\n");
	scanf("%d",&n);
	printf("****FOR OFFICE USE****\n");
	for(i=0;i<n;i++)
		create_owner();
	printf("The Date Of Start of Payment:01/01/2017\n");
	
	do
	{
		printf("1: Add owner\n");
		printf("2: Delete an owner\n");
                printf("3:Display\n");
		printf("4: EXIT\n");
		printf("Enter your option\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: create_owner();
				break;
			case 2: delete_owner();
				break;
			case 3: display();
                    		break;
            		case 4: break;
			default:printf("WRONG CHOICE");
				break;
		}
	}while(op!=4);
	
	while(1)
	{	enter:
		printf("Enter Username:\n");
		scanf("%s",&us);
		printf("Enter Password:\n");
		scanf("%s",&ps);
		ptr = start;
		while(ptr!=NULL)
		{	if(strcmp(ptr->Username,us)==0)
			{	if(strcmp(ptr->Password,ps)==0)
				{	pay:
					printf("Enter\n1:Maintenance\n2:House Tax\n3:Display\n4:Different Account\n5:Exit\n");
					scanf("%d",&op);
					switch(op)
					{	case 1:printf("Enter the month and the year of the Payment:");
							scanf("%d",&month);
							scanf("%d",&year);
							
							mm = Maintenance(month,year,ptr);
							printf("Enter the amount you want to pay:");
							scanf("%d",&amt);
							re = payAmount(mm,amt);
							ptr->maintenance = re;
							ptr->monthPrev = month;
							ptr->yearPrev = year;
							
							goto pay;
						case 2: printf("Enter year of payment");
							scanf("%d",&year);
							
							mm=Housetax(year,ptr);
							printf("Enter the amount you want to pay:");
							scanf("%d",&amt);
							re=payAmount(mm,amt);
							ptr->housetax=re;
							ptr->yearPrev=year;
							goto pay;
						case 3: display();
								goto pay;
						case 4:goto enter;
						case 5:exit(1);
						default:printf("WRONG CHOICE\n");
								goto pay;
					}	
				}
				else
				printf("Wrong Password\n");
			}
			else 
			printf("Wrong Username\n");
			ptr=ptr->next;
		}
			
			
	}
					
}