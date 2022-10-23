#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct stack
{ int items[10];
  int top; 
};

void createEmptyStack(struct stack *s)
{
   s->top=-1;
}
int isEmpty(struct stack *s)
{
  if(s->top==-1)
  return 0;
  else
  return 1;
}
int isFull(struct stack *s)
{
  if(s->top==9)
  return 0;
  else
  return 1;
}

void push(struct stack *s, int a)
{
  if(isFull(s))
  {
   s->top++;
   s->items[s->top]=a;
   
  }
  else{
    cout<<"Stack is Full\n";
  }
}

void pop(struct stack *s)
{
  if(isEmpty(s))
  {    cout<<"The poped Element is:\n"<<s->items[s->top]<<"\n";
       s->top--;
  }
  else{
  	cout<<"Stack is Empty\n";
  }
} 

void printstack(struct stack *s)
{ cout<<"Stack\n";
  for(int i=0;i<=(s->top);i++)
  cout<<s->items[i]<<" ";
  if(s->top==-1)
  cout<<"Stack is Empty";
  cout<<"\n";
  
}

int main()
{ struct stack s;
  int cmd=1,a;
  here:cin>>cmd;
  switch(cmd)
  {
    case 1 :
      createEmptyStack(&s);
      goto here;
      break;

    case 2 :
      cout<<"Enter the element to push:\n";
      cin>>a;
      push(&s,a);
      goto here;
      break;

    case 3:
      pop(&s);
      goto here;
      break;
     
    case 4:
      printstack(&s);
      goto here;
      break;

    default :
      cout<<"Wrong command\n";
      goto here;
      break; 

  
  }
    return 0;
}