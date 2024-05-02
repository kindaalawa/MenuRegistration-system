
#ifndef FILETASKS_H
#define FILETASKS_H

#include "Menu.h"
#include <fstream>
#include <string>

/* =========================================================================================
/**
 * The FileTasks class is responsible for managing file operations related to the Menu.
 * It handles loading menu items from a file and saving them back to a file.
 ========================================================================================= */
class FileTasks {
private:
    Menu& menu; // Reference to the menu object for direct manipulation.

public:
    // Constructor
    /**
     * Constructor that initializes the FileTasks with a reference to a Menu object.
     * Pre-condition: A valid Menu object must be available.
     * Post-condition: FileTasks is ready to perform file operations on the given Menu.
     * menu Reference to the Menu object to manipulate.
     */    
    FileTasks(Menu&);

    // Method to load menu items from file
    /**
     * Loads menu items from a specified file into the Menu object.
     * Pre-condition: The file specified by filename must exist and be formatted correctly.
     * Post-condition: Menu items are loaded into the Menu object provided.
     * filename The name of the file from which to load menu items.
     *  menu Reference to the Menu object where the items will be loaded.
     */    
    void loadMenuFromFile(const string& filename, Menu& menu);

    // Method to write menu items to file
    /**
     * Writes all menu items from the Menu object to a file.
     * Pre-condition: The Menu object must contain items to write.
     * Post-condition: All menu items are written to the file specified by filename.
     *  filename The name of the file to which menu items will be written.
     */    
    void writeMenuToFile(const string& filename);
    /**
     * Writes a single menu item to a file using a C-style FILE pointer.
     * Pre-condition: The file pointed to by 'file' must be open for writing.
     * Post-condition: The menu item is written to the file.
     * file C-style FILE pointer to the file where the item will be written.
     * item The MenuItem object to write to the file.
     */    
    void writeMenuItemToFile(FILE* file, const MenuItem& item);
};


#endif /* FILETASKS_H */
