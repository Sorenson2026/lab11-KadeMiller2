//Kade Miller 3/31/26 Lab 11
/*This program asks for a file name and reads numbers and stores the numbers in an array */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//declare functions
int readFile(int array[]);
void analyzeArray(int array[], int i); 

//create named constant for array size
const int SIZE = 100;

int main()
{
	int numbers[SIZE], size;

	//call readFile to input numbers from file and put into numbers[], and also store size of array to use in next function call
	size = readFile(numbers);

	//call analyzeArray
	analyzeArray(numbers, size);

	return 0;
}


//This function reads numbers from a file input by a user and stores them in an array
int readFile(int array[])
{
	//create variables
	ifstream inFile;
	string fileName;
	int count = 0, num;

	//Ask user to input file name
	cout << "Enter file name followed by file type (.txt most likely): ";
	cin >> fileName;

	//open file
	inFile.open(fileName);

	//create loop to read numbers from file
	while (inFile >> num)
	{
		//break the loop if count gets to one less than SIZE
		if (count >= (SIZE - 1))
			break;

		//input number being read from file into array
		array[count] = num;

		//increment count
		count++;
	}

	//close file
	inFile.close();

	//return the size of the array to use in analyzing 
	return count;
}

//This function analyzes the array made from readFile
void analyzeArray(int array[], int size)
{
	//create variables
	int min = array[0], max = array[0];
	float average = 0, standardDeviation = 0;

	//create loop to analyze array
	for (int i = 0; i < size; i++)
	{
		//calculate average
		average = average + array[i];

		//find min
		if (array[i] < min)
			min = array[i];

		//find max
		if (array[i] > max)
			max = array[i];
	}
	//divide sum for average by size to find actual average
	average = average / size;

	//now find standard deviation
	for (int i = 0; i < size; i++)
	{
		standardDeviation = standardDeviation + pow((array[i] - average), 2);
	}

	//calculate actual value of standard deviation
	standardDeviation = sqrt((standardDeviation / size));

	//output values we found
	cout << "Min is: " << min << endl;
	cout << "Max is: " << max << endl;
	cout << "Average is: " << average << endl;
	cout << "Standard Deviation is: " << standardDeviation << endl;
}




