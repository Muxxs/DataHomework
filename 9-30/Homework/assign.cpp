//
// Created by Muxxs on 2020/9/30.
//

#include "assign.h"

using namespace std;
//赋初值
int assign()
{
    int number,start,count;
    cout << "please input the number began,count:\n";
    cin >>number >>start >>count;

    if(number<2){                //小孩数校验
        cerr <<"bad number of boys\n";
        return 0;
    }

    if(start<0){                 //开始位置校验
        cerr <<"bad began position.\n";
        return 0;
    }

    if(count<1 || count >number){//数小孩个数校验
        cerr <<"bad interval number.\n";
        return 0;
    }

    n=number; began=start; m=count; //赋全局变量值
    return 1;
}