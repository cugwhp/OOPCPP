//==========================================================//
// class DeductionItem										//
// Description: 记录商品满199减50信息，便于计算n件商品总价	//
// Author: Wang Hongping									//
// Date: 7 March, 2018										//
//==========================================================//

#ifndef _DEDUCTION_ITEM_HEADER_
#define _DEDUCTION_ITEM_HEADER_

#include "Item.h"

class DeductionItem : public Item
{
	public:
		DeductionItem(string isbn="", double price=0.0f, double full=199, double deduction=50);
		~DeductionItem();
		double TotalPrice(int nCount);
	private:
		double	m_dFull;
		double	m_dDeduction;
};

#endif	//#ifndef _DEDUCTION_ITEM_HEADER_
