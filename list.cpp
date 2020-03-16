#include"list.h"
using namespace std;

list::list()                                    // Default constructor
{
   head = nullptr;
   cout << "1" << endl;
}

list::list(const list & my_list)                // Copy constructor
{
   head = my_list.head;
   cout << "2" << endl;
}

list::~list()                                   // Destructor
{
   if (head != nullptr)
   {
      node * curr;
      while (head)
      {
         curr = head->get_next();
         delete [] head;
         head = curr;
      }
   curr = nullptr;
   head = nullptr;
   }
   cout << "3" << endl;
}

list & list::operator = (const list & my_list) // Copy assignment
{
      cout << "help me empty" << endl;
   if (my_list.head->get_data() == nullptr)
   {
      head = nullptr;
      return *this;
   }

   head->set_data(my_list.head->get_data());
   head->set_next(my_list.head->get_next());
   node * curr = head;
   while (curr != nullptr)
   {
   node * curr = head;
   while (curr != nullptr)
   {
      curr = curr->get_next();
      curr = curr->get_next();
   }
   cout << "Help me" << endl;
   return *this;
}

// List information
bool list::is_empty()                           // Accessor: empty list
{

   if (head == nullptr) return true;
   else return false;
   cout << "4" << endl;

}

int  list::length()                             // Accessor: return length of list
{
   int count = 0;
   node * curr;
   curr = head;
   while (curr != nullptr)
   {
      curr= curr->get_next();
      count++;
   }
   cout << "5" << endl;
   return count;
}

node * list::find(node * target)                // Accessor: find element in the list
{
   node * curr;
   curr = head;
   while (curr != nullptr)
   {
      if (strcmp(curr->get_data(), target->get_data()) == 0)  return curr;
      else curr = curr->get_next();
   }
   cout << "6" << endl;
   return nullptr;
}

// List access
node & list::operator [](int pos)               // Reference index (allows update)
{
   node * curr = head;
   for (int idx = 0; idx < pos; idx++)
   {
      curr = curr->get_next();
   }
   cout << "7" << endl;
   return *curr;

}

const node & list::operator [](int pos) const {
   cout << "8" << endl;
   return head[pos]; }  // Value index (allows read only)

const node & list::at(int pos)                  // Value accessor (allows read only)
{
   cout << "9" << endl;
   return head[pos];
}

// Remove things from the list
void list::erase()                              // Mutator: erase all elements in the list
{
   node * curr;
   while(head != nullptr)
   {
      curr = head->get_next();
      delete [] head;
      head = curr;
   }
   cout << "10" << endl;
}

void list::remove(int pos)                      // Mutator: remove by position
{
   node * curr;
   node * temp;
   curr = head;
   for (int idx = 0; idx < pos; idx++)
   {
      while (curr != nullptr)  curr = curr->get_next();
   }
   if (curr != nullptr && curr->get_next() != nullptr)
   {
      temp = curr->get_next();
      curr->set_next(temp->get_next());
      pos--;
   }
   else cout << "error - list isn't big enough" << endl;
   cout << "11" << endl;
}

void list::remove(node * target)                        // Mutator: remove by value
{
   node * curr;
   node * test;
   curr = head;
   while (curr->get_next() != nullptr)
   {
      if (strcmp(target->get_data(), head->get_data()) == 0)
      {
         head->set_next(head->get_next());
         delete curr;
      }

      test = curr->get_next();
      if (strcmp(target->get_data(), test->get_data()) == 0)
      {
            curr->set_next(test->get_next());
            delete test;
      }

      else curr = curr->get_next();
   }
   cout << "12" << endl;
}

// Add things to the list
void list::append(node * target)                // Mutator: Append to end of list
{

   node * temp = head;
   while (temp->get_next() != nullptr)
   {
      temp = temp->get_next();
   }
   temp->set_next(target);
   cout << "13" << endl;
}

void list::insert(node * target, int pos)       // Positional insert
{

   node * curr = head;
   node * temp;
   for (int idx = 0; idx <= pos; idx++)
   {
      if (idx == pos)
      {
         temp  = curr->get_next();
         target->set_next(temp);
         curr->set_next(target);
      }
      else curr = curr->get_next();
   }
   cout << "14" << endl;
}

void list::insert(node * target)                // Ordered insertion
{
   node * temp;
   node * curr;
   if (target == nullptr)
      return;
                //If first in list
   if (head == nullptr)
   {
      curr = target;
      curr->set_next(nullptr);
      head = curr;

      cout << "Started list with: " << head->get_data() << endl;

      return;
   }
                //If not first in list
   if (strcmp(curr->get_data(), target->get_data()) <= 0)
   {
      temp = curr->get_next();
      while (strcmp(temp->get_data(), target->get_data()) < 0 && temp != nullptr)
      {
         curr = curr->get_next();
         temp = curr->get_next();
      }
      target->set_next(temp);
      curr->set_next(target);
      return;
   }
   target->set_next(temp);
   curr->set_next(target);
   return;
}
// External functions
std::ostream & operator << (std::ostream & outf, const list & my_list)
{
   node * curr = my_list.head;
   while (curr != nullptr)
   {
      outf << curr->get_data() << endl;
      curr = curr->get_next();
   }
   return outf;

}