#ifndef BULK_ITEM_H
#define BULK_ITEM_H

#include "Item_base.h"

// discount kicks in when a specified number of copies of same book are sold
// the discount is expressed as a fraction used to reduce the normal price

class Bulk_item : public Item_base
{
    public:
        Bulk_item(const std::string &book="", double sales_price=0, std::size_t );
        virtual ~Bulk_item();

        double net_price();
    protected:

    private:
        std::size_t min_qty;
        double  discount;
};

#endif // BULK_ITEM_H
