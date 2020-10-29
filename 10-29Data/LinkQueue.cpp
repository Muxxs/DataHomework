#include <iostream>
#define MAXQSIZE 10
using namespace std;

typedef bool Status;
#define OK true;
#define ERROR false;

typedef struct ElemType
{
    int data;
    struct ElemType *next;
} QElemType, *PointQElement;

typedef struct
{
    QElemType *front; // 尾部
    QElemType *rear;  // 头部
} LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = Q.front;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    return (Q.front == Q.rear && Q.front == NULL);
}

Status GetHead(LinkQueue Q, QElemType &e)
{
    if (QueueEmpty(Q))
        return ERROR;
    e.data = Q.rear->data;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (QueueEmpty(Q))
        return ERROR;
    e = *Q.front;
    QElemType *Ele = Q.front->next;
    free(Q.front);
    Q.front = Ele;
    return OK;
}

Status QueueTraverse(LinkQueue Q)
{
    if (QueueEmpty(Q))
        return ERROR;
    QElemType *Ele = Q.front;
    int times = 1;
    while (Ele != NULL)
    {
        cout << "Number: " << times++ << " data: " << (*Ele).data << endl;
        Ele = Ele->next;
    }
    cout << "---Traverse Finish---" << endl;
    return OK;
}

Status EnQueue(LinkQueue &Q, int Data)
{
    if (Q.front == NULL)
    {
        Q.front = (QElemType *)malloc(sizeof(QElemType));
        Q.front->data = Data;
        Q.front->next = NULL;
        Q.rear = Q.front;
        return OK;
    }
    Q.rear->next = (QElemType *)malloc(sizeof(QElemType));
    Q.rear = Q.rear->next;
    Q.rear->next = NULL;
    Q.rear->data = Data;
    return OK;
}

Status CreateQueue(LinkQueue &Q)
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

Status ClearQueue(LinkQueue &Q)
{
    QElemType *Ele = Q.front, *Next;
    while (Ele->next != NULL)
    {
        Next = Ele->next;
        free(Ele);
        Ele = Next;
    }
    free(Ele);
    Q.rear = Q.front = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    QElemType *Next;
    while (Q.front != NULL)
    {
        Next = Q.front->next;
        free(Q.front);
        Q.front = Next;
    }
    return OK;
}

int main()
{
    LinkQueue S;
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
    cout << "Head : " << head.data << endl;
    QueueTraverse(S);
    cout << "-------Clear-------" << endl;
    ClearQueue(S);
    DestroyQueue(S);
    return 0;
}