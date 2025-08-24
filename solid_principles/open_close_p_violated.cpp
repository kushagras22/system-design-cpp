#include <bits/stdc++.h>
using namespace std;

// Product class representing any item of e-commerce
class Product {
    public:
        string name;
        double price;

        Product(string name, double price) {
            this->name = name;
            this->price = price;
        }
};

// 1. Shopping Cart: Only responsible for Cart related buisness logic.
class ShoppingCart{
    private:
        vector<Product*> products; // Store heap-allocated products
    
    public: 
        void addProduct(Product* p){
            products.push_back(p);
        }

        const vector<Product*>& getProducts() {
            return products;
        }

        // Calculates total price in cart.
        double calculateTotal() {
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;
    
    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout << "Shopping Cart Invoice:\n";
            for(auto p : cart->getProducts()) {
                cout << p->name << "- $" << p->price << endl;
            }
            cout << "Total: $" << cart->calculateTotal() << endl;
        }
};

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage {
    private:
        ShoppingCart* cart;
    
    public:
        ShoppingCartStorage(ShoppingCart* cart){
            this->cart = cart;
        }

        void saveToSQLDatabase() {
            cout << "Saving shopping cart to SQL database..." << endl;
        }

        void saveToMongoDatabase() {
            cout << "Saving shopping cart to Mongo DB" << endl;
        }

        void saveToFile() {
            cout << "Saving shopping cart to file..." << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 150000));
    cart->addProduct(new Product("Mouse", 500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();

    return 0;
}
