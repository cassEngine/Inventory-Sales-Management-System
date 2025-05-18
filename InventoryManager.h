#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include "Product.h"

class InventoryManager
{
    public:

        InventoryManager();
        ~InventoryManager();
        void add_product(const Product&); //specific costumer's purchase
        bool product_update(string);
        void display_all_products();

    private:
        Product*products;
        int numProduct;
        int const capacity=500;

};

#endif // INVENTORYMANAGER_H
