//
// Created by Muxxs on 2020/10/22.
//

#include <iostream>
using namespace std;

typedef bool Status;
#define OK true;
#define ERROR false;
typedef int QElemType;

#define MAXQSIZE 10
typedef struct
{
    QElemType *base; // 初始化分配
    int front;       // 尾部
    int rear;        // 头部
} SqQueue;

Status InitQueue(SqQueue &Q)
{
    Q.base = (QElemType *)malloc(sizeof(QElemType) * MAXQSIZE);
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q)
{
    return (Q.front == Q.rear);
}

Status GetHead(SqQueue Q, QElemType &e)
{
    if (QueueEmpty(Q))
        return ERROR;
    e = Q.base[Q.rear - 1];
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    if (QueueEmpty(Q))
        return ERROR;
    e = Q.base[Q.front++];
    Q.front %= MAXQSIZE;
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status ClearQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueTraverse(SqQueue Q)
{
    if (QueueEmpty(Q))
        return ERROR;
    int times = 1;
    int Rear = Q.rear;
    int Front = Q.front;
    cout << "Traverse : " << endl;
    for (; Front != Rear;)
    {
        cout << "Number: " << times++ << " data: " << Q.base[Front++] << endl;
        Front %= MAXQSIZE;
    }
    cout << "---Traverse Finish---" << endl;
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    if (QueueLength(Q) == MAXQSIZE - 1)
        return ERROR;
    Q.base[Q.rear++] = e;
    Q.rear %= MAXQSIZE;
    return OK;
}

Status CreateQueue(SqQueue &Q)
{
    cout << "请输入数量 (小于" << MAXQSIZE << ") : ";
    int times, data;
    cin >> times;
    while (times--)
    {
        cin >> data;
        EnQueue(Q, data);
    }
    return OK;
}

Status DestroyQueue(SqQueue &Q)
{
    free(Q.base);
    return OK;
}

int main()
{
    SqQueue S;
    QElemType head, e;
    InitQueue(S);
    CreateQueue(S);
    EnQueue(S, 78);
    EnQueue(S, 34);
    EnQueue(S, 23);
    QueueTraverse(S);
    DeQueue(S, e);
    DeQueue(S, e);
    QueueTraverse(S);
    GetHead(S, head);
    cout << "Head : " << head << endl;
    QueueTraverse(S);
    cout << "-------Clear-------" << endl;
    ClearQueue(S);
    DestroyQueue(S);
    return 0;
}