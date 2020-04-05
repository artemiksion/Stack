#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>

class Stack
{
private:
	T* DynamicArray;
	int size;
	int capacity;

	void MemoryAllocation()
	{
		try
		{
			capacity = (int)((double)capacity * 1.6);
			T* NewDynamicArray = new T[capacity];
			for (int i = 0; i < size; i++)
				NewDynamicArray[i] = DynamicArray[i];
			delete[] this->DynamicArray;
			this->DynamicArray = NewDynamicArray;
		}
		catch (bad_alloc)
		{
			capacity = (int)((double)capacity / 1.6);
			throw bad_alloc();
		}
	}
public:
	Stack()
	{
		DynamicArray = nullptr;
		capacity = 10;
		DynamicArray = new T[capacity];
		size = 0;
	}
	~Stack()
	{
		delete[] DynamicArray;
	}

	void PushElement()
	{
		if (size == capacity)
		{
			try
			{
				MemoryAllocation();
			}
			catch (bad_alloc)
			{
				cout << "Can't increase stack to write new element" << endl;
				system("pause");
				return;
			}
		}
		cout << "Input correct element:" << endl;
		while (true)
		{
			cin >> DynamicArray[size];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Repeat input" << endl;
			}
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		size += 1;
	}

	void PopElement()
	{
		if (size > 0)
		{
			size -= 1;
		}
		else
		{
			cout << "Stack is empty" << endl;
			system("pause");
		}
		return;
	}

	void ShowElements()
	{
		if (size > 0)
		{
			for (int i = size - 1; i >= 0; i--)
				cout << DynamicArray[i] << "  ";
		}
		else
			cout << "Stack is empty" << endl;
		system("pause");
		return;
	}
};

template <typename T>

void OperationWithTheStack(Stack<T>& stack)
{
	int Choice;
	while (true)
	{
		cout << "Chouse action with stack:" << endl;
		cout << "1.Push Element" << endl;
		cout << "2.Pop Element" << endl;
		cout << "3.Show Elements" << endl;
		cout << "4.Exit" << endl;
		while (true)
		{
			Choice = _getch() - 48;
			if (Choice == 4)
				return;
			switch (Choice)
			{
			case 1:
				stack.PushElement();
				break;
			case 2:
				stack.PopElement();
				break;
			case 3:
				stack.ShowElements();
				break;
			default:
				break;
			}
			if ((Choice == 1) || (Choice == 2) || (Choice == 3))
				break;
		}
		system("cls");
	}
}

int main()
{
	try
	{
		Stack<int> StackWithIntValues;
		OperationWithTheStack(StackWithIntValues);
	}
	catch (bad_alloc)
	{
		cout << "Memory allocation error" << endl;
		system("pause");
		return 1;
	}
	return 0;
}