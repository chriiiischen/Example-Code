#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;
void printHelp();
int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);
   bool isEnd = false;
   
   while(!isEnd){
      string command;
      cout << "cmd>";
      cin >> command;
      
      if (command == "insert"){
         string name;
         int score;
         cin >> name >> score;
         if((grades->insert(name, score))==false){
            cout << "This name was already present." << endl;
         }
         
      }else if (command == "change"){
         string name;
         int score;
         cin >> name >> score;
         int *p = grades->lookup(name);
         if(p == NULL){
            cout << "This name is not present." << endl;
         }else{
            *p = score;
         }
         
      }else if (command == "lookup"){
         string name;
         cin >> name;
         int *p = grades->lookup(name);
         if(p == NULL){
            cout << "This name is not present." << endl;
         }else{
            cout << *p << endl;
         }
         
      }else if (command == "remove"){
         string name;
         cin >> name;
         if((grades->remove(name)) == false){
            cout << "This name is not present." << endl;
         }
         
      }else if (command == "print"){
         grades->printAll();
         
      }else if (command == "size"){
         cout << grades->numEntries() << endl;
         
      }else if (command == "stats"){
         grades->hashStats(cout);
         
      }else if (command == "help"){
         printHelp();
      }else if (command == "quit"){
         isEnd = true;
         
      }else{
         cout << "ERROR: invalid command" << endl;
         
      }
         
      
      
      
   }

   return 0;
}

//Print the help summary
void printHelp(){
         cout << "insert name score" << endl;
         cout << "   Insert this name and score in the grade table." << endl;
         cout << endl;
         cout << "change name newscore" << endl;
         cout << "   Change the score for name." << endl;
         cout << endl;
         cout << "lookup name" << endl;
         cout << "   Lookup the name, and print out his or her score." << endl;
         cout << endl;
         cout << "remove name" << endl;
         cout << "   Remove this student." << endl;
         cout << endl;
         cout << "print" <<endl;
         cout << "   Prints out all names and scores in the table." << endl;
         cout << endl;
         cout << "size" << endl;
         cout << "   Prints out the number of entries in the table."<< endl;  
         cout << endl;
         cout << "stats" << endl;
         cout << "   Prints out statistics about the hash table at this point."<< endl;
         cout << endl;
         cout << "help"<< endl;
         cout << "   Prints this summary."<< endl;
         cout << endl;
         cout << "quit"<< endl;
         cout << "   Exits the program."<< endl;
   
}