#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    
    Node()
    {
        data=0;
        next=NULL;
        prev= NULL;

    }
    Node(int x)
    {
        data = x;
        next = NULL;
        prev= NULL;
    }
};

class LinkedList
{
    Node *head,*tail;
    public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void insertAtEnd(int x)
    {
        Node *newNode = new Node(x);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        Node *temp= head;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next= newNode;
        newNode->prev=temp;
        temp=newNode;
        tail=newNode;

    }
    void printFromBeg()
    {
        Node *temp= head;
        if(head==NULL)
        {
            cout<<"NO ELEMENTS FOUND!"<<endl;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void printFromEnd()
    {
        Node *temp= tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;

    }
    
};
int main()
{
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.printFromBeg();
    l.printFromEnd();
}
