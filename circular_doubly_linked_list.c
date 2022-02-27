#include<stdio.h>
#include<stdlib.h>
int cnt;
struct student
{
    int id;
    struct student *next,*prev;
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
    node->next=node->prev=NULL; //assign null to next and prev
    printf("Enter your ID: ");
    scanf("%d",&node->id);
    if(head==NULL)
    {
        node->next=node->prev=node;
        head=last=node;
	}
    else
    {
    	head->prev=node;
        node->next=head;
        last->next=node;
        node->prev=last;
        head=node;
    }
}

void del_first()
{
	struct list *temp1;
    if(head==NULL)
        printf("No node is there\n");
    else
    {
	    temp=head;
        if(head==last)
            head=last=NULL;
        else
        {
        	head=head->next;
        	head->prev=last;
        	last->next=head;
		}
        free(temp); //free temp memory
    }
}

void insert_last()
{
    node=(struct student*) malloc(sizeof(struct student)); //assign address to node
    node->next=node->prev=NULL; //assign null to next
    printf("Enter your ID: ");
    scanf("%d",&node->id);
    if(head==NULL)
    {
    	node->next=node->prev=node;
        head=last=node;
	}
    else
    {
        last->next=node;
        node->prev=last;
        head->prev=node;
        node->next=head;
        last=node;
    }
}

void del_last()
{
	if(last==NULL)
	    printf("No node is there\n");
    else
    {
    	temp=last;
		if(head==last)
	        head=last=NULL;
		else
		{
	        last=last->prev;
	        last->next=head;
	        head->prev=last;
		}
       	free(temp);
    }
}

void insert_pos()
{
	int pos,i=1;
	printf("Enter position to insert node: ");
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
	    node->next=node->prev=NULL; //assign null to next
	    printf("Enter your ID: ");
	    scanf("%d",&node->id);
	    temp=head;
	    //ex: pos=3
	    while(i!=(pos-1)) //until the position before the insertion (2) 
	    {
	    	i++;
	    	temp=temp->next; //temp=(2)
		}
		temp->next->prev=node;
		node->next=temp->next;
		node->prev=temp;
		temp->next=node;
	}
}

void del_pos()
{
	struct student* temp1;
	int pos,i=1;
	printf("Enter position to delete node: ");
	scanf("%d",&pos);
	count();
	if(pos==1)
		del_first();
	else if(pos==cnt)
		del_last();
	else if(pos<1 || pos>cnt)
		printf("Position out of bound");
	else
	{
		temp=head;
	    while(i!=pos) //until the position 
	    {
	    	i++;
	    	temp=temp->next; //at the exact position
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
}

void prnt()
{
		temp=head;
	if(head!=NULL)
	{
		do
		{	
			printf("ID = %d\n\n",temp->id);
			temp=temp->next;
		}while(temp!=head);
		printf("\n");
	}	
	else
		printf("list is empty");
}

void main()
{
    int ch,n;
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
			//search();
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
