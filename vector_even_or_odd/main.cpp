#include <iostream>
#include <vector>
using namespace std;

bool isVectorAllEven(const vector<int>& list_of_integers){
   int i;
   for(i = 0; i < list_of_integers.size();++i){
      if (list_of_integers[i] % 2 != 0) {
         return false;
      }
   }
   return true;
}
bool isVectorAllOdd(const vector<int>& list_of_integers){
   int i;
   for(i = 0; i < list_of_integers.size();++i){
      if (list_of_integers[i] % 2 == 0){
         return false;
      }
   }
   return true;
}

int main() {
   int amount_of_numbers;
   int i;
   
   cin >> amount_of_numbers;
   
   vector<int> list_of_numbers(amount_of_numbers);
   
   for (i = 0; i < amount_of_numbers;++i){
      cin >> list_of_numbers[i];
   }
   
   if(isVectorAllEven(list_of_numbers)) {
      cout << "all even" << endl;
   }
   else if (isVectorAllOdd(list_of_numbers)){
      cout << "all odd" << endl;
   }
   else {
      cout << "not even or odd" << endl;
   }

   return 0;
}
