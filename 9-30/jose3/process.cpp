#include <iostream>
#include <iomanip>
#include "quanjubianliang.h"
#include "a3.h"
using namespace std;

void process()
{
  int l=0;
  for(int i=1; i<n-1; i++){
    count(m);                    //��m��С��
    if((l++%10)==0)              //������и�������
      cout <<endl;
    cout <<setw(4) <<pCur->code;

    pivot->next=pCur->next;      //С������
    pCur=pivot;
  }
}
