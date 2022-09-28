
#include "cave.h"

// Remove all white space from start and end of string
string trim(const string str)
{
   unsigned int start = 0;
   unsigned int end = str.length()-1;
   while ((start < str.length()) && (isspace(str[start]))) start++;
   while ((end > start) && (isspace(str[end]))) end--;
   return str.substr(start, (end-start+1));
}

Cave::Cave()
{
   count = 12;
}

Cave::~Cave()
{
}

int Cave::GetCount()
{
   return count;
}

bool Cave::ReadRooms(const string filename)
{
ifstream infile;
   infile.open(filename.c_str());
   if (infile.fail())
      return false;

   for (int i = 0; i < 12; i++)
   {
       int treasure;
       string name;
       string description;
       string creature;
       string item;
       string food;
       
     getline(infile,name,'\n');
     rooms[i].SetName(name);
     infile >> treasure;
     rooms[i].SetTreasure(treasure);
     infile >> creature;
     rooms[i].SetCreature(creature);
     infile >> food;
     rooms[i].SetFood(food);
     infile >> item;
     rooms[i].SetItem(item);
     getline(infile,description,'#');
     rooms[i].SetDescription(description);
     getline(infile,name,'\n');
     
//     Room[i].setGold(treasure);
   }
      
   infile.close();
   return true;
}

bool Cave::WriteRooms(const string filename)
{
   ofstream outfile;
   outfile.open(filename.c_str());
   if (outfile.fail())
      return false;

   for (int i = 0; i < 12; i++)
   {
      outfile << rooms[i].GetName() << endl;
      outfile << rooms[i].GetTreasure() << endl;
      outfile << rooms[i].GetCreature() << endl;
      outfile << rooms[i].GetFood() << endl;
      outfile << rooms[i].GetItem();
      outfile << rooms[i].GetDescription() << "#" << endl;
   }
   outfile.close();
   return true;
}

bool Cave::ReadMap(const string filename)
{
   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail()) 
      return false;

   // Read map information
   for (int room = 0; room < count; room++)
      for (int dir = 0; dir < MAX_DIRS; dir++)
         din >> map[room][dir];

   // Close input file
   din.close();
   return true;
}

bool Cave::WriteMap(const string filename)
{
   // Open output file
   ofstream dout;
   dout.open(filename.c_str());
   if (dout.fail()) 
      return false;

   // Write map information
   for (int room = 0; room < count; room++)
   {
      for (int dir = 0; dir < MAX_DIRS; dir++)
         dout << map[room][dir] << " ";
      dout << endl;
   }

   // Close output file
   dout.close();
   return true;
}

int Cave::VisitRoom(const int room, Player & player)
{
cout << rooms[room].GetDescription();

   player.setGold(player.getGold() + rooms[room].FindTreasure());
   player.setHealth (player.getHealth() - rooms[room].FightCreature());
   player.setHealth (player.getHealth () + rooms[room].EatFood ());
   player.addItem (rooms[room].PickupItem ());
   player.Print();
   
   return 0;
}

int Cave::NextRoom(const int room)
{
   // Error checking
   if (room < 0 || room >= count)
      return 0;

   // Prompt the user for direction
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W'))
   {
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }

   // Return next room number
   int next = room;
   switch (direction)
   {
      case 'N': next = map[room][0]; break;
      case 'S': next = map[room][1]; break;
      case 'E': next = map[room][2]; break;
      case 'W': next = map[room][3]; break;
   }
   return next;
}