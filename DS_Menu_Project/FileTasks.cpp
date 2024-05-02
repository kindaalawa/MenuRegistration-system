#include "FileTasks.h"
#include "MenuItem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio> // For FILE, fopen, fprintf, fclose

using namespace std;

// Constructor for FileManager class
FileTasks::FileTasks(Menu& men) : menu(men) {}

// Write the menu to a file
void FileTasks::writeMenuToFile(const string& filename) {
    FILE* file = fopen(filename.c_str(), "w");
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // Iterate over menu items and write to file
    menu.traverseMenu();

    fclose(file);
}

// Function to write menu item to file
void FileTasks::writeMenuItemToFile(FILE* file, const MenuItem& item) {
    fprintf(file, "%s,%c,%c,%.2f", item.getName().c_str(), item.getType(), item.getCategory(), item.getPrice());
    const string* ingredients = item.getIngredients();
    for (int i = 0; i < item.getIngredientsCount(); i++) {
        fprintf(file, ",%s", ingredients[i].c_str());
    }
    fprintf(file, "\n");
}

// Load menu items from a file and add them to the menu
// Load menu items from a file and add them to the menu
// Load menu items from a file and add them to the menu
void FileTasks::loadMenuFromFile(const string& filename, Menu& menu) {
    ifstream file(filename.c_str());
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        string tokens[6]; // Array to store tokens

        // Tokenize each line by comma
        int idx = 0;
        while (getline(iss, token, ',')) {
            tokens[idx++] = token;
        }

        // Ensure the line has enough tokens to represent a menu item
        if (idx < 6) {
            cerr << "Invalid line, skipping: " << line << endl;
            continue;
        }

        // Extract data from tokens
        int id = atoi(tokens[0].c_str());
        string name = tokens[1];
        char type = toupper(tokens[2][0]);
        char category = toupper(tokens[3][0]);
        double price = atof(tokens[4].c_str());

        // Count the number of ingredients
        int ingredientsCount = min(5, idx - 5); // Maximum 5 ingredients
        string ingredients[5]; // Array to store ingredients
        for (int i = 0; i < ingredientsCount; ++i) {
            ingredients[i] = tokens[i + 5];
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
        cerr << "Invalid type: " << type << endl;
        return;
}
        // Create new menu item and add to menu
        MenuItem newItem(id, name, price, itemType, ingredients, ingredientsCount, category);
        menu.addItem(newItem);
    }
    file.close();
}
