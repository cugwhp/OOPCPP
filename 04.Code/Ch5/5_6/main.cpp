#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int   a[] = {0, 1, 2, 3, 4, 5};
    int     b[2][3] = {{1,2,3},{4,5,6}};

//    int*    p = b;
    int     (*p)[3] = b;

    cout << b << endl;
    cout << b[0] << endl;
    cout << b[1] << endl;
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << &b[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
