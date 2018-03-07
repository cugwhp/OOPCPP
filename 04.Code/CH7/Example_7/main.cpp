#include <iostream>
#include "CollegeStu.h"

using namespace std;

int main()
{
    Person      per("Person", 18);
    Student     stu("Student", 18, 11317102, 90);
    CollegeStu  cStu("CollegeStu", 18, 11317102, 90, "RS");

    cout << "Print Person Info :" << endl;
    per.Print(cout);

    cout << "Print Student Info :" << endl;
    stu.Print(cout);

    cout << "Print CollegeStu Info :" << endl;
    cStu.Print(cout);

    return 0;
}
