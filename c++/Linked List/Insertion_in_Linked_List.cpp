#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        void insertBeginning(Node*& head, int data){
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = head;
            head = new_node;
            return;
        }
        void insertEnd(Node*& head, int data){
            Node* new_node = new Node();
            Node *temp = head;
            new_node->data = data;
            new_node->next = NULL;

            if(head == NULL){
                head = new_node;
                return;
            }

            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            return;
        }
        void insertAfter(Node* prev_Node, int data){
            if(prev_Node == NULL){
                cout<<"Cannot be NULL\n";
                return;
            }
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = prev_Node->next;
            prev_Node->next = new_node;
            return;
        }
        void displayList(Node*& head){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        
};

int main(){
    Node* head = NULL;
    head->insertEnd(head, 16);
    head->insertBeginning(head,5);
    head->insertBeginning(head, 12);
    head->insertAfter(head->next, 4);
    cout<<"Linked list: ";
    head->displayList(head);
    return 0;
}