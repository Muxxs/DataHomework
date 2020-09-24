//
// Created by Muxxs on 2020/9/23.
//

#include <iostream>
using namespace std;

int main(){
    int days,peaches=1;
    cin >> days;
    for (int i = 0; i < days; ++i) {
        peaches+=1+peaches;
    }
    cout << peaches << endl;
}