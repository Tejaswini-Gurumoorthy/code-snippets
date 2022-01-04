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
    public:
    int top;
    Node* a[size];


    stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(Node *x)
    {
        if (isFull())
        {
            cout << "STACK OVERFLOW !!!" << endl;
        }
        else
        {
            a[++top] = x;
        }
    }
    Node *pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW !!!" << endl;
            return NULL;
        }
        else
        {
            return a[top--];
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW !!!" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
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
        while (true)
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
    }
    void InorderDisplay(Node *root)
    {

        Node *temp = root;
        stack stk;

        if (root == NULL)
        {
            return;
        }

        while ((temp != NULL) || (!stk.isEmpty()))
        {
            while (temp != NULL)
            {
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    void PreorderDisplay(Node *root)
    {
        Node *temp = root;
        stack stk;

        if (root == NULL)
        {
            return;
        }

        stk.push(temp);
        while (!stk.isEmpty())
        {
            temp = stk.pop();
            cout << temp->data << " ";
            if (temp->right != NULL)
            {
                stk.push(temp->right);
            }
            if (temp->left != NULL)
            {
                stk.push(temp->left);
            }
        }
    }
    void PostorderDisplay(Node *root)
    {
        stack stk1,stk2;
        Node *temp = root;

        if (root == NULL)
        {
            return;
        }

        stk1.push(root);
        while (!stk1.isEmpty())
        {
            temp = stk1.pop();
            stk2.push(temp);
        }
            stk1.push(temp->left);
        
            stk1.push(temp->right);

        while (!stk2.isEmpty())
        {
            temp = stk2.pop();
            cout << temp->data << " ";
        }
    }
};
int main()
{
    BinaryTree b;
    cout << "value : " << endl;
    Node *root = b.create();
    cout << endl
         << "Inorder Traversal : ";
    b.InorderDisplay(root);
    cout << endl
         
         << "Preorder Traversal : ";
    b.PreorderDisplay(root);
    cout << endl
    << "Postder Traversal : ";
    b.PostorderDisplay(root);
    cout << endl;
}

//inorder
// 1) Create an empty stack S.
// 2) Initialize current node as root
// 3) Push the current node to S and set current = current->left until current is NULL
// 4) If current is NULL and stack is not empty then
//      a) Pop the top item from stack.
//      b) Print the popped item, set current = popped_item->right
//      c) Go to step 3.
// 5) If current is NULL and stack is empty then we are done.

// Preorder traversal.
// 1) Create an empty stack nodeStack and push root node to stack.
// 2) Do the following while nodeStack is not empty.
// ….a) Pop an item from the stack and print it.
// ….b) Push right child of a popped item to stack
// ….c) Push left child of a popped item to stack

// iterativePostorder(node)


// 1. Push root to first stack.
// 2. Loop while first stack is not empty
//    2.1 Pop a node from first stack and push it to second stack
//    2.2 Push left and right children of the popped node to first stack
// 3. Print contents of second stack
