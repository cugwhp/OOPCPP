#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>

//////////////////////////////////////////////////////////////////////////
// class TextQuery														//
//////////////////////////////////////////////////////////////////////////
class TextQuery
{
public:
	typedef std::vector<std::string>::size_type	line_no;	//定义类型别名

	void read_file(std::ifstream &is){		//读文本文件内容，建立单词->行号map
		store_file(is);	make_map();
	}

	std::set<line_no>	run_query(const std::string& ) const;	//执行查询，返回行号列表
	std::string	text_line(line_no) const;	//输入行号，返回改行内容

private:
	void store_file(std::ifstream&);	//读文件内容
	void make_map();					//建立单词->行号map

	std::vector<std::string>	lines_of_text;			//文本内容（按行存放）
	std::map< std::string, std::set<line_no> > word_map;//单词->行号列表 map
};

// 输出查询结果的接口
void print_results(const std::set<TextQuery::line_no>& locs, const std::string& sought, const TextQuery& file);

#endif	//#ifndef _TEXT_QUERY_H_