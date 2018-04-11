#include <iostream>
#include <deque>
using namespace std;
int findLast(int n, int k, int m) //定义函数，带有三个int型形参，自身返回int型，实现的功能是找到最后出列的那一个人
{
    deque<int> ideq; //创建deque容器，存放以k为首的n个元素
    for (int x = k; x != n + 1; ++x)
    {
        ideq.push_back(x);
    }
    for (int y = 1; y != k; ++y)
    {
        ideq.push_back(y);
    }
    deque<int>::iterator iter = ideq.begin(); //定义迭代器
    while (ideq.size() != 1)//一直循环，直到容器只剩下一个元素为止
    {
        for (int cnt = 1; cnt != m; ++cnt)//循环（m-1）次
        {
            ideq.push_back(*iter); //在尾部添加当前迭代器所指向的元素
            iter = ideq.erase(iter); //删除当前位置的元素，返回的迭代器指向下一位置
        }
        iter = ideq.erase(iter); // 此处意为数到m的人直接出列
    }
    return *iter; //返回剩下的最后一个元素
}
int main()
{
    cout << "The last person:" << endl;
    cout << findLast(9, 1, 5) << endl;
    return 0;
}
