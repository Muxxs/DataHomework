#include <iostream>
#include <iomanip>
#include "quanjubianliang.h"
using namespace std;
//����ֵ
int assign()
{
  int number,start,count;
  cout <<"please input the number,begin,count:\n";
  cin >>number >>start >>count;

  if(number<2){                //С����У��
    cerr <<"bad number of boys\n";
    return 0;
  }

  if(start<0){                 //��ʼλ��У��
    cerr <<"bad begin position.\n";
    return 0;
  }

  if(count<1 || count >number){//��С������У��
    cerr <<"bad interval number.\n";
    return 0;
  }

  n=number; begining=start; m=count; //��ȫ�ֱ���ֵ
  return 1;
}
