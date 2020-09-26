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
    Point->Next=NULL;
    List.size = n;
}

status Insert(NodeControl &List,int num[2],int target){
    if (target>List.size or target<0) return 0;
    LinkList NewPointer = List.Head;
    for (int i = 0; i < target - 1 ; ++i) {
        NewPointer = NewPointer->Next;
        if (NewPointer->Next==NULL) break;
    }
    LinkList NewNodePointer = (LinkList)malloc(sizeof(LNode));
    if (NewPointer==NULL){
        NewNodePointer->Next=NULL;
    } else {
        NewNodePointer->Next = NewPointer->Next;
    }
    NewPointer -> Next = NewNodePointer;
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
        cout << "Num "<< i+1 << " : 指数:" << Point->Data[0] << " 系数:" << Point->Data[1] <<endl;
        if (Point->Next==NULL) break;
    }
}

void insert(NodeControl &List){
    int n,num[2];
    cout << "请输入个数:" ;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout <<  "请输入指数:";
        cin >> num[0];
        cout << "请输入系数:";
        cin >> num[1];
        cout << "----" << endl;
        Insert(List,num,List.size);
    }
}

void Deal(NodeControl La,NodeControl Lb,NodeControl &Lc){
    LinkList PointA = La.Head->Next,PointB = Lb.Head->Next,PointC = Lc.Head;
    int NewNum[2];
    bool IsInsert;
    if (PointB==NULL){
        PointC->Next = La.Head->Next;
    }else if (PointA==NULL){
        PointC->Next = Lb.Head->Next;
    }
    while (PointA!=NULL){
        PointB = Lb.Head->Next;
        bool IsInsert= false;
        while (PointB!=NULL){
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
            continue;
        } else{
            Insert(Lc,PointA->Data,Lc.size);
            Lc.size++;
            PointA = PointA->Next;
        }
    }

    PointB = Lb.Head->Next;
    while (PointB->Next!=NULL){
        IsInsert= false;
        PointC = Lc.Head->Next;
        while (PointC!=NULL){
            if (PointB->Data[0]==PointC->Data[0]){
                IsInsert = false;
                break;
            } else if(PointC->Next==NULL){
                IsInsert = true;
                break;
            } else {
                PointC=PointC->Next;
            }
        }
        if (IsInsert){
            NewNum[0]=PointB->Data[0];
            NewNum[1]=PointB->Data[1];
            Insert(Lc,NewNum,Lc.size);
            PointB = PointB->Next;
            continue;
        } else{
            PointB = PointB->Next;
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
    Deal(La,Lb,Lc);
    cout << "Lc Out" << endl;
    ShowList(Lc);
}