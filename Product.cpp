#include "Product.h"

Product::Product()
{
    productID=" ";
    name=" ";
    price=0;
    quantityInStock=0;
}

Product::Product(string productID1, string name1, double price1, int quantityInStock1){

    productID= productID1;
    name=name1;
    price=price1;
    quantityInStock=quantityInStock1;
}

Product::~Product(){
   cout<<"\nProduct destroyed.";
}

string Product:: get_productID()const{
   return productID;
}

string Product:: get_name()const{
   return name;
}

double Product:: get_price()const{
   return price;
}

int Product:: get_quantityInStock()const{
   return quantityInStock;
}

void Product:: set_productID(string ID){
    productID=ID;
}

void Product:: set_name(string na){
    name=na;
}

void Product:: set_price(double pr){
    price=pr;
}

void Product:: set_quantityInStock(int qa){
    quantityInStock=qa;
}

void Product:: display_product_info()const{
   cout<<"\nProduct Informations.";
   cout<<"\nProduct ID: "<<productID;
   cout<<"\nName: "<<name;
   cout<<"\nPrice: "<<price;
   cout<<"\nQuantity in stock: "<<quantityInStock;
}
