#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
   string user_info;
   string first_word;
   string second_word;
   string third_word;
   char target = ',';
   int comma_index;
   int i;
   int index;
   bool end_inputs = false;
   

   
   while(!end_inputs){
      cout << "Enter input string:" << endl;
      
      getline(cin,user_info);
      istringstream inSS(user_info);
      inSS.clear();
      inSS >> first_word;

      if(first_word.at(0) == 'q'){
         end_inputs = true;
      }
      for(i = 0; i < first_word.length();++i){
         index = i;
      }
      
      if(first_word.at(index) == ','){
         cout << "First word: ";
         for(i = 0; i < index;++i){
            cout << first_word[i];
         }
         inSS >> second_word;
         cout << endl << "Second word: " << second_word << endl << endl;
         inSS.clear();
      }
      else if((first_word.at(index) != ',') && (first_word.at(0) != 'q') && !(first_word.find(target) < first_word.length())){
         inSS >> second_word;
         if (second_word.at(0) == ','){
            inSS >> third_word;
            cout << "First word: " << first_word << endl << "Second word: " << third_word << endl << endl;
         }
         else {
            cout << "Error: No comma in string." << endl << endl;
         }
         inSS.clear();
      }
      else if(first_word.find(target) < first_word.length()){
         cout << "First word: ";
         comma_index = first_word.find(target);
         for(i = 0; i < comma_index;++i){
            cout << first_word[i];
         }
         cout << endl << "Second word: ";
         for(i = comma_index + 1; i < first_word.length();++i){
            cout << first_word[i];
         }
         cout << endl << endl;
      }
      
   }
    
   return 0;
}