#include <iostream>
using namespace std;
#define size 100

class queue
{
    int front;
    int rear;
    int a[size];

    public:
    queue()
    {
        front =-1;
        rear=-1;
    }

    bool isFull()
    {
        return rear==size-1;
    }
    bool isEmpty()
    {
        return front==rear;
    }
    
    void enqueue(int x)
    {
        if (isFull())
        {
            cout<<"QUEUE OVERFLOW !!";
        }
        else if((front ==-1 )&&(rear==-1))
        {
            front++;
            a[++rear]=x;
        }
        else
        {
            a[++rear]=x;
        }
    }

    void dequeue()
    {
        if(front==rear)
        {
            cout<<"QUEUE EMPTY !!!";
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout<<"QUEUE EMPTY !!!"<<endl;
        }

        else
        {
        for(int i=front;i<=rear;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        }
    }

};
