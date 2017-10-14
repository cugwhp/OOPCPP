> 输入输出示例代码

```c++
#include <iostream>	//import io libaray
using namespace std;

// 主函数
int main()
{
	//1.输出 cout
	cout << "Hello World." << endl;	//endl meaning end line
	cout << "My Age is " << 19 << endl;
    cout << "My Height is " << 1.75 << "m" << endl;
    
	//2.输入 cin
	cout << "Input 2 Int Number: ";
  	int		a, b;	// 定义变量, 等同于在寄存器中分配存放2个整数的存储空间
	cin >> a >> b;	// 变量a和b等同于存放整数的地址空间的门牌号
	/*	有关变量的含义 
		# 比如我们使用导航系统时，我们输入“中国地质大学（武汉）西区大门”,
        # 导航系统就会跳转到地大。在导航系统里，这个指定的位置是用
        # 经纬度坐标来表示的。但我们记不住地大的经纬度坐标，所以我们就会
        # 用“中国地质大学（武汉）西区大门”这个地名来替代经纬度坐标。此处
        # 的变量a和b就等同于“中国地质大学（武汉）西区大门”的作用，起到简便易记。
        # 所以变量的名称一定要有含义，不可以随便命名为“阿猫”、“阿狗”、“阿三”。#
	*/
    
	//3.输出a+b
	cout << a << "+" << b << "=" << a+b << endl;
    
    // 返回
    return 0;
}
```

