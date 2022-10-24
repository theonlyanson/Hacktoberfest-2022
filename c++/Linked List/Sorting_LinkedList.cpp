#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        void insert(Node*& head, int data){
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
        void display(Node*& head){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        void sort(Node*& head){
            int swapped, i;
            Node *temp;
            Node *ptr = NULL;
            if(head == NULL)
                return;
            do{
                temp = head;
                swapped = 0;
                while(temp->next != ptr){
                    if(temp->data >temp->next->data){
                        int swapp = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = swapp;
                        swapped = 1; 
                    }
                    temp = temp->next;
                }
                ptr = temp;
            }while(swapped);
        }
};
int main(){
    Node* head = NULL;
    head->insert(head, 10);
    head->insert(head, 12);
    head->insert(head, 9);
    head->insert(head, 1);
    head->insert(head, 16);
    head->insert(head, 19);

    cout<<"Before sorting: ";
    head->display(head);
    cout<<"After sorting: ";
    head->sort(head);
    head->display(head);
    return 0;
}