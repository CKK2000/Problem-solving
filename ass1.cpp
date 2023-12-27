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
    // Creating an instance of the Inventory class
    Inventory inventory; 
    int choice;

    do {
        // Display menu options
        cout << "\nSuper Bazaar Inventory Management System" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display All Products" << endl;
        cout << "3. Search Product by ID" << endl;
        cout << "4. Remove Defective Product by ID" << endl;
        cout << "5. Check Inventory Alerts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, dom;
                double price;
                int qty;

                cout << "Enter product name: ";
                cin.ignore(); // To clear the buffer
                getline(cin, name);

                cout << "Enter product price: ";
                cin >> price;

                cout << "Enter date of manufacturing (YYYY-MM-DD): ";
                cin.ignore();
                getline(cin, dom);

                cout << "Enter product quantity: ";
                cin >> qty;

                inventory.addProduct(name, price, dom, qty);
                break;
            }
            case 2:
                inventory.displayAllProducts();
                break;
            case 3: {
                int id;
                cout << "Enter product ID to search: ";
                cin >> id;
                inventory.searchProductById(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter product ID to remove: ";
                cin >> id;
                inventory.removeDefectiveProducts(id);
                break;
            }
            case 5:
                inventory.checkInventoryAlert();
                break;
            case 6:
                cout << "Exiting program... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please choose a valid option." << endl;
                break;
        }

    } while (choice != 6); // Continue the loop until user chooses to exit

    return 0;
}
