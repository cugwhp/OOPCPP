#include <iostream>
#include "Manager.h"
#include "Sales.h"
#include "Wage.h"
#include "Employee.h"
#include "afxtempl.h"

using namespace std;


int main()
{
	CEmployee*	pEmpolyee = NULL;
	CManager	aManager("Manager");
	CSales		aSales("Saler");
	CWage		aWage("Wager");

	pEmpolyee = &aManager;
	cout << pEmpolyee->ComputePay() << endl;
	cout << aManager.ComputePay() << endl;
 
	return 0;
}