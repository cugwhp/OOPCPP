#include <iostream>

using namespace std;

int main()
{
    int     a, b, c;
    int     max = a;
    cout << "Input 3 Integers : ";
    cin >> a >> b >> c;

    if (a>b)
    {
        // a is max
        if (a>c)
        {
            max = a;
        }
        else
        {
            max = c;
        }
    }
    else    //a<=b
    {
        if (b>c)
        {
            max = b;
        }
        else
        {
            max = c;
        }
    }


    max = (a>b) ? a : b;
    max = (max>c) ? max : c;

// "¡¥Ω”£∫http://pan.baidu.com/s/1i5oGNK5 "
//"√‹¬Î£∫3rhe"

    cout << "max = " << max << endl;



    return 0;
}
