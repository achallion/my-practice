#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void eat()
    {
        cout << "I am eating generic food.\n";
    }
};

class Cat : public Animal
{
public:
    void eat()
    {
        cout << "I am eating Rat.\n";
    }
};

class Dog : public Animal
{
public:
    void eat()
    {
        cout << "I am eating Chicken.\n";
    }
};

void function(Animal &ptr)
{
    ptr.eat();
}

int main()
{
    Dog d;
    Cat c;
    function(c);
    return 0;
}