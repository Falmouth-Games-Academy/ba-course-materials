#include <iostream>

class Data
{
    public:
        int a;
        int b;
        int c;

        int GetA() const
        {
            return a;
        }
};

class DataHolder
{
private:
    Data* pData;

public:
    DataHolder()
    {
        this->pData =new Data();
    }

    const Data* GetData()
    {
        return pData;
    }

    void UpdateData(const Data* d)
    {
        d->a = 0;
    }
};

int main()
{
    DataHolder DH;

    //DH.GetData()->a = 4;

    DH.UpdateData(DH.GetData());

    DH.GetData()->GetA();

    return 0;
}