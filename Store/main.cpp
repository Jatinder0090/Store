#include <iostream>
#include <vector>
#include <iomanip>
#include "product.h"


void cheapestProduct(const std::vector<Product>& products) {
    
    if (products.size() == 0) std::cout << "No products\n";
    else {
        double cheapestPrice = products[0].price;
        int cheapestNumber = 0;
        for (size_t i = 1; i < products.size(); i++) {
            if (products[i].price < cheapestPrice) {
                cheapestPrice = products[i].price;
                cheapestNumber = i;
            }
        }
        std::cout << "The cheapest product is " << cheapestNumber + 1 << ". "
            << std::left << std::setw(10) << products[cheapestNumber].name
            << std::fixed << std::setprecision(2) << products[cheapestNumber].price << " EUR"
            << "   quantity: " << products[cheapestNumber].quantity << "\n";
    }

}


void showProducts(const std::vector<Product>& products) {
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "   quantity: " << products[i].quantity << "\n";
    }
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
        std::cout << "2. Cheapest product\n";
        std::cout << "1. Show products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 2: cheapestProduct(products);
            break;

        case 1:
            showProducts(products);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Unknown option.\n";
        }
    }
    return 0;
}
