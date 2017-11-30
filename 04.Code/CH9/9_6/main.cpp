#include <iostream>
#include <vector>
#include <afxtempl.h>
using namespace std;

bool IsPrimer(int);

void ArrayTest(int N);
void StdVectorTest(int N);
void ListTest(int N);
void StdListTest(int N);

int main()
{
	int		N;
	cout << "Input N = ";
	cin >> N;

	ArrayTest(N);

//	StdVectorTest(N);

	ListTest(N);

	return 0;

	StdListTest(N);
}

void ArrayTest(int N)
{
	CArray<int>	aryPrimer;
	int	i;
	int	nCount=0;
	for (i=2; i<N+1; i++)
	{
		if (IsPrimer(i))
			aryPrimer.Add(i);
	}

	cout << "Primer's Count : " << aryPrimer.GetSize() << endl;
	for (i=0;i<aryPrimer.GetSize(); i++)
	{
		if (i>0 && i%10 ==0)
			cout << endl;
		cout << aryPrimer[i] << "\t";
	}
	cout << endl;
}

void StdVectorTest(int N)
{
	vector<int>	aryPrimer;
	vector<int>::const_iterator	iter;
	int	i;
	int	nCount=0;
	for (i=2; i<N+1; i++)
	{
		if (IsPrimer(i))
			aryPrimer.push_back(i);
	}

	cout << "Primer's Count : " << aryPrimer.size() << endl;
	for (iter=aryPrimer.begin(); iter!=aryPrimer.end(); iter++)
	{
		if (nCount>0 && nCount++%10 ==0)
			cout << endl;
		cout << *iter << "\t";
	}
	cout << endl;
}


void ListTest(int N)
{
	CList<int>	aryPrimer;
	int	i;
	int	nCount=0;
	for (i=2; i<N+1; i++)
	{
		if (IsPrimer(i))
			aryPrimer.AddTail(i);
	}

	cout << "Primer's Count : " << aryPrimer.GetSize() << endl;
	POSITION	pos = aryPrimer.GetHeadPosition();
	i = 0;
	while(pos)
	{
		if (i>0 && i%10 == 0)
			cout << endl;

		cout << aryPrimer.GetNext(pos) << "\t";
		i++;
	}
	
	cout << endl;
}

void StdListTest(int N)
{
	/*
	list<int>	aryPrimer;
	list<int>::const_iterator	iter;
	int	i;
	int	nCount=0;
	for (i=2; i<N+1; i++)
	{
		if (IsPrimer(i))
			aryPrimer.push_back(i);
	}

	cout << "Primer's Count : " << aryPrimer.size() << endl;
	for (iter=aryPrimer.begin(); iter!=aryPrimer.end(); iter++)
	{
		if (nCount>0 && nCount++%10 ==0)
			cout << endl;
		cout << *iter << "\t";
	}
	cout << endl;
	*/
}

bool IsPrimer(int n)
{
	int		i;
	for (i=2; i<=n/2; i++)
		if (n%i == 0)
			return false;

	return true;
}