//
// Created by Muxxs on 2020/12/2.
//

#include <iostream>
using namespace std;

template <typename AddType>
AddType Add(AddType a,AddType b){
    return a+b;
}


int main(){
    int a,b;
    cin >>  a >>  b;
    cout << "a + b = " << Add(a,b) << endl;
    return 1;
}