//this program prints to the console as well as writes to a text file all possible
//word combinations from a given 7 digit phone number.

#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <ctime>
#include <fstream>
#include <array>
#include <iterator>
#include <list>
using namespace std;

class PhoneNumberNumerator
{
private:
	vector<string> numeratorList;

public:


	void printAllWordsFromPhoneNumber(string phonenumber)
	{
		printAllWordsFromPrefixAndPhoneNumber("", phonenumber);
	}

	string getLettersForNumber(char digit)
	{
		vector<string> table = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
		bool valid = ((digit >= '0') && (digit <= '9'));
		return valid ? table[digit - '0'] : table[1];
	}

	void printAllWordsFromPrefixAndPhoneNumber(string prefix, string remaining)
	{
		if ((remaining == "") || (remaining.length() == 0))
		{
			numeratorList.push_back(prefix);
		}
		else
		{
			char currentChar = remaining.at(0);
			if ((currentChar >= '2') && (currentChar <= '9'))
			{
				string chars_in_digit = getLettersForNumber(remaining.at(0));

				for (int i = 0; i < chars_in_digit.length(); i++)
				{
					string newprefix = " " + prefix + chars_in_digit.at(i);
					string newremaining = remaining.substr(1);
					printAllWordsFromPrefixAndPhoneNumber(newprefix, newremaining);
				}
			}
			else
			{
				string newprefix = prefix + currentChar;
				string newremaining = remaining.substr(1);
				printAllWordsFromPrefixAndPhoneNumber(newprefix, newremaining);
			}
		}
	}

	int writeFile(string phonenum)
	{
		ofstream phoneNumOutput;
		phoneNumOutput.open("phoneNumOutput.txt");
		for (int i = 0; i < numeratorList.size(); i++)
		{

			if (i % 4 == 0) {
				phoneNumOutput << "\n";
			}
			if (i < 10)
			{
				phoneNumOutput << (i + 1) << ".  " << numeratorList[i] << " ";
			}
			else
			{
				phoneNumOutput << (i + 1) << ". " << numeratorList[i] << " ";
			}

		}
		if (numeratorList.size() == 1) {
			phoneNumOutput << "\n\nFor phone number " << phonenum << " there is " << numeratorList.size() << " possible word." << endl;
		}
		else {
			phoneNumOutput << "\n\nFor phone number " << phonenum << " there are " << numeratorList.size() << " possible words." << endl;
		}
		phoneNumOutput.close();
		return 0;
	}

	void printList(string phonenum)
	{
		for (int i = 0; i < numeratorList.size(); i++)
		{

			if (i % 4 == 0) {
				cout << "\n";
			}

			if (i < 10)
			{
				cout << (i + 1) << "." << numeratorList[i] << " ";
			}
			else
			{
				cout << " " << "\b\b" << (i + 1) << "." << numeratorList[i] << "  ";
			}



		}


		if (numeratorList.size() == 1)
			cout << "\n\nFor phone number " << phonenum << " there is " << numeratorList.size() << " possible word." << endl;
		else
			cout << "\n\nFor phone number " << phonenum << " there are " << numeratorList.size() << " possible words." << endl;

	}


};



//main function that implements the class
int main()
{
	char choice = 'y';
	string phoneGiven;
	string wordList;


	do
	{
		//ask for the phone number
		cout << "Please enter a 7 digit phone number: ";
		cin >> phoneGiven;
		//check to see if given line is 7 digits
		if (phoneGiven.length() != 7)
		{
			cout << "Incorrect length, phone number must be 7 digits.\n\n" << endl;
			return main();
		}

		PhoneNumberNumerator numerator1;
		numerator1.printAllWordsFromPrefixAndPhoneNumber(wordList, phoneGiven);
		numerator1.writeFile(phoneGiven);
		numerator1.printList(phoneGiven);


		//see if the user wants to continue and continue if desired
		cout << "\n\nWould you like to check another phone number? (Y/N): ";
		cin >> choice;
		cout << endl;

	} while (choice == 'y' || choice == 'Y');

	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;
	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}