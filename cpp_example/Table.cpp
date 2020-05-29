#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;




#include "listFuncs.h"

Table::Table() {
   data = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
   data = new ListType[hSize]();
   hashSize = hSize;
}


int * Table::lookup(const string &key) {
   return getValue(data[hashCode(key)], key);
}

bool Table::remove(const string &key) {
   return removeTarget(data[hashCode(key)], key);
}

bool Table::insert(const string &key, int value) {
   return insertFront(data[hashCode(key)], key, value);
}

int Table::numEntries() const {
   int sum = 0;
   for(int i = 0; i < hashSize; i++){
      sum = sum + numKey(data[i]);
   }
   
   return sum;
}


void Table::printAll() const {
   for(int i = 0; i < hashSize; i++){
      printList(data[i]);
   }
}

void Table::hashStats(ostream &out) const {
   int longest = 0;
   int nonEmpty = 0;
   for(int i = 0; i < hashSize; i++){
      int length = numKey(data[i]);
      
      if(length > longest){
         longest = length;
      }
      
      if(length > 0){
         nonEmpty++;
      }

     
   }
    out << "number of buckets: " << hashSize << endl;
    out << "number of entries: " << numEntries() << endl;
    out << "number of non-empty buckets: " << nonEmpty << endl;
    out << "longest chain: " << longest << endl;
   
}

