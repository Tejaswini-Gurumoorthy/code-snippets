#include <iostream>
using namespace std;
#define size 5

class queue
{
    int front;
    int rear;
    int a[size];

public:
    queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return front == (rear + 1) % size;
    }
    bool isEmpty()
    {
        return front == rear;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "QUEUE OVERFLOW !!" << endl;
        }
        else if ((front == -1) && (rear == -1))
        {
            front++;
            a[++rear] = x;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            a[rear] = x;
        }
        else
        {
            a[++rear] = x;
        }
    }

    void dequeue()
    {
        if (front == rear)
        {
            cout << "QUEUE EMPTY !!!";
        }
        else if (front == size - 1)
        {
            front = 0;
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
            cout << "QUEUE EMPTY !!!" << endl;
        }

        else
        {
            if (front < rear)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
            else
            {
                for (int i = front; i < size; i++)
                {
                    cout << a[i] << " ";
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
        }
    }
};
