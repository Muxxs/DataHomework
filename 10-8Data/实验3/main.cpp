//
// Created by Muxxs on 2020/10/8.
//
#include <iostream>
#include <cstdlib>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;
typedef void status;
typedef struct
{
    int data;
} SElementType;

typedef struct
{
    SElementType *top;
    SElementType *base;
    int StackSize;
} SqStack;

status InitStack(SqStack &s) // 初始化
{
    s.base = (SElementType *)malloc(sizeof(SElementType) * STACK_INIT_SIZE);
    s.top = s.base;
    s.StackSize = STACK_INIT_SIZE;
}

status DestroyStack(SqStack &s) // 删除
{
    free(s.base);
}

status ClearStack(SqStack &s) // 清空
{
    s.top = s.base;
}

status push(SqStack &s, SElementType e) // 插入
{
    if (s.StackSize == s.top - s.base)
    {
        s.base = (SElementType *)realloc(s.base, sizeof(SElementType) * (s.StackSize + STACKINCREMENT));
        s.top = s.base + s.StackSize;
    }
    *s.top = e;
    s.top++;
}

status pop(SqStack &s) // 栈顶去除一个元素
{
    s.top--;
}

status GetTop(SqStack &s, SElementType &e) // 获取栈顶
{
    e = *(s.top-1);
}

bool isEmpty(SqStack &s) // 判断是否为空
{
    if (s.top == s.base)
    {
        return true;
    }
    else
    {
        return false;
    }
}

SqStack StackReverse(SqStack &s) // 反转
{
    SqStack S;
    SElementType mid;
    InitStack(S);
    while (!isEmpty(s))
    {
        GetTop(s,mid);
        pop(s);
        push(S, mid);
    }
    return S;
}

status StackTraverse(SqStack &s){ // 输出栈的元素
    int count = 1;
    SElementType *mid = s.base;
    while (mid != s.top)
    {
        cout << "Num :" << count++ << " Data : " << mid++->data << endl;
    }
}

int main()
{
    SqStack s;
    SElementType e;
    e.data = 10;
    InitStack(s);
    for (int i = 0; i < 15; ++i) {
        e.data++;
        push(s, e);
    }
    StackTraverse(s);
    ClearStack(s);
    DestroyStack(s);
}