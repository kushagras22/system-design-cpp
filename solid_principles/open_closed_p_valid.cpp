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

// Abstract Class
class DBPersistence{
    private:
        ShoppingCart* cart;
    
    public:
        virtual void save(ShoppingCart* cart) = 0; // Pure virtual function
};

class SQLPersistence : public DBPersistence {
    public:
        void save(ShoppingCart* cart) override {
            cout << "Saving shopping cart to SQL DB..." << endl;
        }
};

class MongoDBPersistence : public DBPersistence {
    public:
        void save(ShoppingCart* cart) override {
            cout << "Saving shopping cart to MongoDB..." << endl;
        }
};

class FilePersistence : public DBPersistence {
    public:
        void save(ShoppingCart* cart) override {
            cout << "Saving shopping cart to file" << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 150000));
    cart->addProduct(new Product("Mouse", 500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    DBPersistence* db = new SQLPersistence();
    DBPersistence* mongodb = new MongoDBPersistence();
    DBPersistence* file = new FilePersistence();
    
    db->save(cart);
    mongodb->save(cart);
    file->save(cart);

    return 0;
}
