// Author:        James Jenkins
// Program:       AVL Tree
// Date Written:  03/10/17
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <regex>
#include "node.h"
#include "tree.h"

using namespace std;

// Determines if the string is a number
bool isNumeric(string val);
// Used by remove_non_digits
inline bool not_digit(char ch);
// Removes Non Digits and Returns a Number Value String
string remove_non_digits(const std::string& input);

int  main(){

    string filename;
    string number;
    string numFromString;
    int value;

    cout << "Program: AVL Tree" << endl;
    cout << "Author: James Jenkins" << endl << endl;

    // Prompt the user to enter a file name
    cout << "--- Welcome to the AVL Tree Program! ---" << endl;
    cout << "Please provide a file name:" << endl;
    cin >> filename;
    cout << endl << endl;

    // Open the file
	ifstream myFile (filename);

	// Instantiate Tree Object
	Tree myTree;

	if (myFile.is_open()) {
	    // Read input numbers separated by spaces loop
        while( getline( myFile, number, ' ')) {
            // Remove non-numeric characters
            numFromString = remove_non_digits(number);
            // Check to see if value was empty
            if(numFromString == ""){
				// Do nothing because the string value extracted was not a number
			} else {
				// Convert to int from string after stripping out number characters
				//istringstream ( numFromString ) >> value;

                stringstream convert(numFromString);//object from the class stringstream
                convert>>value;  //the object has the value 12345 and stream it to the integer x
                //now the variable x holds the value 12345

			    cout << "Push: " << value << endl;
			    myTree.push(value);

			}
        }

	} else {
		cout << "Unable to open file" << endl;
	}

	myFile.close();


	myTree.print("inorder");
	myTree.print("preorder");

    return 0;
}

// Function Name: isNumeric
// Purpose:    Determines if the string is a number
// Parameters:  string
// Returns:     string
// Pre-conditions: none
// Post-conditions:none
bool isNumeric(string val) {
	istringstream iss(val);
	double dTestSink;
	iss >> dTestSink;
	// was any input successfully consumed/converted?
	if (!iss) {
		return false;
	}
	// was all the input successfully consumed/converted?
	return (iss.rdbuf()->in_avail() == 0);
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
