//
// Created by Muxxs on 2020/10/7.
//

#include "Control.h"
#include "structure.h"
#include <iostream>

using namespace std;
void Display(Student student){
    cout<< "姓名:" << student.name << " 性别:" << student.sex <<" 成绩:" << student.num << endl;
}

void Insert(Student &student){
    cout << "姓名:";
    cin >> student.name;
    cout << "性别:";
    cin >> student.sex;
    cout << "成绩:";
    cin >> student.num;
    cout << "Information Insert Finished" << endl;
    Display(student);
}