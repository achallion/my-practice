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

node *revrec(node *s)
{
    // base
    if (s->next == NULL)
    {
        return s;
    }

    // rec
    node *f = revrec(s->next);
    s->next->next = s;
    s->next = NULL;
    return f;
}

bool ispalin(list &l)
{
    node *s, *f;
    s = l.front;
    f = l.front;
    do
    {
        s = s->next;
        f = f->next->next;
    } while (f != NULL && f->next != NULL);

    if (f != NULL) // odd
        s = s->next;

    s = revrec(s);

    // check palin
    f = l.front;
    while (s != NULL && f->val == s->val)
    {
        s = s->next;
        f = f->next;
    }
    cout << "HERE" << flush;
    if (s == NULL)
        return true;
    return false;
}

int main()
{
    list l;
    push(l, 1);
    push(l, 2);
    push(l, 3);
    push(l, 9);
    push(l, 3);
    push(l, 2);
    push(l, 1);
    cout << ispalin(l);
}