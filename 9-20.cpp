#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define LIST_INIT_SIZE 80

typedef struct
{
    int no;
    char name[20];
    int grade;
} Student;

typedef struct
{
    int Length;
    Student *elements;
    int ListSize;
} SqList;

int CreateList(SqList &L, int n)
{
    L.elements = (Student *)malloc(sizeof(Student) * LIST_INIT_SIZE);
    L.Length = n;
    L.ListSize = LIST_INIT_SIZE;
    if (!L.elements)
    {
        return 1;
    }
    int No;
    char Name[20];
    int Grade;
    Student *q = L.elements;
    for (int i = 0; i < n; i++)
    {
        std::cout << "No:";
        std::cin >> No;
        std::cout << "Grade:";
        std::cin >> Grade;
        std::cout << "Name:";
        scanf("%s", Name);
        q->no = No;
        for (int x = 0; x < 20; x++)
        {
            q->name[x] = Name[x];
        }
        q->grade = Grade;
        *q++;
    }
}

int ListTraverse_Sq(SqList L)
{
    Student *q = L.elements;
    for (int i = 0; i < L.Length; i++)
    {
        printf("No:%d Grade:%d Name:%s\n", q->no, q->grade, q->name);
        *q++;
    }
}

int LocateElem_Sq(SqList L, char S[20])
{
    Student *q = L.elements;
    int NamePoint;
    for (int i = 0; i < L.Length; i++)
    {
        NamePoint = 0;
        for (int x = 0; x < 20; ++x)
        {
            if (S[x] == q->name[x] && x == 19)
            {
                NamePoint = 1;
                printf("No:%d Grade:%d Name:%s\n", q->no, q->grade, q->name);
                break;
            }
        }
        if (!NamePoint)
        {
            break;
        }
        q++;
    }
    return 0;
}

int GetElem_Sq(SqList L, int i, Student &S)
{
    Student *Point = L.elements;
    if (i > L.Length)
        return 0;
    if (i <= 0)
        return 0;
    Point += i - 1;
    S.grade = Point->grade;
    S.no = Point->no;
    for (int j = 0; j < 20; ++j)
    {
        S.name[j] = Point->name[j];
    }
    return 1;
}

int ListInsert_Sq(SqList &L, int i, Student S)
{
    if (i > L.Length + 1 or i < 0)
        return 0;
    Student *Point = L.elements;
    if (i == L.Length + 1)
    {
        for (int j = 0; j < L.Length; ++j)
        {
            *Point++;
        }
        for (int k = 0; k < 20; ++k)
        {
            Point->name[k] = S.name[k];
        }
        Point->grade = S.grade;
        Point->no = S.no;
        L.Length += 1;
        return 1;
    }
    else
    {
        for (int l = 0; l < L.Length; ++l)
        {
            *Point++;
        }
        Student *pre = Point;
        *pre--;
        for (int j = 1; j <= L.Length - i; ++j)
        {
            for (int k = 0; k < 20; ++k)
            {
                Point->name[k] = pre->name[k];
            }
            Point->grade = pre->grade;
            Point->no = pre->no;
            *Point--;
            *pre--;
        }
        for (int k = 0; k < 20; ++k)
        {
            Point->name[k] = pre->name[k];
        }
        Point->grade = pre->grade;
        Point->no = pre->no;
        pre->no = S.no;
        pre->grade = S.grade;
        for (int k = 0; k < 20; ++k)
        {
            pre->name[k] = S.name[k];
        }
        L.Length++;
        return 1;
    }
}

int ListDelete_Sq(SqList &L, int i)
{
    if (i > L.Length + 1 or i < 0)
        return 0;
    Student *Point = L.elements;
    i -= 1;
    for (int j = 0; j < i; ++j)
    {
        Point++;
    }
    Student *Next = Point;
    Next++;
    for (int k = 0; k < L.Length - i; ++k)
    {
        Point->grade = Next->grade;
        Point->no = Next->no;
        for (int j = 0; j < 20; ++j)
        {
            Point->name[j] = Next->name[j];
        }
        *Point++;
        *Next++;
    }
    L.Length--;
}
int main(int argc, char const *argv[])
{
    SqList L;
    int n;
    std::cout << "请输入数量:";
    std::cin >> n;
    CreateList(L, n);    // 建立表，n个人
    char SearchName[20]; // 要查找的人名
    std::cout << "----------------------" << std::endl;
    std::cout << "遍历数据:" << std::endl;
    std::cout << "共有" << L.Length << "个数据" << std::endl;
    ListTraverse_Sq(L); // 遍历数据
    std::cout << "----------------------" << std::endl;
    std::cout << "插入数据:" << std::endl;
    Student S;
    std::cout << "插入位置:";
    std::cin >> n;
    std::cout << "No:";
    std::cin >> S.no;
    std::cout << "Grade:";
    std::cin >> S.grade;
    std::cout << "Name:";
    std::cin >> S.name;
    ListInsert_Sq(L, n, S); // 遍历数据
    std::cout << "----------------------" << std::endl;
    std::cout << "遍历数据:" << std::endl;
    std::cout << "共有" << L.Length << "个数据" << std::endl;
    ListTraverse_Sq(L); // 遍历数据
    std::cout << "----------------------" << std::endl;
    std::cout << "删除数据:" << std::endl;
    std::cout << "删除第几个:";
    std::cin >> n;
    ListDelete_Sq(L, n); // 遍历数据
    std::cout << "----------------------" << std::endl;
    std::cout << "遍历数据:" << std::endl;
    std::cout << "共有" << L.Length << "个数据" << std::endl;
    ListTraverse_Sq(L); // 遍历数据
    std::cout << "----------------------" << std::endl;
    std::cout << "请输入要查找的姓名:";
    std::cin >> SearchName;
    std::cout << "查询结果:" << std::endl;
    LocateElem_Sq(L, SearchName); // print出数据
    Student ST;
    GetElem_Sq(L, 2, ST);
    printf("No:%d Grade:%d Name:%s\n", ST.no, ST.grade, ST.name);
    std::cout << "----------------------" << std::endl;
    return 0;
}
