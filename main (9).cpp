/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "machineBST.h"
using namespace std;

vector<machine> machineByYear;
vector<machine> machineByName;


void readByYear()
{
    int i = 0;
    string title;
    string Maker;
    string sYear;
    int Year;
    string type;
    
    ifstream din;
        din.open("machines_year.txt");
        
    while (!din.eof())
    {

        getline(din, title, ',');
        getline(din, Maker, ',');
        getline(din, sYear, ',');
        Year = stoi(sYear);
        getline(din, type, '\n');
        machineByYear.push_back(machine(title, Maker, Year, type));
        //machineByYear[i].print();
        //cout << endl << i << endl;
        i++;
    }
        
}

int main()
{
    //readByYear();
    BinaryTree tree;
    char x;
    string exa = "";

int year = 0;
string title = " ";
string maker = " ";
string type = " ";
bool b;

char choice = '0';
string choiceS = " ";
//writeAddress();
while (choice != '6')
  {
  cout << "Please select what you would like to do:" << endl;
  cout << "1: Read in the text file of machines to initialize the program" << endl;
  cout << "2: Search the tree for machines by title" << endl;
  cout << "3: Delete a machine from the tree by title" << endl;
  cout << "4: Enter 4 pieces of information in order to insert a new machine into the tree" << endl;
  cout << "5: Print the contents of the tree in order" << endl;
  cout << "6: End the program" << endl;
  cin >> choice;
  getline(cin, choiceS);
  switch (choice)
  {
      case '1':
      tree.Read();
      
      break;
       
      case '2':
      cout << "Please input name of machine that you would like to search for." << endl;
      cin >> ws;
      getline(cin, exa);
      tree.Search(exa);
      break;
      
      case '3':
      cout << "Please input name of machine to delete from tree" << endl;
      cin >> ws;
      getline(cin, exa);
      tree.Delete(exa);
      break;
      
      case '4':
      cout << "Please input machine name" << endl;
      cin >> ws;
      getline(cin, title);
      cout << "Please input maker" << endl;
      cin >> ws;
      getline(cin, maker);
      cout << "Please input year of release" << endl;
      cin >> year;
      cout << "Please input type of machine" << endl;
      cin >> ws;
      getline(cin, type);
      b = tree.Insert(title, maker, year, type);
      if (b==0)
      {
        cout << "error, machine of that name already exists" << endl;
      }
      break;

      case '5':
      cout << endl;
      tree.Print();
      cout << endl;
      break;
      case '6':
      cout << endl << "ending program" << endl;
      break;
      default:
      cout << "invalid input" << endl; 
  }
  }
return 0; 
    

    return 0;
}
