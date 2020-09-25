//
// Created by Muxxs on 2020/9/24.
//
#include <iostream>
using namespace std;
typedef int status ;
typedef struct LNode{
    int Data;
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
        Point->Data = 0;
        Point = Point->Next;
    }
    List.size = n;
}

status Insert(NodeControl &List,int num,int target){
    if (target>List.size or target<0) return 0;
    LinkList NewPointer = List.Head;
    for (int i = 0; i <= target - 1 ; ++i) {
        NewPointer = NewPointer->Next;
    }
    LinkList NewNodePointer = (LinkList)malloc(sizeof(LNode));
    NewNodePointer->Next = NewPointer->Next;
    NewPointer ->Next = NewNodePointer;
    NewNodePointer->Data = num;
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
        cout << "Num "<< i+1 << " : " << Point->Data <<endl;
    }
}

int Search(NodeControl List,int Content){
    LinkList Pointer = List.Head->Next;
    for (int i = 1; i < List.size+1; ++i) {
        if (Pointer->Data==Content){
            cout << "Content: " << Content << " is in the Num : " << i << endl;
            return 1;
        }
        Pointer = Pointer->Next;
    }
    cout << "Content: " << Content << " is not in the List " << endl;
    return 0;
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

int ChangeData(NodeControl &List,int num ,int target){
    if (target>List.size+1 or target<0) return 0;
    LinkList NewPointer = List.Head;
    for (int i = 0; i < target-1; ++i) {
        NewPointer = NewPointer->Next;
    }
    NewPointer->Next->Data = num;
    return 1;
}

int merge(NodeControl &List1,NodeControl &List2){
    LinkList Pointer1=List1.Head->Next,Pointer2=List2.Head->Next,Mid;
    LinkList PointerPre1=List1.Head;
    while (Pointer1!=NULL && Pointer2!=NULL){
        if (Pointer1->Data <= Pointer2->Data){
            if (Pointer1->Next!= NULL) {
                if (Pointer1->Next->Data <= Pointer2->Data) {
                    Pointer1 = Pointer1->Next;
                    PointerPre1 = PointerPre1->Next;
                    continue;
                }
            }
            Mid = Pointer2->Next;
            PointerPre1 = Pointer1;
            Pointer2 -> Next =Pointer1->Next;
            Pointer1 -> Next = Pointer2;
            Pointer1 = Pointer2;
            Pointer2 = Mid;
            List1.size++;
        } else{
            Mid = Pointer2;
            PointerPre1->Next = Pointer2;
            Pointer2->Next = Pointer1;
            Pointer2 = Mid;
            List1.size++;
        }
    }
}

void insert(NodeControl &List){
    int n,num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        Insert(List,num,List.size);
    }
}

int main(){
    NodeControl List1,List2;
    InitLNode(List1,0);
    InitLNode(List2,0);
    insert(List1);
    insert(List2);
    ShowList(List1);
    cout << "------" << endl;
    ShowList(List2);
    merge(List1,List2);
    cout << "------" << endl;
    ShowList(List1);
}