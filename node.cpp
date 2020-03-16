#include "node.h"

// Constructors
node::node()
{
     data = nullptr;
     next = nullptr;
}

node::node(char * string) : node::node()
{
     data = new char[strlen(string) + 1];
     strcpy(data,string);
     next = nullptr;
}

// Destructor
node::~node()
{
     if (data != nullptr) delete [] data;
     next = nullptr;
}

char * node::get_data() const { return data; }
node * node::get_next() const { return next; }
void node::set_data(char * parm) { data = parm; }
void node::set_next(node * parm) { next = parm; }

std::ostream & operator << (std::ostream & out, node & rvalue)
{
     out << rvalue.data;
     return out;
}

bool operator == (const node & left, const node & right)
{
     if (strcmp(left.get_data(), right.get_data()) == 0) return true;
     else return false;
}

bool operator > (const node & left, const node & right)
{
     if (strcmp(left.get_data(), right.get_data()) <= 0) return false;
     else return true;
}

bool operator != (const node & left, const node & right)
{
     return !(left == right);
}