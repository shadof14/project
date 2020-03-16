#include "main.h"
using namespace std;

int main(int argc, char **argv, char **envp)
{
     // List Control
     list      my_list;
     bool      done = false;

     // Create the list
     for (int idx = 0; envp[idx] != nullptr; idx++)
     {
          node * target = new node(envp[idx]);    // Create a node
          my_list.insert(target);                 // Ordered insert, no duplicates
     }

     // Remove items that do not begin with a lower case letter
     do {
          done = true;
          for (int idx = 0; idx < my_list.length(); idx++) {
               if (my_list[idx].get_data()[0] < 'a' || my_list[idx].get_data()[0] > 'z') {
                    my_list.remove(idx);
                    done = false;
                    break;
               }
          }
     } while (done != true);

     // Display the list
     cout << "List of Environment Variables That Start With Lower Case Character:\n" << my_list << endl;


     return 0;
}