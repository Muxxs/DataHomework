//
// Created by Muxxs on 2020/10/1.
//

#include <iostream>

using namespace std;

void High(){}

void Middle(){}

void Low() {}

void Quit() {}

int main(){
    cout << "请输入序号:" ;
    int m;
    cin >> m;
    if (m==1){
        High();
    }else if (m==2){
        Middle();
    }else if (m==3){
        Low();
    } else{
        Quit();
    }
}

