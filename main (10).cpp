
#include "cave.h"

int main()
{
   // Initialize game
   srandom(time(NULL));
int Croom = 0;
   // Initialize player
   Player player;
   player.setName("Spencer");
   player.setGold(0);
   player.setHealth(100);


   // Initialize cave
   Cave cave;
   cave.ReadRooms("rooms.txt");
   cave.ReadMap("map.txt");
   
   cave.WriteRooms("rooms.copy");

   while (player.getHealth() != 0 && player.getGold() < MAX_GOLD)
   {
cave.VisitRoom(Croom,player);
Croom = cave.NextRoom(Croom);
}
   

   // Print final message
   if (player.getHealth() == 0)
      cout << "\nSorry, you died exploring the cave." << endl;
   else
      cout << "\nYou leave the cave with " << MAX_GOLD << " gold coins!" << endl;
   return 0;
}