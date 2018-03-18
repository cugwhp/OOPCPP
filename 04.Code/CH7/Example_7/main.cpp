#include <iostream>
#include "CollegeStu.h"

using namespace std;

int main()
{
    Person      per("Person", 18);
    Student     stu("Student", 18, 11317102, 90);
    CollegeStu  cStu("CollegeStu", 18, 11317102, 90, "RS");

    per.Print(cout);
    stu.Print(cout);
    Person* ptobj[] = {&per, &stu, &cStu};
    for (int i=0; i<3; i++)
    {
        ptobj[i]->Print(cout);
    }

    cout << "Print Person Info :" << endl;
    cout << per << endl;
    cout << "------------------" << endl;

    cout << "Print Student Info :" << endl;
    cout << stu << endl;
    cout << "------------------" << endl;

    cout << "Print CollegeStu Info :" << endl;
    cout << cStu << endl;
    cout << "------------------" << endl;

    return 0;
}
