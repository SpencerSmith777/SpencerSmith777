#include "machineBST.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string Value, machine * Tree)
{
   // Data value not found 
   if (Tree == NULL)
   {
       cout << "Error: machine not found" << endl;
      return false;
   }

   // Data value found 
   else if (Tree->getTitle() == Value)
   {
       //cout << Tree->getTitle() << endl;
       //cout << "Value:" << Value << endl;
       Tree->print();
       return true;
   }
      

   // Recursively search for data value
   else if (Tree->getTitle() > Value)
      return (SearchHelper(Value, Tree->Left));
   else if (Tree->getTitle() < Value)
      return (SearchHelper(Value, Tree->Right));
      
    return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string title, string Maker, int Year, string type, machine * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new machine(title, Maker, Year, type);
      //Tree->Value = Value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->getTitle() == title)
   {
      return false; 
   }

   // Recursively search for insertion position
   else if (Tree->getTitle() > title)
      return (InsertHelper(title, Maker, Year, type, Tree->Left));
   else if (Tree->getTitle() < title)
      return (InsertHelper(title, Maker, Year, type, Tree->Right));
      
    return false;
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string title, string Maker, int Year, string type)
{
   // Call tree insertion function
   return (InsertHelper(title, Maker, Year, type, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(machine * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      Tree->print();

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}

void BinaryTree::Read()
{
        int i = 0;
    string title;
    string Maker;
    string sYear;
    int Year;
    string type;
    int ASCII;
    int total = 1;
    char x;
    int n = 0;
    
    ifstream din;
        din.open("machines_year.txt");
        
    while (!din.eof())
    {
total = 1;
        getline(din, title, ',');
        getline(din, Maker, ',');
        getline(din, sYear, ',');
        Year = stoi(sYear);
        getline(din, type, '\n');
        machine * temp = new machine(title, Maker, Year, type);
        for (i=0; i < title.length(); i++)
        {
            x = title.at(i);
            ASCII = int (i);
            if (ASCII!=0)
            {
            total = total*ASCII;
            }
            Insert(title, Maker, Year, type);
        }
        // machineByName.push_back(machine(title, Maker, Year, type));
        // machineByName[i].print();
        // i++;
        //  n++;
        // if(n%100 == 0)
        // {
         
        //  cout << title << " " << n << endl;
        // }
    }
}

bool BinaryTree::DeleteNode(machine * &Tree)
{
   machine *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      machine *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->setTitle(Temp->getTitle());
      Tree->Value = Temp->Value;
   }

   // Delete node
   cout << "machine deleted" << endl;
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string key, machine * &Tree)
{
   // Data value not found
   if (Tree == NULL)
   {
       cout << "error: machine not found" << endl;
      return false;
   }

   // Data value found and deleted
   else if (Tree->getTitle() == key)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->getTitle() > key)
      return (DeleteHelper(key, Tree->Left));
   else if (Tree->getTitle() < key)
      return (DeleteHelper(key, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string Value)
{
   // Call tree deletion function
   return (DeleteHelper(Value, Root));
}