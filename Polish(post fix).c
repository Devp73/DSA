#include<stdio.h>
char s[10];
int top=-1;
void push(char c)
{
	s[++top]=c;
}

char pop()
{
	if(top==-1)
		return -1;
	else
		return s[top--];
}

int priority(char c)
{
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
}

void main()
{
	char exp[10], *e;
	printf("Enter INFIX notation: ");
	scanf("%s",exp);
	e=exp;
	printf("POSTFIX notation: ");
	while(*e!='\0')
	{
		if(isalnum(*e)) //print if its operand
			printf("%c",*e);
		else
		{
			while(priority(s[top]) >= priority(*e))
				printf("%c", pop()); //remove same or higher priority operator/s
			push(*e);
		}
		e++; //goto next char
	}
	while(top!=-1) //empty the stack at last if any operators are +nt
		printf("%c",pop());
}
