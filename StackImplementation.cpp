#include<iostream>
using namespace std;
const int Size=10;
class Stack{

	private:
		int Top;
		int StackArray[Size];
	
	public:
		Stack()
		{
			Top=0;
			cout<<"Your Stack is created"<<endl;
		}
		bool IsEmpty()
		{
			if(Top==0){
				return true;
			}
			else
			{
				return false;
			}
		}
		bool IsFull()
	{
		if(Top==Size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Push(int element)
	{
		if(IsFull()==true)
		{
			cout<<"There is no space in stack";
		}
		else
		{
			StackArray[Top++]=element;
		}
	}
	void Pop()
	{
		if(IsEmpty()==true)
		{
			cout<<"There is no element in stack";
		}
		else
		{
			Top--;
		}
	}
	int TopSize()
	{
		return Top;
	}
	void Binary(int element)
	{
		while(element>0)
		{
			int remainder=element%2;
			Push(remainder);
			element = element/2;
		}
	}
	void Display()
	{
		if(Top==0)
		{
			cout<<"No element in stack";
		}
		else
		{
			for(int i=TopSize()-1;i>=0;i--)
			{
				cout<<StackArray[i]<<" ";
			}
		}
	}
};
int main()
{
Stack stk;
stk.Binary(50);
//int choice;
//int element;
//for(int i=0;i<Size;i++)
//{
//cout<<"Enter 1 to insert data , Enter 2 to delete data\nEnter 3 For Top value\n Enter 4 to Exit  ";
//cin>>choice;	
//switch(choice)
//{
//	case 1:
//	cout<<"Enter element to insert ";
//	cin>>element;
//		stk.Push(element);
//		break;
//	case 2:
//		stk.Pop();
//		break;
//	case 3:
//		cout<<"Top Size is "<<stk.TopSize()<<endl;
//		break;
//	default:
//		cout<<"Exit";
//}
//}
stk.Display();
}