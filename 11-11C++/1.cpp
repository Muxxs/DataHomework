//
// Created by Muxxs on 2020/11/11.
//

#include <iostream>
#include <ctime>
using namespace std;

class student{
public:
    int num;
    string name;
    char sex;
    tm birth;
};

class GraduateStudent : public student{
    tm GraduateTime;
};

class Phd : public GraduateStudent{
    string school;
};

int main(){

}