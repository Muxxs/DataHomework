//
// Created by Muxxs on 2020/10/21.
//

#include <iostream>

using namespace std;

class Student{
public:
    Student(int n,float s):num(n),score(s){};
    void change(int n,float s){
        num = n;
        score = s;
    }
    void display(){
        cout << num << " " << score <<endl;
    }

private:
    int num;
    float score;
};

void fun(Student& stu,int n,float s){
    stu.change(n,s);
    stu.display();
}

int main(){
    Student stud(100,78.5);
    stud.display();
    fun(stud,101,80.5);
    return 0;
}