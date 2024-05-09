#include <iostream>
#include <vector>
using namespace std;

void sortVector(vector<int>& numbers){
   int i;
   int j;
   for(i = 0; i < numbers.size() - 1;++i) {
      for(j = 0; j < numbers.size() - i - 1;++j){
         if(numbers[j] > numbers[j + 1]){
            int swap_temp = numbers[j];
            numbers[j] = numbers[j + 1];
            numbers[j + 1] = swap_temp;
         }
      }
   }
}

int main() {
   int amount_of_numbers;
   int i;
   cin >> amount_of_numbers;
   
   vector<int> sort_numbers(amount_of_numbers);
   
   for(i = 0; i < amount_of_numbers;++i){
      cin >> sort_numbers[i];
   }
   sortVector(sort_numbers);
   
   for(i = 0; i < amount_of_numbers;++i){
      cout << sort_numbers[i] << " ";
   }
   cout << endl;
   

   return 0;
}
