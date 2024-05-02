#include "SpecialOffer.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Initialize the discount value.
const double SpecialOffer::DISCOUNT = 0.30;

// Generate special offers for each category.
void SpecialOffer::generateSpecialOffer() {
const char categoryArray[] = { 'A', 'M', 'D', 'B' };
const vector<char> categories(categoryArray, categoryArray + sizeof(categoryArray) / sizeof(categoryArray[0]));
    for (int i = 0; i < categories.size(); ++i) {
        char category = categories[i];
        for (int j = 0; j < 2; ++j) {
            int itemId = offerItemGenerator(category);
            if (itemId != -1) {
                addOfferItem(itemId, quantityGenerator());
            }
        }
    }
}

// Constructor for SpecialOffer.
SpecialOffer::SpecialOffer(Menu& menu) : menu(menu) {
    generateSpecialOffer();
}

// Generate a random item ID for a given category.
int SpecialOffer::offerItemGenerator(char category) {
    std::vector<int> offerIds;

    // Initialize the random number generator
    srand(static_cast<unsigned>(time(NULL)));

    // since MenuItem IDs are consecutive and start from 100, and go up to 499
    const int StartID = 100;
    const int EndID = 499;

    for (int i = StartID; i <= EndID; ++i) {
        MenuItem* item = menu.findItemById(i);
        if (item != NULL && item->getCategory() == category) {
            offerIds.push_back(item->getId());
        }
    }

    // Check if we have collected any valid item IDs
    if (!offerIds.empty()) {
        int randomIndex = rand() % offerIds.size();
        return offerIds[randomIndex];
    }

    return -1; // Return -1 if no items found
}




int SpecialOffer::quantityGenerator() {
    return 3 + rand() % 8;
}

// Add an offer item to the special offer list.
void SpecialOffer::addOfferItem(int itemId, int quantity) {
  if (offers.size() < 8) {
        offers.push_back(OfferItem(itemId, quantity));
    }
}

// Remove an offer item from the special offer list.
bool SpecialOffer::removeOfferItem(int itemId) {
    for (int i = 0; i < offers.size(); ++i) {
        if (offers[i].itemId == itemId) {
            for (int j = i + 1; j < offers.size(); ++j) {
                offers[j - 1] = offers[j];
            }
            offers.pop_back();  // Remove the last element (which is now a duplicate)
            return true;
        }
    }
    return false;
}


// Update the quantity of an offer item in the special offer list.
bool SpecialOffer::updateQuantity(int itemId, int newQuantity) {
    for(int i = 0; i < offers.size(); i++){
         if(offers[i].itemId == itemId) {
            offers[i].quantity == newQuantity;
            return true;
        }
    }
    return false;
}

// Get the current list of special offer items.
const vector<SpecialOffer::OfferItem>& SpecialOffer::getCurrentOffers() const {
    return offers;
}

// Calculate the discounted price for an item.
double SpecialOffer::calculateDiscountedPrice(int itemId) const {
        double originalPrice = getItemPrice(itemId);
    return originalPrice -originalPrice * DISCOUNT;
}

// Check if an item is part of a special offer.
bool SpecialOffer::isSpecialOfferItem(int itemId){
    for(int i = 0; i < offers.size(); i++){
        if(offers[i].itemId == itemId)
            return true;
    }
    return false;
}

// Get the category of an item.
char SpecialOffer::getItemCategory(int itemId) const {
    if (itemId >= 100 && itemId <= 199) return 'A';
    else if (itemId >= 200 && itemId <= 299) return 'M';
    else if (itemId >= 300 && itemId <= 399) return 'D';
    else if (itemId >= 400 && itemId <= 499) return 'B';
    return 'X';
}

// Update a special offer item.
void SpecialOffer::updateOffer(int index) {
    char category = getItemCategory(offers[index].itemId);
    int newItemId = offerItemGenerator(category);
    int newQuantity = quantityGenerator();

    offers[index].itemId = newItemId;
    offers[index].quantity = newQuantity;
}

// Get the price of an item.
double SpecialOffer::getItemPrice(int itemId) const {

    MenuItem* item = menu.findItemById(itemId);
    if (item) {
        return item->getPrice();
    } else {
        cerr << "Error: Item ID " << itemId << " not found in menu." << endl;
        return 0.0;
    }
}

// Display the current special offers.
void SpecialOffer::displayCurrentOffers() const {
    if (offers.empty()) {
        cout << "No offers available." << endl;
        return;
    }

   for (int i = 0; i < offers.size(); ++i) {
    const OfferItem& offer = offers[i];
    double discountedPrice = calculateDiscountedPrice(offer.itemId);
    cout << "Item ID: " << offer.itemId
         << ", Quantity: " << offer.quantity
         << ", Discounted Price: $" << discountedPrice
         << endl;
}

}
