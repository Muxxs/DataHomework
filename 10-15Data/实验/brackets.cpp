//
// Created by Muxxs on 2020/10/15.
//

#include <iostream>
#include <cstdlib>
#include <string>
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

Status ClearStack(LinkStack &S,ElemType){
    while (S.L->Next!=NULL){
        ElemType * NextElemType = S.L->Next;
        free(S.L);
        S.L=NextElemType;
    }
    free(S.L);
    S.L=NULL;
    S.length=0;
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
    LinkStack S;
    InitStack(S);
    string Str= "(([)]))";
    ElemType This,Pre;
    for(char i : Str){
        This = MakeElem(i);
        if (i == '[' || i == '(') {
            Push(S, This);
            continue;
        } else{
            GetTop(S,Pre);
            if (i == ']' && Pre.data == '['){
                Pop(S,Pre);
                continue;
            }else if (i == ')' && Pre.data == '('){
                Pop(S,Pre);
                continue;
            }else{
                cout << "不匹配" << endl;
                return 0;
            }
        }
    }
    cout << "匹配" << endl;
};
