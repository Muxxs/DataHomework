//
// Created by Muxxs on 2020/10/21.
//

#include <iostream>

using namespace std;

class student{
private:
    string num;
    string name;
    int chinese;
    int math;
    int english;
    static int chinese_all;
    static int math_all;
    static int english_all;
    static int count;
public:
    student(string A,string B,int C,int D,int E):num(A),name(B),chinese(C),math(D),english(E){
        student::chinese_all+=chinese;
        student::math_all+=math;
        student::english_all+=english;
        count++;
    };
    static void display(){
        cout << "平均成绩:数学" << student::math_all/count << ",语文"<< student::chinese_all/count <<",英语:"<<student::english_all/count<<endl;
    }
};

int student::chinese_all=0;
int student::math_all=0;
int student::english_all=0;
int student::count=0;

int main(){
    student stdu("111","wj",1,2,3);
    student stdu1("111","wj",3,2,1);
    stdu.display();
    return 0;
}