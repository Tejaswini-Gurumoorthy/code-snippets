#include <iostream>
using namespace std;
#define size 100

class stack
{
    int top;
    int a[size];

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
    void push(int x)
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
