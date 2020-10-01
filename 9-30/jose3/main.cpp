#include <iostream>
#include <iomanip>
#include "quanjubianliang.h"
#include "a1.h"
#include "a2.h"
#include "a3.h"
#include "a4.h"

using namespace std;

int n;        //С����
int begining; //��ʼλ��
int m;        //��С�����
Jose *pivot;  //�����ڱ�
Jose *pCur;   //��ǰ���ָ��

//������
int main()
{
  if (!assign())
  {
    cout << "The program failed.\n";
    return 0;
  }

  Jose *pJose = new Jose[n]; //����ṹ����
  initial(pJose);            //��ʼ���ṹ����
  count(begining);           //ת����ʼλ��
  process();                 //��������δ��ʤС��

  cout << "\nthe winner is " << pCur->code << endl;

  delete[] pJose; //�����ṹ������ѿռ�
  return 0;
}
