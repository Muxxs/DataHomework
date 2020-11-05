//
// Created by Muxxs on 2020/11/5.
//

#include <iostream>
using namespace std;
#define OK true;
#define ERROR false;
typedef char ElemType;
typedef bool Status;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode * lchild;
    struct BiTNode * rchild;
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T){
    ElemType ch;
    cin >> ch;
    if(ch=='$'){
        T = NULL;
    }else {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        if(!T)
            return ERROR;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

Status PreOrderTraverse(BiTree T){
    if(!T) return ERROR;
    cout << (*T).data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return OK;
}

Status InOrderTraverse(BiTree T){
    if (!T) return ERROR;
    InOrderTraverse(T->lchild);
    cout << T->data;
    InOrderTraverse(T->rchild);
    return OK;
}

Status PostOrderTraverse(BiTree T){
    if (!T) return ERROR;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << T->data;
    return OK;
}

void CountBiTreeLeaf(int &i,BiTree T){
    if (T!=nullptr){
        i++;
    } else{
        return;
    }
    CountBiTreeLeaf(i,T->lchild);
    CountBiTreeLeaf(i,T->rchild);
}

int BiTreeDepth(BiTree T){
    int l,r;
    if (!T) return 0;
    if (T->lchild!=NULL){
        l=BiTreeDepth(T->lchild);
    } else{
        l=0;
    }
    if (T->rchild!=NULL){
        r = BiTreeDepth(T->rchild);
    } else{
        r=0;
    }
    return r>l? r+1 : l+1;
}

int main(){
    BiTree T;
    int Leaf;
    CreateBiTree(T);
    cout << "前序遍历:";
    PreOrderTraverse(T);
    cout << endl;
    cout << "中序遍历:";
    InOrderTraverse(T);
    cout << endl;
    cout << "后序遍历:";
    PostOrderTraverse(T);
    cout << endl;
    CountBiTreeLeaf(Leaf,T);
    cout << "子结点数:" << Leaf-1 << endl; // 去掉根节点
    cout << "深度：" << BiTreeDepth(T) << endl;
    return 0;
}