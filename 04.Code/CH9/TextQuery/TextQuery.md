# TextQuery - 实现过程

## 理解需求
> 需求：查询文本文件中某个单词出现在文件中的行号，并输出所在的行号。
```
程序设计的关键是数据+算法，对于简单的程序，我们可以从分析数据及数据流向开始。TextQuery的需求可以理解为：TextFile --Read--> vector<string> --make_map--> map<string, set<long> > --run_query--> set<long> --Print--> cout.
```
通过以上的分析，基本上就确定了：1）程序运行的基本过程；2）函数的定义（返回值、名称、参数列表）；3）构建类，满足上述功能。

下面按照搭设计类接口、主流程、函数填空这几个步骤来实现TextQuery的功能。

## 设计类接口
根据前面分析的结果，我们可以提炼出TextQuery类的接口。
代码如下：
```c++
#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include <string>
#include <fstream>
#include <set>
#include <vector>
class TextQuery
{
public:
	//构造和析构函数
	TextQuery();
	virtual ~TextQuery();
	
	//功能接口
	typedef std::vector<std::string>::size_type	line_no;	//定义类型别名
	void read_file(std::ifstream &);
	std::set<line_no>	run_query(const std::string& ) const;	//执行查询，返回行号列表
};
#endif	//#ifndef _TEXT_QUERY_H_
```
在这个阶段，我们重点只关注接口的输入输出参数，函数体的实现先不管。
为了保证程序流程能通过，可以在TextQuery.cpp中实现空的函数体，代码如下：
```c++
// TextQuery.cpp

#include "TextQuery.h"

TextQuery::TextQuery()
{
}

TextQuery::~TextQuery()
{    
}

bool TextQuery::read_file(ifstream& is)
{
    return false;
}

set<line_no> TextQuery::run_query(const string& strWord)
{
    return set<line_no>();
}
```
> 注意，此处的函数接口，都没有真正实现。

## 搭主流程
事实上，定义类的接口和搭建主流程的顺序没有明确的先后，可以是在使用的过程中，逐步添加的。

```c++
#include <iostream>
#include <fstream>
using namespace std;

//==========================================================//
//		Text Query Function:								//
// 1.打开文本文件，按行读取内容，程序保存行号和每行的内容	//
// 2.将每行内容按单词分解，并记录每个单词所在的行号			//
// 3.输入单词，能查询该单词所在的所有行号（按升序排序）		//
// 4.根据行号，输出包含该单词所在行的内容					//
//==========================================================//
int main(int argc, char** argv)
{	
	// 输入文件路径
	string		strTextFilePath;
	cout << "Input Text File Path: ";
	cin >> strTextFilePath;
	
	// 打开文本文件
	ifstream	ifs;
	ifs.open(strTextFilePath);
	if (ifs.is_open())
	{
		cerr << "Open File Failed!" << endl;
		return 2;
	}

	// 读文件内容，生成<单词-所在行>的map
	TextQuery	tq;
	tq.read_file(ifs);
	ifs.close();

	// 循环输入查询单词，输出查询结果
	while(true)
	{
		// 查询单词
		cout << "enter word to look for, or q to quit: ";
		string	str;
		cin >> str;

		// "q" is quit
		if (!cin || str=="!q")
			break;

		// 执行查询
		set<TextQuery::line_no> locs = tq.run_query(str);

		//输出查询结果
		set<TextQuery::line_no>::iterator	iter;
		for (iter=locs.begin(); iter!=locs.end(); ++iter)
			cout << *iter << "\t";
		cout << endl;
	}
	return 0;
}
```
自此，程序就能够正常执行了，但基本的功能未实现。

## 函数填空
```c++
bool read_file(std::ifstream &is)
{		//读文本文件内容，建立单词->行号map
		if (!store_file(is))
        	return false;
        	
		make_map();
		return true;
}
	
void	//读文件，一行一行地存入vector<string>
TextQuery::store_file(std::ifstream& ifs)
{
	if (!ifs.is_open())
		return false;
		
	std::string	strTextLine;
	while(std::getline(ifs, strTextLine))
		lines_of_text.push_back(strTextLine);
		
	return true;
}

void	//逐单词分解，记录每个单词出现的行号列表
TextQuery::make_map()
{
	for (line_no line_num=0; line_num!=lines_of_text.size(); ++line_num)
	{
		istringstream	line(lines_of_text[line_num]);
		string	word;
		while(line >> word)
			word_map[word].insert(line_num);
	}
}

set<TextQuery::line_no>	//执行查询
TextQuery::run_query(const std::string &query_word) const
{
	map<string, set<line_no> >::const_iterator	loc;
	loc = word_map.find(query_word);

	if (loc == word_map.end())
		return set<line_no>();
	else
		return loc->second;
}
```