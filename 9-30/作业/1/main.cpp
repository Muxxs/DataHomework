//
// Created by Muxxs on 2020/10/1.
//

#include <iostream>
#include "High.cpp"
#include "Middle.cpp"
#include "Low.cpp"
#include "Quit.cpp"

using namespace std;

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

