//only add prime number in linked list

#include<stdio.h>
#include<stdlib.h>
int cnt;
struct student
{
    int id;
    struct student *next;
}*head=NULL, *node, *temp, *last=NULL;

void count()
{
	temp=head;
	cnt=0;
	while(temp!=NULL)
	{
		cnt++;
		temp=temp->next;
	}
}

void insert_first(int no)
{
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=NULL; //assign null to next
    /*printf("Enter your ID: ");
    scanf("%d",&node->id);*/
	node->id=no;
    if(head==NULL)
        head=last=node;
    else
    {
        node->next=head; //first create the link then assign head or last
        head=node;
    }
}

void del_first()
{
    if(head==NULL)
        printf("No node is there\n");
    else
    {
        temp=head;
        if(head->next==NULL) //last data in linked list
            head=last=NULL;
        else
        	head=temp->next;
        free(temp); //free temp memory
    }
}

void insert_last(int no)
{
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=NULL; //assign null to next
    /*printf("Enter your ID: ");
    scanf("%d",&node->id);*/
    node->id=no;
    if(head==NULL)
        head=last=node;
    else
    {
    	/*
    	temp=head;
    	while(temp->next!=NULL)
    	    temp=temp->next;
	    temp->next=node;
	    */
        last->next=node;
        last=node;
    }
}

void del_last()
{
	struct student* temp1;
	if(last==NULL)
	    printf("No node is there\n");
    else
    {
    	temp=head;
		if(head->next==NULL)
	        head=last=NULL;
		else
		{
	    	while(temp->next!=NULL) //or temp!=last
			{
				temp1=temp; //second last in linked list
	            temp=temp->next; //temp will be last
	        }
	        last=temp1;
	        temp1->next=NULL;
		}
       	free(temp);
    }
}

void insert_pos(int no)
{
	int pos,i=1;
	printf("Enter position for node: ");
	scanf("%d",&pos);
	count();
	if(pos==1)
		insert_first(no);
	else if(pos==cnt+1)
		insert_last(no);
	else if(pos<1 || pos>(cnt+1))
		printf("Position out of bound");
	else
	{
		node=(struct student*) malloc(sizeof(struct student)); //assign address to node
	    node->next=NULL; //assign null to next
	    /*printf("Enter your ID: ");
	    scanf("%d",&node->id);*/
	    node->id=no;
	    temp=head;
	    //ex: pos=3
	    while(i!=(pos-1)) //until the position before the insertion (2) 
	    {
	    	i++;
	    	temp=temp->next; //temp=(2)
		}
		node->next=temp->next; //link the node next value first
		temp->next=node; //link the node in link
	}
}

void del_pos()
{
	struct student* temp1;
	int pos,i=1;
	printf("Enter position for node: ");
	scanf("%d",&pos);
	count();
	if(pos==1)
		del_first();
	else if(pos==cnt+1)
		del_last();
	else if(pos<1 || pos>(cnt+1))
		printf("Position out of bound");
	else
	{
		temp=head;
	    while(i!=pos) //until the position 
	    {
	    	i++;
	    	temp1=temp; //before the position
	    	temp=temp->next; //at the exact position
		}
		temp1->next=temp->next; //link it
		free(temp);
	}
}

void prnt()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("Id = %d\n",temp->id);
		temp=temp->next;
		printf("\n\n");
	}
}

//function to check if the number is prime or not
int pri()
{
    int id,x=0,i;
    printf("Enter the number");
    scanf("%d",&id);
    if(id<=1) //1 is not prime
    	x=1;
    for(i=2;i <= id/2;i++)
    {
    	if(id%i == 0)
    	{
    		x=1;
    		break;
		}
	}
	if(x==0) //number is prime
		return id;
	else
	{
		printf("Number is not prime\n");
		pri();
	}
}

void main()
{
    int ch,id;
	while(ch!=8)
	{
	printf("\n1. Insert at first\n");
	printf("2. Delete from first\n");
	printf("3. Insert at last\n");
	printf("4. Delete from last\n");
	printf("5. Insert at position\n");
	printf("6. Delete from position\n");
	printf("7. Print data link\n");
	printf("8. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			id=pri();
			insert_first(id);
			break;
		case 2:
			del_first();
			break;
		case 3:
			id=pri();
			insert_last(id);
			break;
		case 4:
			del_last();
			break;
		case 5:
			id=pri();
			insert_pos(id);
			break;
		case 6:
			del_pos();
			break;
		case 7:
			prnt();
			break;
		case 8:
			return;
		default:
			printf("Enter from the given options\n");
	}
	}
}
