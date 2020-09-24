//
// Created by Muxxs on 2020/9/23.
//

#include <iostream>

using namespace std;
void PrintSpace(int Spaces){
    for (int i = 0; i < Spaces; ++i) {
        cout << " ";
    }
}
void PrintST(int n){
    for (int i = 0; i < n; ++i) {
        if (i%2==0){
            cout << "S";
        } else{
            cout << "T";
        }
    }
}

int main(){
    int N=19;
    for (int NPre=N; NPre >= 0 ; --(--NPre)) {
        PrintSpace((N-NPre)/2);
        PrintST(NPre);
        PrintSpace((N-NPre)/2);
        cout<<endl;
    }
}