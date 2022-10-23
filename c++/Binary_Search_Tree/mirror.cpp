#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    
    cout << root->data <<" ";
    inorder(root->right);
}
Node* mirror(Node* root){
if(root==NULL){
    return root;
}
Node *t = root->left;
root->left=root->right;
root->right =t;
if(root->left){
    mirror(root->left);
}
if(root->right){
mirror(root->right);
}
return root;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
     inorder(root);
     cout<<"\n";
     mirror(root);
     inorder(root);
    return 0;
    }
