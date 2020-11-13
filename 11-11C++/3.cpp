//
// Created by Muxxs on 2020/11/11.
//

#include <iostream>
#include <math.h>
using namespace std;

class TR1 {
private:
    double x, y, z;
public:
    TR1(double x1, double y1, double z1) {
        if (x1 + y1 <= z1 or x1 + z1 <= y1 or z1 + y1 <= x1) {
            cout << "ERROR" << endl;
            return;
        } else {
            x = x1;
            y = y1;
            z = z1;
        }
    }

    double area() {
        return sqrt((x + y + z) / 2.0 * ((x + y + z) / 2.0 - x) * ((x + y + z) / 2.0 - y) * ((x + y + z) / 2.0 - z));
    }

    double peri() {
        return x + y + z;
    }
};
class COL: public TR1{
private:
    double height;
public:
    COL(double x1, double y1, double z1, double h) : TR1(x1, y1, z1) {
        height = h;
    }
    double volume(){
        return area()*height;
    }
    double COLarea(){
        return area()*2.0+peri()*height;
    }
};

int main(){
    double x,y,z,h;
    cin >> x >> y >> z >> h;
    COL co(x,y,z,h);
    TR1 *tr;
    tr = &co;
    cout << "volume : " << co.volume() << endl;
    cout << "area : " << tr->area() << endl;
}