#pragma once
#include <iostream>
#include <vector>
// using namespace std;

class Product{

    private:
        int product_id;
        string product_name;
        float product_price;


    public:
        //construtors:

        Product(){
            product_id=1123565;
            product_name="Motorola";
            product_price=275;
        }

        Product(int product_id,string product_name,float product_price){
            this->product_id=product_id;
            this->product_name=product_name;
            this->product_price=product_price;
        }

        //Setters
        void set_id(int product_id){
            this->product_id=product_id;
        }
        void set_name(string product_name){
            this->product_name=product_name;
        }
        void set_price(float product_price){
            this->product_price=product_price;
        }

    //Getters:
        int get_id()const{
            return product_id;
        }

        string getProductName()const{
            return product_name;
        }

        float get_prd_price()const{
            return product_price;
        }
};
