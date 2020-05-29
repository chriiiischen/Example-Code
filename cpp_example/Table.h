
#ifndef TABLE_H
#define TABLE_H




#include <iostream>
#include <string>
#include <functional>


class Node;

typedef Node * ListType;

class Table {
 public:

   static const int HASH_SIZE = 9973;  // a prime number

   // create an empty table, i.e., one where numEntries() is 0
   Table();

   // create an empty table, i.e., one where numEntries() is 0
   // such that the underlying hash table is hSize
   Table(unsigned int hSize);

   // insert a new pair into the table
   // return false iff this key was already present 
   //         (and no change made to table)
   bool insert(const std::string &key, int value);

   // returns the address of the value that goes with this key
   // or NULL if key is not present.
   //   Thus, this method can be used to either lookup the value or
   //   update the value that goes with this key.
   int *lookup(const std::string &key);

   // remove a pair given its key
   // false iff key wasn't present
   bool remove(const std::string &key);

   // print out all the entries in the table, one per line.
   void printAll() const;

   int numEntries() const;      // number of entries in the table

   // hashStats: for diagnostic purposes only
   // prints out info to let us know if we're getting a good distribution
   // of values in the hash table.
   void hashStats(std::ostream &out) const;

 private:
   Table &operator =(const Table &);
   Table(const Table &);

   // hash function for a std::string
   unsigned int hashCode(const std::string &word) const {

      // Note: calls a std library hash function for string (it uses the good hash
      //   algorithm for strings that we discussed in lecture).
      return std::hash<std::string>()(word) % hashSize;
   }


   unsigned int hashSize;      // size of the hash table
   // (used in hashCode method above)
   
   ListType * data;       //The hash table

};

#endif

