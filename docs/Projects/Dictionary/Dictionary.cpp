#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct WordExplain
{
    string  strExplain;
    string  strWordType;
};
int main()
{
    ifstream    ifs("d:\\dictionary.txt");
    string      strLine;
    string      strWord;
    WordExplain explain;
    char        sBuff[512];
    map<string, WordExplain>    dictionary;

    // Read File
    if (ifs && ifs.is_open())
    {
        while(!ifs.eof())
        {
            ifs.getline(sBuff, 512);

            strLine = sBuff;
            if (strLine.size()<1)
                continue;

            // 解析文本
            stringstream    ss(strLine);
            ss >> strWord >> explain.strExplain >> explain.strWordType;

            // 插入到map
			if (strWord.size()>0 && explain.strExplain.size()>0)
			{
				dictionary.insert(make_pair(strWord, explain));
			}
        }
    }

    cout << "############### Dictionary Information ############" << endl;
    cout << "Size: " << dictionary.size() << endl;
    cout << "####################################################" << endl;
    cout << "输入单词，查询中文解释。" << endl;
    cout << "输入 !q 退出程序。" << endl;

    // 查询词典
    map<string, WordExplain>::const_iterator  iter;
    do
    {
        cout << "Please Input a word to query the explain: ";
        cin >> strWord;
        iter = dictionary.find(strWord);
        if (iter != dictionary.end())
        {
            cout << strWord << "\t";
            cout << (*iter).second.strExplain << "\t";
            cout << (*iter).second.strWordType << endl;
        }
        else if (strWord == string("!q"))
        {
            cout << "The program is exited." << endl;
        }
        else
        {
            cout << " is not found." << endl;
        }
    }while(strWord!=string("!q"));

    return 0;
}
