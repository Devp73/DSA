#include<stdio.h>
int arr[10],top=-1;
int size=4;
void push()
{
	if(top>=size-1)
		printf("\nStack Overflow");
	else
	{
		printf("Enter value to push: ");
		scanf("%d",&arr[++top]); //push the value to the top
	}
}

void pop()
{
	if(top<0)
	printf("\nStack Underflow");
	else
		printf("\nRemoved: %d\n",arr[top--]);
}

void print()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
}

void main()
{
	int ch,n;
	while(ch!=4)
	{
	printf("\n1. Push\n");
	printf("2. Pop\n");
	printf("3. Print stack\n");
	printf("4. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			push();
			break;
		case 2:
			pop();
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
