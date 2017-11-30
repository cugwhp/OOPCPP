#include <iostream>
#include "Complex.h"

using namespace std;

/// ¸´ÊıÀàµÄ²âÊÔ
int main()
{
    complex     c(1,3);     /// 1+3i
    complex     d(2,4);     /// 2+4i

    cout << (c+d) << endl;  /// ²âÊÔ+
    cout << (c-d) << endl;  /// ²âÊÔ-

    /// ²âÊÔ /
    complex     e = c/d;
    cout << e << endl;  ///²âÊÔÊä³ö

    cout << d*e << endl;    ///²âÊÔ*

    return 0;
}
