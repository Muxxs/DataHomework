//
// Created by Muxxs on 2020/10/20.
//

#include <iostream>
using namespace std;

class Control
{
public:
    string num;
    static float quanlity;
    static float price;
    static float discount;
    static float All;
    static float average;
    Control(string Num, float Quanlity, float Pri)
    {
        num = Num;
        quanlity += Quanlity;
        price = Pri;
        if (quanlity > 10)
        {
            discount = 0.98;
        }
        else
        {
            discount = 1;
        }
        Control::Count(Quanlity);
        Control::Average();
    }
    static void Count(float Quanlity){
        All += Quanlity * discount * price;
    };
    static void Average()
    {
        average = All / quanlity;
    }
    void display(){
        cout << "共"  << Control::quanlity << "件, 平均价格:" << Control::average << "元, 总额:"  << Control::All << endl;
    }
};

float Control::quanlity=0;
float Control::discount=0;
float Control::price=0;
float Control::All=0;
float Control::average=0;

int main()
{
    Control I1("101", 5, 23.5);
    Control I2("101", 11, 23.5);
    I2.display();
}