#include "BulkItem.h"

BulkItem::BulkItem(string isbn, double price, int minQty, double discount) : Item(isbn, price)
{
	m_nMinQty = minQty;
	m_dDiscount = discount;
}

BulkItem::~BulkItem()
{

}

double BulkItem::TotalPrice(int nCount)
{
    if (nCount<m_nMinQty)
        return Item::TotalPrice(nCount);
    else
        return (1-m_dDiscount)*Item::TotalPrice(nCount);
 }
