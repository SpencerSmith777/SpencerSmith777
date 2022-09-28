#ifndef MACHINE_H
#define MACHINE_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class machine
{
public:
   // Constructor methods
   machine();
   machine(string game_title, string Maker, int Year, string Type);
   ~machine();
   
   void setTitle(string game_title);
   void setMaker(string Maker);
   void setYear(int Year);
   void setType(string Type);
   
   string getTitle();
   string getMaker();
   int getYear();
   string getType();

   void print();
   
machine * Left;
machine * Right;
int Value = 0;
private:
string gameTitle;
string maker;
int year;
string type;


};
#endif