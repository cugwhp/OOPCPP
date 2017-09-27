// 变量作用域
#include <iostream>
using namespace std;

int		i;		//文件作用域

namespace Ns
{
	int		j;		//名字空间作用域
}

// 主函数
int main()
{
	i = 5;	//global
	Ns::j = 6;	//

	{
		using namespace Ns;
		 int		i = 7;	//局部作用域

		 cout << "i = " << i << endl;	//local
		 cout << "Ns::j = " << j << endl;
	}

	cout << "i = " << i << endl;	//global
	
	return 0;
} 