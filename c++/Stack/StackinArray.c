#include<stdio.h>
#include<stdlib.h>
int MAX_SIZE=10;

struct stack{
	int a[10];
	int front,rear;
}st;

void create(struct stack* st)
{
	st->front=0;
	st->rear=-1;
}

void display(struct stack* st)
{   int i;
	printf("The stack is\n");
	for(i=st->front;i<=st->rear;i++)
	{
		printf("%d ",st->a[i]);
	}
	printf("\n");
}

void push(struct stack* st, int val)
{
    if(st->rear>-2&&st->rear<9)
    {   
	    st->rear++;
    	st->a[st->rear]=val;		
	}
	else{
      printf("OVERFLOW\n");
	}
}
void peek(struct stack* st)
{
	if(st->rear==-1)
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("The top element of the stack is: %d\n",st->a[st->rear]);
	}
}
void pop(struct stack* st)
{
	if(st->rear>-1&&st->rear<10)
	{
	   st->rear--;	
	}
	else{
		printf("The stack is empty\n");
	}
}

int main()
{   //struct stack st;
    create(&st);
    push(&st,2);
    push(&st,3);
    push(&st,6);
    push(&st,9);
	display(&st);
	pop(&st);
	display(&st);
	peek(&st);
//	printf("%d,%d",st.a[0],st.a[1]);
	return 0;
}
