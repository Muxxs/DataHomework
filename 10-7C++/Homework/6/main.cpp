//
// Created by Muxxs on 2020/10/7.
//

#include <iostream>
#include "rectangle.h"

int main(){
    rectangle R1,R2,R3;
    cout << "长方形1:" << endl;
    R1.set_value();
    cout << "长方形2:" << endl;
    R2.set_value();
    cout << "长方形3:" << endl;
    R3.set_value();

    cout << "长方形1:" << endl;
    R1.calculate();
    cout << "长方形2:" << endl;
    R2.calculate();
    cout << "长方形3:" << endl;
    R3.calculate();
}