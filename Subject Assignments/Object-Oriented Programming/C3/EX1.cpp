#include <bits/stdc++.h>

using namespace std;

class Stack
{
protected:
    int data[100000];
    int capacity;
    int nextIndex = 0;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
    }

    ~Stack()
    {
        cout << "Stack has been destroyed.";
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    bool isFull()
    {
        return nextIndex == capacity;
    }

    void push(int value)
    {
        data[nextIndex] = value;
        nextIndex++;
    }

    int pop()
    {
        int value = data[nextIndex - 1];
        nextIndex--;
        return value;
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack(10);
    for (int i = 0; i < 12; i++)
    {
        if (stack.isFull())
        {
            cout << "Stack is full. Cannot push " << i << endl;
            continue;
        }

        stack.push(i);
    }

    cout << endl;
    stack.print();

    for (int i = 0; i < 10; i++)
    {
        int v = stack.pop();
        cout << "Popped " << v << endl;
    }

    cout << endl;
    stack.print();

    return 0;
}