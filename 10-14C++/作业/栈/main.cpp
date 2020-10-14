// Created by Muxxs on 2020/10/14
// Copyright (c) 2020
// All rights reserved
#include <iostream>

using namespace std;

typedef int SElementType;

class Stack
{
private:
    SElementType *top;
    SElementType *base;
    int size;

public:
    Stack(int size)
    {
        base = (SElementType *)malloc(sizeof(SElementType) * size);
        top = base;
        size = 0;
    }
    void GetTop()
    {
        cout << "Top: " << *(top - 1) << endl;
    }
    void push(SElementType s)
    {
        if (size >= 10)
        {
            base = (SElementType *)realloc(base, sizeof(SElementType)*(size+1));
            top = base + size;
            size++;
        }

        *(top++) = s;
        size++;
    }
    void pop()
    {
        top--;
        size--;
    }
    void show_value()
    {
        SElementType *Pointer = base;
        for (int i = 0; i < size; i++)
        {
            cout << "第" << i + 1 << "个数字是:" << *(Pointer++) << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Stack s(10);
    s.push(1);
    s.push(2);
    s.GetTop();
    s.pop();
    s.show_value();
    return 0;
}
