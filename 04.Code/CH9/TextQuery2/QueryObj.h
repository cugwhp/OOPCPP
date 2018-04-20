#ifndef QUERYOBJ_H
#define QUERYOBJ_H

#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

class QueryObj
{
public:
    QueryObj();
    virtual ~QueryObj();

    //
    typedef vector<string>::size_type line_no;
    bool load_file(ifstream& ifs);
    set<line_no> query(const string& strWord);

protected:
    bool store_file(ifstream& ifs);
    void make_map();
private:
    vector<string> m_vecStrs;
    map<string, set<line_no> >   m_mapWords;
};

#endif // QUERYOBJ_H
