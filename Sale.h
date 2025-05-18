#ifndef SALE_H
#define SALE_H
#include <Product.h>
#include <array>
#include <ctime> //library to catch time

class Sale
{
    public:
        Sale();
        ~Sale();
        void add_product(const Product&);
        int get_numProducts();
        void set_numProducts(int);
        double get_totalPrice()const;
        void set_totalPrice(double);
        void print_sale()const;


    private:
        static const int capacity= 500;
        Product purchasedItems[capacity]; // this array is an object component
        int numProducts;
        double totalPrice;
        time_t timestamp; //current time. time_t is a typedef, timestamp is a variable
};

#endif // SALE_H
