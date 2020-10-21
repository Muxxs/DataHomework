//
// Created by Muxxs on 2020/10/20.
//

#include <iostream>
using namespace std;

class Manager
{
public:
    string num;
    static float quantity;
    static float price;
    static float discount;
    static float All;
    static float average;
    Manager(string Num, float Qua, float Pri)
    {
        num = Num;
        quantity += Qua;
        price = Pri;
        if (quantity > 10)
        {
            discount = 0.98;
        }
        else
        {
            discount = 1;
        }
        Manager::Count(Qua);
        Manager::Average();
    }
    static void Count(float Qua){
        All += Qua * discount * price;
    };
    static void Average()
    {
        average = All / quantity;
    }
    void display(){
        cout << "共"  << Manager::quantity << "件, 平均价格:" << Manager::average << "元, 总额:"  << Manager::All << endl;
    }
};

float Manager::quantity=0;
float Manager::discount=0;
float Manager::price=0;
float Manager::All=0;
float Manager::average=0;

int main()
{
    Manager I1("101", 5, 23.5);
    Manager I2("101", 11, 23.5);
    I2.display();
}