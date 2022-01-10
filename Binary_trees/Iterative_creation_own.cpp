#include <iostream>
#include <string.h>
using namespace std;
#define size 100

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
class stack
{
    int top;
    Node* a[size];

    public:
    stack()
    {
        top=-1;
    }

    bool isFull()
    {
        return top==size-1;
    }
    bool isEmpty()
    {
        return top==-1;
    }
    void push(Node* x)
    {
        if (isFull())
        {
            cout<<"STACK OVERFLOW !!!"<<endl;
        }
        else
        {
            a[++top]= x;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"STACK UNDERFLOW !!!"<<endl;
        }
        else
        {
                top--;
        }
    }
    Node* getTop()
    {
        return a[top];
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"STACK UNDERFLOW !!!"<<endl;
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }


};
class BinaryTree
{
public:
    Node *root = NULL;
    Node *temp = NULL;

    Node *create()
    {
        int x,cnt;
        stack s;
        cout<<"Enter root node : "<<endl;
        cin >> x;
        Node* newNode= new Node(x);
        s.push(newNode);
        root= newNode;
        int f=0;


            while(true)
            {
            cout<<"Enter left node of "<<s.getTop()->data <<" : "<<endl;
            cin>>x;
            if(x==-1)
            {
                while(true)
                {
                cout<<"Enter right node of "<<s.getTop()->data<<" : "<<endl;
                cin>>x;
                if(x==-1)
                {
                    s.pop();
                    if(s.getTop()->right==NULL)
                    {
                    continue;
                    }
                    else
                    {
                        while(s.getTop()!=NULL)
                        {
                        s.pop();
                        if(s.isEmpty())
                        {
                            f=1;
                        }
                        }
                        continue;
                    }

                }
                newNode= new Node(x);
                s.getTop()->right= newNode;
                s.push(newNode);
                break;
                }
                continue;
            }
                newNode= new Node(x);
                s.getTop()->left= newNode;
                s.push(newNode);

                if(f==1)
                {
                    break;
                }

            }
        
        return root;
        
        
        
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
