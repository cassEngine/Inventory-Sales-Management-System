#include <iostream>
#include <ctime>
#include <sstream> //convert a string to create a StringStream object
#include "SalesManager.h"
#include "InventoryManager.h"
#include "Product.h"
#include "Sale.h"
#include <fstream>

using namespace std;

int main()
{
    int price,quantity;
    string name, ID, answer;
    ofstream myfile;

    myfile.open("groceries.txt", ios::out);

    if( !myfile){

        cerr<<"File cannot opened.";
        exit(EXIT_FAILURE);
    }

    SalesManager salesManager;
    Sale sale;

    cout<<"Enter your product informations.";
    cout<<"\nYes to enter, 'Exit' to exit:\n";
    cin>>answer;

    while (answer != "Exit" && answer != "exit" && answer != "EXIT"){
    if(answer != "Exit" && answer != "exit" && answer != "EXIT"){
             break;
    }
    cout<<"\nID of product: ";
    cin>> ID;
    cout<<"\nProduct name: ";
    cin>> name;
    cout<<"\nPrice of product: ";
    cin>>price;
    cout<<"\nQuantity in stock: ";
    cin>>quantity;

    Product product (ID, name,price,quantity);
    sale.add_product(product);
    myfile<<name<<" - "<<ID<<" - "<<price<<" - $"<<quantity<<" left.\n";

    cout<<"\nAdd another product? 'Exit' to exit.";
    cin>>answer;

    }
    salesManager.new_sale(sale);
    time_t now= time(0);

    tm*localtim= localtime(&now);
    char dateBuffer[9];

    strftime(dateBuffer, sizeof(dateBuffer), "%Y%m%d", localtim);
    stringstream filename;
    filename<<"\nSales_report"<<dateBuffer<<" .txt";

    cout<<"\nSales report will be saved to: "<<filename.str();
    salesManager.print_daily_reports();

    myfile.close();

    ofstream myfile1(filename.str());
    myfile1.open("sales_report_YYYYMMDD.txt", ios::out);

    if (!myfile1){
        cerr<<"File could not opened";
        exit(EXIT_FAILURE);
    }
     cout<<"\nSales report: "<<dateBuffer<<"\n";

     myfile1.close();

    return 0;

}
