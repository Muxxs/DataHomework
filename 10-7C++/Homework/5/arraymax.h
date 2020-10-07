//
// Created by Muxxs on 2020/10/7.
//

#ifndef DATAHOMEWORK_ARRAYMAX_H
#define DATAHOMEWORK_ARRAYMAX_H
#include <iostream>
using namespace std;
struct Array_max{
public:
    void set_value();
    void show_value();
    void max_value();

private:
    int array[10];
    int max=0;
};
#endif //DATAHOMEWORK_ARRAYMAX_H
