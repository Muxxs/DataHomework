#include <iostream>
#include <iomanip>
#include "quanjubianliang.h"
using namespace std;
//链表初始化
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
