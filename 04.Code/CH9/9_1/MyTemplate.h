#pragma once

// 模板函数-绝对值
template<typename T>
T Abs(T val)
{
	return (val<0 ? -val : val);
}

// 模板函数特例
int Abs(int val)
{
	return (val>0 ? val : -val);
}

