//
// Created by Muxxs on 2020/10/7.
//

#include "arraymax.h"

void Array_max::set_value() {
    for (int & i : array) {
        cin >> i;
        if (max < i){
            max = i;
        }
    }
}

void Array_max::show_value() {
    for(int &i : array){
        cout << i << " ";
    }
    cout << endl;
}

void Array_max::max_value() {
    cout << "Max : " << max << endl;
}