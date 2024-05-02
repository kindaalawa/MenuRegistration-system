#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <iostream>
#include <istream>

using namespace std;
/*-- MenuItem.h ----------------------------------------------------------------------

  This header file defines the data type MenuItem for representing an item on a restaurant's menu.
  Basic operations are:
     Constructors
     Copy constructor
     Destructor
     Assignment operator
     Accessors:       getId, getName, getPrice, getType, getCategory, getIngredients
     Mutators:         setId, setName, setPrice, setType, setCategory, setIngredients
     Comparison operators:   ==, !=
     >>, <<:          Input and Output operators

----------------------------------------------------------------------------------*/
class MenuItem {
public:
    enum Type { Vegan = 'V', Vegetarian = 'G', Normal = 'N' };
    static int generateId(char category);
    /** Function Members **/
    /* Class constructors */    
    /*-------------------------------------------------------------------------
         Constructs a MenuItem object (default).

         Precondition:  None.
         Postcondition: MenuItem object is initialized with default values;
            that is, id is initialized to 100, name to an empty string, price
            to 0.0, type to Normal, and ingredients to an empty vector.
    -------------------------------------------------------------------------*/
    MenuItem();
    /*-------------------------------------------------------------------------
         Constructs a MenuItem object with specified values.

         Preconditions: None.
         Postcondition: MenuItem object is initialized with specified values
            for id, name, price, type, and ingredients.
    -------------------------------------------------------------------------*/    
    MenuItem(int id, const string& name, double price, Type type,
    const string ingredients[], int ingredientsCount, char category);
    /*-------------------------------------------------------------------------
         Copy constructer.

         Precondition:  The existence of a valid MenuItem object with
            initialized values.
         Postcondition: A copy of an original MenuItem object has been
            constructed.
    -------------------------------------------------------------------------*/    
    MenuItem(const MenuItem& other);
    /*-------------------------------------------------------------------------
         Destructs a MenuItem object.

         Precondition:  The existance of a valid MenuItem object.
         Postcondition: Deallocates any dynamically allocated memory.
    -------------------------------------------------------------------------*/    
    ~MenuItem();
    /*-------------------------------------------------------------------------
         Copy assignment operator.

         Precondition:  The existence of valid MenuItem objects.
         Postcondition: Assigns the values of one MenuItem object to
            another.
    -------------------------------------------------------------------------*/    
    MenuItem& operator=(const MenuItem& other);
    /* Accessors */
    /*-------------------------------------------------------------------------
         Retrieve the id of the MenuItem.

         Precondition:  None.
         Postcondition: The id of the MenuItem is returned.
    -------------------------------------------------------------------------*/    
    int getId() const;
    /*-------------------------------------------------------------------------
         Retrieve the name of the MenuItem.

         Precondition:  None.
         Postcondition: The name of the MenuItem is returned.
    -------------------------------------------------------------------------*/    
    string getName() const;
    /*-------------------------------------------------------------------------
         Retrieve the price of the MenuItem.

         Precondition:  None.
         Postcondition: The price of the MenuItem is returned.
    -------------------------------------------------------------------------*/    
    double getPrice() const;
    /*-------------------------------------------------------------------------
         Retrieve the type of the MenuItem.

         Precondition:  None.
         Postcondition: The type of the MenuItem is returned.
    -------------------------------------------------------------------------*/    
    Type getType() const;
    /*-------------------------------------------------------------------------
         Retrieve the category of the MenuItem.

         Precondition:  None.
         Postcondition: The category of the MenuItem is returned as a char.
    -------------------------------------------------------------------------*/    
    char getCategory() const;
    /*-------------------------------------------------------------------------
         Get the number of ingredients.
         Precondition:  None.
         Postcondition: Returns the count of ingredients.
    -------------------------------------------------------------------------*/    
    int getIngredientsCount() const; // Return number of ingredients
    /*-------------------------------------------------------------------------
         Retrieve the ingredients of the MenuItem.

         Precondition:  None.
         Postcondition: Return pointer to ingredients array.
    -------------------------------------------------------------------------*/    
   const string* getIngredients() const;
    /* Mutators */
    /*-------------------------------------------------------------------------
         Set the id of the MenuItem.

         Preconditions: None.
         Postconditon:  The id of the MenuItem is set to the specified value.
    -------------------------------------------------------------------------*/    
    void setId(int id);
    /*-------------------------------------------------------------------------
         Set the name of the MenuItem.

         Preconditions: None.
         Postconditon:  The name of the MenuItem is set to the specified value.
    -------------------------------------------------------------------------*/    
    void setName(const string& name);
    /*-------------------------------------------------------------------------
         Set the price of the MenuItem.

         Preconditions: None.
         Postconditon:  The price of the MenuItem is set to the specified value.
    -------------------------------------------------------------------------*/    
    void setPrice(double price);
    /*-------------------------------------------------------------------------
         Set the type of the MenuItem.

         Preconditions: None.
         Postconditon:  The type of the MenuItem is set to the specified value.
    -------------------------------------------------------------------------*/    
    void setType(Type type);
    /*-------------------------------------------------------------------------
         Set the category of the MenuItem.
         Precondition:  None.
         Postcondition: The category is set.
    -------------------------------------------------------------------------*/    
    void setCategory(char category);

    /*-------------------------------------------------------------------------
         Set the ingredients of the MenuItem.

         Preconditions: None.
         Postconditon:  The ingredients of the MenuItem are set in the ingredients array
    -------------------------------------------------------------------------*/    
    void setIngredients(const string newIngredients[], int newIngredientsCount);
        /*-------------------------------------------------------------------------
         Display details of the MenuItem.
         Precondition:  None.
         Postcondition: Details of the MenuItem are displayed.
    -------------------------------------------------------------------------*/    
    void displayDetails() const;
    /* Comparison operators */
    /*-------------------------------------------------------------------------
         Determine if one MenuItem object is equal to another MenuItem object.

         Precondition:  None.
         Postcondition: true is returned if both MenuItem objects have the
            same id, name, price, type, and ingredients; otherwise, false
            is returned.
    -------------------------------------------------------------------------*/    
    bool operator==(const MenuItem& other) const;
    /*-------------------------------------------------------------------------
         Determine if one MenuItem object is not equal to another MenuItem object.

         Precondition:  None.
         Postcondition: true is returned if both MenuItem objects have
            different id, name, price, type, or ingredients; otherwise, false
            is returned.
    -------------------------------------------------------------------------*/    
    bool operator!=(const MenuItem& other) const;

private:
 /* Data Members */   
    
    static int appetizerCounter; // Static counter for appetizers
    static int mainDishCounter;// Static counter for main dishes
    static int dessertCounter;// Static counter for desserts
    static int beverageCounter;// Static counter for beverages 
    int id; // id of the MenuItem
    string name; // name of the MenuItem
    double price; // price of the MenuItem
    Type type;// type of the MenuItem
    char category; // Category of the MenuItem
    
    string ingredients [10];// ingredients of the MenuItem
    int ingredientsCount;  // Number of ingredients
};
// Stream operators for the MenuItem
/*-------------------------------------------------------------------------
Overload the output stream operator for the MenuItem.
Precondition: A valid ostream and MenuItem objects must be provided.
Postcondition: Outputs the MenuItem details to the ostream.
-------------------------------------------------------------------------*/
ostream& operator<<(ostream& os, const MenuItem& item);
/*-------------------------------------------------------------------------
Overload the input stream operator for the MenuItem.
Precondition: A valid istream must be provided.
Postcondition: MenuItem details are read from the istream and set to the MenuItem.
-------------------------------------------------------------------------*/
istream& operator>>(istream& in, MenuItem& item);

#endif // MENUITEM_H
