
#include <iostream>

using namespace std;

typedef int SElementType;

class Stack
{
private:
    SElementType *top;
    SElementType *base;
    int size;

public:
    Stack(int size){
        base = (SElementType *)malloc(sizeof(SElementType) * size);
        top = base;
        size = 0;
    }
    void push(SElementType s)
    {
        *(top++) = s;
        size++;
    }
    void pop(){
        top--;
        size--;
    }
    void show_value(){
        SElementType *Pointer = base;
        for (int i = 0; i < size; i++)
        {
            cout << "第" << i+1 << "个数字是:" <<  *(Pointer++) << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Stack s(10);
    s.push(1);
    s.push(2);
    s.pop();
    s.show_value();
    return 0;
}
