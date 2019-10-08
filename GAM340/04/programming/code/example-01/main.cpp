#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Vector
{
    float x;
    float y;
};

Vector* Vector_Set(Vector* pResult, float x, float y)
{
    pResult->x = x;
    pResult->y = y;

    return pResult;
}

Vector* Vector_Add(Vector* pResult, Vector* pInA, Vector* pInB)
{
    pResult->x = pInA->x + pInB->x;
    pResult->y = pInA->y + pInB->y;

    return pResult;
}

void Vector_Print(Vector* pVec)
{
    printf("%f:%f\n", pVec->x,pVec->y);
}

int main(void)
{
    Vector vecA;
    Vector vecB;
    Vector vecC;

    Vector_Set(&vecA,10,0);
    Vector_Set(&vecB,0,10);

    Vector_Add(&vecC,&vecA,&vecB);

    Vector_Print(&vecC);
    printf("Vector %d vector ptr %d\n", sizeof(Vector), sizeof(Vector*));
}