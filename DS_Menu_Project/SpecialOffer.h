#ifndef SPECIALOFFER_H
#define SPECIALOFFER_H

#include <iostream>
#include <istream>
#include <vector>
#include "MenuItem.h"

class Menu;

using namespace std;
/*-- SpecialOffer.h ----------------------------------------------------------------------
  This header file defines the SpecialOffer class for managing special offers on menu items.
  Basic operations are:
     Constructor
     Destructor
     addOfferItem:    To add a new item to the special offers
     removeOfferItem: To remove an item from the special offers
     updateQuantity:  To update the quantity of an existing offer item
     getCurrentOffers: To retrieve the current special offers
----------------------------------------------------------------------------------*/

class SpecialOffer {
public:
    class OfferItem {
    public:
        int itemId;
        int quantity;
        OfferItem(int id, int qty) : itemId(id), quantity(qty) {}
    };

    vector<OfferItem> offers;
public:


    /*-------------------------------------------------------------------------
         Add a new item to the special offers, based on the MenuItem and quantity

         Precondition:  The existence of a MenuItem object and a positive quantity.
         Postcondition: A new OfferItem is added to the special offers list.
    -------------------------------------------------------------------------*/    
    void addOfferItem(int itemId, int quantity);

    /*-------------------------------------------------------------------------
         Remove an item from the special offers by item ID.

         Precondition:  The existance of a valid SpecialOffer object and a valid item ID.
         Postcondition: The OfferItem with the specified ID is removed from the offers list.
    -------------------------------------------------------------------------*/
    bool removeOfferItem(int itemId);

    /*-------------------------------------------------------------------------
         Update the quantity of an existing offer item.

         Precondition:  The existance of a valid SpecialOffer object, a valid item ID, and a positive new quantity.
         Postcondition: The quantity of the OfferItem with the specified ID is updated to the new quantity.
    -------------------------------------------------------------------------*/
    bool updateQuantity(int id, int newQuantity);
    
    bool isSpecialOfferItem(int itemId);
    char getItemCategory(int itemId)const;
        /*-------------------------------------------------------------------------
         Get the original price of an item from the menu.

         Precondition:  The ID of the item for which the price is to be retrieved.
         Postcondition: Returns the original price of the item from the menu.
    -------------------------------------------------------------------------*/
    double getItemPrice(int itemId) const;
    /*-------------------------------------------------------------------------
         Retrieve the current special offers.

         Precondition:  The existance of a valid SpecialOffer object.
         Postcondition: Returns a vector containing all the current special offers.
    -------------------------------------------------------------------------*/
     const vector<OfferItem>& getCurrentOffers() const;
    /*-------------------------------------------------------------------------
         Display the current special offers.

         Precondition:  The existence of a valid SpecialOffer object.
         Postcondition: Prints information about all the current special offers.
    -------------------------------------------------------------------------*/     
      void displayCurrentOffers() const;
    /*-------------------------------------------------------------------------
         Generate a special offer item based on a specified category.

         Precondition:  A valid category character.
         Postcondition: Returns the ID of a randomly selected item within the specified category.
    -------------------------------------------------------------------------*/      
      int offerItemGenerator(char category);
    /*-------------------------------------------------------------------------
         Calculate the discounted price for an item based on special offers.

         Precondition:  The ID of the item for which the discounted price is to be calculated.
         Postcondition: Returns the discounted price of the item.
    -------------------------------------------------------------------------*/      
      double calculateDiscountedPrice(int itemId) const;
    /*-------------------------------------------------------------------------
         Constructor: Initializes the SpecialOffer object with the provided Menu reference.
    -------------------------------------------------------------------------*/      
      SpecialOffer(Menu&);
    /*-------------------------------------------------------------------------
         Update a special offer item with a new item.

         Precondition:  The index of the special offer item to be updated.
         Postcondition: Updates the special offer item with a new randomly selected item.
    -------------------------------------------------------------------------*/      
      void updateOffer(int index);
    /*-------------------------------------------------------------------------
         Generate special offers by selecting random items from the menu.

         Precondition:  The existence of a valid SpecialOffer object and a populated menu.
         Postcondition: Random items from the menu are selected as special offers.
    -------------------------------------------------------------------------*/      
      void generateSpecialOffer() ;
          /*-------------------------------------------------------------------------
         Generate a random quantity for special offer items.

         Precondition:  None.
         Postcondition: Returns a random integer representing the quantity for special offer items.
    -------------------------------------------------------------------------*/
      static int quantityGenerator();
      static const double DISCOUNT; //Static constant representing the discount percentage for special offers.

private:

        Menu& menu;
};

#endif // SPECIALOFFER_H
