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
    Node *head;
    public:
    LinkedList()
    {
        head=NULL;
    }
    void insert(int x)
    {
        Node *newNode = new Node(x);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        Node *temp= head;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next =newNode;

    }

    void print()
    {
        Node *temp= head;
        if(head==NULL)
        {
            cout<<"The list is empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp= temp->next;
        }
        cout<<endl;

    }
};
int main()
{
    LinkedList l;
    l.print();
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.print();
}
