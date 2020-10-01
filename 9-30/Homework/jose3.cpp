//******************************
//**    Josephus问题解法三    **
//**    jose3.cpp             **
//******************************
#include <iostream>
#include <iomanip>
#include "initial.cpp"
#include "assign.cpp"
#include "count.cpp"
#include "process.cpp"

using namespace std;

//函数声明
int assign();                  //赋初值，返回1：成功，0：失败
void initial(Jose* pBoys);     //初始化环链表
void count(int m);             //数m个小孩
void process();                //处理所有未获胜小孩

//主函数
int main()
{
    if(!assign()){
        cout <<"The program failed.\n";
        return 0;
    }

    Jose* pJose=new Jose[n];     //分配结构数组
    initial(pJose);              //初始化结构数组
    count(began);                //转到开始位置
    process();                   //处理所有未获胜小孩

    cout <<"\nthe winner is " <<pCur->code <<endl;

    delete[]pJose;               //返还结构数组给堆空间
}
