//
// Created by Muxxs on 2020/11/25.
//


#include "employee.h"

using namespace std;

int main() {
    SalariedEmployee peo1("Wj", "1190403030", 2020, 11, 25);
    peo1.show();
    CommissionEmployee peo2("Wj1", "1190403030", 2020, 11, 25,3000);
    peo2.show();
    BasePlusCommissionEmployee peo3("Wj2", "1190403030", 2020, 11, 25,3000);
    peo3.show();
    HourlyEmployee peo4("Wj3", "1190403030", 2020, 11, 25,50);
    peo4.show();
}
//     结果如下
//------------------
//Name : Wj
//ID : 1190403030
//Birth : 2020-11-25
//price : 1000
//------------------
//------------------
//Name : Wj1
//ID : 1190403030
//Birth : 2020-11-25
//price : 900
//------------------
//------------------
//Name : Wj2
//ID : 1190403030
//Birth : 2020-11-25
//price : 1900
//------------------
//------------------
//Name : Wj3
//ID : 1190403030
//Birth : 2020-11-25
//price : 2000
//------------------