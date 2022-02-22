#include<stdio.h>
#include<stdlib.h>

struct list
{
	int id;
	struct list *next;
}*head=NULL, *node, *temp, *last=NULL, *head1=NULL, *last1=NULL;

void insert_first()
{
    node=(struct list*) malloc(sizeof(struct list)); //assign address to node
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

void insert_first_1()
{
    node=(struct list*) malloc(sizeof(struct list)); //assign address to node
    node->next=NULL; //assign null to next
    printf("Enter your ID: ");
    scanf("%d",&node->id);
    if(head1==NULL)
        head1=last1=node;
    else
    {
        node->next=head1; //first create the link then assign head or last
        head1=node;
    }
}

void del_first_1()
{
    if(head1==NULL)
        printf("No node is there\n");
    else
    {
        temp=head1;
        if(head1->next==NULL) //last data in linked list
            head1=last1=NULL;
        else
        	head1=temp->next;
        free(temp); //free temp memory
    }
}

void prnt_1()
{
	temp=head1;
	while(temp!=NULL)
	{
		printf("Id = %d\n",temp->id);
		temp=temp->next;
		printf("\n\n");
	}
}

void merge()
{
	last->next=head1; //no more warning
}

void main()
{
    int ch;
	while(ch!=8)
	{
	printf("\n1. Insert at first (1)\n");
	printf("2. Delete from first (1)\n");
	printf("3. Print (1)\n");
	printf("4. Insert at first (2)\n");
	printf("5. Delete from first (2)\n");
	printf("6. Print (2)\n");
	printf("7. Merge (1) with (2)\n");
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
			prnt();
			break;
		case 4:
			insert_first_1();
			break;
		case 5:
			del_first_1();
			break;
		case 6:
			prnt_1();
			break;
		case 7:
			merge();
			break;
		case 8:
			return;
		default:
			printf("Enter from the given options\n");
	}
	}
}
