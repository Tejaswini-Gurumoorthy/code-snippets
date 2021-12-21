#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
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
        head = NULL;
    }
    void insertAtEnd(int x)
    {
        Node *newNode = new Node(x);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtBeg(int x)
    {
        Node *newNode = new Node(x);
        Node *temp = head;
        head = newNode;
        newNode->next = temp;
    }

    void insertBeforeEle(int x, int ele)
    {
        Node *newNode = new Node(ele);
        Node *temp = head;
        Node *tempPrev = NULL;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if ((temp->data == x) && (temp == head))
            {
                insertAtBeg(ele);
            }
            else if (temp->data == x)
            {
                tempPrev->next = newNode;
                newNode->next = temp;
                break;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
    }

    void insertAfterEle(int x, int ele)
    {
        Node *newNode = new Node(ele);
        Node *temp = head;
        Node *tempPrev = temp;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if ((temp->data == x) && (temp == head))
            {
                insertAtBeg(ele);
            }
            else if (tempPrev->data == x)
            {
                tempPrev->next = newNode;
                newNode->next = temp;
                break;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
    }
    void insertAtPos(int x, int pos)
    {
        Node *newNode = new Node(x);
        Node *temp = head;
        Node *tempPrev = NULL;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            tempPrev = temp;
            temp = temp->next;
        }
        tempPrev->next = newNode;
        newNode->next = temp;
    }

    void deleteAtPos(int pos)
    {
        Node *temp = head;
        Node *tempPrev = NULL;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            tempPrev = temp;
            temp = temp->next;
        }
        tempPrev->next = temp->next;
        delete temp;
    }
    void deleteEle(int ele)
    {
        Node *temp = head;
        Node *tempPrev = temp;
        if (head == NULL)
        {
            cout << "NO ELEMENTS FOUND !" << endl;
            return;
        }
        while (temp != NULL)
        {
            if ((temp->data == ele) && (temp == head))
            {
                head = temp->next;
                delete temp;
            }

            else if (temp->data == ele)
            {
                tempPrev->next = temp->next;
                delete temp;
                break;
            }
            else
            {
                tempPrev = temp;
                temp = temp->next;
            }
        }
    }
    void deleteAtEnd()
    {
        Node *temp = head;
        Node *tempPrev = NULL;
        while (temp->next != NULL)
        {
            tempPrev = temp;
            temp = temp->next;
        }
        tempPrev->next = NULL;
        delete temp;
    }

    void print()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data;

            temp = temp->next;
            if (temp == NULL)
            {
                break;
            }
            cout << "->";
        }
        cout << endl;
    }
};
