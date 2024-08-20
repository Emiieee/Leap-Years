/*
Inefficient program that I made to help a friend understand programming. They use a different environment where
a lot of functions and libraries that are built in to c++ are not available. It could be created much better.

------------------------------------
This program takes a starting year and an ending year and finds out how many leap years are in between and
how many days should be added to the total.
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//------------------------------------------- Function prototypes ---------------------------------------------
int findLeaps(int startYear, int endYear);	//Function for finding the amount of leap years
int findDays(int years, int days);	//Function for finding the amount of days to add

int main()
{
	//Variables
	int startYear,	//This is the variable for the starting year
		endYear;	//This is the variable for the ending year
	int days = 0;	//This will hold the days.
	int years = 0;	//This will hold the amount of years that are leap years

	//-----------------------------------------	Prompt for input ----------------------------------------------
	// This could be done in its own function, but this program is simple and short so I am leaving it here
	//Prompt for first year
	cout << "Enter the first year: ";
	cin >> startYear;
	//Prompt for second year
	cout << "Enter the second year: ";
	cin >> endYear;

	//-------------------------------------------- Calculate ---------------------------------------------------
	//Call findLeaps function to find the amount of years that were leap years
	years = findLeaps(startYear, endYear);
	//Call findDays function to find the amount of days to add to the total years
	days = findDays(years, days);

	//---------------------------------------------	Output -----------------------------------------------------
	cout << "Extra days to add to total is: " << years << endl;
	cout << "The total amount of days is: " << days << endl;

	//END
	return 0;
};

int findLeaps(int startYear, int endYear)
{
	//Variables
	int years = 0;	//Variable that will hold the total amount of years that are considered leap years
	int yearDifference = endYear - startYear;	//Subtract for how many years are between the start and end date
	vector<int> allYears;	//This will hold the years that occurred between both dates

	//Append the years to the vector until the iterator is equal to the yearDifference
	for (int i = 0; i <= yearDifference; i++)
	{
		allYears.push_back(startYear + i);	//add to the start year the iterator to get the current year
	};

	//For each value in each index in the vector, use the formula to find if it is a leap year
	for (int i = 0; i < allYears.size(); i++)
	{
		//Check to see if the current year is a leap year
		if ((allYears[i] % 400 == 0 || allYears[i] % 100 != 0) && allYears[i] % 4 == 0)
		{
			//If the year is a leap year, add a year to the year variable
			years = years + 1;
		};
	};

	//Return the amount of leap years to where the function was called
	return years;
};

int findDays(int years, int days)
{
	//Ideally, days would not be 0 as this would be used in a different program.
	//Variables
	int daysTotal;	//Will hold total of days and years with extra days

	//Combine days and years to have the total of days with included extra days from leap year
	daysTotal = years + days;

	//return the total to where the function was called
	return daysTotal;
}