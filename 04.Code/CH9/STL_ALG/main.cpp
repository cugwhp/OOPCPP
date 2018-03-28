#include <iostream>

using namespace std;

extern void Test_Find();

extern void Test_Numeric();

extern void Test_Sort();

extern void Test_InsertIter();


int main(void)
{
	cout << "STL Algorithm " << endl;

	Test_Find();

	Test_Sort();

	Test_InsertIter();

	Test_Numeric();

	int		iVal = 8;

	cin.tie(&cout);
	cout << iVal;
	cin >> iVal;
	return 0;


	ostream	*old_tie = cin.tie();
	cin.tie(0);
	cin.tie(&cerr);

	cin.tie(0);
	cin.tie(old_tie);

	return 0;
}
