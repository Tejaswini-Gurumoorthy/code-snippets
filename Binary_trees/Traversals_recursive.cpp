#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree
{
public:
    Node *root = NULL;
    Node *temp = NULL;

    Node *create()
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            return NULL;
        }
        Node *newNode = new Node(x);
        cout << "Value of left node of " << x << " - ";
        newNode->left = create();

        cout << "Value of right node of " << x << " - ";
        newNode->right = create();

        return newNode;
    }
    void InorderDisplay(Node *root)
    {
       
        if (root == NULL)
        {
            return;
        }
            InorderDisplay(root->left);
            cout << root->data << " ";
            InorderDisplay(root->right);
        
    }
    void PreorderDisplay(Node *root)
    {
        
        if (root == NULL)
        {
            return;
        }
            
            cout << root->data << " ";
            PreorderDisplay(root->left);
            PreorderDisplay(root->right);
        
    }
     void PostorderDisplay(Node *root)
    {
        
        if (root == NULL)
        {
            return;
        }
            
            PostorderDisplay(root->left);
            PostorderDisplay(root->right);
            cout << root->data << " ";
            
            
        
    }
};
int main()
{
    BinaryTree b;
    cout << "value : " << endl;
    Node *root= b.create();
     cout<<endl<<"Inorder Traversal : ";
    b.InorderDisplay(root);
    cout<<endl<<"Postder Traversal : ";
    b.PostorderDisplay(root);
    cout<<endl<<"Preorder Traversal : ";
    b.PreorderDisplay(root);
    cout<<endl;
}
