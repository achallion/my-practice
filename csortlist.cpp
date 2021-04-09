#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

node *f = NULL, *b = NULL;
void pushback(int val)
{
    node *temp = new node;
    temp->next = NULL;
    temp->val = val;

    if (f == NULL && b == NULL)
    {
        f = b = temp;
        return;
    }

    b->next = temp;
    b = temp;
}
void pushback(node *&f, node *&b, int val)
{
    node *temp = new node;
    temp->next = NULL;
    temp->val = val;

    if (f == NULL && b == NULL)
        f = b = temp;

    b->next = temp;
    b = temp;
}
void clearlist(node *f)
{
    while (f != NULL)
    {
        node *temp = f;
        f = f->next;
        delete temp;
    }
}

void merge(node *&f1, node *&f2)
{
    node *h1 = f1, *h2 = f2;
    node *f3 = NULL;
    node *b3 = NULL;

    while (h1 != NULL && h2 != NULL)
    {
        node *temp = new node;
        temp->next = NULL;

        if (h1->val <= h2->val)
        {
            pushback(f3, b3, h1->val);
            h1 = h1->next;
        }
        else
        {
            pushback(f3, b3, h2->val);
            h2 = h2->next;
        }
    }

    while (h1 != NULL)
    {
        node *temp = new node;
        temp->next = NULL;
        pushback(f3, b3, h1->val);
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        node *temp = new node;
        temp->next = NULL;
        pushback(f3, b3, h2->val);
        h2 = h2->next;
    }

    clearlist(f2);
    clearlist(f1);
    f1 = f3;
}

void mergesort(node **front)
{
    // basecase for 1 or 2 elements
    if ((*front)->next == NULL) // 1 element
        return;
    if (((*front)->next)->next == NULL) // 2 elements
    {
        int small = min((*front)->val, (*front)->next->val);
        int large = max((*front)->val, (*front)->next->val);
        (*front)->val = small;
        (*front)->next->val = large;
        return;
    }
    // else

    // find f1 and f2
    node *s = *front, *f = *front;
    while (f != NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
    }

    node *f2 = s->next;
    s->next = NULL;
    // merge sort f1 and f2
    mergesort(front);
    mergesort(&f2);
    // merge sorted lists
    merge(*front, f2);
}

int arr[] = {231,124,623};
int n = sizeof(arr) / sizeof(int);

int main()
{
    for (int i = 0; i < n; i++)
        pushback(arr[i]);
    if (n > 1)
        mergesort(&f);

    node *temp = f;
    while (f != NULL)
    {
        cout << f->val << " ";
        f = f->next;
    }
    f = temp;
    cout << "\n";
    clearlist(f);
    return 0;
}