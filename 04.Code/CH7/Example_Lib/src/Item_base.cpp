#include "Item_base.h"

Item_base::Item_base(const std::string &book, double sales_price):
    isbn(book), price(sales_price)
{
}

// returns total sales price for a specified number of items
// derived classes will override and apply different discount algorithms
double Item_base::net_price(std::size_t n) const
{
    return n*price;
}

Item_base::~Item_base()
{

}
