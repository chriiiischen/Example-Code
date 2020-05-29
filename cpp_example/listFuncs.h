#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;


//insert a node at the front of the list
//return false iff the key is already present and the list remainds unchanged
bool insertFront(ListType &list, const std::string &key, int value);

//remove the target from the list
//retrun false iff the target is not on the list
bool removeTarget(ListType &list, const std::string &target);


//return true iff the target key is in the list
bool contains(ListType &list, const std::string &target);

//return the pointer of the value of the target
//return NULL iff the target is not on the list
int *getValue(ListType &list, const std::string &target);

//print all the entries in the list
void printList(const ListType &list);

//return number of entries in the list
int numKey(const ListType &list);



// keep the following line at the end of the file
#endif
