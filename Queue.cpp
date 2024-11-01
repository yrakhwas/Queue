#include <iostream>
using namespace std;

template <class T>
class Queue {
    T* data;
    int maxSize;
    int size;
public:
    Queue() = default;
	Queue(int maxSize) : maxSize(maxSize), size(0) {
		data = new T[maxSize];
	}
	~Queue()
	{
		if(data!=nullptr)
			delete[] data;
	}
	void Enqueue(T elem) 
	{
		if (!IsFull())
		{
			data[size++] = elem;
		}
		else {
			cout << "Queue is full" << endl;
		}
	}
	bool IsFull() const
	{
		return size == maxSize;
	}
	bool IsEmpty()const
	{
		return size == 0;
	}
	T Dequeue()
	{
		if (!IsEmpty())
		{
			T firstElem = data[0];
			for (int i = 0; i < size; i++)
			{
				data[i - 1] = data[i];
			}
			--size;
			//data[size - 1] = firstElem;
			return firstElem;
		}
	}
	int GetCount()const
	{
		return size;
	}
	void Clear()
	{
		size = 0;
	}
	void Show()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Queue<int> q(25);
	//Створити чергу на 25 елементів типу int, заповнити її рандомними числами від 1 до 100, продемонструвати роботу методів черги.Йгц
}
