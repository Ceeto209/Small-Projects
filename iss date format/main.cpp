#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int convertMonthToNumber(string month) {
	int month_number = 0;
	
	if (month == "January")
		month_number = 1;
	else if (month == "February")
		month_number = 2;
	else if (month == "March")
		month_number = 3;
	else if (month == "April")
		month_number = 4;
	else if (month == "May")
		month_number = 5;
	else if (month == "June")
		month_number = 6;
	else if (month == "July")
		month_number = 7;
	else if (month == "August")
		month_number = 8;
	else if (month == "September")
		month_number = 9;
	else if (month == "October")
		month_number = 10;
	else if (month == "November")
		month_number = 11;
	else if (month == "December")
		month_number = 12;
		
	return month_number;
}

int main () {
   string full_date;
   string month;
	string day_of_month;
	string year;
	char target = ',';
	int i;
	int index;
	
	while(cin >> month && month != "-1"){
	   getline(cin,full_date);

	   istringstream gather_date_info_instringstream(full_date);
	   gather_date_info_instringstream.clear();
	   
	   gather_date_info_instringstream >> day_of_month;
	   gather_date_info_instringstream >> year;
	   
	   for(i = 0; i < day_of_month.length();++i){
	      index = i;
	   }
	   
	   if(day_of_month[index] == ','){
	      cout << convertMonthToNumber(month) << "/" << day_of_month.substr(0,index) << "/" << year << endl;
	   }
	   else{
	      gather_date_info_instringstream.clear();
	   }
	}
	return 0;
}
