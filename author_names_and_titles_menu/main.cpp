/*************************************************************************
  predefined classes, functions, structures
*************************************************************************/
#include <iostream>// cin, cout
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*************************************************************************
  global formatting constants
*************************************************************************/
const unsigned int AUTHOR_COLUMN_WIDTH = 25;
const unsigned int TITLE_COUNT_COLUMN_WIDTH = 18;

/*************************************************************************
  function prototypes
*************************************************************************/
void showMenu();
void displayFirstFileLine(const string file_name);
void displayFirstAuthorName(const string file_name);
void displayFirstAuthorInformation(const string file_name);
void displayAllAuthorInformation(const string file_name);
void displayFormattedTableNoAverage(const string file_name);
void displayEntireFormattedTable(const string file_name);

/*************************************************************************
  main() definition
*************************************************************************/


/*************************************************************************
  main() definition
*************************************************************************/
int main()
{	
	// loop through menu
	unsigned int user_choice;
	const string FILE_NAME = "author_titles_data.txt";
	
	// get first user choice
	showMenu();
	
	cout << "Enter your choice [1 to 7]: ";
	cin >> user_choice;
	while (user_choice < 7)
	{
		cout << endl;
		
		switch (user_choice)
		{
			case 1:
				displayFirstFileLine(FILE_NAME);
				break;
			case 2:
				displayFirstAuthorName(FILE_NAME);
				break;
			case 3:
				displayFirstAuthorInformation(FILE_NAME);
				break;
			case 4:
				displayAllAuthorInformation(FILE_NAME);
				break;
			case 5:
				displayFormattedTableNoAverage(FILE_NAME);
				break;
			case 6:
				displayEntireFormattedTable(FILE_NAME);
				break;
			default:
				// nothing
				break;
		}
		
	  cout << endl;

	  // get next user choice
	  showMenu();
	  cout << "Enter your choice [1 to 7]: ";
	  cin >> user_choice;
	}
	
	cout << endl;
	
	return 0;
}

/*************************************************************************
  function definitions
*************************************************************************/
void showMenu()
{
	cout << "Choose an option:" << endl
			 << "1) display the first file line unformatted to screen" << endl
			 << "2) display the first author name to screen" << endl
			 << "3) display the first author name, 3 spaces, title count to screen" << endl
			 << "4) display all authors name, 3 spaces, title count to screen" << endl
			 << "5) display formatted table of authors no average" << endl
			 << "6) option 5 plus the formatted average titles per author" << endl
			 << "7) quit" << endl
			 << endl;
			 
  return;		 
}

//*************************************************************************

void displayFirstAuthorName(const string file_name)
{
   ifstream authors_data;
   string full_name_and_titles;
	authors_data.open(file_name);
	getline(authors_data,full_name_and_titles);
	
	
	for(int i = 0; i < full_name_and_titles.length();++i){
	  if(full_name_and_titles.at(i) == ';'){
	      cout << endl;
	      authors_data.close();
	      return;
	  }
	  else {
	     cout << full_name_and_titles[i];
	  }
	}
	cout << endl;
	authors_data.close();
	return;
}

//*************************************************************************

void displayFirstFileLine(const string file_name)
{
   ifstream authors_data;
   string full_name_and_titles;
	authors_data.open(file_name);
	getline(authors_data,full_name_and_titles);
	cout << full_name_and_titles << endl;
	authors_data.close();
	return;
}

//*************************************************************************

void displayFirstAuthorInformation(const string file_name)
{
   ifstream authors_data;
   string full_name_and_titles;
	authors_data.open(file_name);
	getline(authors_data,full_name_and_titles);
	
	for(int i = 0; i < full_name_and_titles.length();++i){
	   if(full_name_and_titles.at(i) == ';'){
	      cout << "  ";
	   }
	   else {
	      cout << full_name_and_titles[i];
	   }
	}
	cout << endl;
	authors_data.close();
	return;
}

//*************************************************************************

void displayAllAuthorInformation(const string file_name)
{
	ifstream authors_data;
   string full_name_and_titles;
	authors_data.open(file_name);

	
	while(!authors_data.eof()){
	   getline(authors_data,full_name_and_titles);
	   istringstream full_line(full_name_and_titles);
	   string author;
	   int number_of_titles;
	   getline(full_line, author,';');
	   full_line >> number_of_titles;
	   
	   cout << author << "   " << number_of_titles << endl;
	}
	
	authors_data.close();	
	return;
}

//*************************************************************************

void displayFormattedTableNoAverage(const string file_name)
{
   cout << "Number of Novels Authored" << endl << endl;
   cout << setfill(' ');
   cout << setw(AUTHOR_COLUMN_WIDTH) << left << "Author Name" << "|";
   cout << setw(TITLE_COUNT_COLUMN_WIDTH) << right << "Number Of Titles" << endl;
   cout << setfill('-') << setw(AUTHOR_COLUMN_WIDTH + TITLE_COUNT_COLUMN_WIDTH + 1) << "" << endl;
   
   ifstream authors_data;
   string full_name_and_titles;
	authors_data.open(file_name);

	
	while(!authors_data.eof()){
	   getline(authors_data,full_name_and_titles);
	   istringstream full_line(full_name_and_titles);
	   string author;
	   int number_of_titles;
	   getline(full_line, author,';');
	   full_line >> number_of_titles;
	   
	   cout << setfill(' ');
	   cout << setw(AUTHOR_COLUMN_WIDTH) << left << author << "|";
	   cout << setw(TITLE_COUNT_COLUMN_WIDTH) << right << number_of_titles << endl;
	}
	
	return;
}

//*************************************************************************

void displayEntireFormattedTable(const string file_name)
{
   cout << "Number of Novels Authored" << endl << endl;
   cout << setfill(' ');
   cout << setw(AUTHOR_COLUMN_WIDTH) << left << "Author Name" << "|";
   cout << setw(TITLE_COUNT_COLUMN_WIDTH) << right << "Number Of Titles" << endl;
   cout << setfill('-') << setw(AUTHOR_COLUMN_WIDTH + TITLE_COUNT_COLUMN_WIDTH + 1) << "" << endl;
   
   ifstream authors_data;
   string full_name_and_titles;
	authors_data.open(file_name);
	int number_of_authors = 0;
	int sum_of_all_titles = 0;
	int average_titles;

	
	while(!authors_data.eof()){
	   getline(authors_data,full_name_and_titles);
	   istringstream full_line(full_name_and_titles);
	   string author;
	   int number_of_titles;
	   getline(full_line, author,';');
	   full_line >> number_of_titles;
	   
	   cout << setfill(' ');
	   cout << setw(AUTHOR_COLUMN_WIDTH) << left << author << "|";
	   cout << setw(TITLE_COUNT_COLUMN_WIDTH) << right << number_of_titles << endl;
	   
	   number_of_authors++;
	   sum_of_all_titles += number_of_titles;
	}
	average_titles = ((double)sum_of_all_titles / number_of_authors);
	cout << setfill(' ');
	cout << setw(AUTHOR_COLUMN_WIDTH) << left << "" << "|";
	cout << setw(TITLE_COUNT_COLUMN_WIDTH) << endl;
	cout << setw(AUTHOR_COLUMN_WIDTH) << left << "Average titles" << "|";
	cout << setw(TITLE_COUNT_COLUMN_WIDTH) << right << average_titles << endl;
	
	return;
}