#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        void insert(Node*& head, int data){
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = head;
            head = new_node;
            return;
        }
        void reverse(Node *& head){
            if(head==NULL)
                return;
            Node* current = head;
            Node* prev = NULL;
            Node* temp = current->next;
            while(current){
                temp = current->next;
                current->next = prev;
                prev = current;
                head = prev;
                current = temp;
            }
        }
        void displayList(Node*& head){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
int main(){
    Node* head = NULL;
    head->insert(head,5);
    head->insert(head,15);
    head->insert(head,25);
    head->insert(head,35);
    head->insert(head,45);
    head->insert(head,55);
    cout<<"Linked List: ";
    head->displayList(head);
    head->reverse(head);
    cout<<"Reversed Linked List: ";
    head->displayList(head);
    return 0;
}