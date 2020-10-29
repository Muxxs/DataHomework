#include <iostream>

using namespace std;

class Date;
class Time
{
public:
    friend class Date;
    Time(int, int, int);
    void display(Date &);

private:
    int hour, minute, second;
};

class Date
{
public:
    Date(int, int, int);
    friend class Time;

private:
    int year, month, day;
};

Time::Time(int Hour, int Min, int Sec): hour(Hour), minute(Min),  second(Sec){};

void Time::display(Date &d)
{
    cout << d.month << "/" << d.year << "/" << d.day << endl;
    cout << hour << ":" << minute << ":" << second << endl;
};

Date::Date(int m, int y, int d)
{
    month = m;
    day = d;
    year = y;
}

int main()
{
    Time t1(10, 13, 56);
    Date d1(12, 25, 2005);
    t1.display(d1);
    return 0;
}