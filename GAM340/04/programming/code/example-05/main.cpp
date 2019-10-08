#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class BaseClass
{
public:
    BaseClass()
    {
        printf("Base ctor()\n");
    }

    //make this virtual to ensure that the derived dtor() is called
    //this happens if you are instanciating a derived object into a base(r) pointer
    virtual ~BaseClass()
    {
        printf("Base dtor()\n");
    }

    virtual void DoSomething()
    {
        printf("Base DoSomething()\n");
    }
};

class Derived: public BaseClass
{
public:
    Derived(float x)
    {
        printf("Derived ctor()\n");
    }

    ~Derived()
    {
        printf("Derived dtor()\n");
    }

    void DoSomething()
    {
        printf("Derived DoSomething()\n");
    }

    void DoSomething(int i)
    {
        printf("Derived DoSomething(int)\n");
    }
};


int main(void)
{
    BaseClass* pDerived = new Derived(1);

    //this will call the derived fn()
    pDerived->DoSomething();

    //so will this
    ((Derived*)pDerived)->DoSomething(1);

    delete pDerived;


}