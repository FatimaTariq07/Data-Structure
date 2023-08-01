#include <iostream>
using namespace std;
const int size = 10;
struct DeleteArray
{
    int array1[size];
    int length;
};
void DeleteData(DeleteArray *ptr, int index)
{
    if (index >= 0 && index <= ptr->length)
    {
        for (int i = index; i < ptr->length; i++)
        {
            ptr->array1[i] = ptr->array1[i + 1];
        }
        ptr->array1[ptr->length--];
    }
}
void PrintArray(DeleteArray *ptr)
{
    for (int i = 0; i < ptr->length; i++)
    {
        cout << ptr->array1[i] << " ";
    }
}
int main()
{
    DeleteArray obj;
    cout << "Enter length of array: ";
    cin >> obj.length;
    for (int i = 0; i < obj.length; i++)
    {
        cout << "Enter element [" << i << "]: ";
        cin >> obj.array1[i];
    }
    DeleteData(&obj, 2);
    cout << endl;
    cout << "-----------------------------------------------";
    PrintArray(&obj);
}