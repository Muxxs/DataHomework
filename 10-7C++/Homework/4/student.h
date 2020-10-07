//
// Created by Muxxs on 2020/10/7.
//

#ifndef DATAHOMEWORK_STUDENT_H
#define DATAHOMEWORK_STUDENT_H
#include <iostream>
using namespace std;
struct student{
public:
    void display();
    void set_value();

private:
    int num;
    string name;
    string sex;
};

#endif //DATAHOMEWORK_STUDENT_H
