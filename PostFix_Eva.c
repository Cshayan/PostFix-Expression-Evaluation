#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100


int stack[SIZE];
int top = -1;

void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
int pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();

		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
void postEvaluate(char post[])
{
    char item;
    int i,j, A, B, ans;
    i=0; j=0;

    item= post[i];
    while(item!='\0')
    {
        if(isdigit(item))
      {
        push(item-'0');
      }
      if(is_operator(item)==1)
      {
          A=pop();
          B=pop();

          switch(item)
          {
              case '^':
                  ans=pow(B, A);
                  break;
              case '*':
                ans=B*A;
                break;
              case '/':
                ans=B/A;
                break;
              case '+':
                ans=B+A;
                break;
              case '-':
                ans=B-A;
                break;

          }
          push(ans);
      }


      i++;
      item=post[i];
    }

    printf("\nAns is %d ",pop());

}
int main()
{
    char post[SIZE];
    printf("\nEnter the postfix expression:- ");
    gets(post);
    postEvaluate(post);
}
