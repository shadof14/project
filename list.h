#pragma once
#include <iostream>
#include "node.h"

class    list
{
private:
     node      *    head;          // List head pointer

public:
     list();                       // Default constructor
     list(const list &);           // Copy constructor
     ~list();                      // Destructor
     list & operator = (const list &); // Copy assignment

     // List information
     bool is_empty();              // Accessor: empty list
     int  length();                // Accessor: return length of list
     node * find(node *);          // Accessor: find element in the list

     // List access
     node & operator [](int);      // Reference index (allows update)
     const node & operator [](int) const; // Value index (allows read only)
     const node & at(int);         // Value accessor (allows read only)

     // Remove things from the list
     void erase();                 // Mutator: erase all elements in the list
     void remove(int);             // Mutator: remove by position
     void remove(node *);          // Mutator: remove by value

     // Add things to the list
     void append(node *);          // Mutator: Append to end of list
     void insert(node *, int);     // Positional insert
     void insert(node *);          // Ordered insertion

     // External functions
     friend std::ostream & operator << (std::ostream &, const list &);
};