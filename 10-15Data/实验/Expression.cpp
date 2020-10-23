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
    while (Now!=NULL){
        cout << "Num :" << times++ << " Data :" << Now->data << endl;
        Now = Now->Next;
    }
    return OK;
}

ElemType MakeElem(int data){
    ElemType *Res;
    Res = (ElemType *)malloc(sizeof(ElemType));
    (*Res).data = data;
    (*Res).Next = NULL;
    return *Res;
}

bool ConfirmSymbol(char symbol,LinkStack S){
    ElemType Past;
    GetTop(S,Past);
    if ( (Past.data=='*' or Past.data == '\\') and symbol!='('  ) {
        return true;
    }else if (Past.data){

    }
}

int Deal(int a,int b,char symbol){
    cout << "Deal : " << a << symbol << b << endl;
    if (symbol==45){
        return a+b;
    }else if (symbol == 42){
        return a*b;
    } else if (symbol == 43){
        return a-b;
    }
}

void PushStr(string Str,LinkStack Num,LinkStack Symbol){
    ElemType New,Trash,past1,past2;
    bool isNumber= false;
    for(char i : Str){
        if (i>=48 and i <= 57){ // 数字录入部分
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
        } else{ // 符号录入部分
            isNumber = false;
            GetTop(Symbol,Trash);
            cout << (char)Trash.data << endl;
//            if ( i > Trash.data && Trash.data!=1){ //
//                GetTop(Symbol,Trash);
//                Pop(Num,past1);
//                Pop(Num,past2);
//                New = MakeElem(Deal(past1.data,past2.data,i));
//                cout << "New:" << New.data << endl;
//                Push(Num,New);
//            }
            New = MakeElem(i);
            Push(Symbol,New);
        }
    }
}

int main(){
    string Str = "1+223*41";
    LinkStack Num; // 数栈
    LinkStack Symbol; // 数栈
    InitStack(Num);
    InitStack(Symbol);
    PushStr(Str,Num,Symbol);
    StackTraverse(Symbol);
    StackTraverse(Num);
};
