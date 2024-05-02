#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "FileTasks.h"
#include "Menu.h"
#include "Order.h"
#include "SpecialOffer.h"
#include "Authenticate.h"
#include <stdio.h>


/* =========================================================================================*
 * The UserInterface class manages the user interactions and facilitates the various functionalities
 * of the restaurant management system. It provides mechanisms for login authentication, menu management,
 * order processing, and handling special offers.
 ========================================================================================= */

class UserInterface {
public:
     /**
     * Constructs a UserInterface object.
     * Pre-condition: None.
     * Post-condition: A UserInterface instance is initialized with default values.
     */   
    UserInterface();
    /**
     * Starts the main loop of the user interface.
     * Pre-condition: UserInterface instance has been properly initialized.
     * Post-condition: The application's user interface is running, waiting for user input.
     */    
    void run();
    
private:
    Authenticate auth;         // Authentication system to handle login processes.
    Order order;             // Order management.
    Menu menu;              // Menu management.
    SpecialOffer offers;   // Special offers management.
    bool loggedInAsAdmin; // Flag to check if the current user is logged in as an administrator.

    
    /**
     * Displays the current menu to the user.
     * Pre-condition: The menu items must be loaded into the 'menu' object.
     * Post-condition: Outputs the list of menu items to the standard output.
     */    
    void displayMenu();
    /**
     * Displays the current special offers.
     * Pre-condition: Special offers must be loaded into the 'offers' object.
     * Post-condition: Outputs the list of special offers to the standard output.
     */    
    void displayOffers();
    /**
     * Displays various options available to the user depending on their authentication status.
     * Pre-condition: User must be either logged in as admin or as a regular user.
     * Post-condition: Outputs relevant options to the standard output.
     */    
    void displayOptions();
    /**
     * Processes user input and executes the corresponding function based on the choice.
     * Pre-condition: User input has been received.
     * Post-condition: The appropriate action (method) corresponding to user input is called.
     */    
    void processChoice();
    /**
     * Loads menu items from a data source into the Menu object.
     * Pre-condition: Data source is available and accessible.
     * Post-condition: Menu items are loaded into the menu object.
     */    
    void loadMenuItems();
    /**
     * Facilitates the placing of an order by a user.
     * Pre-condition: Menu items must be loaded and displayed.
     * Post-condition: Order is recorded and processed.
     */    
    void placeOrder();
    /**
     * Displays the bill for the current order.
     * Pre-condition: An order has been placed.
     * Post-condition: The bill corresponding to the current order is displayed to the user.
     */    
    void displayBill();
    /**
     * Adds a new item to the menu.
     * Pre-condition: User is logged in as admin.
     * Post-condition: A new menu item is added and the menu is updated.
     */    
    void addItemToMenu();
    /**
     * Removes an item from the menu.
     * Pre-condition: User is logged in as admin.
     * Post-condition: The specified menu item is removed and the menu is updated.
     */    
    void removeItemFromMenu();
    /**
     * Modifies an existing item in the menu.
     * Pre-condition: User is logged in as admin.
     * Post-condition: The specified menu item is updated with new details.
     */    
    void modifyItemInMenu();
    /**
     * Modifies an existing order.
     * Pre-condition: An order exists to be modified.
     * Post-condition: The specified order is updated according to the modifications.
     */    
    void modifyOrder();
    /**
     * Removes an existing order.
     * Pre-condition: An order exists to be removed.
     * Post-condition: The specified order is removed.
     */    
    void removeOrder();
    /**
     * Updates the special offers available.
     * Pre-condition: User is logged in as admin.
     * Post-condition: Special offers are updated with new or modified offers.
     */    
    void updateSpecialOffers();
    /**
     * Facilitates login for admin users.
     * Pre-condition: Correct admin credentials are provided.
     * Post-condition: loggedInAsAdmin flag is set to true if credentials are authenticated.
     */
    bool loginAdmin();
};

#endif /* USER_INTERFACE_H */
