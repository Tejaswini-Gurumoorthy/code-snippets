#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    
    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
    Node *head, *top,*newNode;
    public:
    LinkedList()
    {
        head=NULL;
        top=NULL;
    }
    void push(int x)
    {
        newNode = new Node(x);
        if(head==NULL)
        {
            head=newNode;
            top=newNode;
            return;
        }
        newNode->next=top;
        top= newNode;
    }
    int getTop()
    {
        return top->data;
    }
    void pop()
    {
        top= top->next;
        delete newNode;

    }
    void print()
    {
        Node *temp = top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
LinkedList l;
l.push(1);
l.push(2);
l.push(3);
l.push(4);
l.push(5);
l.print();
cout<<l.getTop()<<endl;
l.pop();
l.print();

}
