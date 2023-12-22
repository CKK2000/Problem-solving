// Data Structure Training Assignment 

 

// Please read the following problem description thoroughly then create a program to solve the same with your choice of language i.e. C/C++/Java. 

// Please write simple and clean code, do not over engineer or complicate the code. 

// The code should be easy to understand, write proper comments wherever required. 

// You needn't use any database or file system to store the data. Please try to implement the solution with the suitable data structures like Linked List, Stack, Queue, etc. 

// You needn’t to build any user interface; this would be a simple console based program. Input on console and required output on console. 

 

// Problem Statement # 1: 

// The Super Bazaar wants to automate its inventory. They want to achieve following functionality: 

// Generate a “unique product id” to identify each product (like Soap, Tea, Biscuits, etc.). 

// Add new product into inventory with “unique product id” and other product attributes like product name, price, date of manufacturing etc. 

// Remove defective products from inventory, if any. 

// Search for any product with “unique product id”. 

// Display all products with “unique id” so that the selling department could see. 

// Continues monitoring inventory if any product quantity reaches to 5 and then send an alert to the manager. 





#include <iostream> 
#include <string>    
#include <vector>

using namespace std; 

//Here I define class struct which name product to hold details of a product

struct Product {
    int productId;             
    string name;              
    double price;              
    string dateOfManufacturing; 
    int quantity;             


    // Constructor(product with value) 
    Product(int id, const string& n, double p, const string& dom, int qty)
        : productId(id), name(n), price(p), dateOfManufacturing(dom), quantity(qty) {}
};



// Define a class named Inventory to manage product inventory
class Inventory {
private:
    //store product obj
    vector<Product> products; 

public:

    // Fn to generate product ID
    int generateUniqueId() {
        static int id = 1;
        return id++;       
    }

    // Fn to add a new product to the inventory
    void addProduct(const string& name, double price, const string& dom, int qty) {
        int productId = generateUniqueId(); 
        // Create and add the prdct to the vetor aray
        products.push_back(Product(productId, name, price, dom, qty)); 
    // Display a success message with the new product ID
        cout << "Product added successfully with ID: " << productId << endl; 
    }

    // Fn to remove defective products from the inventory
    void removeDefectiveProducts(int id ) {
       for (auto it = products.begin(); it != products.end();) {
    if (it->productId == id) {
        cout << "Removing product with ID: " << it->productId << endl;
        it = products.erase(it);
    } else {
        ++it;
    }
}
    }

    // Fn to search product by  ID
    void searchProductById(int id) {
        for (const auto& product : products) { 
            if (product.productId == id) {                
                cout << "Product ID: " << product.productId << ", Name: " << product.name
                     << ", Price: " << product.price << ", Date of Manufacturing: " << product.dateOfManufacturing
                     << ", Quantity: " << product.quantity << endl;
                return; 
            }
        }
        cout << "Product not found!" << endl; // If no product with the given ID is found
    }


    void displayAllProducts() {
        for (const auto& product : products) { 
                cout << "Product ID: " << product.productId << ", Name: " << product.name<< ", Price: " << product.price << ", Date of Manufacturing: " << product.dateOfManufacturing  << ", Quantity: " << product.quantity << endl;
        }
    }

    // Fn which check inventry to snd alert for less qnty 
    void checkInventoryAlert() {
        for (const auto& product : products) {
            if (product.quantity <= 5) {
               cout << "Product that have ID " << product.productId << " is low quantity!" << endl;
            }
          
        }
    }
};

int main() {

    // here I am Creating an instance of the Inventory class
    Inventory inventory; 

    
    inventory.addProduct("Soap", 100.0, "2023-08-18", 10);
    inventory.addProduct("Tea", 500.0, "2022-07-08", 9);
    inventory.addProduct("Biscuit", 80.0, "2023-09-10", 7);

    
    inventory.checkInventoryAlert();    
    inventory.removeDefectiveProducts(3);
    inventory.displayAllProducts();
    return 0; 
}
