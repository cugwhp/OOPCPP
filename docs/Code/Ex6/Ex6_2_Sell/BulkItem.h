//==========================================================//
// class BulkItem											//
// Description: 记录批量商品的折扣，便于计算n件商品总价		//
// Author: Wang Hongping									//
// Date: 7 March, 2018										//
//==========================================================//

#ifndef _BULK_ITEM_HEADER_
#define _BULK_ITEM_HEADER_

#include "Item.h"

class BulkItem : public Item
{
	public:
		BulkItem(string isbn="", double price=0.0f, int minQty=0, double discount=0.0f);
		~BulkItem();
		double TotalPrice(int nCount);
	private:
		int		m_nMinQty;		//享受折扣的最小量
		double	m_dDiscount;	//折扣比例
};

#endif	//#ifndef _BULK_ITEM_HEADER_