#include <iostream>
using namespace std;
class LinkList1
{
private:
    int data;
    LinkList1 *NextAddress;
    LinkList1 *CurrentLocation;

public:
    LinkList1()
    {
        CurrentLocation = NULL;
    }
    void InsertData(int data)
    {
        LinkList1 *NewNode = new LinkList1();
        NewNode->data = data;
        NewNode->NextAddress = NULL;
        LinkList1 *TempNode = CurrentLocation;
        if (TempNode != NULL)
        {
            while (TempNode->NextAddress != NULL)
            {
                TempNode = TempNode->NextAddress;
            }
            TempNode->NextAddress = NewNode;
        }
        else
        {
            CurrentLocation = NewNode;
        }
    }
    void printList()
    {
        LinkList1 *newPtr = CurrentLocation;
        while (newPtr != NULL)
        {
            cout << newPtr->data << " ";
            newPtr = newPtr->NextAddress;
        }
    }
};

int main()
{
    LinkList1 object;
    object.InsertData(10);
    object.InsertData(100);
    object.InsertData(20);
    object.InsertData(200);
    object.InsertData(30);
    object.printList();
}
