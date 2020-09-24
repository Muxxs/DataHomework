//
// Created by Muxxs on 2020/9/24.
//

#include <iostream>

using namespace std;

bool Su(int Num){
    for (int i = 1; i < Num; ++i) {
        if (Num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cin >> num;
    if (Su(num)){
        cout << "是素数" << endl;
    } else{
        cout << "不是素数" << endl;
    }
}