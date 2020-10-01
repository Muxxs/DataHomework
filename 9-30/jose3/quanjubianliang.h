#ifndef QUANJUBIANLIANG_H_INCLUDED
#define QUANJUBIANLIANG_H_INCLUDED

struct Jose{            //小孩结构
  int code;             //存放小孩编号
  Jose* next;           //用于指向下一个小孩结点
};

 extern int n;                         //小孩数
 extern int begining;                     //开始位置
 extern int m;                         //数小孩间隔
 extern Jose* pivot;                   //链表哨兵
 extern Jose* pCur;                    //当前结点指针


#endif // QUANJUBIANLIANG_H_INCLUDED
