// Author:        James Jenkins
// Program:       Hash Table
// Description:   Creates hash table from txt file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <regex>
#include "hash.h"

using namespace std;

// Removes Non Digits and Returns a Number Value String
string remove_non_digits(const string& input);

int main(){
    string line;
    int value;
    Hash myHash;
    string filename;

    cout << "Hash Table" << endl;

    cout << "Please provide a file name to read data from." << endl;
    cin >> filename;

    cout << endl << "You have chosen: " << filename << endl;

    // Open the file
    cout << "Opening file..." << endl;
	ifstream myFile (filename);

	if (myFile.is_open()) {

	    cout << "Reading in data..." << endl;
		while (myFile.good()) {
			// Get the current line in the file
			getline (myFile, line);
			//removes non digit characters
			line = remove_non_digits(line);
			//converts string to int
			istringstream ( line ) >> value;
			//add value from file to Hash Table
			myHash.add(value);
		}

		//display hash table results
		myHash.show();

	} else {
		cout << "Unable to open file..." << endl;
	}


    return 0;
}

// Used by remove_non_digits
inline bool not_digit(char ch) {
    return '0' <= ch && ch <= '9';
}

// Function Name: remove_non_digits
// Purpose:    Removes Non Digits and Returns a Number Value String
// Parameters:  string
// Returns:     string
// Pre-conditions: none
// Post-conditions:none
std::string remove_non_digits(const std::string& input) {
    std::string result;
    std::copy_if(input.begin(), input.end(),
        std::back_inserter(result),
        not_digit);
    return result;
}
