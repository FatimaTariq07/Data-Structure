#include <iostream>
using namespace std;
const int Size = 5;
class Queue
{
private:
    int QueueArray[Size];
    int front;
    int back;

public:
    Queue()
    {
        front = -1;
        back = -1;
    }
    bool IsEmpty()
    {
        if (front == back || back == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsFull()
    {
        if (back == Size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Enqueue(int element)
    {
        if (IsFull() == true)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            back++;
            QueueArray[back] = element;
        }
    }
    void Dequeue()
    {
        if (IsEmpty() == true)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            front++;
        }
    }
    void DisplayQueue()
    {
        for (int i = front + 1; i <= back; i++)
        {
            cout << QueueArray[i] << " ";
        }
    }
};
int main()
{
    Queue que;
    int element;
    for (int i = 0; i < Size; i++)
    {
        cout << "Enter element to enter : ";
        cin >> element;
        que.Enqueue(element);
    }
    que.Dequeue();

    //    que.Enqueue(10);
    //    que.Enqueue(20);
    //    que.Enqueue(30);
    //    que.Enqueue(40);
    //    que.Dequeue();
    que.DisplayQueue();
}