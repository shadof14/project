#pragma once
#include <iostream>
#include <cstring>

class  node
{
private:
     char      *data;         // Data is c-string
     node      *next;         // next pointer

public:
     node();                  // Default constructor
     node(char *);            // Parm constructor
    ~node();                  // Destructor

     char * get_data() const; // Accessor
     node * get_next() const; // Accessor

     void set_data(char *);   // Mutator
     void set_next(node *);   // Mutator

     friend std::ostream & operator << (std::ostream &, node &);
};

bool operator == (const node &, const node &);
bool operator > (const node &, const node &);
bool operator != (const node &, const node &);