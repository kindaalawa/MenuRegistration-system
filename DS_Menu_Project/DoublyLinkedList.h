/*------------------------------------------------------------------ DoublyLinkedList.h ----------------------------------------------------------------------

  This header file defines the template data type DoublyLinkedList for representing a doubly linked list.
  Basic operations are:
     Constructors
     Copy constructor
     Destructor
     Assignment operator
     Accessors:       isEmpty, getSize
     Mutators:       insertSorted, deleteSorted, clear
     Display:         display
     Find:            findByID, getAtPos
     >>, <<:          Input and Output operators

----------------------------------------------------------------------------------*/
/**
 * Template class for a doubly linked list that supports generic data types.
 * Provides functionalities to manage a list through basic operations like
 * insertion, deletion, and traversal in a sorted order.
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>
#include "MenuItem.h"

using namespace std;

template <typename ElementType>
class DoublyLinkedList {
public:
    /* Function Members */

    /* Class constructors */
    /*-------------------------------------------------------------------------
         Constructs an empty DoublyLinkedList object.

         Precondition:  None.
         Postcondition: DoublyLinkedList object is initialized as an empty list.
    -------------------------------------------------------------------------*/    
    DoublyLinkedList();
        /*-------------------------------------------------------------------------
         Copy constructor.

         Precondition:  The existence of a valid DoublyLinkedList object.
         Postcondition: A copy of an original DoublyLinkedList object has been
            constructed.
    -------------------------------------------------------------------------*/
    DoublyLinkedList(const DoublyLinkedList& orig);
    /*-------------------------------------------------------------------------
         Destructs a DoublyLinkedList object.

         Precondition:  The existence of a valid DoublyLinkedList object.
         Postcondition: Deallocates the memory used by the DoublyLinkedList.
    -------------------------------------------------------------------------*/
    ~DoublyLinkedList();

    /* Accessors */
    /*-------------------------------------------------------------------------
         Checks if the doubly linked list is empty.

         Precondition:  None.
         Postcondition: Returns true if the doubly linked list is empty; 
            otherwise, returns false.
    -------------------------------------------------------------------------*/    
    bool isEmpty() const;
    /*-------------------------------------------------------------------------
         Retrieves the size of the doubly linked list.

         Precondition:  None.
         Postcondition: Returns the number of elements in the doubly linked list.
    -------------------------------------------------------------------------*/
    int getSize() const;
    
    /* Modifiers */
        /*-------------------------------------------------------------------------
         Clears all elements from the doubly linked list.

         Precondition:  None.
         Postcondition: Removes all elements from the doubly linked list, 
            leaving it with a size of 0.
    -------------------------------------------------------------------------*/
    void clear();
    /*-------------------------------------------------------------------------
         Inserts an item into the doubly linked list in sorted order.

         Precondition:  None.
         Postcondition: Inserts the item into the doubly linked list 
            while maintaining ascending order based on item IDs.
    -------------------------------------------------------------------------*/

    void insertSorted(const ElementType& item);
    /*-------------------------------------------------------------------------
         Deletes an item with the specified ID from the doubly linked list.

         Precondition:  None.
         Postcondition: Deletes the item with the specified ID from the 
            doubly linked list if found. Returns true if the deletion is 
            successful; otherwise, returns false.
    -------------------------------------------------------------------------*/
    bool deleteSorted(int itemID);

    /* Display */
    /*-------------------------------------------------------------------------
         Displays the elements of the doubly linked list.

         Precondition:  None.
         Postcondition: Prints the elements of the doubly linked list to the 
            standard output stream.
    -------------------------------------------------------------------------*/    
    void display() const;
    /**
     * Displays elements of the list filtered by type.
     * Precondition: 'type' is a valid type identifier.
     * Postcondition: Elements of the specified 'type' are displayed.
     */    
     void displayByType(char type) const;
    /**
     * Displays elements of the list filtered by category.
     * Precondition: 'category' is a valid category identifier.
     * Postcondition: Elements of the specified 'category' are displayed.
     */     
     void displayByCategory(char category) const;
    /**
     * Performs a traversal of the list.
     * Precondition: None.
     * Postcondition: The list is traversed from beginning to end.
     */     
     void traverse() const;


    /* Find */
         /*-------------------------------------------------------------------------
         Finds an item with the specified ID in the doubly linked list.

         Precondition:  None.
         Postcondition: Returns a pointer to the item with the specified ID 
            if found in the doubly linked list; otherwise, returns NULL.
    -------------------------------------------------------------------------*/

    MenuItem* findByID(int itemID) const;
    /*-------------------------------------------------------------------------
         Retrieves the item at the specified position in the doubly linked list.

         Precondition:  None.
         Postcondition: Returns a pointer to the item at the specified position 
            in the doubly linked list if the position is valid; otherwise, 
            returns NULL.
    -------------------------------------------------------------------------*/

    MenuItem* getAtPos(int pos) const;

private:

    class Node {
    public:
        ElementType data; // Data held by the node
        Node* next;      // Pointer to the next node in the list
        Node* prev;     // Pointer to the previous node in the list
        /**
         * Node constructor.
         * Precondition: 'item' is properly initialized, 'nextPtr' and 'prevPtr' point to existing nodes or are NULL.
         * Postcondition: Node is initialized with 'item' and links to next and previous nodes.
         */
        Node(const ElementType& item, Node* nextPtr = NULL, Node* prevPtr = NULL)
        : data(item), next(nextPtr), prev(prevPtr) {
        }
    };

    Node* myFirst; // Pointer to the first node in the list
    int mySize;   // Number of elements in the list
};

//----- << and >> operators
template <typename ElementType>
ostream& operator<<(ostream& out, const DoublyLinkedList<ElementType>& list);
template <typename ElementType>
istream& operator>>(istream& in, DoublyLinkedList<ElementType>& list);


//=================================EndOfHeader===============================/

//==Function Definitions==/
#include "MenuItem.h"
#include <iostream>

// Constructor: Initializes the list to be empty with 'myFirst' set to NULL and 'mySize' to 0.

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList() : myFirst(NULL), mySize(0) {
}

// Copy Constructor: Creates a deep copy of the original list.

template <typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList& orig) : myFirst(NULL), mySize(0) {
    Node* current = orig.myFirst;
    while (current != NULL) {
        insertSorted(current->data);
        current = current->next;
    }
}

// Destructor: Cleans up all dynamically allocated memory by deleting each node.

template <typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList() {
    clear();
}

// Clears the entire list, freeing all nodes.

template <typename ElementType>
void DoublyLinkedList<ElementType>::clear() {
    Node* current = myFirst;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    myFirst = NULL;
    mySize = 0;
}

// Checks if the list is empty. Returns true if empty, otherwise false.

template <typename ElementType>
bool DoublyLinkedList<ElementType>::isEmpty() const {
    return myFirst == NULL;
}

// Returns the number of items currently in the list.

template <typename ElementType>
int DoublyLinkedList<ElementType>::getSize() const {
    return mySize;
}

// Inserts a new MenuItem into the list maintaining sorted order by price.

template <typename ElementType>
void DoublyLinkedList<ElementType>::insertSorted(const ElementType& item) {
    Node* newNode = new Node(item);
    Node* current = myFirst;
    Node* previous = NULL;

    while (current != NULL && current->data.getPrice() < newNode->data.getPrice()) {
        previous = current;
        current = current->next;
    }

    newNode->next = current;
    newNode->prev = previous;

    if (previous == NULL) {
        myFirst = newNode;
    } else {
        previous->next = newNode;
    }

    if (current != NULL) {
        current->prev = newNode;
    }

    mySize++;
}

// Deletes a node from the list based on the given MenuItem ID.

template <typename ElementType>
bool DoublyLinkedList<ElementType>::deleteSorted(int itemID) {
    Node* current = myFirst;
    while (current != NULL && current->data.getId() != itemID) {
        current = current->next;
    }

    if (current == NULL) {
        return false; // Item not found
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        myFirst = current->next; // Update myFirst if the first node is being deleted
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    delete current;
    mySize--;
    return true;
}

// Displays all MenuItems in the list.

template <typename ElementType>
void DoublyLinkedList<ElementType>::display() const {
    Node* current = myFirst;
    while (current != NULL) {
        cout << "ID: " << current->data.getId()
                << ", Name: " << current->data.getName()
                << ", Price: $" << current->data.getPrice() << endl;
        current = current->next;
    }
}

// Displays  MenuItems in the list based on type.
template <typename ElementType>
void DoublyLinkedList<ElementType>::displayByType(char type) const {
    Node* current = myFirst;
    while (current != NULL) {
        if (current->data.getType() == type) {
            cout << "ID: " << current->data.getId()
                 << ", Name: " << current->data.getName()
                 << ", Price: $" << current->data.getPrice() << endl;
        }
        current = current->next;
    }
}

// Displays  MenuItems in the list based on category.
template <typename ElementType>
void DoublyLinkedList<ElementType>::displayByCategory(char category) const {
    Node* current = myFirst;
    while (current != NULL) {
        if (current->data.getCategory() == category) {
            cout << "ID: " << current->data.getId()
                 << ", Name: " << current->data.getName()
                 << ", Price: $" << current->data.getPrice() << endl;
        }
        current = current->next;
    }
}
// Finds a MenuItem by ID. Returns NULL if not found.

template <typename ElementType>
MenuItem* DoublyLinkedList<ElementType>::findByID(int itemID) const {
    Node* current = myFirst;
    while (current != NULL) {
        if (current->data.getId() == itemID) {
            return &(current->data);
        }
        current = current->next;
    }
    return NULL;
}

// Retrieves a MenuItem at a specific position. Returns NULL if position is out of bounds.

template <typename ElementType>
MenuItem* DoublyLinkedList<ElementType>::getAtPos(int pos) const {
    if (pos < 0 || pos >= mySize) {
        return NULL;
    }

    Node* current = myFirst;
    int count = 0;
    while (current != NULL) {
        if (count == pos) {
            return &(current->data);
        }
        current = current->next;
        count++;
    }
    return NULL;
}
// Method that traverses from the first node in the doubly linked list till the last node.
template <typename ElementType>
void DoublyLinkedList <ElementType>::traverse() const {
    Node* current = myFirst;
    while (current != NULL) {
        current = current->next;
    }
}
#endif // DOUBLY_LINKED_LIST_H