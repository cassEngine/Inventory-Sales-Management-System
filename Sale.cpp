#include "Sale.h"
#include "Product.h"
#include <iomanip>

Sale::Sale()
{
    numProducts=0;
    totalPrice=0.0;
    timestamp=time(0);

}

Sale::~Sale(){
   //cout<<"\nSale ended.";
}

void Sale:: add_product(const Product& iden){
        if(numProducts<capacity){
            purchasedItems[numProducts]=iden;
            totalPrice+=iden.get_price(); //update total price from product object iden
            numProducts++; //move to next slot
            return;
        }
    cout<<"\nSale is full. Cannot add more products." ;
}
double Sale:: get_totalPrice()const{
   return totalPrice;
}

void Sale:: set_totalPrice(double TOTAL){
    totalPrice=TOTAL;
}

void Sale:: set_numProducts(int d){
    numProducts=d;
}

int Sale:: get_numProducts()const{
   return numProducts;
}

Product Sale::get_purchasedItem(int index) const {
    return purchasedItems[index];
}


void Sale:: print_sale()const{
    double totalPrice = 0;
    int totalQuantity = 0;

    for(int i=0; i<numProducts; i++){
    const Product& p = purchasedItems[i];
    p.display_product_info(p.get_quantityInStock(), capacity);
    totalPrice += p.get_price() * p.get_quantityInStock();
    totalQuantity += p.get_quantityInStock();
    }

    cout<<fixed<<setprecision(2); //fixed-point notation (not scientific) and limits outputs to 2 digits after decimal point
    cout<<"\n\nTotal Price of purchase : "<<totalPrice<<" $."; //prints price formatted to 2 decimal places
    cout<<"\nTime Stamp: "<<ctime(&timestamp); // converts into human readable time using ctime() function
                                              //ctime() passes a pointer by value to a time_t and returns a C-style string (char*) showing the date and time.

    //NOT PASS BY REFERENCE: Think of * as "go to the value" and & as "give me the memory address."
    //                       Read it this way: “Call the ctime function, and pass it the address of the variable timestamp.”
}
