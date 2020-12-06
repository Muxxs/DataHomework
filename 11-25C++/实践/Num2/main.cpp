//
// Created by Muxxs on 2020/11/29.
//

#include "employee.h"
#include "SalariedEmployee.h"
using namespace std;

int main(){
    int ThisMonth = 11;
    SalariedEmployee peo1("Wj", "1190403030", 2020, 11, 25);
    if(peo1.Birth.GetMonth()==ThisMonth) peo1.ChangePrice(peo1.price()+100);
    peo1.show();
    CommissionEmployee peo2("Wj1", "1190403030", 2020, 11, 25,3000);
    if(peo2.Birth.GetMonth()==ThisMonth) peo2.ChangePrice(peo2.price()+100);
    peo2.show();
    BasePlusCommissionEmployee peo3("Wj2", "1190403030", 2020, 11, 25,3000);
    if(peo3.Birth.GetMonth()==ThisMonth) peo3.ChangePrice(peo3.price()+100);
    peo3.show();
    HourlyEmployee peo4("Wj3", "1190403030", 2020, 11, 25,50);
    if(peo4.Birth.GetMonth()==ThisMonth) peo4.ChangeHour(10);
    peo4.show();
}
