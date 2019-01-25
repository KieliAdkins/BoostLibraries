/*
Kieli Adkins
11/1/2018
Boost Libraries 
Implementing 5 or more different types of boost libraries. 
*/

// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

// Including boost libraries
#include <boost/foreach.hpp>
#include <boost/array.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/algorithm/string.hpp>

// Using namespaces
using namespace std; 
using namespace boost::lambda;
using namespace boost;

// Declaring the variables
string username;
string lastname; 
const int MAX_NUM = 3;
vector<char> password;
int userNumber = 0;
int month = 0; 
int day = 0; 
int year = 0; 


// Calling functions
void numbers();
void user(); 
void date(); 
int multiplier(); 
const int MAX_WORDS = 1024; 

// Main function
void main()
{
	// Calling the functions
	user(); 

	date(); 

	numbers(); 

	multiplier(); 

	// Printing the name
	for (unsigned int i = 0; i < password.size(); i++)
	{
		cout << password[i];
	}

	cout << endl; 

	/*
	Using the boost format library to print out the date in an easily-understandable format
	*/
	cout << "The current date is " << boost::format{ "%1%.%2%.%3%" } % month % day % year << '\n';

	system("pause");
}

/// User function
void user()
{
	// Printing the information
	cout << "Please enter your first name: " << endl;
	cin >> username;

	/*
	Using the string algorithm library to make the string uppercase 
	*/
	to_upper(username); 

	/*
	Using the boost for_each function to dissect a string into individual characters
	*/
	BOOST_FOREACH(char ch, username)
	{
		password.push_back(ch); 
	}
	
	cout << "Please enter your last name: " << endl; 
	cin >> lastname; 

	/*
	Using the string algorithm library to make the string uppercase
	*/
	to_upper(lastname);

	/*
	Using the boost for_each function to dissect a string into individual characters
	*/
	BOOST_FOREACH(char ch, lastname)
	{
		password.push_back(ch);
	}

}

/// Date function
void date()
{
	// Entering the information
	cout << endl << endl << "Enter the month in numerical form: " << endl;
	cin >> month;

	cout << "Enter the day in numerical form: " << endl;
	cin >> day;

	cout << "Enter the year in numerical form: " << endl;
	cin >> year;
}

/// Multiplier function
int multiplier()
{
	/*
	Using the boost random generator to generate a random number
	*/
	boost::random::mt19937 rng;
	boost::random::uniform_int_distribution<> dist(1, 10);
	return dist(rng);
}


/// Numbers function
void numbers()
{
	/*
	Using the boost.array library to creat an array with a constant size
	*/
	int numberEntry[MAX_NUM];

	// Asking user for numbers
	cout << endl << endl << "Please enter three numbers: " << endl; 
	cout << "-";
	cin >> numberEntry[0];
	cout << "-";
	cin >> numberEntry[1];
	cout << "-";
	cin >> numberEntry[2];

	// Printing the numbers
	cout << endl << "Your numbers are: " << endl;
	for (int i = 0; i < MAX_NUM; i++)
	{
		cout << numberEntry[i] << endl;
	}

	// Getting the random number to multiply by 
	int randomResult = multiplier();
	cout << endl; 

	/*
	Using the boost for_each function to multiply each user-entered number by the random number
	*/
	BOOST_FOREACH (int i, numberEntry)
	{
		cout << i << " x " << randomResult << " = " << (i * randomResult) << " " << endl; 
	}
	cout << endl << endl;

	return; 
}

