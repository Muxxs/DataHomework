//
// Created by Muxxs on 2020/9/30.
//

#include "initial.h"
#include <iostream>

using namespace std;
struct Jose{            //小孩结构
    int code;             //存放小孩编号
    Jose* next;           //用于指向下一个小孩结点
};

//全局变量
int n;                         //小孩数
int began;                     //开始位置
int m;                         //数小孩间隔
Jose* pivot;                   //链表哨兵
Jose* pCur;                    //当前结点指针

void initial(Jose* pJose)
{
    int l=0;
    Jose* px=pJose;

    for(int i=1;i<=n;i++){
        px->next=pJose+i%n;
        px->code=i;
        px=px->next;
        if((l++%10)==0)               //输出行中个数控制
            cout <<endl;
        cout <<setw(4) <<i;
    }
    cout <<endl;
    pCur=pJose+n-1;                 //指向结构数组最后一个元素
}