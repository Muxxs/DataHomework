//
// Created by Muxxs on 2020/10/14.
//

#include <iostream>

using namespace std;

struct Student
{
    int Num;
    int Score;
};

int Max(Student *student, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((*student).Score >= max)
            max = (*student).Score;
        if (i != n - 1)
            student++;
    }
    return max;
}

int main()
{
    int n = 3; // 个数
    Student students[3];
    for (int i = 0; i < n; ++i)
    {
        cout << "请输入第" << i + 1 << "个学生的学号：";
        cin >> students[i].Num;
        cout << "请输入第" << i + 1 << "个学生的成绩：";
        cin >> students[i].Score;
    }
    int max = Max(&students[0], n);
    cout << "Max :" << max << endl;
}