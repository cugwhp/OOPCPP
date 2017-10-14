```c++
/* 有关循环结构的示例代码
 * 
*/
#include <iostream>		//import io library
using namespace std;

// main function
int main()
{
  // 输入一个正整数，我们计算从1-正整数的和
  int	iNum;		//存放输入的正整数
  int	iSum = 0;	//存放和
  cout << "Input an integer number: ";
  cin >> iNum;
  
  // while loop
  int	i = iNum;
  while (i>0)	//循环条件，i>0 is true, loop continues, otherwise, loop stops.
  {
    iSum += i;	//equal iSum = iSum + i;
    i--;	//equal i=i-1;
  }
  
  // for loop
  for (i=iNum; i>0; i--)	//把while中几个与循环变量i相关的语句，整合到一行，其实是3条语句
  {
      iSum += i;	// equal iSum = iSum + i;
  }
  
  // do... while loop
  i = iNum;
  do
  {
  	iSum += i;
    i--;
  }while(i>0);
  
  /* 比较下这3个循环
   * 1. 这3类循环是否等价
   * 2. 这3类循环的含义是否一致
   * 3. 此处的do...while循环求和，有没有什么问题？
  */
  
  return 0;
}

```

