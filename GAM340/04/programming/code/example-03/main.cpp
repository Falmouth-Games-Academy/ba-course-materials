#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class GameObject
{
public:
    GameObject()
    {
        ID = masterID++;
    }

    virtual void DebugPrint()
    {
        printf("ID: %d\n",ID);
    }
protected:
    int ID;
private:
    static int masterID;

};

//This isn't C#, so static initialisation needs to occur manually.
int GameObject::masterID = 0;

class Vector : public GameObject
{
public:
    Vector() : GameObject()
    {

    }

    Vector(float x, float y) : GameObject()
    {
        this->x = x;
        this->y = y;
    }

    Vector* Set(float x, float y)
    {
        this->x = x;
        this->y = y;

        return this;
    }

    Vector* Set(Vector* pIn)
    {
        this->x = pIn->x;
        this->y = pIn->y;

        return this;
    }

    Vector* Add(Vector* pInA)
    {
        this->x += pInA->x;
        this->y += pInA->y;

        return this;
    }

    void DebugPrint()
    {
        GameObject::DebugPrint();
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

    vecA.DebugPrint();

}