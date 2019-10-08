#include <stdlib.h>
#include <stdio.h>
#include <string.h>


class Vector
{

public:
    Vector* Set(float x, float y)
    {
        this->x = x;
        this->y = y;

        return this;
    }

    Vector* Add(Vector* pInA)
    {
        this->x += pInA->x;
        this->y += pInA->y;

        return this;
    }

    void Print()
    {
        printf("%f:%f\n", this->x,this->y);
    }


private:
    float x;
    float y;
};


int main(void)
{
    Vector vecA;
    Vector vecB;
    Vector vecC;

    vecA.Set(10,0);
    vecB.Set(0,10);

    vecA.Add(&vecB);

    vecA.Print();

}