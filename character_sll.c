#include<stdio.h>
#include<stdlib.h>
int cnt;
struct student
{
    char id;
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

void insert_first()
{
	char x;
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=NULL; //assign null to next
    if(head==NULL)
    {
    	fflush(stdin); //to clear the buffer
    	printf("Enter the char: ");
    	scanf("%c",&node->id); //take input from the user if there is no data
        head=last=node;
	}
    else
    {
    	x=head->id; 
	    if(x==65 || x==97) //x=='A' OR x=='a'
	    	x=x+25; //assign Z or z
	    else
	    	x--;
	    node->id=x; //assign data to node
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

void insert_last()
{
	char x;
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=NULL; //assign null to next
    if(head==NULL)
    {
    	fflush(stdin); //clear the buffer
    	printf("Enter the char: ");
    	scanf("%c",&node->id); //take input from the user if there is no data
        head=last=node;
	}
    else
    {
    	/*
    	temp=head;
    	while(temp->next!=NULL)
    	    temp=temp->next;
	    temp->next=node;
	    */
	    x=last->id; //take last data
	    if(x==90 || x==122) //x=='Z' OR x=='z'
	    	x=x-25; //assign a or A
	    else
	    	x++;
	    node->id=x;
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

void insert_pos()
{
	char x;
	int pos,i=1;
	printf("Enter position for node: ");
	scanf("%d",&pos);
	count();
	if(pos==1)
		insert_first();
	else if(pos==cnt+1)
		insert_last();
	else if(pos<1 || pos>(cnt+1))
		printf("Position out of bound");
	else
	{
		node=(struct student*) malloc(sizeof(struct student)); //assign address to node
	    node->next=NULL; //assign null to next
	    temp=head;
	    //ex: pos=3
	    while(i!=(pos-1)) //until the position before the insertion (2) 
	    {
	    	i++;
	    	temp=temp->next; //temp=(2)
		}
		x=temp->id;
		if(x==90 || x==122) //x=='z' OR x=='Z'
	    	x=x-25; //assign A or a
	    else
	    	x++;
		node->id=x;
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
		printf("char = %c\n",temp->id);
		temp=temp->next;
		printf("\n\n");
	}
}

void main()
{
    int ch;
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
			insert_first();
			break;
		case 2:
			del_first();
			break;
		case 3:
			insert_last();
			break;
		case 4:
			del_last();
			break;
		case 5:
			insert_pos();
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
