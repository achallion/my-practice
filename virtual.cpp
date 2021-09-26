#include <iostream>

using namespace std;

class mybase
{
public:
    void show()
    {
        cout << "Base Class Show Function Called \n";
    }

    virtual void print()
    {
        cout << "Base Class Print Function Called \n";
    }
};

class derived : public mybase
{
public:
    void show()
    {
        cout << "Derived Class Show Function Called \n";
    }

    void print()
    {
        cout << "Derived Class Print Function Called \n";
    }
};

int main()
{
    mybase *b;
    derived d;
    b = &d;
    b->show();
    b->print();
    d.show();
    d.print();
}