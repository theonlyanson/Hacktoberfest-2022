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
                void deleteBeginning(Node*& head){
            if(head == NULL)
                return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void deleteEnd(Node*& head){
            if(head == NULL)
                return;
            Node* temp = head;
            Node* end = NULL;
            while(temp->next){
                end = temp;
                temp = temp->next;
            }
            end->next = NULL;
            delete temp;
        }
        void deleteSpecific(Node*& head, int position){
            Node* temp = head;
            Node* prev = head;
            for(int i=0;i<position;i++){
                if(i==0 && position ==1)
                    deleteBeginning(head);
                else{
                    if(i== position - 1 && temp){
                        prev->next = temp->next;
                        delete temp;
                    }
                    else{
                        prev = temp;
                        if(prev == NULL)
                            break;
                        temp = temp->next;
                    }
                }
            }
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
    head->insert(head,5);
    head->insert(head,10);
    head->insert(head,15);
    head->insert(head,20);
    head->insert(head,25);

    head->deleteBeginning(head);
    head->deleteEnd(head);
    head->deleteSpecific(head,2);
    head->displayList(head);
    return 0;
}
