//
// Created by Muxxs on 2020/11/22.
//

#include <iostream>
using namespace std;
class Point{
public:
    Point(int Col){
        color = Col;
    };
    ~Point(){
        cout << "executing Point destructor" << endl;
    }

private:
    int color;
};

class Circle: public Point{
public:
    Circle(int Col , int Rad):Point(Col){
        radius = Rad;
    }
    ~Circle(){
        cout << "executing Circle destructor" << endl;
    }
private:
    int radius;
};

int main(){
    Point *p = new Circle(1,1);
    Circle *gradl = new Circle(1,1);
    delete p;
    // executing Point destructor
    // 只是Point的析构函数
    delete gradl;
    // executing Circle destructor
    // executing Point destructor
    // 执行Circle和Point的析构函数
    return 0;
}