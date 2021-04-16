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

node *find(list &l, int val)
{
    node *it = l.front;
    while (it != NULL)
    {
        if (it->val == val)
            return it;
        it = it->next;
    }
    return NULL;
}

bool iscycle(list &l)
{
    node *s = l.front, *f = l.front->next;
    while (f != NULL && f->next != NULL)
    {
        if (s == f)
            return true;
        s = s->next;
        f = f->next->next;
    };
    return false;
}

int cyclelen(list &l)
{
    node *s, *f;
    s = l.front;
    f = l.front->next;
    while (f != NULL && f->next != NULL)
    {
        if (s == f)
            break;
        s = s->next;
        f = f->next->next;
    }
    if (f == NULL || f->next == NULL)
        return 0;

    // finding len now
    int count = 0;
    do
    {
        f = f->next;
        count++;
    } while (f != s);
    return count;
}

node *cstart(list &l, int clen)
{
    node *p1, *p2;
    p1 = l.front;
    p2 = l.front;
    int cnt = clen;
    while (cnt > 0)
    {
        p2 = p2->next;
        cnt--;
    }

    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

int main()
{
    list l;
    push(l, 1);
    push(l, 2);
    push(l, 3);
    push(l, 4);
    push(l, 5);
    push(l, 6);
    push(l, 7);
    push(l, 8);
    push(l, 9);
    l.back->next = find(l, 4);
    if (iscycle(l))
    {
        int len = cyclelen(l);
        cout << "\nLength of cycle : " << len;
        cout << "\nCycle Start at : " << cstart(l, len)->val;
    }
    return 0;
}