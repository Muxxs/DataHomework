//
// Created by Muxxs on 2020/9/30.
//

#include "process.h"
#include <iostream>

using namespace std;
void process()
{
    int l=0;
    for(int i=1; i<n-1; i++){
        count(m);                    //数m个小孩
        if((l++%10)==0)              //输出行中个数控制
            cout <<endl;
        cout <<setw(4) <<pCur->code;

        pivot->next=pCur->next;      //小孩脱链
        pCur=pivot;
    }
}