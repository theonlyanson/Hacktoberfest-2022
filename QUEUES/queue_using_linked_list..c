#include<stdio.h>
#include<stdlib.h>
struct node * f = NULL;
struct node * r = NULL;
struct node {
    int data;
    struct node * next;
};

void enqueue(int value){
    struct node * n = (struct node * )malloc(sizeof(struct node));
    if(n==NULL){
        printf("queue is full \n");
    }
    else{
            n->data = value;
            n->next = NULL;
            if(f==NULL){
                f = r = n;
            }
            else{
                r->next = n;
                r = n;
            }
    }
}
int dequeue(){
    int value  = -1;
    struct node * ptr;
    if(f==NULL){
        printf("queue is full \n");
        return -1;
    }
    else{

        f = f->next;
        value = ptr->data;
        free(ptr);
        return value;
    }
}

void traversal(struct node * ptr  ){
    printf("PRINTING THE ELEMENT OF THE LINKED LIST \n");
    while(ptr!=NULL){
        printf("element  : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    printf("DEQUEUEING ELEMENT : %d\n", dequeue());
    enqueue(13);
    enqueue(4);
    enqueue(7);
    enqueue(9);
    traversal(f);
    printf("DEQUEUEING ELEMENT : %d\n", dequeue());
    printf("DEQUEUEING ELEMENT : %d\n", dequeue());
    traversal(f);


    return 0;
}
