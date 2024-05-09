#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct soccerPlayers {
   string first_name;
   string last_name;
   int jersey_number;
   int player_rating;
};
void menu_options() {
   cout << "MENU" << endl << "a - Add player" << endl << "d - Remove player" << endl;
   cout << "u - Update player rating" << endl << "o - Output roster" << endl << "q - Quit" << endl << endl;
   cout << "Choose an option: " << endl;
   cout << endl;
}
void addPlayer(vector<soccerPlayers>& Roster){
   soccerPlayers Player;
   cout << "Enter the new player's data" << endl << "first name:" << endl;
   cin >> Player.first_name;
   cout << "last name:" << endl;
   cin >> Player.last_name;
   cout << "jersey number:" << endl;
   cin >> Player.jersey_number;
   cout << "rating:" << endl;
   cin >> Player.player_rating;
   cout << endl;
   Roster.push_back(Player);
   
}
void outputRoster(const vector<soccerPlayers>& Roster){
   int i;
   cout << "ROSTER" << endl;
   for(i = 0; i < Roster.size();++i){
      cout << "Player " << i + 1 << " -- " << Roster[i].first_name << " " << Roster[i].last_name << ", jersey number ";
      cout << Roster[i].jersey_number << ", rating " << Roster[i].player_rating << endl;
   }
   cout << endl;
}
void updatePlayerRating(vector<soccerPlayers>& Roster){
   soccerPlayers Player;
   int i;
   int player_number;
   int new_rating;
   cout << "Enter a jersey number:" << endl;
   cin >> player_number;

   for(i = 0; i < Roster.size();++i){ 
      if(player_number == Roster[i].jersey_number){
         cout << "Enter a new rating for player:" << endl;
         cin >> new_rating;
         Roster[i].player_rating = new_rating;
         cout << endl;
      }
   }
}
void deletePlayer(vector<soccerPlayers>& Roster){
   soccerPlayers Player;
   int i;
   int player_number;
   int index_to_delete;
   cout << "Enter a jersey number:" << endl;
   cin >> player_number;
   
   for(i = 0; i < Roster.size();++i){
      if(player_number == Roster[i].jersey_number){
         index_to_delete = i;
      }
   }
   for(i = index_to_delete + 1; i < Roster.size();++i){
      Roster[i - 1] = Roster[i];
   }
   Roster.pop_back();
   cout << endl;
}

int main() {
   vector<soccerPlayers> Roster;
   char menu_option;
   
   while(cin >> menu_option){
      menu_options();
      if(menu_option == 'a'){
         addPlayer(Roster);
      }
      else if(menu_option == 'd'){
         deletePlayer(Roster);
      }
      else if(menu_option == 'u'){
         updatePlayerRating(Roster);
      }
      else if(menu_option == 'o'){
         outputRoster(Roster);
      }
      else if(menu_option == 'q'){
         return 1;
      }
      else {
         menu_options();
      }
      
   }
      

   return 0;
}