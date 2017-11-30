#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#include <map>
#include <set>
using namespace std;


// TEMPLATE FUNCTION partial_sum
template<class _InIt, class _OutIt>
_OutIt Container_Out(_InIt _First, _InIt _Last, _OutIt _Dest)
{	// compute partial sums into _Dest
	for (; _First != _Last; ++_First,++_Dest)
		*_Dest = *_First;

	return (++_Dest);
}

class Foo
{
public:
	Foo(int i=0) {m_i=i;}

private:
	int		m_i;
};

int main()
{
	map<string, int>	map1;
	//key-string, value-int
	map1.insert(make_pair("RS",113160));
	map1.insert(make_pair("cug",10491));

	map1.erase("RS");

	list<Foo>	lFoo(10,1);

	//================ Vector Initialize ===============//
	cout << "========= Vector Initialize ======" << endl;
	int		iAry[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int>	iVec1(iAry, iAry+7);	// 
	vector<int> iVec2(5);				// 
	vector<int>	iVec3(5,1);				// 
	vector<int>	iVec4(iVec1.begin(), iVec1.begin()+5);	//
	vector<int>	iVec5(iVec1);			// 

	// 
	ostream_iterator<int>	oite(cout, "\t");
	Container_Out(iVec1.begin(), iVec1.end(), oite);
	cout << endl;

	Container_Out(iVec2.begin(), iVec2.end(), oite);
	cout << endl;

	Container_Out(iVec3.begin(), iVec3.end(), oite);
	cout << endl;

	Container_Out(iVec4.begin(), iVec4.end(), oite);
	cout << endl;

	Container_Out(iVec5.begin(), iVec5.end(), oite);
	cout << endl;

	// ======================== List Initialize ===============//
	cout << "\n====== List Initialize ========\n";
	list<int>	iList1(iAry, iAry+7);
	list<int>	iList2(5);
	list<int>	iList3(5, 1);
//	list<int>	iList4(iList1.begin(),iList1.begin()+5);
	list<int>	iList5(iList1);
	list<int>	iList6(iVec1.begin(), iVec1.end());
//	list<int>	iList7(iVec1);

	Container_Out(iList1.begin(), iList1.end(), oite);
	cout << endl;


	//===================== deque Initialize ==============//
	cout << "\n===== deque Initialize =====\n";
	deque<int>	iDeque1(iAry, iAry+7);
	deque<int>	iDeque2(iDeque1);
	deque<int>	iDeque3(5);
	deque<int>	iDeque4(5, 2);
	deque<int>	iDeque5(iDeque1.begin(), iDeque1.begin()+5);
	deque<int>	iDeque6(iDeque1.begin(), iDeque1.end());
//	deque<int>	iDeque7(iVec1);

	Container_Out(iDeque1.begin(), iDeque1.end(), oite);
	cout << endl;

	for_each(iVec1.begin(), iVec1.end(), negate<int>());
	Container_Out(iVec1.begin(), iVec1.end(), oite);
	cout << endl;

	return 0;
}