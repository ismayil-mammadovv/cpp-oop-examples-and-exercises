#include <iostream>
#include <vector>
using namespace std;

/*
    Exercise: Online Shop System

    Description:
    Design and implement an Online Shop System using multiple files and classes in C++. 
    The system should allow you to manage products and orders in an online shop.

    Requirements:

    1. Create two classes: "Product" and "Order".

    2. The "Product" class should have the following attributes:
        Product ID (an integer)
        Product name (a string)
        Product price (a floating-point number)

    3. The "Order" class should have the following attributes:
        Order ID (an integer)
        Customer name (a string)
        Ordered products (an array/vector of Product objects)
        (Vectors: https://www.geeksforgeeks.org/vector-in-cpp-stl/)
    
    4. Define the "Product" class in a separate header file called "Product.h" 
    and implement its member functions.

    5. Define the "Order" class in a separate header file called "Order.h" 
    and implement its member functions

    6. Include the necessary header files in the main program file.

    7. Demonstrate the functionality of the Online Shop System by creating products, 
    creating orders, and performing operations like adding products to orders, calculating order totals, etc.

    Tips:

    Use header files to declare the class structure and member function prototypes.
    Use include guards or pragma once to prevent multiple inclusion of header files.
    
    This exercise will help you practice creating separate classes in different files 
    and including them in a main program file to build a functional Online Shop System!
*/


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


class Order{
    private:
        int order_id;
        string customer_name;
        vector<Product> ordered_products;

    public:
        Order(int order_idP, string customer_nameP){
            order_id=order_idP;
            customer_name=customer_nameP;
        }

        //Getters:
        void displayProducts(){
            for(size_t i=0; i<ordered_products.size();i++){
                cout<<ordered_products[i].get_id()<<endl;   
            }
        }

        int getOrderID(){
            return order_id;
        }

        string getCustomerName(){
            return customer_name;
        }

        vector<Product> getOrderedProducts() {
            return ordered_products;
        }

        void addProduct(Product product){
           ordered_products.push_back(product);
        }


        double calculateOrderTotal(){
            double total=0;
            for(int i=0; i<ordered_products.size();i++){
                total+=ordered_products[i].get_prd_price();
                // cout<<ordered_products[i].get_prd_price<<endl;   
            }
            return total;
            
        }
};





int main() {

    system("clear");

    // Create products
    Product p1(1, "Product 1", 10.0);
    Product p2(2, "Product 2", 20.0);
    Product p3(3, "Product 3", 30.0);

    // Create an order
    Order order(1, "John Doe");

    // Add products to the order
    order.addProduct(p1);
    order.addProduct(p2);
    order.addProduct(p3);

    // Calculate the order total
    double total = order.calculateOrderTotal();

    // Display the order details
    cout << "Order ID: " << order.getOrderID() << endl;
    cout << "Customer Name: " << order.getCustomerName() << endl;
    cout << "Ordered Products:" << endl;

    for (const Product& product : order.getOrderedProducts()) {
        cout << " - " << product.getProductName() << endl;
    }
    
    cout << "Total: $" << total << endl;

    return 0;
}