#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <list>
using namespace std;

struct Stu{
    Stu(){nAge=18;Name="1131712";Grade=1;Major="RS";}

    int     nAge;
    string  Name;
    int     Grade;
    string  Major;

    bool operator<(const Stu& s)
    {
        return Name < s.Name;
    }
};


int main()
{
    int     a[] = {1,2,3,4,5};
    vector<int> v1(&a[0], &a[0]+5);
    list<int>   l1(&a[0], &a[0]+5);
    vector<int>::iterator iter1;
    list<int>::iterator iter2;

    iter1 = v1.begin();
    cout << (*iter1) << endl;
    cout << *(iter1+3) << endl;

    iter2 = l1.begin();
    cout << (*iter2) << endl;

    for (iter1=v1.begin(); iter1!=v1.end(); ++iter1)
    {
        cout << (*iter1) << endl;
    }

    for (iter2=l1.begin(); iter2!=l1.end(); ++iter2)
    {
        cout << (*iter2) << endl;
    }

    string      s1;
    set<string> set1;

   s1 = "RS_1";
   set1.insert(s1);

   s1 = "RS_2";
   set1.insert(s1);

   cout << set1.size() << endl;

   set1.insert(s1);
   set1.insert(s1);
   cout << set1.size() << endl;

   set<string>::iterator    iter;
   iter = set1.find(s1);

    s1 = "RS";
    iter = set1.find(s1);

    return 0;
}
