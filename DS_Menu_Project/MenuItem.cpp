#include "MenuItem.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream> 

using namespace std;

// Initialize static member variables
int MenuItem::appetizerCounter = 0;
int MenuItem::mainDishCounter = 0;
int MenuItem::dessertCounter = 0;
int MenuItem::beverageCounter = 0;

// Default constructor for MenuItem.
MenuItem::MenuItem()
    : id(100), name(""), price(0.0), type(Normal),category('U'), ingredientsCount(0) {
        // Initialize ingredients array to empty strings
    for (int i = 0; i < sizeof(ingredients) / sizeof(ingredients[0]); ++i) {
        ingredients[i] = "";
    }
}

// Parameterized constructor for MenuItem.
MenuItem::MenuItem(int id, const string& name, double price, Type type,
        const string ingredients[], int ingredientsCount,char category)
    : id(id), name(name), price(price), type(type), category(category), ingredientsCount(ingredientsCount){
        // Copy ingredients into the ingredients array
    for (int i = 0; i < ingredientsCount; ++i) {
        this->ingredients[i] = ingredients[i];
    }
    // If ingredientsCount is less than the maximum size of ingredients array, initialize remaining elements to empty strings
    for (int i = ingredientsCount; i < sizeof(this->ingredients) / sizeof(this->ingredients[0]); ++i) {
        this->ingredients[i] = "";
    }
}

// Copy constructor for MenuItem.
MenuItem::MenuItem(const MenuItem& other)
    : id(other.id), name(other.name), price(other.price), type(other.type),
         category(other.category), ingredientsCount(other.ingredientsCount)  {
        // Copy ingredients into the ingredients array
    for (int i = 0; i < ingredientsCount; ++i) {
        this->ingredients[i] = other.ingredients[i];
    }

}

// Destructor for MenuItem.
MenuItem::~MenuItem() {
    delete[] ingredients;
}
// Assignment operator for MenuItem.
MenuItem& MenuItem::operator=(const MenuItem& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        price = other.price;
        type = other.type;
        category = other.category;
        ingredientsCount = other.ingredientsCount;
        // Copy ingredients into the ingredients array
        for (int i = 0; i < ingredientsCount; ++i) {
            this->ingredients[i] = other.ingredients[i];
        }
    }
    return *this;
}
// Getters
// Getter for ID.
int MenuItem::getId() const {
    return id; 
}

// Getter for name.
string MenuItem::getName() const {
    return name;
}

// Getter for price.
double MenuItem::getPrice() const {
    return price;
}

// Getter for type.
MenuItem::Type MenuItem::getType() const {
    return type;
}

// Getter for category.
char MenuItem::getCategory() const {
    return category;
}

// Getter for ingredients.
const string* MenuItem::getIngredients() const {
    return ingredients;
}

// Getter for ingredients count.
int MenuItem::getIngredientsCount() const {
    return ingredientsCount;
}
// Define the function to generate the next ID based on the category
int MenuItem::generateId(char category) {
    switch (category) {
        case 'A':
            return 100 + (++appetizerCounter); // First digit represents Appetizers
        case 'M':
            return 200 + (++mainDishCounter); // First digit represents Main Dishes
        case 'D':
            return 300 + (++dessertCounter); // First digit represents Desserts
        case 'B':
            return 400 + (++beverageCounter); // First digit represents Beverages
        default:
            cerr << "Invalid category" << endl;
            return 0;
    }
}
// Setters
// Setter for ID.
void MenuItem::setId(int newId) { 
    id = newId; 
}

// Setter for name
void MenuItem::setName(const string& newName) { 
    name = newName;
}

// Setter for price.
void MenuItem::setPrice(double newPrice) { 
    if (newPrice > 0) {
        price = newPrice;
    } else {
        cerr << "Error: Price must be positive." << endl;
    }
    price = newPrice;
}

// Setter for type.
void MenuItem::setType(Type newType) { 
    type = newType;
}

// Setter for category.
void MenuItem::setCategory(char category) { 
    category = category;
}

// Setter for ingredients.
void MenuItem::setIngredients(const string newIngredients[], int newIngredientsCount) {
    delete[] ingredients;  // First delete the existing array
    // Copy ingredients into the ingredients array
    for (int i = 0; i < newIngredientsCount; ++i) {
        this->ingredients[i] = newIngredients[i];
    }
    // If ingredientsCount is less than the maximum size of ingredients array, initialize remaining elements to empty strings
    for (int i = ingredientsCount; i < sizeof(this->ingredients) / sizeof(this->ingredients[0]); ++i) {
        this->ingredients[i] = "";
    }
    this->ingredientsCount = ingredientsCount;
}

// Display details of MenuItem.
void MenuItem::displayDetails() const {
    cout << "ID: " << id << "\nName: " << name << "\nPrice: $" << price << "\nType: " << type
              << "\nCategory: " << category << "\nIngredients: ";
    for (int i = 0; i < ingredientsCount; i++) {
        cout << ingredients[i];
        if (i < ingredientsCount - 1) cout << ", ";
    }
    cout << endl;
}

// Comparison operators
// Equal to operator.
bool MenuItem::operator==(const MenuItem& other) const {
    if (id != other.id || name != other.name || price != other.price || type != other.type || category != other.category || ingredientsCount != other.ingredientsCount) {
        return false;
    }
    // Compare ingredients
    for (int i = 0; i < ingredientsCount; ++i) {
        if (ingredients[i] != other.ingredients[i]) {
            return false;
        }
    }
    return true;
}

// Not equal to operator.
bool MenuItem::operator!=(const MenuItem& other) const {
    return !(*this == other);
}

// Stream operators
// Stream insertion operator.
ostream& operator<<(ostream& os, const MenuItem& item) {
    os << "ID: " << item.getId() << "\n"
       << "Name: " << item.getName() << "\n"
       << "Price: $" << item.getPrice() << "\n"
       << "Type: " << static_cast<char>(item.getType()) << "\n"
       << "Category: " << item.getCategory() << "\n"
       << "Ingredients: ";
    
    // Iterate over the ingredients using getIngredientsCount() to determine the number of ingredients
    for (int i = 0; i < item.getIngredientsCount(); ++i) {
        os << item.getIngredients()[i]; // Access each ingredient using array notation
        if (i < item.getIngredientsCount() - 1)
            os << ", ";
    }
    os << endl;
    return os;
}

// Stream extraction operator.
istream& operator>>(istream& in, MenuItem& item) {
    int id;
    cout << "Enter item ID: ";
    in >> id;
    item.setId(id);

    string name;
    cout << "Enter item name: ";
    in.ignore(); // Ignore newline character from previous input
    getline(in, name);
    item.setName(name);

    double price;
    cout << "Enter item price: ";
    in >> price;
    item.setPrice(price);

    char type;
    cout << "Enter item type (V for Vegan, G for Vegetarian, N for Normal): ";
    in >> type;
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
            cout << "Invalid type. Setting to Normal.\n";
            itemType = MenuItem::Normal;
    }
    item.setType(itemType);

    char category;
    cout << "Enter item category (A for Appetizers, M for Main Dishes, D for Desserts, B for Beverages): ";
    in >> category;
    item.setCategory(category);

    int ingredientsCount;
    cout << "Enter number of ingredients: ";
    in >> ingredientsCount;

    // Read ingredients
    cout << "Enter ingredients (one per line):\n";
    in.ignore(); // Ignore newline character from previous input
    string ingredients[10]; // Assuming a maximum of 10 ingredients
    for (int i = 0; i < ingredientsCount; ++i) {
        getline(in, ingredients[i]);
    }
    item.setIngredients(ingredients, ingredientsCount);

    return in;
}



