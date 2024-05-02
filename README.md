CSIS216 Menu Registration System - Spring 23-24

Project Overview:

This project aims to develop a sophisticated menu registration system using C++. The system provides comprehensive functionalities for both administrators and clients, facilitating menu management and ordering processes.

Features:

Menu Composition:
Constructed using a static array and linked lists for efficient data organization.
Attributes include ID, name, price, type, category, and ingredients for each menu item.
Categories: Appetizers, Main Dishes, Desserts, and Beverages.
Items within categories sorted by price to enhance user experience.
Special Offer Management:
Special offer feature integrated via C++ vector container.
Includes 8 items at a time, 2 from each category, with limited quantities.
Automatic replacement of depleted items with new offers, accompanied by a 30% discount.
Vegan/Vegetarian Menu:
Dedicated menu offering plant-based options.
Generated as a static array of categories with linked lists of menu item IDs.
Application Functionality:
Admin and client login functionality implemented for secure access.
Admins empowered to add, modify, or remove menu items, as well as manage file operations.
Clients can browse menus, place orders, and receive detailed bills.
Ordering from special offers dynamically updates quantities.
Billing system ensures transparency and accuracy in transactions.
