#include "Order.h"
#include "MenuItem.h"
#include "Menu.h"
#include "SpecialOffer.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Constructor for OrderItem.
Order::OrderItem::OrderItem(const MenuItem& item, int quantity) : item(item), quantity(quantity) {}

// Constructor for Order.
Order::Order() {
    order = vector<OrderItem>();
}

// Destructor for Order.
Order::~Order() {
    order.clear();
}

// Adds a menu item to the order with the specified quantity.
void Order::add(MenuItem& item, int quantity) {
    OrderItem newOrder(item, quantity);
    order.push_back(newOrder);
}

// Removes a menu item from the order.
void Order::remove(MenuItem& item) {
    for (int i = 0; i < order.size(); ++i) {
        if (order[i].item.getId() == item.getId()) {
            order.erase(order.begin() + i);
            break; // Exit loop after removing the item
        }
    }
}

// Modifies a menu item in the order with a new item and quantity.
void Order::modify(MenuItem& oldItem, MenuItem& newItem, int newQuantity) {
    for (int i = 0; i < order.size(); ++i) {
        if (order[i].item.getId() == oldItem.getId()) {
            order[i].item = newItem;
            order[i].quantity = newQuantity;
            break; // Exit loop after modifying the item
        }
    }
}

// Adds a special offer to the order with the specified quantity.
void Order::addOffer(SpecialOffer& offers, int quantity) {
    const vector<SpecialOffer::OfferItem>& offerItems = offers.getCurrentOffers();
for (int i = 0; i < offerItems.size(); ++i) {
    const SpecialOffer::OfferItem& offerItem = offerItems[i];
    // Rest of your loop body


        MenuItem* menuItem = menu.findItemById(offerItem.itemId);
        if (!menuItem) {
            cout << "Item not found with ID " << offerItem.itemId << "." << endl;
            continue;
        }
        string itemName = menuItem->getName();
        cout << "Limited quantity of " << itemName << " available in the offer." << endl;
        cout << "Stock available: " << offerItem.quantity << endl;
        cout << "Would you like to purchase the remaining stock of this item? (yes/no): ";
        string choice;
        cin >> choice;
        if (choice == "yes") {
            int finalQuantity = min(offerItem.quantity, quantity);
            add(*menuItem, finalQuantity);
            offers.updateQuantity(offerItem.itemId, offerItem.quantity - finalQuantity);
        }
    }
}
// Displays the bill for the order.
void Order::display() {
    double total = 0;
    cout << "Order Bill:" << endl;
    for (int i = 0; i < order.size(); ++i) {
        double lineTotal = order[i].quantity * order[i].item.getPrice();
        total += lineTotal;
        cout << order[i].item.getId() << " " << order[i].item.getName() << "\t" << order[i].quantity << "\t" << order[i].item.getPrice() << "\t$" << lineTotal << endl;
    }
    cout << "Total: $" << total << endl;
}
// Checks if the order is empty.
bool Order::empty() const {
    // Checks if the order is empty.
    return order.empty();
}
