// Author:        James Jenkins
// Assignment:    Program - Stacks & Queues
// Date Written:  02/10/17
// Description:   Stack & Queue
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <regex>
#include "node.h"
#include "stack.h"
#include "queue.h"

using namespace std;

// Determines if the string is a number
bool isNumeric(string val);

// Used by remove_non_digits
inline bool not_digit(char ch);

// Removes Non Digits and Returns a Number Value String
string remove_non_digits(const std::string& input);

string filename;
string PUSH = "push";
string POP = "pop";
string SERVE = "serve";
string APPEND = "append";

int main() {

// 	Order of Operation
// 1.	[DONE] Instantiate the objects of stack and queue. The constructors should initialize the top, front and rear.
// 2.	[DONE] Read a record from the data file
// 3.	[DONE] parse (interpret) the command from the file with it’s associated data from the file
// 4.	[DONE] perform the command with the appropriate data from the file
// 5.	[DONE] output the appropriate info to the screen
// 6.	[DONE] continue steps 2 through 5 until every record in the file is processed.
// 7.	[DONE] close the file
// 8.	[DONE] print the contents of both data structure stack and queue
// 9.	[DONE] end the program gracefully

    string line;
    string numFromString;
    int value;
	int lineNum;

	//stack obj
	Stack myStack;
	//queue obj
	Queue myQueue;

    //prompt the user to enter a file name
    cout << "Welcome to the Stack & Queue program!" << endl;
    cout << "Please provide a file name." << endl;
    cin >> filename;

    cout << endl << "You have chosen the following file name: " << filename << endl;

    // Open the file
	ifstream myFile (filename);
		if (myFile.is_open()) {
		// While the file is good
		while (myFile.good()) {
			// Get the current line in the file
			getline (myFile, line);

			numFromString = remove_non_digits(line);

			if(numFromString == ""){
				value = 0;
			} else {
				//convert to int from string after stripping out number
				istringstream ( remove_non_digits(line) ) >> value;
			}

	        // --- Interpret Commands ---

	        // Stack Calls
		    if(line.find(PUSH) != string::npos) {
            	cout << "PUSH " << numFromString << endl;
            	myStack.push(value);
            }
		    if(line.find(POP) != string::npos) {
		        cout << "POP " << numFromString << endl;
		        myStack.pop();
            }
            // Queue Calls
            if(line.find(SERVE) != string::npos) {
		    	cout << "SERVE " << numFromString << endl;
		    	myQueue.serve();
            }
            if(line.find(APPEND) != string::npos) {
		        cout << "APPEND " << numFromString << endl;
		        myQueue.append(value);
            }
		}

		cout << endl;

		myFile.close();

		myStack.print();
		myQueue.print();
	} else {
		cout << "Unable to open file\n";
	}


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
