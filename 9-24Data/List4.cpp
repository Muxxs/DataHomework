//
// Created by Muxxs on 2020/9/25.
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
    List.Head = (LinkList)malloc(sizeof(LNode)*1);
    LinkList Point = List.Head;
    for (int i = 0; i < n; ++i) {
        Point->Next = (LinkList)malloc(sizeof(LNode));
        Point->Data = 0;
        Point = Point->Next;
    }
    Point->Next=NULL;
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
    if (target>List.size or target<0) return 0;
    LinkList NewPointer = List.Head;
    for (int i = 0; i < target-1; ++i) {
        NewPointer = NewPointer->Next;
    }
    NewPointer->Next->Data = num;
    return 1;
}

void insert(NodeControl &List){
    int n,num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        Insert(List,num,List.size);
    }
}

void reverse(NodeControl &List){
    LinkList Pointer = List.Head->Next,Pre=NULL,NextNext,Mid;
    if (Pointer->Next==NULL) return;
    LinkList PointerNext = Pointer->Next;
    while (PointerNext!=NULL){
        Mid = PointerNext;
        Pointer->Next = Pre;
        NextNext = PointerNext->Next;
        PointerNext->Next = Pointer;
        PointerNext = NextNext;
        Pre = Pointer;
        Pointer = Mid;
        if (!NextNext){
            break;
        }
    }
    Pointer->Next = Pre;
    List.Head->Next=Pointer;
}

int main(){
    NodeControl Lists;
    InitLNode(Lists,0);
    insert(Lists);
    cout << Lists.size << endl;
    ShowList(Lists);
    reverse(Lists);
    cout << "-----" << "转序" << "-----" << endl;
    ShowList(Lists);
}