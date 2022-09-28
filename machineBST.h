#include <iostream>
#include <fstream>
#include "machine.h"
using namespace std;

// Data node definition
// class Node
// {
//   public:
//   int Value;
//   Node *Left;
//   Node *Right;
// };

//-----------------------------------------------------------
// Define the binary tree class interface. 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string Value);
   bool Insert(string title, string Maker, int Year, string type);
   bool Delete(string Value);
   void Print();
   void Read();

 private:
   // Helper functions
   bool SearchHelper(string title, machine * Tree);
   bool InsertHelper(string title, string Maker, int Year, string type, machine * &Tree);
   bool DeleteNode(machine * &Tree);
   bool DeleteHelper(string Value, machine * &Tree);
   void PrintHelper(machine * Tree);

   // Tree pointer
   machine *Root;
};