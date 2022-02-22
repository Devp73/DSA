#include<stdio.h>
int f=-1,r=-1,q[10];
int size=4;
void ins()
{
	if(f==-1)
		f=r=0;
	if(r>=size)
		printf("Queue is full");
	else
		printf("Enter value to insert: ");
		scanf("%d",&q[r++]); //keeping r value ahead from f
}

void del()
{
	if(f>=r)
	{
		printf("Queue is empty");
		f=r=-1; //reset queue
	}
	else
		printf("Removed: %d",q[f++]);
}

void print()
{
	int i;
	for(i=f;i<r;i++)
	{
		printf("%d ",q[i]);
	}
}

void main()
{
	int ch,n;
	while(ch!=4)
	{
	printf("\n1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print Queue\n");
	printf("4. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			ins();
			break;
		case 2:
			del();
			break;
		case 3:
			print();
			break;
		case 4:
			return;
		default:
			printf("Enter from the given options");
	}
	}
}
