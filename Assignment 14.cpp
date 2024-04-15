#include <iostream>
#include <string>
using namespace std;
class Item {
protected:
    string name;
    double price;
public:
    Item(string name, double price) : name(name), price(price) {}
    double calculateCost() const {
        return price;
    }
    void display() const {
        cout << name << ": Rs." << price << endl;
    }
};
class FoodItem : public Item {
private:
    string category;
public:
    FoodItem(string name, double price, string category) : Item(name, price), category(category) {}
    double calculateCost() const {
        return price;
    }
    void display() const {
        cout << name << " (" << category << "): Rs." << price << endl;
    }
};
class DrinkItem : public Item {
private:
    string size;
public:
    DrinkItem(string name, double price, string size) : Item(name, price), size(size) {}
    double calculateCost() const {
        return price;
    }
    void display() const {
        string displaySize;
        if (size == "16") {
            displaySize = "Small";
        } else if (size == "12") {
            displaySize = "Medium";
        } else if (size == "8") {
            displaySize = "Large";
        } else {
            displaySize = "Unknown";
        }
        cout << name << " (" << displaySize << "): Rs." << price << endl;
    }
};
class Order {
private:
    static const int MAX_ITEMS = 10;
    Item* items[MAX_ITEMS];
    int itemCount;
public:
    Order() : itemCount(0) {}
    void addItem(Item* item) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = item;
        } else {
            cout << "Order is full, cannot add more items." << endl;
        }
    }
    double calculateTotal() const {
        double total = 0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->calculateCost();
        }
        return total;
    }
    void display() const {
        for (int i = 0; i < itemCount; ++i) {
            items[i]->display();
        }
    }
};
int main() {
    Order order;
    FoodItem burger("Burger", 249, "Main Dish");
    DrinkItem coke("Coke", 80, "16");
    DrinkItem coffee("Coffee", 149, "12");
    order.addItem(&burger);
    order.addItem(&coke);
    order.addItem(&coffee);
    cout << "Order Details:" << endl;
    order.display();
    cout << "Total: Rs." << order.calculateTotal() << endl;
    return 0;
}