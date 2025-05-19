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
    int capacity=500; // quantity of any products is 500;
    ofstream myfile;

    myfile.open("groceries.txt", ios::out);

    if( !myfile){

        cerr<<"File cannot opened.";
        exit(EXIT_FAILURE);
    }

    SalesManager salesManager;
    Sale sale;

    cout<<"Do you want to save your items informations on the receipt?\n";
    cout<<"\nYes to type informations, 'Exit' to exit:\n\t";
    cin>>answer;

    while (answer != "Exit" && answer != "exit" && answer != "EXIT"){

    cout<<"\nID of product: ";
    cin>> ID;
    cout<<"\nProduct name: ";
    cin>> name;
    cout<<"\nPrice of product in $: ";
    cin>>price;
    cout<<"\nAmount of item purchased: ";
    cin>>quantity;
    if (quantity >500){
        cout<<"\nThere are only 500 "<< name<<" in stock. Please enter a valid number.\n";
        cout<<"\nAmount of item purchased: ";
        cin>>quantity;
    }
    cout<<"\nQuantity in stock left: "<<capacity-quantity;

    Product product (ID, name,price,quantity);
    sale.add_product(product);
    myfile<<name<<" - "<<ID<<" - "<<price<<" - $"<<quantity<<" left.\n";

    cout<<"\n\n\tAdd another product? 'Yes' to continue or 'Exit' to stop.\n\t";
    cin>>answer;
    }
    salesManager.new_sale(sale);
    time_t now= time(0);

    tm*localtim= localtime(&now);
    char dateBuffer[9];

    strftime(dateBuffer, sizeof(dateBuffer), "%Y/%m/%d", localtim);
    stringstream filename;
    filename<<"\nSales_report"<<dateBuffer<<" .txt";

    cout<<" Sales report will be saved to: "<<filename.str();
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
