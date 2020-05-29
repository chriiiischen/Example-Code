#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}

//insert a node at the front of the list
bool insertFront(ListType &list, const string &key, int value){
   if(contains(list, key)){
      return false;
   }
   Node *newNode = new Node(key, value, list);
   list = newNode;
   return true;
}

//remove the target front the list
bool removeTarget(ListType &list, const string &target){
   if(list == NULL){
      return false;
   }
   
   Node *p = list;
   if(p->key == target){
      list = p->next;
      return true;
   }
   Node *p2 = p->next;
   while(p2 != NULL){
      if(p2->key ==target){
         p->next = p2->next;
         return true;
      }
      p = p2;
      p2 = p2->next;
   }
   return false;
   
}



//check if target key is in the list
bool contains(ListType &list, const string &target){
   Node *p = list;
   while(p != NULL){
      if(p->key == target){
         return true;
      }
      p = p->next;
   }
   return false;
   
}

//return the value of the target
int *getValue(ListType &list, const string &target){
   
   Node *p = list;
   while(p != NULL){
      if(p->key == target){
         return &(p->value);
      }
      p = p->next;
   }
   return NULL;
   
}


//print all the entries in the list
void printList(const ListType &list){
   Node *p = list;
   while(p != NULL){
      cout << p->key << " " << p->value << endl;
      p = p->next;
   }
   
}


//return number of entries in the list
int numKey(const ListType &list){
   Node *p = list;
   int num = 0;
   while(p != NULL){
      num++;
      p = p->next;
   }
   return num;
   
}