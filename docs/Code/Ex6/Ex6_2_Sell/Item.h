//==========================================================//
// class Item												//
// Description: 记录商品的编码和单价，便于计算n件商品总价	//
// Author: Wang Hongping									//
//==========================================================//

#ifndef _ITEM_HEADER_
#define _ITEM_HEADER_

#include <string>
using namespace std;

class Item
{
	public:
		Item(string isbn="", double price=0.0f);
		virtual ~Item();

		double TotalPrice(int nCount);
	private:
		string	m_strISBN;	//Item Identified ID
		double	m_dPrice;	//Price
};

#endif	//#ifndef _ITEM_HEADER_
