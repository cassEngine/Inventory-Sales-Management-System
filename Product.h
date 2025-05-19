#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

using namespace std;

class Product
{
    public:
        Product();
        Product (string, string, double, int);
        ~Product();

        string get_productID()const;
        string get_name()const;
        double get_price()const;
        int get_quantityInStock()const;

        void set_productID(string);
        void set_name(string);
        void set_price(double);
        void set_quantityInStock(int);

        void display_product_info(int,int)const;
        int quantity;

    private:
        string productID;
        string name;
        double price;
        int quantityInStock;
        int capacity=500;

};

#endif // PRODUCT_H
