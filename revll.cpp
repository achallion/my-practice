#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
    node()
    {
        val = 0;
        next = NULL;
    }
    node(int a)
    {
        val = a;
        next = NULL;
    }
    node(int a, node *n)
    {
        val = a;
        next = n;
    }
};

struct list
{
    node *front;
    node *back;
    list()
    {
        front = back = NULL;
    }
};

void push(list &a, int val)
{
    node *temp = new node(val);
    if (a.front == NULL && a.back == NULL)
    {
        a.back = temp;
        a.front = temp;
        return;
    }
    a.back->next = temp;
    a.back = temp;
}

void revlist(list &l)
{
    node *temp = l.front;
    node *prev = NULL;
    while (temp != NULL)
    {
        node *temp1 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp1;
    }
    l.front = prev;
}

void print(list &l)
{
    node *temp = l.front;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}

void revpq(list &l, int p, int q)
{
    node *temp = l.front, *temp1 = NULL;
    int n = 1;
    while (n < p)
    {
        n++;
        temp1 = temp;
        temp = temp->next;
    }

    // --------

    node *prev = NULL;
    node *next;
    while (p <= q)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        p++;
    }
    if (temp1 == NULL)
    {
        next = l.front;
        l.front = prev;
    }
    else
    {
        next = temp1->next;
        temp1->next = prev;
    }

    next->next = temp;
}

int main()
{
    list l;
    push(l, 1);
    push(l, 2);
    push(l, 3);
    push(l, 4);
    push(l, 5);
    revpq(l, 1, 2);
    print(l);

    return 0;
}