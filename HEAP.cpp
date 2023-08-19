#include <iostream>
using namespace std;
const int SIZE = 10;
class Heap
{
private:
    int Array[SIZE];
    int length;

public:
    Heap()
    {
        length = 0;
    }
    int GetParentNode(int index)
    {
        return (index - 1) / 2;
    }
    //MAX HEAP
    void CmpMaxHeap(int index)
    {
        if (index == 0)
        {
            return;
        }
        else
        {
            int ParentIndex = GetParentNode(index);
            if (Array[index] > Array[ParentIndex])
            {
                swap(Array[index], Array[ParentIndex]);
                CmpMaxHeap(ParentIndex);
            }
        }
    }
    void InsertMaxData(int data)
    {
        if (length == SIZE)
        {
            cout << "Heap memory is full!" << endl;
            return;
        }
        else
        {
            Array[length] = data;
            CmpMaxHeap(length);
            length++;
        }
    }
    //Min heap
    void CmpMinHeap(int index)
    {
        if (index == 0)
        {
            return;
        }
        else
        {
            int Pindex = GetParentNode(index);
            if (Array[index] < Array[Pindex])
            {
                swap(Array[index], Array[Pindex]);
                CmpMinHeap(Pindex);
            }
        }
    }
    void InsertMinHeap(int data)
    {
        if (length == SIZE)
        {
            cout << "Heap memory is full!" << endl;
            return;
        }
        else
        {
            Array[length] = data;
            CmpMinHeap(length);
            length++;
        }
    }
    void Display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << Array[i] << " ";
        }
    }
};
int main()
{
    Heap hp;
    hp.InsertMaxData(10);
    hp.InsertMaxData(20);
    hp.InsertMaxData(30);
    hp.InsertMaxData(25);
    hp.InsertMaxData(5);
    hp.InsertMaxData(40);
    hp.InsertMaxData(35);
    hp.Display();
}