//
// Created by Muxxs on 2020/10/23.
//

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef int Char;

typedef struct CharLink
{
    Char number;
    CharLink *Next;
} CharLink, *CharLinkPointer;

typedef struct CharStack
{
    CharLinkPointer base;
    int size;
} CharStack;

bool CharIsEmpty(CharStack L)
{
    return L.base == NULL;
}

bool CharPush(CharStack &L, Char e)
{ // 入栈
    if (L.base == NULL)
    {
        L.base = (CharLink *)malloc(sizeof(CharLink));
        L.base->Next = NULL;
        L.base->number = e;
        L.size++;
        return true;
    }
    CharLinkPointer NEXT = L.base;
    L.base = (CharLink *)malloc(sizeof(CharLink));
    L.base->Next = NEXT;
    L.base->number = e;
    L.size++;
    return true;
}

void CharTraverse(CharStack L)
{ // 遍历
    for (int i = 0; i < L.size; ++i)
    {
        cout << "Number " << i + 1 << " element :" << L.base->number << endl;
        L.base = L.base->Next;
    }
}

int Pop(CharStack &L)
{ // 出栈
    int e = L.base->number;
    CharLinkPointer Next = L.base->Next;
    free(L.base);
    L.base = Next;
    L.size--;
    return e;
}

int GetTop(CharStack L)
{ // 获取顶部
    if (L.size == 0)
        return 0;
    int e = L.base->number;
    return e;
}

void CharInit(CharStack &L)
{ // 初始化
    L.base = NULL;
    L.size = 0;
}

bool IsNumber(char Char)
{ // 判断是否为数字
    return Char >= 48 and Char <= 57;
}

bool IsOperate(char Last, char Now)
{ // 判断是否执行操作
    if ((Now == 43 or Now == 45) and (Last == 42 or Last == 47))
        return true;
}

int Deal(int b, int a, char operation)
{ // 执行计算操作
    cout << "Operation:" << a << operation << b << endl;
    switch (operation)
    {
    case 42:
        return a * b;
    case 43:
        return a + b;
    case 45:
        return a - b;
    case 47:
        return a / b;
    }
    return 0;
}

void PushStr(string Str, CharStack &Num, CharStack &Sym)
{
    bool IsLastNumber = false;
    char i; // 每个字符
    for (int x; x < Str.length(); x++)
    {
        i = Str[x];
        if (IsNumber(i))
        { // 这次是数字
            if (IsLastNumber)
            {                                        // 上一个是数字
                int last = Pop(Num);                 // 获取上一个数字
                CharPush(Num, atoi(&i) + last * 10); // 上一个*10 + 这个数字
            }
            else
            {
                IsLastNumber = true;     // 下次的上次是数字
                CharPush(Num, atoi(&i)); // push
            }
        }
        else
        { // 这次是符号
            char LastSym = (char)GetTop(Sym);
            if (IsOperate(LastSym, i) and Num.size >= 2)
            {
                Pop(Sym);
                int LastNum = Pop(Num);
                int LLastNum = Pop(Num);
                CharPush(Num, Deal(LastNum, LLastNum, LastSym));
                x--;
            }
            else
            {
                CharPush(Sym, i);
                IsLastNumber = false;
            }
        }
    }
    int LastNum, LLastNum, Size = Sym.size;
    char Now;
    for (int j = 0; j < Size; j++)
    {
        Now = (char)Pop(Sym);
        LastNum = Pop(Num);
        LLastNum = Pop(Num);
        CharPush(Num, Deal(LastNum, LLastNum, Now));
    }
}

int main()
{
    CharStack NumStack, SymbolStack;
    int m;
    CharInit(NumStack);
    CharInit(SymbolStack);
    string Str = "2*1+20*30+2*3";
    cout << "Question:" << Str << endl;
    cout << "---Start---" << endl;
    PushStr(Str, NumStack, SymbolStack);
    cout << "Result:" << NumStack.base->number << endl;
}