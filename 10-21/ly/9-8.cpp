#include <iostream>
using namespace std;

class Students
{
public:
    Students(int n, float s) : num(n), score(s){};
    void update(int n, float s)
    {
        num = n;
        score = s;
    }
    void display()
    {
        cout << num << " " << score << endl;
    }

private:
    int num;
    float score;
};

void fun(Students &stu, int n, float s)
{
    stu.update(n, s);
    stu.display();
}

int main()
{
    Students stud(100, 78.5);
    stud.display();
    fun(stud, 101, 80.5);
    return 0;
}