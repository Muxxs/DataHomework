//
// Created by Muxxs on 2020/12/2.
//

#include <iostream>

using namespace std;

template<class numtype>
class Compare {
private:
    numtype x, y;
public:
    Compare(numtype a, numtype b) : x(a), y(b) {}

    numtype max();

    numtype min();
};

template<class numtype>
numtype Compare<numtype>::max() {
    return (x < y ? y : x);
}

template<class numtype>
numtype Compare<numtype>::min() {
    return (x > y ? y : x);
}

int main() {
    Compare<int> cmpl(3, 7);
    cout << cmpl.max() << " is the Maximum of two integer numbers." << endl;
    cout << cmpl.min() << " is the Minimum of two integer numbers." << endl;
    Compare<float> cmpl1(45.78, 93.6);
    cout << cmpl1.max() << " is the Maximum of two float numbers." << endl;
    cout << cmpl1.min() << " is the Minimum of two float numbers." << endl;
    Compare<char> cmpl2('a', 'A');
    cout << cmpl2.max() << " is the Maximum of two characters." << endl;
    cout << cmpl2.min() << " is the Minimum of two characters." << endl;
    return 1;
}
//    7 is the Maximum of two integer numbers.
//    3 is the Minimum of two integer numbers.
//    93.6 is the Maximum of two float numbers.
//    45.78 is the Minimum of two float numbers.
//    a is the Maximum of two characters.
//    A is the Minimum of two characters.