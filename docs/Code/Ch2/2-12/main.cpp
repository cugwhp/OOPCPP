#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 定义结构体
struct student
{
    int     num;
    string  name;
    char    gender;
    int     age;
};

int main()
{
    student stu={97001,"Lin Lin",'F',19};
    cout<<setw(7)<<stu.num<<setw(20)<<stu.name<<setw(3)<<stu.gender<<setw(3)<<stu.age;

    return 0;
}
