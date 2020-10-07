//
// Created by Muxxs on 2020/10/7.
//

#include <iostream>
using namespace std;

class Time{
public:
    void set_time(void );
    void show_time(void );

private:
    int hour;
    int minute;
    int sec;
};
Time t;

int main(){
    t.set_time();
    t.show_time();
    return 0;
}

void Time::set_time() {
    cin >> hour;
    cin >> minute;
    cin >> sec;
}

void Time::show_time() {
    cout << hour << ":" << minute << ":" << sec << endl;
}