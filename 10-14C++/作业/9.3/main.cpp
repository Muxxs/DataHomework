//
// Created by Muxxs on 2020/10/14.
//

#include <iostream>

using namespace std;

class Date
{
public:
    Date(int = 1, int = 1, int = 2005); //默认为 1， 1， 2005
    void display();

private:
    int month;
    int day;
    int year;
};

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

void Date::display()
{
    cout << month << "/" << day << "/" << year << endl;
}

int main()
{
    Date Bir(10);
    Bir.display();
}
