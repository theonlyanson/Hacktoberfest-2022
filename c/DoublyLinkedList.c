#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
}*stdnode;
void InsertAtStart(){
     

    printf("Enter data of new node: ");
    struct node *new =(struct node*)malloc(sizeof(struct node));
    scanf("%d",&(new->data));
 
        new->right = stdnode;
        stdnode=new; 
}
void InsertNode(int pos,int len){
    struct node *temp = stdnode;
    struct node *new =(struct node*)malloc(sizeof(struct node));
    printf("Enter data of new node: ");
    scanf("%d",&(new->data));
     if(pos==len){
        int i;
        for(i=1;i<len;i++){
            temp=temp->right;
        }
        new->right=NULL;
        temp->right=new;
    }
    else{
        int i;
        for(int i=1;i<pos;i++){
            temp=temp->right;
        }
        new->right = temp->right;
        temp->right=new;
        temp->right->left = new;
        new->left = temp;
    }
}
void Update(int pos, int len){
    struct node *temp = stdnode;
    struct node *prev = stdnode;
    int i;
    for(i=1;i<len;i++){
        prev = temp;
        temp=temp->right;
    }
    int newdata;
    printf("Enter new data: ");
    scanf("%d",&newdata);
    prev->data = newdata;
}
void DeleteNode(int pos, int len){
    struct node *temp = stdnode;
    struct node *prev = stdnode;
    if(pos==1){
        stdnode=stdnode->right;
    }
    else{
        int i;
        for(i=1;i<pos;i++){
            prev=temp;
            temp = temp -> right;
        } 
        prev->right = temp ->right;
        free(temp);
        
    }
}
int main(){
  stdnode=(struct node*)malloc(sizeof(struct node*));
  int n;
  printf("Enter number of nodes: \n");
  scanf("%d",&n);
  printf("Enter data of node 1: \n");
  scanf("%d",&(stdnode->data));
  int i;
  struct node *head = stdnode;
  struct node *temp = stdnode;
  for(i=2;i<=n;i++){ 
    struct node *new = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of node %d:\n",i);
    scanf("%d",&(new->data));
    new->right=NULL;
    
    temp->right = new;
    new->left=temp;
    temp=temp->right;
    
} 
  int choice;
  while(choice!=3){
  printf("Enter 0 for insertion, 1 for deletion, 2 for updation, 3 to exit \n");
  int pos;
  
  scanf("%d",&choice);
  switch(choice){
    case 0: 
     printf("Enter pos of node to be updated ");

     scanf("%d",&pos);
     if(pos==0){
        InsertAtStart();
     }
     else{
     InsertNode(pos,n);
     }
     break;
    case 1:
    printf("Enter pos of node to be deleted ");

    scanf("%d",&pos);
    DeleteNode(pos,n); 
    break;
    case 2:
    printf("Enter pos of node to be updated ");

    scanf("%d",&pos);
    Update(pos,n);
    break;
 }
  }
  printf("Data: \n");
  struct node *print = stdnode;
  while(print!=NULL){
    printf("%d\n",(print->data));
    print=print->right;
  }
}