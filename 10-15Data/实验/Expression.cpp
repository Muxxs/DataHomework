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

int main(){
    string Str = "1+2*3-4";
    LinkStack Num; // 数栈
    ElemType New,Trash;
    InitStack(Num);
    bool isNumber= false;

    for(char i : Str){
        if (i>=48 and i <= 57){
            if (!isNumber){
                MakeElem(atoi(reinterpret_cast<const char *>(i)));
                Push(Num,New);
            } else {
                GetTop(Num,New);
                New = MakeElem(New.data*10+atoi(reinterpret_cast<const char *>(i)));
                Pop(Num,Trash);

            }
        } else{

        }
    }
};
