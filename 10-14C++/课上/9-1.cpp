//
// Created by Muxxs on 2020/10/14.
//

#include <iostream>
using namespace std;
class Time
{
public:
    Time(int Hour, int Min, int Sec);
    Time(int Hour, int Min);
    Time(int Hour);

    void set_time();
    void show_time();

private:
    int hour;
    int minute;
    int sec;
};

void Time::set_time()
{
    cin >> hour;
    cin >> minute;
    cin >> sec;
}

void Time::show_time()
{
    cout << hour << ":" << minute << ":" << sec << endl;
}

Time::Time(int Hour, int Min, int Sec)
{
    hour = Hour;
    minute = Min;
    sec = Sec;
}

Time::Time(int Hour, int Min)
{
    hour = Hour;
    minute = Min;
}

Time::Time(int Hour) : hour(Hour) {}

int main()
{
    Time t1(1, 1, 1);
    t1.show_time();
    Time t2(2, 2, 2);
    t2.show_time();
    return 0;
}
