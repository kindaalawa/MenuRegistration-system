

#include "UserInterface.h"
#include <iostream>
// Constructor: Initializes a UserInterface object with default values for admin login status,
// loads menu items from a file, and initializes the offers based on the menu.
UserInterface::UserInterface() : loggedInAsAdmin(false) ,menu(), order(), offers(menu) {
 loadMenuItems();
 
}
// Main function to run the interface loop. It prompts the user to identify as a client or admin,
// handles their input, and facilitates the appropriate actions based on their role and choices.
void UserInterface::run() {
    char userType;
    bool exitProgram = false;
    do {
        cout << "Welcome to Roa & Kinda  Menu System \nAre you a client (C) or an admin (A)? ";
        cin >> userType;
        if (userType == 'C' || userType == 'c') {
            loggedInAsAdmin = false;
            displayOptions();
            processChoice();
        } else if (userType == 'A' || userType == 'a') {
            loggedInAsAdmin = false;
            do {
                if (loginAdmin()) {
                    loggedInAsAdmin = true;
                    displayOptions();
                    processChoice();
                } else
                    cout << "Invalid password! Please try again." << endl;
            } while (!loggedInAsAdmin);
        } else if (toupper(userType) == 'Q') {
            cout << "Exiting program.\n";
            exitProgram = true;
        } else {
            cout << "Invalid choice. Please enter 'C' for client, 'A' for admin, or 'Q' to quit." << endl;
        }
    } while (!exitProgram);
}

// Displays the menu organized by categories. Allows the user to navigate through different
// categories and view items.
void UserInterface::displayMenu() {
        char choice;
    char category;
    do {
        cout << "Choose Your Category: 'A' for appetizers, 'M' for main dishes, 'D' for desserts, or 'B' for beverages" << endl;
        cin >> category;
        toupper(category);
        menu.displayByCategory(category);

        cout << "Do you want to check the other menus? (Y/N): ";
        cin >> choice;
        if (toupper(choice) != 'Y') {
            break;
        }
    } while (toupper(choice) == 'Y');
}
    

/* Display menu items
 Displays current special offers. This function calls a method from the offers object that lists
 active special offers.*/
void UserInterface::displayOffers() {
    offers.displayCurrentOffers();
    
}

// Displays menu options available to the user based on whether they are logged in as an admin or not.
void UserInterface::displayOptions() {
  if (loggedInAsAdmin) {
        cout << "Admin Menu\t" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Display Offers" << endl;
        cout << "3. Add Item to Menu" << endl;
        cout << "4. Remove Item from Menu" << endl;
        cout << "5. Modify Item in Menu" << endl;
        cout << "6. Update Special Offers" << endl;
        cout << "L. Logout" << endl;
    } else {
        cout << "User Menu\t" << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Display Offers" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. Modify Order" << endl;
        cout << "5. Remove Order" << endl;
        cout << "6. Display Bill" << endl;
        cout << "L. Login as Admin" << endl;
    }
    cout << "Q. Quit" << endl;
}

// Processes the user's choice in the main menu and executes the corresponding function based on their selection
void UserInterface::processChoice() {
    char choice;
    cin >> choice;
    if (loggedInAsAdmin) {
        switch (toupper(choice)) {
            case '1': displayMenu(); break;
            case '2': displayOffers(); break;
            case '3': addItemToMenu(); break;
            case '4': removeItemFromMenu(); break;
            case '5': modifyItemInMenu(); break;
            case '6': updateSpecialOffers();break;
            case 'L': loggedInAsAdmin = false; cout << "Logged out as Admin.\n"; break; // Reset admin status on logout
            case 'Q': cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } else {
        switch (toupper(choice)) {
            case '1': displayMenu(); break;
            case '2': displayOffers(); break;
            case '3': placeOrder(); break;
            case '4': modifyOrder();break;
            case '5': removeOrder();break;
            case '6': displayBill(); break;
            case 'L': if (loginAdmin()) { loggedInAsAdmin = true; displayOptions(); processChoice(); } break; // Handle re-login as admin
            case 'Q': cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    }
}
// Loads menu items from a file specified in the 'filename' string.
void UserInterface::loadMenuItems() {
    string filename= "C:\\Users\\AMOEBA\\Desktop\\DS Lab\\DS_Menu_Project\\menuItems.txt";
    FileTasks file (menu);
    file.loadMenuFromFile(filename,menu);
    // Load menu items from file
}

// Allows the user to place an order by selecting an item and specifying a quantity.
void UserInterface::placeOrder() {
    cout << "Enter the ID of the item you want to order: ";
    int itemId;
    cin >> itemId;

    MenuItem* item = menu.findItemById(itemId);
    if (!item) {
        cout << "Item not found!" << endl;
        return;
    } 

    cout << "Enter the quantity: ";
    int quantity;
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity. Must be greater than zero." << endl;
        return;
    }

    if (offers.isSpecialOfferItem(itemId)) {
        order.addOffer(offers, quantity);
        offers.updateQuantity(itemId, quantity); // Decrement quantity or replace the offer if depleted
    } else {
        order.add(*item, quantity);
    } 
}

// Displays the total bill for the current order.
void UserInterface::displayBill() {
    order.display();
    // Display the bill
}

// Admin function to add a new item to the menu, requiring details such as name, price, category, and type.
void UserInterface::addItemToMenu() {
    // Add an item to the menu
        string name;
    double price;
    char category, type;
    int ingredientsCount;

    cout << "Enter the name of the item: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover newline
    getline(cin, name);

    cout << "Enter the price of the item: $";
    while (!(cin >> price) || price <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid price. Please enter a positive value: ";
    }

    cout << "Enter the category of the item (A for Appetizers, M for Main dishes, D for Desserts, B for Beverages): ";
    cin >> category;
    category = toupper(category);
    while (category != 'A' && category != 'M' && category != 'D' && category != 'B') {
        cout << "Invalid category. Please enter 'A', 'M', 'D', or 'B': ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> category;
        category = toupper(category);
    }

    cout << "Enter the type of the item (V for Vegan, G for Vegetarian, O for Omnivorous): ";
    cin >> type;
    type = toupper(type);
    while (type != 'V' && type != 'G' && type != 'O') {
        cout << "Invalid type. Please enter 'V', 'G', or 'O': ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> type;
        type = toupper(type);
    }

    cout << "Enter the number of ingredients: ";
    while (!(cin >> ingredientsCount) || ingredientsCount <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Please enter a positive integer: ";
    }

    string* ingredients = new string[ingredientsCount];
    cin.ignore(); // Clear newline character before reading strings
    cout << "Enter the ingredients (one per line):" << endl;
    for (int i = 0; i < ingredientsCount; ++i) {
        cout << "Ingredient " << (i + 1) << ": ";
        getline(cin, ingredients[i]);
    }
    // Convert the char type to MenuItem::Type
MenuItem::Type itemType;
switch (type) {
    case 'V':
        itemType = MenuItem::Vegan;
        break;
    case 'G':
        itemType = MenuItem::Vegetarian;
        break;
    case 'N':
        itemType = MenuItem::Normal;
        break;
    default:
        // Handle invalid type
        //cerr << "Invalid type: " << type << endl;
        return;
}
        int id;
        cout << "Enter the ID of the item: ";
        cin >> id;
        // Create new menu item and add to menu
        MenuItem newItem(id, name, price, itemType, ingredients, ingredientsCount, category);
        menu.addItem(newItem);
        FileTasks file(menu);
        file.writeMenuToFile("C:\\Users\\AMOEBA\\Desktop\\DS Lab\\DS_Menu_Project\\menuItems.txt");

        cout << "New item added to menu successfully." << endl;
}

// Admin function to remove an item from the menu.
void UserInterface::removeItemFromMenu() {
    
        if (order.empty()) {
        cout << "No orders to remove." << endl;
        return;
    }

    cout << "Enter the ID of the item you want to remove from the order: ";
    int itemId;
    cin >> itemId;

    MenuItem* item = menu.findItemById(itemId);
    if (!item) {
        cout << "Item not found!" << endl;
        return;
    }

    order.remove(*item);
    cout << "Item removed from the order successfully." << endl;
}

// Admin function to modify an existing menu item.
void UserInterface::modifyItemInMenu() {
    int id;
    cout << "Enter the ID of the item you want to modify: ";
    cin >> id;

    MenuItem* item = menu.findItemById(id);

    if (item != NULL) {
        string name;
        double price;
        char type, category;
        int ingredientsCount;

        cout << "Enter the new name: ";
        cin.ignore(); // Clear buffer before reading line
        getline(cin, name);

        cout << "Enter the new price: ";
        while (!(cin >> price) || price <= 0) {
            cin.clear();
            cin.ignore(10000, '\n'); // Ignore characters until newline is reached
            cout << "Invalid price. Please enter a positive value: ";
        }

        cout << "Enter the new type (V for Vegan, G for Vegetarian, O for Omnivorous): ";
        while (true) {
            cin >> type;
            type = toupper(type);
            if (type == 'V' || type == 'G' || type == 'O') {
                break;
            } else {
                cout << "Invalid type. Enter 'V', 'G', or 'O': ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        cout << "Enter the new category (A for Appetizers, M for Main dish, D for Dessert, B for Beverages): ";
        while (true) {
            cin >> category;
            category = toupper(category);
            if (category == 'A' || category == 'M' || category == 'D' || category == 'B') {
                break;
            } else {
                cout << "Invalid category. Enter 'A', 'M', 'D', or 'B': ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        cout << "Enter the number of ingredients: ";
        while (!(cin >> ingredientsCount) || ingredientsCount < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid count. Enter a positive integer: ";
        }

        string* ingredients = new string[ingredientsCount];
        cout << "Enter the ingredients (one per line):" << endl;
        cin.ignore(); // Clear the buffer before reading lines
        for (int i = 0; i < ingredientsCount; ++i) {
            cout << "Ingredient " << (i + 1) << ": ";
            getline(cin, ingredients[i]);
        }
   // Convert the char type to MenuItem::Type
MenuItem::Type itemType;
switch (type) {
    case 'V':
        itemType = MenuItem::Vegan;
        break;
    case 'G':
        itemType = MenuItem::Vegetarian;
        break;
    case 'N':
        itemType = MenuItem::Normal;
        break;
    default:
        // Handle invalid type
        //cerr << "Invalid type: " << type << endl;
        return;
}
        int id;
        cout << "Enter the ID of the item: ";
        cin >> id;
        // Create new menu item and add to menu
        MenuItem newItem(id, name, price, itemType, ingredients, ingredientsCount, category);;
        menu.modifyItem(id, newItem);  // Update the item in the menu

        // FileTasks replaces FileManager for file operations
        FileTasks fileTasks(menu);
        fileTasks.writeMenuToFile("C:\\Users\\AMOEBA\\Desktop\\DS Lab\\DS_Menu_Project\\menuItems.txt");
        cout << "Item modified successfully." << endl;

        // Cleanup: free dynamically allocated memory
        delete[] ingredients;
    } else {
        cout << "Item not found." << endl;
    }
}

// Modifies an existing order, such as changing the item or its quantity.
void UserInterface::modifyOrder() {
  if (order.empty()) {
        cout << "No orders to modify." << endl;
        return;
    }

    cout << "Enter the ID of the item you want to modify: ";
    int oldItemId;
    cin >> oldItemId;

    MenuItem* oldItem = menu.findItemById(oldItemId);
    if (!oldItem) {
        cout << "Item not found!" << endl;
        return;
    }

    cout << "Enter the new item ID: ";
    int newItemId;
    cin >> newItemId;

    MenuItem* newItem = menu.findItemById(newItemId);
    if (!newItem) {
        cout << "New item not found!" << endl;
        return;
    }

    cout << "Enter the new quantity: ";
    int newQuantity;
    cin >> newQuantity;

    if (newQuantity <= 0) {
        cout << "Invalid quantity. It must be greater than zero." << endl;
        return;
    }
    
    order.modify(*oldItem, *newItem, newQuantity);
    cout << "Order modified successfully." << endl;
}

// Removes an item from an existing order.
void UserInterface::removeOrder() {
    if (order.empty()) {
        cout << "No orders to remove." << endl;
        return;
    }

    cout << "Enter the ID of the item you want to remove from the order: ";
    int itemId;
    cin >> itemId;

    MenuItem* item = menu.findItemById(itemId);
    if (!item) {
        cout << "Item not found!" << endl;
        return;
    }

    order.remove(*item);
    cout << "Item removed from the order successfully." << endl;
}

// Updates the details of special offers, such as quantity available.
void UserInterface::updateSpecialOffers() {
    cout << "Updating special offers...\n";
    offers.displayCurrentOffers();
    cout << "Enter the ID of the offer to update: ";
    int offerId;
    cin >> offerId;
    int newQuantity = SpecialOffer::quantityGenerator();
    offers.updateQuantity(offerId, newQuantity);
    cout << "Special offer updated.\n";
    // Update special offers
}

// Handles the admin login process, verifying the admin password.
bool UserInterface::loginAdmin() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    return auth.adminLogin(password);

}
