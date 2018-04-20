#include <iostream>
#include "TextQuery.h"
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
	//判断输入参数合法性
	if (argc < 2)
	{
		cerr << "No Input file!" << endl;
		return 1;
	}

	// 打开文本文件
	ifstream	ifs;
	ifs.open(argv[1]);
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
		print_results(locs, str, tq);
	}

	return 0;
}