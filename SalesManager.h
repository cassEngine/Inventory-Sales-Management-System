#ifndef SALESMANAGER_H
#define SALESMANAGER_H
#include <Sale.h>
#include "InventoryManager.h"
#include <iomanip>
class SalesManager
{
    public:
        SalesManager();
        ~SalesManager();
        void new_sale(const Sale&);
        void print_daily_reports(); //displays all sales
    private:
        Sale*sales;
        int numSales;
        int const capacity =500;
};

#endif // SALESMANAGER_H
