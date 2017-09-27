#include<iostream>
using namespace std;

int main()
{
	int*	ptr_i;		//声明int型指针i_pointer
	int		i;			//声明int型数i

	// const int* ptr_i
	// int* const ptr_i

	ptr_i = &i;	//取i的地址赋给i_pointer

	i = 10;		// int型数赋初值
	*ptr_i = 10;	//整数赋值

	cout<< "Output int i=" << i <<endl;		//输出int型数的值
	cout<< "Output int pointer i=" << *ptr_i <<endl;	//输出int型指针所指地址的内容

	return 0;
}