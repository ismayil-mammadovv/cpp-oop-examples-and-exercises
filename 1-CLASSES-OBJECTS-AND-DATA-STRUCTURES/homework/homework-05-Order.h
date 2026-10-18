#pragma once
#include "homework-05-Product.h"
#include <iostream>
#include <vector>
// using namespace std;


class Order{
    private:
        int order_id;
        string customer_name;
        vector<Product*> products;

    public:
        Order(int order_idP, string customer_nameP){
            order_id=order_idP;
            customer_name=customer_nameP;
        }

        //Getters:
        void displayProducts(){
            for(size_t i=0; i<products.size();i++){
                cout<<products[i]->get_id()<<endl;   
            }
        }

        int getOrderID(){
            return order_id;
        }

        string getCustomerName(){
            return customer_name;
        }

        vector<Product*> getOrderedProducts() {
            return products;
        }

        void addProduct(Product *product){
           products.push_back(product);
        }


        double calculateOrderTotal(){
            double total=0;
            for(int i=0; i<products.size();i++){
                total+=products[i]->get_prd_price();
            }
            return total;  
        }
};