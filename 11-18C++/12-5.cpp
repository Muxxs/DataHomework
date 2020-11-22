//
// Created by Muxxs on 2020/11/22.
//

#include <iostream>
using namespace std;
#include <math.h>
#define pi 3.1415926

class Shape{
public:
    virtual double area(){};
};

class Circle : public Shape{
public:
    Circle(int rad){
        Rad = rad;
    }
    virtual double area(){
        return pi*Rad*Rad;
    }
private:
    int Rad;
};

class Triangle : public Shape{
private:
    int x,y,z;
public:
    Triangle(int x1,int y1,int z1):x(x1),y(y1),z(z1){};
    virtual double area(){
        return 0.25*(double )sqrt((x+y+z)*(x+y-z)*(x+z-y)*(y+z-x));
    }
};

class Rectangle : public Shape{
private:
    int a,b;
public:
    Rectangle(int A,int B):a(A),b(B){};
    virtual double area(){
        return a*b;
    }
};

class Square : public Shape{
private:
    int a;
public:
    Square(int A):a(A){};
    virtual double area(){
        return a*a;
    }
};

class Trapezoid : public Shape{
private:
    int a,b,h;
public:
    Trapezoid(int A,int B,int H):a(A),b(B),h(H){};
    virtual double area(){
        return (a+b)*h/2;
    }
};

int main(){
    Shape *pointers[5];
    pointers[0]=new Trapezoid(1,1,1);
    pointers[1]=new Square(1);
    pointers[2]=new Rectangle(1,1);
    pointers[3]=new Circle(1);
    pointers[4]=new Triangle(3,4,5);
    cout << "梯形面积:" << pointers[0]->area() << endl;
    cout << "正方形面积:" << pointers[1]->area() << endl;
    cout << "矩形面积:" << pointers[2]->area() << endl;
    cout << "圆形面积:" << pointers[3]->area() << endl;
    cout << "三角形面积:" << pointers[4]->area() << endl;
    // 梯形面积:1
    // 正方形面积:1
    // 矩形面积:1
    // 圆形面积:3.14159
    // 三角形面积:6
}