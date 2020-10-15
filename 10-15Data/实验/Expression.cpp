//
// Created by Muxxs on 2020/10/15.
//


#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef bool Status;
#define OK true;
#define ERROR false;


typedef struct Data{
    int data;
    Data * Next;
}ElemType;

typedef struct{
    ElemType *L;
    int length;
}LinkStack;

Status InitStack(LinkStack &S){
    S.length=0;
    S.L=NULL;
    return OK;
}


Status DestroyStack(LinkStack &S){
    ElemType * NextElemtype;
    while (S.L->Next!=NULL){
        NextElemtype=S.L->Next;
        free(S.L);
        S.L=NextElemtype;
    }
    free(S.L);
    return OK;
}

Status Push(LinkStack &S, ElemType e){
    ElemType *New;
    New = (ElemType *)malloc(sizeof(ElemType));
    New->Next = S.L;
    New->data = e.data;
    S.L=New;
    S.length++;
    return OK;
}

Status Pop(LinkStack &S, ElemType &e){
    ElemType * ThisElemType = S.L;
    e = *ThisElemType;
    S.L = S.L->Next;
    S.length--;
    return OK;
}

Status ClearStack(LinkStack &S,ElemType){
    while (S.L->Next!=NULL){
        ElemType * NextElemType = S.L->Next;
        free(S.L);
        S.L=NextElemType;
    }
    free(S.L);
    S.L=NULL;
    S.length=0;
}

Status GetTop(LinkStack &S,ElemType &e){
    if (S.length==0) return ERROR;
    e.data = S.L->data;
    return OK;
}

Status StackTraverse(LinkStack S){
    int times = 1;
    ElemType *Now = S.L;
    while (Now->Next!=NULL){
        cout << "Num :" << times++ << " Data :" << Now->data << endl;
        Now = Now->Next;
    }
    cout << "Num :" << times++ << " Data :" << Now->data << endl;
    return OK;
}

ElemType MakeElem(int data){
    ElemType *Res;
    Res = (ElemType *)malloc(sizeof(ElemType));
    (*Res).data = data;
    (*Res).Next = NULL;
    return *Res;
}

bool

int main(){
    string Str = "1+22*3-4";
    LinkStack Num; // 数栈
    LinkStack Symbol; // 数栈
    ElemType New,Trash;
    InitStack(Num);
    InitStack(Symbol);
    bool isNumber= false;
    for(char i : Str){
        if (i>=48 and i <= 57){
            if (!isNumber){
                New = MakeElem(atoi(&i));
                Push(Num,New);
                isNumber= true;
            } else {
                GetTop(Num,New);
                New = MakeElem(New.data*10+atoi(&i));
                Pop(Num,Trash);
                Push(Num,New);
                isNumber= true;
            }
        } else{
            isNumber = false;
            New = MakeElem(i);
            Push(Symbol,New);
        }
    }
    StackTraverse(Symbol);
    StackTraverse(Num);
};
