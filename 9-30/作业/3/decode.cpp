//
// Created by Muxxs on 2020/10/3.
//

#include "decode.h"
#include <iostream>
using namespace std;

string Decode(string str){
    string result=str;
    for(int i=1; i<str.length(); i++){
        if(result[i]>'z')
            result[i] -= 91;   //'z'-' '+1=122-32+1=91;
        result[i] -= key[i%7]-'0';
    }
    return result;
}