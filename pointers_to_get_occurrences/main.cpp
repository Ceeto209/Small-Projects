#include <iostream>

// missing header files
// may not include <cstring> in your answer. So none of the functions in this header file may be used
// in your answer.
using namespace std;

char* findLastOccurrence(char* input_characters, char search_character){
   char* last_occurrence = nullptr;
   char* check_characters = input_characters;
   
   while(*check_characters != '\0'){
      if(*check_characters == search_character){
         last_occurrence = check_characters;
      }
      check_characters++;
   }
   return last_occurrence;    
}

int main()
{
	// use these constants in your display of the final results
	const char DOUBLE_QUOTES = '"';
	const char SINGLE_QUOTE = '\'';
	
	const int max_input_size = 51;
   char* input_characters = nullptr;
	char search_character;
	input_characters = new char[max_input_size];
	
	cout << "Enter a string [up to 50 characters]:" << endl << endl;
	cin.getline(input_characters, max_input_size);
	
	cout << "Enter a character to find:" << endl << endl << endl;
	cin >> search_character;
	
   char* last_occurrence = findLastOccurrence(input_characters, search_character);
   
   if(last_occurrence != nullptr){
      cout << "The last occurrence of " << SINGLE_QUOTE << search_character  << SINGLE_QUOTE;
      cout << " begins the substring of " << DOUBLE_QUOTES << last_occurrence << DOUBLE_QUOTES << endl;
   }
   
   // destroy the dynamic C-string to avoid memory leaks
   delete [] input_characters;
   input_characters = nullptr;
   
	return 0;
}