#ifndef ITEM_BASE_H
#define ITEM_BASE_H

#include <string>

// Item sold at an undiscounted price
// derived classes will define various discount strategies
class Item_base{
  public:
  	Item_base(const std::string &book="", double sales_price=0);
  	virtual ~Item_base();

  	std::string book() const { return isbn; }

  	// returns total sales price for a specified number of items
  	// derived classes will override and apply different discount algorithms
  	virtual double net_price(std::size_t n) const;

  private:
  	std::string		isbn;	// identifier for item
  protected:
  	double		price;		//normal, undiscounted price
};

#endif // ITEM_BASE_H
