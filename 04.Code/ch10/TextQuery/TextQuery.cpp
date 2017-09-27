#include "TextQuery.h"

#include <iostream>
#include <sstream>

using namespace std;


void	//读文件，一行一行地存入vector<string>
TextQuery::store_file(std::ifstream& ifs)
{
	std::string	strTextLine;
	while(std::getline(ifs, strTextLine))
		lines_of_text.push_back(strTextLine);
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

std::string	//返回某行的文本
TextQuery::text_line(line_no line) const
{
	if (line>=0 && line < lines_of_text.size())
		return lines_of_text[line];
	throw std::out_of_range("line number out of range");
}

void print_results(const std::set<TextQuery::line_no>& locs, const std::string& sought, const TextQuery& file)
{
	typedef std::set<TextQuery::line_no> line_nums;
	line_nums::size_type	size = locs.size();
	cout << "\n" << sought << "occurs " << size << " "
		<< (size==1 ? "time" : "s") << endl;

	line_nums::const_iterator	it = locs.begin();
	for (; it!=locs.end(); ++it)
	{
		cout << "\t(line " << (*it)+1 << ") "
			<< file.text_line(*it) << endl;
	}
}