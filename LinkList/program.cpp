// Author:          James Jenkins
// Program:         Linked List
// Date Written:    01/18/17
// Description:     Provides a linked list program for creating linked list data structures
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "linklist.h"

using namespace std;

std::string filename;

// Determines if the string is a number
bool isNumeric(string val);

int main() {

    string line;
	int lineNum;

	// New Link List
    LinkList list;
    // New Double Link List
    DoubleLinkList doubleList;

    //prompt the user to enter a file name
    cout << "Please provide a file name." << endl;
    cin >> filename;

    cout << endl << "You have chosen the following file name: " << filename << endl;

    //read in the file
    ifstream myfile (filename);
    if (myfile.is_open()) {
        cout << "Single Linked List contents:" << endl;
        while (myfile.good() ) {

        	// Get the current line in the file
			getline (myfile, line);
			// Verify that the line is an integer
			if (isNumeric(line)) {
				// Convert 'line' to an integer and calculate
				stringstream convert(line);
				convert>>lineNum;
				// Sdd line integery to link list as a node value
				list.Append(lineNum);

			}

        }


        // Return current read position to beginning of file
        myfile.clear();
		myfile.seekg(0, ios::beg);

		// Step 6:  Traverse the single linked list node by node, for each node in the single linked list
		//int sum = list.Traverse();
		//cout << "sum: " << sum << endl;

		// Step 7:  Insert the integer from the node of the single linked list into the double linked list in ascending order
        doubleList.storeNode(list.getNode());

        // Step 8:  Do steps 6 and 7 for all of the nodes of single linked list.
        //doubleList.Append(0);

        // Step 9:  Print each integer from the single linked list using the traverse function passing the print function as a parameter.
		cout << endl << "Single Linked List contents:" << endl;
		list.Print();
		cout << endl;

		// Step 10: Print each integer from the double linked list using the traverse function passing the print function as a parameter.
		cout << endl << "Double Linked List contents:" << endl;
		doubleList.Print();
		cout << endl;

    } else {
        cout << "The file specified could not be opened." << endl;
    }

    return 0;
}

// Determines if the string is a number
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
