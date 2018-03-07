#include "DeductionItem.h"

DeductionItem::DeductionItem(string isbn, double price, double full, double deduction) :
    Item(isbn, price), m_dFull(full), m_dDeduction(deduction)
{

}

DeductionItem::~DeductionItem()
{

}

double DeductionItem::TotalPrice(int nCount)
{
	double	dTotal;		//总价
	int		nDeductionCount;	//满减的数量

	dTotal	= Item::TotalPrice(nCount);	//折扣前的总价
	nDeductionCount = dTotal / m_dFull;	//满减的数量

	dTotal -= nDeductionCount*m_dDeduction;	//折扣后的价格

	return dTotal;
}
