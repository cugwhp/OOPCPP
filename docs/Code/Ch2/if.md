```c++
#include <iostream>		//import io library
using namespace std;	//

// main function
int main()
{
  	// 输入分数，判断成绩是否及格
  	int	iScore;
  	cout << "Input a score : ";
  	cin >> iScore;
  	
  	// 分支机构
  	if (iScore < 60)
    {
        cout << "Not pass (:V:)." << endl;
    }
  	else
    {
      	// if (iScore > 90) ??
        cout << "Pass (:^:)." << endl;
    }
  
    return 0;
}
```

