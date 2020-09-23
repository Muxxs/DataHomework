#include <iostream>
using namespace std;

void myswap(int &a, int &b)
{
    int mid =a ;
    a = b;
    b = mid;
}

int main()
{
    int a = 16, b = 48;
    cout << "a=" << a << ",b=" << b << endl;
    myswap(a, b);
    cout << "After Being Swapped:\n";
    cout << "a=" << a << ",b=" << b << endl;
}

