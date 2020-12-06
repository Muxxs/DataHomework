//
// Created by Muxxs on 2020/11/29.
//

#ifndef DATAHOMEWORK_SALARIEDEMPLOYEE_H
#define DATAHOMEWORK_SALARIEDEMPLOYEE_H

#include "employee.h"
#include <iostream>

using namespace std;

class SalariedEmployee : public employee {
private:
    int Price = 1000;
public:
    SalariedEmployee(string name, string id, int year, int month, int day) : employee(name, id, year, month, day) {
    }

    virtual int price() {
        return Price;
    }

    void ChangePrice(int prices) {
        Price = prices;
    }

    void show() {
        cout << "------------------" << endl;
        Display();
        cout << "price : " << Price << endl;
        cout << "------------------" << endl;
    }
};

#endif //DATAHOMEWORK_SALARIEDEMPLOYEE_H
