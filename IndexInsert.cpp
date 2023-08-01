#include <iostream>
using namespace std;
const int size = 10;
struct InsertArray
{
    int array[size];
    int length;
};
void InsertData(InsertArray *ptr, int element, int index)
{
    if (index >= 0 && index < ptr->length)
    {
        for (int i = ptr->length; i >= 0; i--)
        {
            ptr->array[i + 1] = ptr->array[i];
        }
        ptr->array[ptr->length++];
        ptr->array[index] = element;
    }
}
void PrintArray(InsertArray *ptr)
{
    for (int i = 0; i < ptr->length; i++)
    {
        cout << ptr->array[i] << " ";
    }
}
int main()
{
    InsertArray obj;
    cout << "Enter length of array: ";
    cin >> obj.length;
    for (int i = 0; i < obj.length; i++)
    {
        cout << "Enter element [" << i << "] : ";
        cin >> obj.array[i];
    }
    InsertData(&obj, 120, 3);
    cout << "-----------------------------------------";
    PrintArray(&obj);
}