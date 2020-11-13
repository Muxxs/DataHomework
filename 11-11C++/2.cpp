//
// Created by Muxxs on 2020/11/13.
//

#include <iostream>
using namespace std;

class Teacher
{
public:
    string title;
    string name;
    int age;
    char sex;
    string address;
    string phone;
};

class Cadre
{
public:
    string name;
    int age;
    char sex;
    string address;
    string phone;
    string post;
};

class Teacher_Cadre : public Teacher, public Cadre
{
public:
    int wages;
    Teacher_Cadre(string Title, string Post, string Name, int Age, char Sex, string Address, string Phone, int Wages);
    void display();
};

Teacher_Cadre::Teacher_Cadre(string Title, string Post, string Name, int Age, char Sex, string Address, string Phone, int Wages)
{
    Teacher::title = Title;
    Cadre::post = Post;
    Teacher::name = Cadre::name = Name;
    Teacher::age = Cadre::age = Age;
    Teacher::sex = Cadre::sex = Sex;
    Teacher::address = Cadre::address = Address;
    Teacher::phone = Cadre::phone = Phone;
    wages = Wages;
}
void Teacher_Cadre::display()
{
    cout << "Title:" << Teacher::title << endl;
    cout << "Name:" << Teacher::name << endl;
    cout << "age:" << Teacher::age << endl;
    cout << "sex:" << Teacher::sex << endl;
    cout << "address:" << Teacher::address << endl;
}

int main()
{
    Teacher_Cadre Peo("High", "Monster", "WangJiao", 19, 'M', "Beijing", "110", 10000);
    Peo.display();
    cout << "wages:" << Peo.wages << endl;
    cout << "post:" << Peo.post << endl;
}