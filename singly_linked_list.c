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

void insert_first()
{
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=NULL; //assign null to next
    printf("Enter your ID: ");
    scanf("%d",&node->id);
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

void insert_last()
{
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=NULL; //assign null to next
    printf("Enter your ID: ");
    scanf("%d",&node->id);
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

void insert_pos()
{
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
	    printf("Enter your ID: ");
	    scanf("%d",&node->id);
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

void search()
{
	int s=0,src,c=0;
	printf("Enter the id you want to search: ");
	scanf("%d",&src);
	temp=head;
	while(temp!=NULL)
	{
		if(temp->id==src)
		{
			s=1;
			printf("Present at %d",c);
			return;
		}
		temp=temp->next;
		c++;
	}
	if(s==0)
		printf("Not Present");
}

void main()
{
    int ch;
	while(ch!=9)
	{
	printf("\n1. Insert at first\n");
	printf("2. Delete from first\n");
	printf("3. Insert at last\n");
	printf("4. Delete from last\n");
	printf("5. Insert at position\n");
	printf("6. Delete from position\n");
	printf("7. Search data in the link list\n");
	printf("8. Print data link\n");
	printf("9. Exit\n");
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
			search();
			break;
		case 8:
			prnt();
			break;
		case 9:
			return;
		default:
			printf("Enter from the given options\n");
	}
	}
}
