#include "Item.h"

Item::Item(string isbn, double price) : m_strISBN(isbn), m_dPrice(price)
{

}

Item::~Item()
{

}

double Item::TotalPrice(int nCount)
{
	return m_dPrice*nCount;
}
