//
// Created by Muxxs on 2020/9/24.
//

#include <iostream>

using namespace std;

typedef int status ;

typedef struct LNode{
    int Data[2]; // 0: 指数 1: 系数
    struct LNode * Next;
}Node,*LinkList;

typedef struct NodeControl{
    LinkList Head;
    int size;
};


void InitLNode(NodeControl &List,int n){
    List.Head = (LinkList)malloc(sizeof(LNode)*n);
    LinkList Point = List.Head;
    for (int i = 0; i < n; ++i) {
        Point->Next = (LinkList)malloc(sizeof(LNode));
        Point->Data[0] = 0;
        Point->Data[1] = 0;
        Point = Point->Next;
    }
    List.size = n;
}

status Insert(NodeControl &List,int num[2],int target){
    if (target>List.size or target<0) return 0;
    LinkList NewPointer = List.Head;
    for (int i = 0; i <= target - 1 ; ++i) {
        NewPointer = NewPointer->Next;
    }
    LinkList NewNodePointer = (LinkList)malloc(sizeof(LNode));
    NewNodePointer->Next = NewPointer->Next;
    NewPointer ->Next = NewNodePointer;
    NewNodePointer->Data[0] = num[0];
    NewNodePointer->Data[1] = num[1];
    List.size++;
    return 1;
}

status Delate(NodeControl &List,int target){
    if (target>List.size or target<0) return 0;
    LinkList NewPointer = List.Head;
    for (int i = 0; i < target-1; ++i) {
        NewPointer = NewPointer->Next;
    }
    NewPointer->Next = NewPointer->Next->Next;
    List.size--;
    return 1;
}

void ShowList(NodeControl List){
    LinkList Point = List.Head;
    for (int i = 0; i < List.size; ++i) {
        Point = Point->Next;
        cout << "Num "<< i+1 << " : " << Point->Data[0] << "," << Point->Data[1] <<endl;
    }
}


void DelateList(NodeControl &List){
    LinkList Pointer = List.Head,NextNode;
    while (Pointer->Next!=NULL){
        NextNode=Pointer->Next;
        free(Pointer);
        Pointer = NextNode;
    }
    free(Pointer);
    List.Head=NULL;
    List.size=0;
}

void insert(NodeControl &List){
    int n,num[2];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[0];
        cin >> num[1];
        cout << "----" << endl;
        Insert(List,num,List.size);
    }
}

void Deal(NodeControl La,NodeControl Lb,NodeControl &Lc){
    LinkList PointA = La.Head->Next,PointB = Lb.Head->Next,PointC = Lc.Head;
    int CountLc=0;
    int NewNum[2];
    bool IsInsert= false;
    if (PointB==NULL){
        PointC->Next = La.Head->Next;
    }else if (PointA==NULL){
        PointC->Next = Lb.Head->Next;
    }
    while (PointA!=NULL){
        PointB = Lb.Head->Next;
        CountLc == 0;
        while (PointB!=NULL){
            CountLc++;
            cout << "PointB:" << PointB->Data[0] << endl;
            cout << "PointA:" << PointB->Data[0] << endl;
            if (PointB->Data[0]==PointA->Data[0]){
                NewNum[0]=PointB->Data[0];
                NewNum[1]=PointB->Data[1]+PointA->Data[1];
                Insert(Lc,NewNum,Lc.size);
                IsInsert = true;
                Lc.size++;
                break;
            } else{
                PointB = PointB->Next;
            }
        }
        if (IsInsert){
            PointA = PointA->Next;
            IsInsert= false;
            continue;
        } else{
            Insert(Lc,PointA->Data,Lc.size);
            Lc.size++;
            PointA = PointA->Next;
        }
    }
}

int main(){
    NodeControl La,Lb,Lc;
    InitLNode(La,0);
    InitLNode(Lb,0);
    InitLNode(Lc,0);
    cout << "La Insert" << endl;
    insert(La);
    cout << "Lb Insert" << endl;
    insert(Lb);
    ShowList(La);
    ShowList(Lb);
    Deal(La,Lb,Lc);
    cout << "Lc Out" << endl;
    ShowList(Lc);
}