#ifndef MENU_H
#define MENU_H
#include "DoublyLinkedList.h"
#include "MenuItem.h"
#include <iostream>
#include <istream>
#include <fstream>   // For file operations
#include <string>
#include <vector>

using namespace std;

/* =========================================================================================
 * This header file is for the Menu class implementation.
 * Basic operations are:
 *   - Constructor: Initializes a Menu object.
 *   - Destructor: Destroys a Menu object.
 *   - loadMenuFromFile: Loads the menu from a file.
 *   - saveMenuToFile: Saves the current menu to a file.
 *   - displayMenu: Displays the entire menu.
 *   - addCategory: Adds a category to the menu.
 *   - removeCategory: Removes a category from the menu.
 *   - findCategory: Finds a category by name.
 ========================================================================================= */

class Menu {
public:
        
     //Default constructor for Menu.
    /*-------------------------------------------------------------------------
         Constructs a Menu object.

         Precondition:  None.
         Postcondition: Menu object is initialized.
    -------------------------------------------------------------------------*/    
    Menu();   
    /*-------------------------------------------------------------------------
         Destructs a Menu object.

         Precondition:  The existence of a valid Menu object.
         Postcondition: Deallocates any dynamically allocated memory.
    -------------------------------------------------------------------------*/    
    ~Menu();  
    /**
     * Adds a new item to the menu.
     * Pre-condition: None.
     * Post-condition: The new item is added to the menu.
     * @param item The MenuItem to be added.
     */
    void addItem(const MenuItem& item);
    /**
     * Deletes an item from the menu by item ID.
     * Pre-condition: The item with the specified ID exists in the menu.
     * Post-condition: The item is removed from the menu if found.
     * @param itemID The ID of the item to delete.
     * @return true if the item was successfully deleted, false otherwise.
     */    
    bool deleteItem(int itemID);
    
    /*-------------------------------------------------------------------------
         Display the entire menu.

         Precondition:  None.
         Postcondition: The entire menu is displayed.
    -------------------------------------------------------------------------*/
    void displayMenu() const;
    /**
     * Displays menu items filtered by type.
     * Pre-condition: None.
     * Post-condition: Menu items of the specified type are displayed.
     * @param type The type of items to display.
     */    
    void displayByType(char type) const ;
    /**
     * Displays menu items filtered by category.
     * Pre-condition: None.
     * Post-condition: Menu items of the specified category are displayed.
     * @param category The category of items to display.
     */    
    void displayByCategory(char category) const;
    /**
     * Modifies an existing menu item.
     * Pre-condition: The item with the specified ID exists in the menu.
     * Post-condition: The item's data is updated if found.
     * @param id The ID of the item to modify.
     * @param newData The new data for the item.
     * @return true if the item was successfully modified, false otherwise.
     */    
    bool modifyItem(int id, const MenuItem& newData);
    /**
     * Traverses and displays all menu items.
     * Pre-condition: None.
     * Post-condition: All menu items are displayed.
     */    
    void traverseMenu()const;
    /**
     * Finds a menu item by its ID.
     * Pre-condition: None.
     * Post-condition: Returns a pointer to the found MenuItem or NULL if not found.
     * @param id The ID of the item to find.
     * @return Pointer to the found MenuItem or NULL.
     */    
    MenuItem* findItemById(int id)const;
private:
 DoublyLinkedList <MenuItem> menuList; // Using DoublyLinkedList template with MenuItem as ElementType
};


#endif // MENU_H
