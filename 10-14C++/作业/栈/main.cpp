// Created by Muxxs on 2020/10/14
// Copyright (c) 2020
// All rights reserved
#include <iostream>

using namespace std;

typedef int SElementType;

class Stack
{
private:
    int MaxSize;
    SElementType *top;
    SElementType *base;
    int size;

public:
    Stack(int Size)
    {
        base = (SElementType *)malloc(sizeof(SElementType) * Size);
        top = base;
        MaxSize = Size;
        size = 0;
    }
    void GetTop()
    {
        cout << "Top: " << *(top - 1) << endl;
    }
    void push(SElementType s)
    {
        if (size >= MaxSize)
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
        if (size==0) return;
        top--;
        size--;
    }
    void clearStack(){
        top = base;
    }
    void DestroyStack(){
        free(base);
    }
    void StackTraverse()
    {
        SElementType *Pointer = base;
        for (int i = 0; i < size; i++)
        {
            cout << "第" << i + 1 << "个数字是:" << *(Pointer++) << endl;
        }
    }
    ~Stack(){
        DestroyStack();
        delete base;
        delete top;
    }
};

int main(int argc, char const *argv[])
{
    Stack s(10);
    s.push(1);
    s.push(2);
    s.GetTop();
    s.pop();
    s.StackTraverse();
    return 0;
}
