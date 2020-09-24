//
// Created by Muxxs on 2020/9/24.
//

#include <iostream>

using namespace std;
void ChangeAB(int &a,int &b){
    if (a>b){
        int mid = a;
        a = b;
        b = mid;
    }
}

int Big(int a,int b){
    if (a==b) return a;
    ChangeAB(a,b);
    for (int i = a; i >= 1; --i) {
        if (a%i==0 and b%i==0) return i;
    }
}

int Min(int a,int b){
    if (a==b) return a;
    ChangeAB(a,b);
    int MinNum=b;
    while (true){
        if (MinNum%a==0 && MinNum%b==0){
            return MinNum;
        }else{
            MinNum++;
        }
    }
}

int main(){
    int a,b;
    cin >> a;
    cin >> b;
    cout << "最小公倍数:" << Min(a,b) <<endl;
    cout << "最大公因数:" << Big(a,b) << endl;
}