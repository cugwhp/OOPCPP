#include "QueryObj.h"

QueryObj::QueryObj()
{
    //ctor
}

QueryObj::~QueryObj()
{
    //dtor
}

bool QueryObj::load_file(ifstream& ifs)
{
    //1. store_file -> vector<string>
    if (!store_file(ifs))
        return false;

    //2. make_map vector<string>-> map
    make_map();

    return true;
}

set<QueryObj::line_no>
QueryObj::query(const string& strWord)
{
    map<string, line_no>::iterator  iter;
    iter = m_mapWords.find(strWord);
    if (iter != m_mapWords.end())
        return iter->second;
    else
        return set<line_no>();
}

bool QueryObj::store_file(ifstream& ifs)
{
    m_vecStrs.clear();

    string      strTxt;
    while(!ifs.eof())
    {
        getline(ifs, strTxt);
        m_vecStrs.push_back(strTxt);
    }
    return true;
}

void QueryObj::make_map()
{
    vector<string>::iterator    iter;
    stringstream    ss;
    string          strWord;
    line_no         ln;
    for (ln=1,iter=m_vecStrs.begin(); iter!=m_vecStrs.end(); ++iter,++ln)
    {
        ss.clear();
        ss.str(*iter);

        strWord = "";
        do
        {
            ss >> strWord;
            if (strWord!="")
            {
                m_mapWords[strWord].insert(ln);
            }
        }while(strWord!="");
    }

    return;
}
