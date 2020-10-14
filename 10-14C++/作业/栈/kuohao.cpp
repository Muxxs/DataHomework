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
    char size;

public:
    Stack(int Size)
    {
        base = (SElementType *)malloc(sizeof(SElementType) * Size);
        top = base;
        size = Size;
    }
    SElementType GetTop()
    {
        //cout << "Top: " << *(top - 1) << endl;
        return *(top - 1);
    }
    void push(SElementType s)
    {
        if (size >= 10)
        {
            base = (SElementType *)realloc(base, sizeof(SElementType) * (size + 1));
            top = base + size;
            size++;
        }

        *(top++) = s;
        size++;
    }
    void pop()
    {
        if (size == 0)
            return;
        top--;
        size--;
    }
    void clearStack()
    {
        top = base;
    }
    void DestroyStack()
    {
        free(base);
    }
    void StackTraverse()
    {
        SElementType *Pointer = base;
        for (int i = 0; i < size; i++)
        {
            cout << "第" << i + 1 << "个字符是:" << (char)*(Pointer++) << endl;
        }
    }
};

bool Compare(char a, char b){
    if (a =='[' && b == ']') return true;
    if (a == '(' && b == ')') return true;
    return false;
}

int main(int argc, char const *argv[])
{
    string str = "[([])]";
    Stack s(10);
    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
    {
        if (Compare(s.GetTop(),str[i]))
        {
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }
    s.StackTraverse();
}
