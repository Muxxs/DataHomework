//
// Created by Muxxs on 2020/9/24.
//

#include <iostream>

using namespace std;
string Res;

void Operation(int Number){
    Res += to_string(Number%10);
    Number/=10;
    if (Number==0){
        return;
    } else{
        Operation(Number);
    }
}

void ToRight(){
    string Result=Res;
    for (int i = 0; i < Res.length(); ++i) {
        Result[Res.length()-i-1]=Res[i];
    }
    Res = Result;
}

int main(){
    int num;
    cin >> num;
    Operation(num);
    ToRight();
    cout << Res;
}