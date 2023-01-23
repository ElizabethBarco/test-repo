// Tester Program to verify correctness of Pat Morin's 
// modified SLList.h singly linked list implementation
// SLList_MOD.h. The source code for SLList.h is from 
// Morin's Open Data Structures project, accessible 
// through the following hyperlink: https://opendatastructures.org/


// All C++ source code from Open Data Structures is released under a 
// Creative Commons Attribution 2.5 Canada license, which is available for 
// viewing here: https://creativecommons.org/licenses/by/2.5/ca/


// A changelog of modifications is available on CS 2's Canvas page.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SLList_MOD.h"
using namespace std;


const int SIZE = 10;


int main()
{
        srand(time(0));

        cout << "CSCI 2 - Linked List Lab Project Tester\n"
		<< "*************************\n\n";

        // Declare a char-typed SLList named testList, initially empty
        //
        SLList<char> testList;


        // Insert letters ['A', 'J'] of the 
        // alphabet, in uppercase format
        //
        char letter = 'A';

        for (int i = 0; i < SIZE; i++)
                testList.addBack(letter + i);


        // Size of the list
        cout << "Size of list, after inserting the first ten (10) "
        << "letters of the alphabet, uppercase:"
        << testList.getSize() << endl << endl;
        

        // Output testList's elements, in order:
        // 'A'
        // 'B'
        // ...
        // 'J'
        for (int i = 0; i < testList.getSize(); i++)
                cout << testList.get(i) << endl;
        cout << endl;


        int choice;
        do
        {
            cout << "Select which operations you would like to test:\n";
            cout << "1. Attempt to add a duplicate value using addUnique( )\n";
            cout << "2. Attempt to add a unique value using addUnique( )\n";
            cout << "3. isUnique( )\n";
			cout << "4. set( )\n";
            cout << "5. Copy Constructor\n";
			cout << "6. combineLists( )\n";
            cout << "Choice: ";
            cin >> choice;
            cout << endl;

            if (1 <= choice && choice <= 6)
                break;
        } while (true);


        if (choice == 1)
        {
            char uLetter;
            do
            {
                cout << "Enter any letter in the closed interval [\'A\', \'J\']: ";
                cin >> uLetter;
                if ('A' <= uLetter && uLetter <= 'J')
                    break;
            } while (true);


            int currentSize = testList.getSize();
            if (testList.addUnique(uLetter) == currentSize)
                cout << "Duplicate value successfully not inserted into list.\n";
            else
                cout << "Duplicate value incorrectly inserted into list.\n";


            cout << "\ntestList's contents, in order:\n";
            for (int i = 0; i < testList.getSize(); i++)
                cout << testList.get(i) << endl;

        }
        else if (choice == 2)
        {
            char uLetter;
            do
            {
                cout << "Enter any uppercase letter greater than 'J': ";
                cin >> uLetter;
                if ('J' < uLetter && uLetter <= 'Z')
                    break;
            } while (true);


            int currentSize = testList.getSize();
            if (testList.addUnique(uLetter) > currentSize)
                cout << "Unique value is successfully inserted into list.\n";
            else if (testList.getSize() > currentSize)
                cout << "Unique value is *NOT* successfully inserted into list.\n";


            cout << "\ntestList's contents, in order:\n";
            for (int i = 0; i < testList.getSize(); i++)
                cout << testList.get(i) << endl;
        }
        else if (choice == 3)
        {
            // testList currently stores the first 10 uppercase letters of the
            // alphabet, in order. isUnique( ) should successfully confirm that
            // each element in this testList is unique:
            if (testList.isUnique())
                cout << "List is confirmed to only have unique elements.\n";
            else
                cout << "List is *NOT* confirmed to only have unique elements.\n";


            // Insert a duplicate value, then call isUnique( ) again:
            testList.addBack('G');
            if (!testList.isUnique())
                cout << "After duplicate insertion, list is confirmed to\n"
                << "no longer be a list of unique elements.\n";
            else
                cout << "After duplicate insertion, list is incorrectly\n"
                << "determined to be a list of unique elements.\n";
        }
        else if (choice == 4)
        {
            int r = rand() % testList.getSize();
            testList.set(r, 'V');

            cout << "\nAfter modifying at index " << r << ",\n"
            << "testList's contents, in order:\n";
            for (int i = 0; i < testList.getSize(); i++)
                cout << testList.get(i) << endl;
        }
		else if (choice == 5)
        {
            // Copy constructor call
            SLList<char> testList2 = testList;

            cout << "\ntestList2's contents, in order:\n";
            for (int i = 0; i < testList2.getSize(); i++)
                cout << testList2.get(i) << endl;
        }
		else if (choice == 6)
        {
			//Create a char-typed, 0-based, singly linked list
			SLList<char> testList2;
			
			//Seven (7) random characters inserted to the end of the list
			int r = rand() % 26 + 'A';         
			for (int i = 0; i < 7; i++)
			{
				testList2.addBack(r);
				r = rand() % 26 + 'A';
			}

			// Output testList2
			cout << endl << "List 2: " << endl;
			for (int i = 0; i < testList2.getSize(); i++)
			cout << testList2.get(i) << endl;
			cout << endl;

			testList.combineLists(testList2); 

			cout << "\n\nUnion: " << endl;
			for (int i = 0; i < testList.getSize(); i++)
				cout << testList.get(i) << endl;      
        }


        // Terminate program
        //
        cout << endl << "End of program!" << endl << endl;		
        return 0;
}