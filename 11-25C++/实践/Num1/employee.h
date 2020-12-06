//
// Created by Muxxs on 2020/11/25.
//

#ifndef DATAHOMEWORK_EMPLOYEE_H
#define DATAHOMEWORK_EMPLOYEE_H

#include "employee.h"
#include <iostream>
#include <vector>
using namespace std;

int day31[] = {1,3,5,7,8,10,12};
int day30[] = {4,6,9,10};
class Date{
private:
    int year;
    int month;
    int date;
public:
    void set(int Year,int Month,int Day){
        year = Year;
        month = Month;
        date = Day;
    }
    bool checkMonth(){
        return month<=12 and month >0;
    }
    bool checkDay(){
        for(int i:day31){
            if (month==i){
                return date == 31;
            }
        }
        for(int i:day30){
            if (month==i){
                return date == 30;
            }
        }
        if (date==2) return year%4==0?date==29:date==28;
        return false;
    }
    int GetDay() const{
        return date;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
};

class employee {
private:
    string name;
    string ID;
public:
    Date Birth;
    employee(string Name , string Id , int year, int month, int day):name(Name),ID(Id){
        Birth.set(year,month,day);
    };
    void changeName(string Name){
        name = Name;
    }
    void Display(){
        cout << "Name : " << name << endl;
        cout << "ID : " << ID << endl;
        cout << "Birth : " << Birth.GetYear() << "-" << Birth.GetMonth() << "-" << Birth.GetDay() << endl;
    }
    virtual int price(){}
};

class SalariedEmployee : public employee{
private:
    int Price = 1000;
public:
    SalariedEmployee(string name, string id, int year, int month, int day) : employee(name, id, year, month, day) {
    }
    virtual int price(){
        return Price;
    }
    void ChangePrice(int prices){
        Price = prices;
    }
    void show(){
        cout << "------------------" << endl;
        Display();
        cout << "price : " << Price << endl;
        cout << "------------------" << endl;
    }
};

class CommissionEmployee : public employee{
private:
    int nums = 0;
    float proportion = 0.3;
    float Price = 0;
public:
    CommissionEmployee(string name, string id, int year, int month, int day,int Num) : employee(name, id, year, month, day),nums(Num) {
        Price = nums * proportion;
    }
    void ChangePrice(int prices){
        Price = prices;
    }
    virtual int price(){
        return Price;
    }
    void show(){
        cout << "------------------" << endl;
        Display();
        cout << "price : " << Price << endl;
        cout << "------------------" << endl;
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee{
private:
    int BasePrice = 1000;
    int Price = 0;
public:
    BasePlusCommissionEmployee(string name, string id, int year, int month, int day , int nums) : CommissionEmployee(name, id, year, month, day,nums){
        Price = CommissionEmployee::price() + BasePrice;
    }
    void ChangePrice(int prices){
        Price = prices;
    }
    virtual int price(){
        return Price;
    }
    void show(){
        cout << "------------------" << endl;
        Display();
        cout << "price : " << Price << endl;
        cout << "------------------" << endl;
    }
};

class HourlyEmployee : public employee{
private:
    int perhour = 40;
    int Price = 40;
    int hour = 0;
public:
    HourlyEmployee(string name, string id, int year, int month, int day,int hours) : employee(name, id, year, month, day) , hour(hours){
        Price = perhour * hour;
    }
    void ChangeHour(int Hour){
        hour += Hour;
        Price = perhour * hour;
    }
    virtual int price(){
        return Price;
    }
    void show(){
        cout << "------------------" << endl;
        Display();
        cout << "price : " << Price << endl;
        cout << "------------------" << endl;
    }
};

#endif //DATAHOMEWORK_EMPLOYEE_H
