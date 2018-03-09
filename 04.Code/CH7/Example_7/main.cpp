#include <iostream>
#include "CollegeStu.h"

using namespace std;

void PrintInfo(const Person* ptPerson)
{
    if (ptPerson)
        ptPerson->Print(cout);
}

void PrintInfo(const Person& onePerson)
{
    onePerson.Print(cout);
}

int main()
{
    Person      per("Person", 18);
    Student     stu("Student", 18, 11317102, 90);
    CollegeStu  cStu("CollegeStu", 18, 11317102, 90, "RS");

    cout << "Print Person Info :" << endl;
    PrintInfo(&per);
    PrintInfo(per);
    per.Print(cout);
    cout << "------------------" << endl;

    cout << "Print Student Info :" << endl;
    PrintInfo(&stu);    //Student*
    Person* p = &stu;
    PrintInfo(p);

    PrintInfo(stu);     //Student&
    stu.Print(cout);
    cout << "------------------" << endl;

    cout << "Print CollegeStu Info :" << endl;
    PrintInfo(&cStu);
    PrintInfo(cStu);
    cStu.Print(cout);
    cout << "------------------" << endl;

    return 0;
}
