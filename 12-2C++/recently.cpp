//
// Created by Muxxs on 2020/12/2.
//

#include<cstdio>
#include<cstdlib>
typedef struct Node{
    int x;
    struct Node *next;
}node;
int main(void)
{
    int n=0,i=0,mod=0;
    int a[100]={0};
    node *p[10];
    node *head[10];
    scanf("%d",&n);
    *p=(node *)malloc(sizeof(*p)*10);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        node *NewNode=(node *)malloc(sizeof(node));
        NewNode->next=NULL;
        p[i]=head[i]=NewNode;
    }
    for(i=0;i<n;i++)
    {
        mod=a[i]%10;
        node *ptr=(node *)malloc(sizeof(node));
        ptr->x=a[i];
        ptr->next=NULL;
        head[mod]->next=ptr;
        head[mod]=ptr;
    }
    i=0;
    node *ptr=(node *)malloc(sizeof(node));
    ptr=p[0]->next;
    while(ptr&&i==9)
    {
        printf("%d ",ptr->x);
        if(ptr->next==NULL)
        {
            i++;
            ptr=p[i]->next;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    return 0;
}
