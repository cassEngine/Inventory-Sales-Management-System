#include "SalesManager.h"
#include <fstream>

SalesManager::SalesManager()
{
    numSales=0;
    sales= new Sale[capacity];
}

SalesManager::~SalesManager(){
   cout<<"\nSale destroyed.";
   delete [] sales;
}

void SalesManager:: new_sale(const Sale & s){
     if (numSales<capacity){
        sales[numSales]=s;
        numSales++;
        cout<<"\nNew sale processed.";
        return;
     }
}

void SalesManager:: print_daily_reports(){

       ofstream report;
       report.open("sales_report.text", ios::out);
       if(!report){
        cerr<<"File could not open.";
        exit(EXIT_FAILURE);
       }

       cout<<"\nToday's Sales Report: ";
       double dailyTotal_Revenue=0;
       double totalItemsSold=0;
       for (int i=0; i<numSales; i++){
        sales[i].print_sale();
        dailyTotal_Revenue+=sales[i].get_totalPrice();
        totalItemsSold+= sales[i].get_numProducts();
        report<<"Sale #" <<(i+ 1)<<" : $ "<< fixed << setprecision(2)<< sales[i].get_totalPrice()<<" \n";
       }

       report.close();
       cout<<fixed<<setprecision(2);
       cout<<"\nTotal Revenue Today: "<<dailyTotal_Revenue<<" $.";
       cout<<"\nTotal items sold: "<<totalItemsSold<<"\n";
       cout<<"\nTotal Revenue: "<<dailyTotal_Revenue<<fixed<<setprecision(2)<<"\n";

}
