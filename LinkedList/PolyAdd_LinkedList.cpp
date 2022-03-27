#include <iostream>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;

    Node(int c, int e)
    {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

class LinkedList
{
    Node *head = NULL;

public:
    Node *getPoly()
    {
        Node *temp = NULL;
        cout << "Enter the polynomial : " << endl;
        cout << "(Enter 0 if your polynomial has ended)" << endl;
        int i = 1;
        int c, e;
        while (true)
        {
            cout << "Term " << i << " : " << endl;
            cout << "Coeffecient : ";
            cin >> c;
            if (c == 0)
            {
                break;
            }
            cout << endl;
            cout << "Power : ";
            cin >> e;
            cout << endl;
            Node *newNode = new Node(c, e);

            if (head == NULL)
            {
                head = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
            i++;
        }
        return head;
    }

    Node *addPoly(Node *h1, Node *h2)
    {
        int coeffecient, power;
        Node *t1 = h1, *t2 = h2, *temp = NULL;
        head = NULL;

        while (t1 != NULL && t2 != NULL)
        {
            if (t1 == NULL)
            {
                while (t2 != NULL)
                {
                    coeffecient = t2->coeff;
                    power = t2->exp;
                    t2 = t2->next;
                }
            }
            else if (t2 == NULL)
            {
                while (t1 != NULL)
                {
                    {
                        coeffecient = t1->coeff;
                        power = t1->exp;
                        t1 = t1->next;
                    }
                }
            }
            else
            {
                if (t1->exp == t2->exp)
                {
                    coeffecient = t1->coeff + t2->coeff;
                    power = t1->exp;
                    t1 = t1->next;
                    t2 = t2->next;
                }
                else if (t1->exp > t2->exp)
                {
                    coeffecient = t1->coeff;
                    power = t1->exp;
                    t1 = t1->next;
                }
                else if (t1->exp < t2->exp)
                {
                    coeffecient = t2->coeff;
                    power = t2->exp;
                    t2 = t2->next;
                }
            }
            Node *newNode = new Node(coeffecient, power);
            if (head == NULL)
            {
                head = newNode;
                temp = head;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
        }

        return head;
    }
    void dispPoly(Node *h)
    {
        Node *temp = h;
        while (temp != NULL)
        {
            cout << temp->coeff << "x ^ " << temp->exp;
            temp = temp->next;
            if (temp == NULL)
            {
                break;
            }
            cout << " + ";
        }
        cout << endl;
    }
};
int main()
{
    LinkedList l1, l2, l;
    Node *h1, *h2, *h;
    h1 = l1.getPoly();
    h2 = l2.getPoly();
    cout << "The first polynomial is : " << endl;
    l1.dispPoly(h1);
    cout << "The second polynomial is : " << endl;
    l2.dispPoly(h2);
    h = l.addPoly(h1, h2);
    cout << "Polynomial after addition is : " << endl;
    l.dispPoly(h);
}
