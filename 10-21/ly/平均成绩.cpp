#include <iostream>
using namespace std;
class student{
private:
    string num;
    string name;
    int Chinese;
    int Math;
    int English;
public:
    static int Chinese_sum;
    static int Math_sum;
    static int English_sum;
    static int count;
    student(string A,string B,int C,int D,int E):num(A),name(B),Chinese(C),Math(D),English(E){
        student::Chinese_sum+=Chinese;
        student::Math_sum+=Math;
        student::English_sum+=English;
        count++;
    };
    static void display(){
        cout << "平均成绩:数学" << student::Math_sum/count << ",语文"<< student::Chinese_sum/count <<",英语:"<<student::English_sum/count<<endl;
    }
};

int student::Chinese_sum=0;
int student::Math_sum=0;
int student::English_sum=0;
int student::count=0;

int main(){
    student stdu("111","luoyang",1,2,3);
    student stdu1("111","luoyangyang",3,2,1);
    stdu.display();
    return 0;
}