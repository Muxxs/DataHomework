//
// Created by Muxxs on 2020/9/23.
//

#include <iostream>
#include <sstream>
#include <fstream>

int counting=0;
int Nums[10];
using namespace std;

void GetPerWord(string s){
    string One="";
    string Space=" ";
    string NuLL="";
    for (int i = 0; i < sizeof(s)/(sizeof(s[0])*sizeof(char)); i++)
    {
        if (s[i] != Space[0] and s[i]!=NuLL[0])
        {
            One+=s[i];
        }else{

                if (One!=""){
                    Nums[counting++]=stoi(One);
                    One = "";
                }
        }
    }
}

void NumsOperation(){
    for (int j = 0; j < 10; ++j) {
        if (Nums[j]==0){
            break;
        } else {
            cout << Nums[j] << ":" << endl;
        }
        if (!Nums[j]%3 && !Nums[j]%5 && !Nums[j]%7)
        {
            cout << "能同时被3，5，7 整除"<<endl;
        } else{
            cout << "不能被3，5，7整除"<<endl;
        }
        int count=0;
        for (int i = 0; i < 10; ++i) {
            if (Nums[i]==0){
                break;
            }
            if (i!=j && Nums[j]%Nums[i]==0){
                if(++count==2){
                    break;
                }
            }
        }
        if (count==2){
            cout << "能被其中两个数整除" << endl;
        }else if(count==1){
            cout << "能被其中一个数整除" << endl;
        }
    }
}


int main(int argc, char const *argv[])
{
    string s;
    ifstream in("abc.txt");
    for (string i; getline(in, s);)
    {
        s.erase(s.length()-1,2);
        GetPerWord(s);
    }
    NumsOperation();
    return 0;
}

