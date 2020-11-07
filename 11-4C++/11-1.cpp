//
// Created by Muxxs on 2020/11/7.
//

#include <iostream>

using namespace std;

class Student
{
public:
    void get_value()
    {
        cin >> num >> name >> sex;
    }
    void display()
    {
        cout << "num:" << num << endl;
        cout << "name:" << name << endl;
        cout << "sex:" << sex << endl;
    }

private:
    int num;
    string name;
    char sex;
};

class Student1 : public Student
{
public:
    void get_value_1()
    {
        cin >> age >> addr;
    }
    void display_1()
    {
        cout << "age:" << age << endl;
        cout << "addr:" << addr << endl;
    }

private:
    int age;
    string addr;
};

int main(){
    Student1 AStudent;
    AStudent.get_value();
    AStudent.get_value_1();
    AStudent.display();
    AStudent.display_1();
    return 0;
}