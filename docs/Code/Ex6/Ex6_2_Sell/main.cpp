#include <iostream>
#include "Item.h"
#include "BulkItem.h"
#include "DeductionItem.h"

using namespace std;

int main()
{
    Item    it("item", 99.0);
    BulkItem    bit("bitem", 99.0, 5, 0.2f);
    DeductionItem   dit("ditem", 99.0, 199.0f, 50.f);

    int     i;
    for (i=1; i<=10; i++)
    {
        cout << "Count: " << i << "    ";
        cout << "Price: " << it.TotalPrice(i) << "\t";
        cout << bit.TotalPrice(i) << "\t";
        cout << dit.TotalPrice(i) << endl;
    }

    return 0;
}
