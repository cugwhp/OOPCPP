#include <iostream>
#include <string>

using namespace std;

int main()
{
    int     num;
    int     sum = 0;
    int     i;

    do
    {
        cout << "Input a int num: ";
        cin >> num;

        // 1+2+...+num (num/2)
        for (i=1,sum=0; i<=num; i++)
        {
            sum += i;
        }
        cout << "sum = " << sum << endl;

    }while(num>0);

    /*
      int     classNo;
      string  strName;

      cout << "Enter a classNo : ";
      cin >> classNo;


      switch(classNo)
      {
      case 113:
      case 114:
      case 115:
          strName = "IS";
          cout << strName << endl;
          break;
      default:
          strName = "Unknown";
          cout << strName << endl;
          break;
      }
      */

    return 0;
}
