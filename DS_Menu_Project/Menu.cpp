#include "Menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
 * =============================================================================
 *                               Menu.cpp
 * Implements the Menu class functionalities for a restaurant system.
 * =============================================================================
 
 * =============================================================================
 */

 //Constructor for the Menu class.
Menu::Menu(): menuList() {
    
}

//Destructor for the Menu class.
Menu::~Menu() {

}
// Add an item to the menu list
void Menu::addItem(const MenuItem& item) {
    menuList.insertSorted(item);
}
bool Menu::modifyItem(int id, const MenuItem& newData) {
    MenuItem* item = menuList.findByID(id);
    if (item) {
        *item = newData;
        return true;
    }
    return false;
}

// Delete an item from the menu list based on its ID
bool Menu::deleteItem(int itemID) {
    return menuList.deleteSorted(itemID);
}

 // Display the menu
void Menu::displayMenu() const {
    using namespace std;
    cout << "Menu:" << endl;
    menuList.display();
}

// Function to display menu items of a specific type (Vegan, Vegetarian, or Normal)
void Menu::displayByType(char type) const {
// Display items of a specific type using the list's specialized display function    
    menuList.displayByType(type);
}

// Displays menu items filtered by category.
void Menu::displayByCategory(char category)const {
// Display items of a specific category    
    menuList.displayByCategory(category);
}

// Traverses through the menu and performs an action for each item.
void Menu::traverseMenu() const {
// Traverse the entire menu, potentially for debugging or iterative processing    
    menuList.traverse();
}

// Finds and returns a pointer to a MenuItem in the menu by its ID.
MenuItem* Menu::findItemById(int itemId)const{
// Return the result of the findByID search within the menu list    
    menuList.findByID(itemId);
}