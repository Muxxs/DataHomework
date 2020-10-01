//
// Created by Muxxs on 2020/10/1.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int a,times=0,time=0;
    string res;
    cin >> a;
    int b = a;
    while (true){
        times++;
        a = a >> 1;
        if (a==0){ break;}
    }
    while (true){
        if (time++<4){
            res=to_string(b%2)+res;
        }
        b = b >> 1;
        if (b==0){ break;}
    }
    cout << res << endl;
}