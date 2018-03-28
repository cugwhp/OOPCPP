#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec1;

    for (int i=0; i<10; i++)
    vec1.push_back(i*i+5);

    vec1.Size();
    vec1[0];    //operator[]
    vec1.pop_back();

    vector<int>::iterator iter;
    iter = vec1.begin();
    iter = vec1.end();

    sort(vec1.begin(), vec1.end,)


    iter++;
    !=
    ==
    (*iter)


    return 0;
}
