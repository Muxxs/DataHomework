//
// Created by Muxxs on 2020/10/7.
//

#ifndef DATAHOMEWORK_RECTANGLE_H
#define DATAHOMEWORK_RECTANGLE_H

#include <iostream>
using namespace std;

struct rectangle{
private:
    int length;
    int width;
    int height;
    int volume=0;
public:
    void set_value(){
        cout << "长:";
        cin >> length;
        cout << "宽:";
        cin >> width;
        cout << "高:";
        cin >> height;
    }
    void calculate(){
        volume = length * width * height;
        cout << "体积:" << volume << endl;
    }
};

#endif //DATAHOMEWORK_RECTANGLE_H
