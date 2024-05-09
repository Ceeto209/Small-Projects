#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getFrequencyOfWord(vector<string> words, string current_word){
   vector<string> names = words;
   vector<int> frequencies;
   int counter = 1;
   int i;
   int j;
   
   for(i = 0; i < names.size() - 1;++i){
      if (names[i] == current_word){
         counter++;
      }
      else {
         counter = 1;
      }
   }
   
   return counter;
}


int main() {
   int i;
   int number_of_words;
   string current_word;
   

   
   cin >> number_of_words;
   vector<string> names(number_of_words);
   vector<int> frequencies(number_of_words);
   
   for (i = 0; i < number_of_words;++i){
      cin >> names[i];
   }

   
   for(i = 0; i < number_of_words;++i){
      current_word = names[i];
      frequencies[i] = getFrequencyOfWord(names, current_word);
      cout << names[i] << " " << frequencies[i] << endl;
   }
   
   

   return 0;
}
