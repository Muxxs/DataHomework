//
// Created by Muxxs on 2020/10/1.
//

#include "encode.h"
#include <iostream>
using namespace std;

string Encode(string str){
    string result=str;
    for(int i=1; i<str.length(); i++){
        result[i] += key[i%7]-'0';
        if(result[i]>'z')
            result[i] = result[i]%(122-32+1)+32;   //'z'-' '+1=122-32+1=91;
    }
    return result;
}