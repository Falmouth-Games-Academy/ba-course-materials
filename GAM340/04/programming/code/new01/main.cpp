#include <stdio.h>

class Vector
{
public:
    float x;
    float y;
    Vector()
    {
        printf("Vector ctor()\n");
    }

    Vector(float x, float y)
    {
        printf("Vector ctor(x,y)\n");
        this->x = x;
        this->y = y;
    }

    ~Vector()
    {
        printf("Vector dtor()\n");
    }

    Vector operator + (const Vector& a)
    {
        Vector result;
        result.x = this->x + a.x;
        result.y = this->y + a.y;

        return result;

    }

    Vector operator * (float f)
    {
        Vector result;
        result.x = this->x *f;
        result.y = this->y *f;

        return result;

    }

    void operator *= (float f)
    {
        this->x *=f;
        this->y *=f;
    }
};

int main()
{
    Vector A;

    printf("do some maths\n");

    A = Vector(1,1) + Vector(2,2) + Vector(3,3) + Vector(4,4);

    A *= 4;

    Vector* B = new Vector(10,1);
    Vector* C = new Vector(2,4);

    A = (*B+ *C)*3;

    return 0;
}
