//
// Created by Muxxs on 2020/10/1.
//

#include <iostream>
#include <string>
#include "encode.cpp"
#include "decode.cpp"

using namespace std;
int main(){
    string String,encode,decode;
    getline(cin,String);
    cout << "Encode:" << endl;
    encode=Encode(String);
    cout << encode << endl;
    cout << "Decode:" << endl;
    decode = Decode(encode);
    cout << decode << endl;
}