// This .cpp file acts as the user client and calls the 6 
// different functions created in memberList.cpp
// to display and edit the list of members for 
// BGInsurance                                      
//*********************************************************
//******************************************************
// Program: memberListClient.cpp				       *
// Client program to use the memberNode and memberList *
// classes                                             *
//******************************************************
#include "memberNode.h"
#include "memberList.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

memberNode* CreatecurrNode();
ifstream infile;				//file variable declared globally
								//no need to pass as a parameter

int main() {

	infile.open("memberData.txt");		//open file for input

	memberList MyListOfmembers;			//memberList Object
	int yrs;
	int choice, Delid;					//input variables for processing the list
	string policy;
	memberNode* currNode;				//pointer to current node to be added to the list

	infile >> choice; // get a menu choice before entering the loop		

	while (choice != 7)					//loop until 7 is entered
	{
		if (choice == 1) {				//Adds a newly created node to the front of the list
			currNode = CreatecurrNode();
			MyListOfmembers.AddOneMember(currNode);    //calls the AddOneMember member function for the list

		}
		else if (choice == 2) {			//Finds and deletes a node based on the integer entered
			infile >> Delid;
			MyListOfmembers.RemoveOneMember(Delid); //calls the RemoveOneMember member function for the list
		}
		else if (choice == 3) {
			MyListOfmembers.PrintMemberList();    //calls the PrintMemberList member function for the list
		}
		else if (choice == 4) {
			infile.ignore();	//skips the new line character
			getline(infile, policy);
			MyListOfmembers.PrintPolicy(policy);    //calls the PrintPolicy member function for the list
		}
		else if (choice == 5) {
			infile >> yrs;
			MyListOfmembers.PrintYear(yrs);    //calls the PrintYear member function for the list
		}
		else if (choice == 6) {
			MyListOfmembers.PrintLowPremium();    //calls the PrintLowPremium member function for the list
		}
		infile >> choice;				// get a menu choice in the loop	
	}

	return 0;
}
//-----------------------------------------------------
// Function: CreatecurrNode
// Create a node with member data
// Returns a pointer to that current node
//-----------------------------------------------------
memberNode* CreatecurrNode()
{
	memberNode* currNode;		//local pointer for the dynamic node that will be created
	string memberName;
	int memberID;
	string memberPolicy;
	int memberYear;
	int memberPremium;


	//input those variables to popluate your node.
	infile >> memberID;
	infile.ignore();
	getline(infile, memberName);
	getline(infile, memberPolicy);
	infile >> memberYear;
	infile >> memberPremium;

	//add those variables as arguments to populate your node.
	currNode = new memberNode(memberID, memberName, memberPolicy, memberYear, memberPremium);

	return currNode;    //returns the pointer that points to the dynamic node

}
