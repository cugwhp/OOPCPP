# 实习（八）STL

## 实习目的
- 了解STL的容器、迭代器、算法、仿函数的协同工作原理
- 掌握容器的常用接口
- 运用容器、算法，完成简单的应用
	
## 实习题目
### 题目1：完成TextQuery文本查询。
    输入：文本文件（多行）
	输出：某个单词出现在文本文件中的行号（可以是多个）
	过程描述：1)读取文本文件；2)输入某个单词，查询某个单词出现的行号，依次输出
	
### 题目2：使用accumulate统计vector<int>容器对象的元素之和。
	提示：
	```c++
	#include <algorithm>
	#include <numeric>
	```
	
### 题目3：查找某个字符串在另一个字符串中出现的次数。
	提示：使用find_first_of函数。

### 题目4：熟悉写容器的算法
	- fill
	- fill_n
	- back_inserter
	- copy
	_ replace
	_ replace_copy

### 题目5：统计一段文字中单词长度大于6的单词数目，同一个单词只记录计算一次。
	提示：1. 用容器存放单词；2.用到的函数 sort, unique, stable_sort, count_if
	思考：能否想出2种不同的实现途径。
	
### 题目6：读入一个词典文件，实现一个简易的词典查询系统。
	提示：词典文件[dictionary](./dictionary.txt)

	