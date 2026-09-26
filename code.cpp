#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

int main() {
    vector<Product> products;

    int choice;

    while (true) {
        cout << "\n===== VyaaparSathi =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Sell Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Product p;

            cout << "Enter product name: ";
            cin >> p.name;

            cout << "Enter price: ";
            cin >> p.price;

            cout << "Enter quantity: ";
            cin >> p.quantity;

            products.push_back(p);

            cout << "Product added successfully!\n";
        }

        else if (choice == 2) {
            cout << "\n--- Products ---\n";

            if (products.empty()) {
                cout << "No products available.\n";
            }

            for (int i = 0; i < products.size(); i++) {
                cout << "\nProduct: " << products[i].name;
                cout << "\nPrice: ₹" << products[i].price;
                cout << "\nStock: " << products[i].quantity << "\n";
            }
        }

        else if (choice == 3) {
            string name;
            int quantity;

            cout << "Enter product name: ";
            cin >> name;

            cout << "Enter quantity sold: ";
            cin >> quantity;

            bool found = false;

            for (auto &p : products) {
                if (p.name == name) {
                    found = true;

                    if (p.quantity >= quantity) {
                        p.quantity -= quantity;

                        cout << "Sale completed!\n";
                        cout << "Total amount: ₹"
                             << p.price * quantity << "\n";
                    }
                    else {
                        cout << "Not enough stock!\n";
                    }

                    break;
                }
            }

            if (!found) {
                cout << "Product not found!\n";
            }
        }

        else if (choice == 4) {
            cout << "Thank you for using VyaaparSathi!\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
