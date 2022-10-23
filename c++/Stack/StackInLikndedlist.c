#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* head=NULL;
void push()
{
	if(head==NULL)
	{ 	head=(struct node*)malloc(sizeof(struct node));
	    printf("Enter the value to be inserted at pushed\n");
	    scanf("%d",&head->data);
	    head->next=NULL;
	}
	else{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted at pushed\n");
	scanf("%d",&temp->data);
	temp->next=head;
	head=temp;	
	}
}

void display()
{   struct node* p=head;
	printf("The Stack is:\n");
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("\n");
}

void pop()
{  
    if(head!=NULL)
   {   struct node *p;
       p=head;
       head=head->next;
	   free(p);
   }
   else{
   	printf("The stack is empty\n");
   }
}

void peek()
{
	printf("The top element of the stack is: %d\n",head->data);
}

int main()
{   int choice,val,itr=1;
printf("1 to push\n2 to pop\n3 to display\n4 to peek\n5 to exit\n\n");
    while(itr)
       { 
        printf("Enter the choice\n");
	    scanf("%d",&choice);
    	switch(choice)
    	{

    		case 1:
    			push();
				break;
			case 2:
			    pop();
				break;
		    case 3:
			    display();
			    break;
			case 4:
			    peek();
			    break;
			case 5:
			    itr=0;
			    break;			    
			default:
				printf("wrong case\n");
				break;
			
							
		}
	}

	return 0;
}
