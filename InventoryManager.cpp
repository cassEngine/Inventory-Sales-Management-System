#include "InventoryManager.h"
#include "Product.h"


InventoryManager::InventoryManager(){
   numProduct=0;
   products=new Product[capacity];
}

InventoryManager::~InventoryManager(){
   //cout<<"\nProduct destroyed.";
   delete [] products;
}
void InventoryManager:: add_product(const Product& add){

   if (numProduct<capacity){
    products[numProduct]=add;
    numProduct++;
   }
}

bool InventoryManager:: product_update(string product_ID){

    for (int i=0; i<numProduct; i++){
        if(products[i].get_productID()==product_ID){
            cout<<"\nProduct "<<product_ID<<" exists.";
            products[numProduct]=products[numProduct-1];
            numProduct--;
             cout<<"\nProduct removed from inventory.";
             return true;
        }
    }
    cout<<"\nProduct not found.";
    return false;
}

void InventoryManager:: display_all_products(int quantity, int capacity){
    for (int i=0; i<numProduct; i++){
    cout<<"\nAll products info: ";
    products[i].display_product_info(quantity, capacity);
    }
}

