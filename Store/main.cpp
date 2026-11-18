#include <iostream>
#include <vector>
#include <iomanip>
#include "product.h"

void showProducts(const std::vector<Product>& products) {
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "   quantity: " << products[i].quantity << "\n";
    }
}

bool readInt(int& value) {
    if (std::cin >> value) return true;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return false;
}

void showStock(const std::vector<Product>& products) {
    showProducts(products);
    std::cout << "Choose product number: ";
    int n;
    if (!readInt(n) || n < 1 || n >(int)products.size()) {
        std::cout << "Invalid product.\n";
        return;
    }
    const Product& p = products[n - 1];
    std::cout << p.name << ": " << p.quantity << " left in stock.\n";
}

void buyProduct(std::vector<Product>& products) {
    showProducts(products);
    std::cout << "Choose product number: ";
    int n;
    if (!readInt(n) || n < 1 || n >(int)products.size()) {
        std::cout << "Invalid product.\n";
        return;
    }
    Product& p = products[n - 1];

    std::cout << "How many " << p.name << " do you want to buy? ";
    int amount;
    if (!readInt(amount) || amount <= 0) {
        std::cout << "Invalid amount.\n";
        return;
    }
    if (amount > p.quantity) {
        std::cout << "Not enough stock. Only " << p.quantity << " left.\n";
        return;
    }
    p.quantity -= amount;
    std::cout << "Bought " << amount << " x " << p.name
        << " for " << std::fixed << std::setprecision(2)
        << amount * p.price << " EUR.\n";
    std::cout << p.name << " left: " << p.quantity << "\n";
}

int main() {
    std::vector<Product> products = {
        { "Milk", 1.20, 30 },
        { "Bread", 0.95, 15 },
        { "Cheese", 4.50, 8 }
    };

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== Store ===\n";
        std::cout << "1. Show products\n";
        std::cout << "2. Check stock of a product\n";
        std::cout << "3. Buy a product\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        if (!readInt(choice)) {
            std::cout << "Please enter a number.\n";
            choice = -1;
            continue;
        }

        switch (choice) {
        case 1: showProducts(products); break;
        case 2: showStock(products); break;
        case 3: buyProduct(products); break;
        case 0: std::cout << "Bye!\n"; break;
        default: std::cout << "Unknown option.\n";
        }
    }
    return 0;
}