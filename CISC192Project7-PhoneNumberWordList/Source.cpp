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
using namespace std;

class PhoneNumberNumerator
{
public:
	vector<char> numeratorList;

	void printAllWordsFromPhoneNumber(string phonenumber)
	{
		printAllWordsFromPrefixAndPhoneNumber("", phonenumber);
	}

	string getLettersForNumber(char digit)
	{
		string[] table = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
		bool valid = ((digit >= '0') && (digit <= '9'));
		return valid ? table[digit - '0'] : "";
	}

	void printAllWordsFromPrefixAndPhoneNumber(string prefix, string remaining)
	{
		if ((remaining == null) || (remaining.length() == 0))
		{
			cout << prefix;
		}
		else
		{
			char currentChar = remaining.at(0);
			if ((currentChar >= '2') && (currentChar <= '9'))
			{
				string chars_in_digit = getLettersForNumber(remaining.at(0));

				for (int i = 0; i < chars_in_digit.length(); i++)
				{
					string newprefix = prefix + chars_in_digit.at(i);
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
};

//method to write to file
int writeFile()
{
	ofstream phoneNumOutput;
	phoneNumOutput.open("phoneNumOutput.txt");
	phoneNumOutput << "Writing this to a file.\n";
	phoneNumOutput << "Writing this to a file.\n";
	phoneNumOutput << "Writing this to a file.\n";
	phoneNumOutput << "Writing this to a file.\n";
	phoneNumOutput.close();
	return 0;
}

//another method to write to file
int writeToFile()
{
	ofstream myfile("phoneNumOutput.txt");

	if (myfile.is_open())
	{
		string str;
		do {
			getline(cin, str);
			myfile << str << endl;
		} while (str != "");
		myfile.close();
	}
	else cerr << "Unable to open file";

	return 0;
}


int main()
{
	char choice = 'y';
	string phoneGiven;
	vector<char> phoneNum = {};
	int i = 0;
	vector<string> wordList = {};


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

		//copy contents of string to vector
		vector<char> phoneNum(phoneGiven.begin(), phoneGiven.end());



		//print through each word in vector list after our function is performed
		for (vector<string>::const_iterator i = wordList.begin(); i != wordList.end(); i++)
			cout << *i << " ";


		//print line showing how many words were found for the given number
		cout << "For phone number " << phoneGiven << " there are " << wordList.size() << " possible words." << endl;

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