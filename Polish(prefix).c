#include<stdio.h>
#include<string.h>
char s[10]; //to store the operators
int top=-1; //for indexing of string "s"
char ans[10]; //to store the answer and at last it will be reversed
int x=0; //for indexing of ans
void push1(char c) //store the value in array
{
	ans[x++]=c; //x will be incremented after the assignment
}

void prt()
{
	printf("%s", strrev(ans)); //print the reverse of the string
}

void reverse(char exp[]) //function to reverse the string of the notation
{
	exp=strrev(exp);
}

void push(char c) //store the operator
{
	s[++top]=c; //top will be incremented first and then assigned
}

char pop() //pop from the stack
{
	if(top==-1)
		return -1;
	else
		return s[top--]; //top will decremented after returning the value
}

int priority(char c) //to check the priority of the operators
{
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
}

void main()
{
	char exp[10], *e; 
	printf("Enter INFIX notation = ");
	scanf("%s",exp);
	reverse(exp);
	e=exp; //assign the value to the pointer after reversing the notation(string)
	printf("PREFIX notation: ");
	while(*e!='\0')
	{
		if(isalnum(*e)) //if operand direct push in the ans string
		   push1(*e);
		else
		{
			while(priority(s[top])>priority(*e)) //check priority
				push1(pop()); //push the operand in ans string
			push(*e); //push the operand in stack "s"
		}
		e++; //proceed to next charector
	}
	while(top!=-1)
	{
		push1(pop()); //empty the stack
	}
	prt(); //finally print the output
}
