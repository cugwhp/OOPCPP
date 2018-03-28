#include <numeric>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void Test_Nonmutation()
{
	int		a[] = {1,2,3,4,5};
	vector<int>	iv(a,a+5);

	vector<int>::const_iterator	iter =
	find(iv.begin(), iv.end(), 5);

	cout << "The Value " << 5;
	cout << (iter==iv.end()? " is not present" :
           " is present.") << endl;

	size_t	cnt;
	cnt = count(iv.begin(),iv.end(), 5);
}

void Test_Find()
{
	int		a[] = {10, 7, 4, 8, 9, 5, 2, 3, 6, 1};
	int		b[] = {5,3,1,11};
	vector<int>	iv(a,a+10);
	list<int>	il(b,b+4);

	vector<int>::iterator	it = iv.begin();
	vector<int>::size_type	cnt = 0;
	while ((it = find_first_of(it, iv.end(), il.begin(), il.end())) != iv.end())
	{
		++cnt;
		++it;
	}
	cout << "Found " << cnt << " times on both containers." << endl;
}


void Test_Numeric()
{
	// find
	int		a[] = {1,2,3,4,5};
	vector<int>	iv(a,a+5);

	// 1+2+3+4+5
	cout << accumulate(iv.begin(), iv.end(), 0.0f) << endl;

	// (-1)+(-2)+(-3)+(-4)+(-5)
	cout << accumulate(iv.begin(), iv.end(), 0.0f, minus<int>()) << endl;

	// 10 + (1*1) +(2*2) +(3*3) + (4*4) + (5*5)
	cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) << endl;

	// 10 - (1+1) -(2+2) - (3+3) - (4+4) - (5+5), minus(10-plus(1,1)
	cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10, minus<int>(), plus<int>()) << endl;

	ostream_iterator<int> oite(cout, " ");
	partial_sum(iv.begin(), iv.end(), oite);	//1 3 6 10 15
	partial_sum(iv.begin(), iv.end(), oite, minus<int>());	// 1 -1 -4 -8 -13

	return;
}

bool GT6(const string& str)
{
	return str.size()>=6;
}

template<typename T>
struct GT2
{
	bool operator() (const T& t) {return t.size()>=2;}
};

bool string_compare(const string& str1, const string& str2)
{
	return str1.size()>str2.size();
}

void Test_Sort()
{
	string	strTxt("the quick red fox jumps over the slow red turtle");
	istringstream	ss(strTxt);
	vector<string>	words;
	vector<string>::iterator	iter,end_unique;

	cout << strTxt << endl;

	while(ss >> strTxt)
		words.push_back(strTxt);

	sort(words.begin(),words.end());

	for (iter=words.begin(); iter!=words.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//
	end_unique = unique(words.begin(), words.end());
	for (iter=words.begin(); iter!=words.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	words.erase(end_unique, words.end());

	size_t	cnt = 0;
	cnt = count_if(words.begin(), words.end(), GT2<string>());
	cout << cnt << endl;
}

void Test_InsertIter()
{
	list<int>	ilst, ilst2, ilst3;
	for (list<int>::size_type i=0; i!=4; ++i)
		ilst.push_front(i);

	copy(ilst.begin(), ilst.end(), front_inserter(ilst2));
	copy(ilst.begin(), ilst.end(), inserter(ilst3, ilst3.begin()));

	return;
}
