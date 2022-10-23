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

        bool search(Node *& head, int key){
            if(head == NULL){
                cout<<"Empty list"<<endl;
                return false;
            }
            Node* temp = head;
            while(temp != NULL){
                if(temp->data==key){
                    return true;
                    break;
                }
                temp= temp->next;
            }
            return false;
        }

        void display(Node*& head){
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
    int key;
    cout<<"Enter the key to be searched: ";
    cin>>key;
    head->insert(head, 10);
    head->insert(head, 12);
    head->insert(head, 9);
    head->insert(head, 1);
    head->insert(head, 16);
    head->insert(head, 19);
    head->display(head);

    if(head->search(head,key))
        cout<<key<<" is present.\n";
    else
        cout<<key<<" is not found.\n";
    return 0;
}