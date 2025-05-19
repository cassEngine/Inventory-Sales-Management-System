#include "SalesManager.h"
#include <fstream>

SalesManager::SalesManager()
{
    numSales=0;
    sales= new Sale[capacity];
}

SalesManager::~SalesManager(){
   //cout<<"\nSale destroyed.";
   delete [] sales;
}

void SalesManager:: new_sale(const Sale & s){
     if (numSales<capacity){
        sales[numSales]=s;
        numSales++;
        cout<<"\nNew sale successfully processed!";
        return;
     }
}

void SalesManager:: print_daily_reports(){

       ofstream report; //file to keep track of items purchased
       report.open("sales_report.text", ios::out);
       if(!report){
        cerr<<"File could not open.";
        exit(EXIT_FAILURE);
       }

       cout<<"\n"<<"\nToday's Sales Report: ";
       double dailyTotal_Revenue = 0;
       double totalItemsSold = 0;

       for (int i=0; i<numSales; i++){

        const Sale & s = sales[i];
        s.print_sale();

       for (int j = 0; j < s.get_numProducts(); j++) {
            Product p = s.get_purchasedItem(j);
            totalItemsSold += p.get_quantityInStock();
            dailyTotal_Revenue += p.get_quantityInStock() * p.get_price();
        }

        report<<"Sale #" <<(i+1)<<" : $ "<< fixed << setprecision(2)<< s.get_totalPrice()<<" \n";
       }

       report.close();
       cout<<"\nTotal items sold: "<<totalItemsSold<<"\n";
       cout<<"Total Revenue (without taxes) : "<<dailyTotal_Revenue<<fixed<<setprecision(2)<<"$\n";

}
