#include "machine.h"

machine :: machine()
{
    
}


machine :: machine(string game_title, string Maker, int Year, string Type)
{
    gameTitle = game_title;
    maker = Maker;
    year = Year;
    type = Type;
}

machine :: ~machine()
{
    
}

void machine :: setTitle(string game_title)
{
   gameTitle = game_title; 
}

void machine :: setMaker(string Maker)
{
   maker = Maker; 
}

void machine :: setYear(int Year)
{
   year = Year; 
}

void machine :: setType(string Type)
{
   type = Type;  
}


string machine :: getTitle()
{
    return gameTitle;
}

string machine :: getMaker()
{
    return maker;
}

int machine :: getYear()
{
    return year;
}

string machine :: getType()
{
    return type;
}

void machine :: print()
{
    cout << "======================================" << endl;
    cout << "Title: " << gameTitle << endl;
    cout << "Manufacturer: " << maker << endl;
    cout << "Year: " << year << endl;
    cout << "Type: " << type << endl;
    cout << "======================================" << endl;
}