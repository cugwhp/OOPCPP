/******************************************************************************
// 输入一个0-100的分数，输出成绩等级A-E，输入<0,退出
******************************************************************************/
#include <iostream>

using namespace std;

enum Grade{A, B, C, D, E};  //成绩枚举变量

int main()
{
    int     i;
    char    c;
    for (i=0; i<256; ++i)
    {
        cout << i << "\t";

        c = (char)i;
        cout << c << "\t";

    }
    cout << endl;
    return 0;

    int     score;
    enum Grade      level;
    do
    {
        cout << "Input a 0-100 score(<0 return) : ";
        cin >> score;

        // 根据分数，判断等级
        switch(score/10)
        {
        case 10:
        case 9:
            level = A;
            break;
        case 8:
            level = B;
            break;
        case 7:
            level = C;
            break;
        case 6:
            level = D;
            break;
        default:
            level = E;
            break;
        }

        cout << "score is " << score;
        cout << ", grade is ";
        cout << char(level+65) << endl << endl;
    }while(score > 0);

    return 0;
}
