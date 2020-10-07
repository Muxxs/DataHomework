//
// Created by Muxxs on 2020/10/7.
//

#include "student.h"

void student::display() {
    cout<< "姓名:" << name << " 性别:" << sex <<" 成绩:" << num << endl;
}

void student::set_value(){
    cout << "姓名:";
    cin >> name;
    cout << "性别:";
    cin >> sex;
    cout << "成绩:";
    cin >> num;
    cout << "Information Insert Finished" << endl;
    display();
}