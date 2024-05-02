#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"
#include "MenuItem.h"
#include "SpecialOffer.h"
#include <vector>

/**
 * @class Order
 * Represents an order within a restaurant system.
 */
class Order {
public:
    /**
     * Constructs an Order object.
     * Precondition: None.
     * Postcondition: Order object is initialized with an empty order list.
     */
    Order();

    /**
     * Destructor.
     * Precondition: Order object exists.
     * Postcondition: Order object is destructed and all associated memory is released.
     */
    ~Order();

    /**
     * Adds a menu item with a specified quantity to the order.
     * Precondition: The MenuItem exists in the menu.
     * Postcondition: The item and its quantity are added to the order list.
     */
    void add(MenuItem& menuItem, int quantity);

    /**
     * Removes a menu item from the order.
     * Precondition: The MenuItem exists in the order.
     * Postcondition: The item is removed from the order list.
     */
    void remove(MenuItem& itemId);

    /**
     * Modifies an existing menu item in the order.
     * Precondition: The old MenuItem exists in the order.
     * Postcondition: The old item is replaced with the new item and its new quantity in the order list.
     */
    void modify(MenuItem& oldItem, MenuItem& newItem, int newQuantity);

    /**
     * Adds a special offer to the order.
     * Precondition: The SpecialOffer exists and is valid.
     * Postcondition: The special offer and its quantity are added to the order list.
     */
    void addOffer(SpecialOffer& offers, int quantity);

    /**
     * Displays the detailed bill for the order.
     * Precondition: None.
     * Postcondition: The complete order list with item details and total cost is displayed.
     */
    void display();

    /**
     * Checks if the order contains any items.
     * Precondition: None.
     * Postcondition: Returns true if the order is empty, false otherwise.
     */
    bool empty() const;

private:
    /**
     * Represents an item in the order along with its quantity.
     */
    class OrderItem {
    public:
        MenuItem item; // The menu item in the order.
        int quantity; // Quantity of the item.
            /**
         * Default constructor for OrderItem.
         * Precondition: None.
         * Postcondition: OrderItem is initialized with default values, quantity set to 0.
         */    
        OrderItem() : quantity(0) {}
        /**
         * Constructs an OrderItem with a MenuItem and a quantity.
         * Precondition: The MenuItem is defined and quantity is a positive integer.
         * Postcondition: OrderItem is initialized with specified item and quantity.
         */        
        OrderItem(const MenuItem&, int quantity);
    };

    vector<OrderItem> order; // List of items in the order.
    Menu menu;              // Reference to the menu to validate item existence.
};

#endif // ORDER_H