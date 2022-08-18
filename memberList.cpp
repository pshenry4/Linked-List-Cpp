//Program #4 - BGInsurance Program
// Programmer: Parker Henry
// Class: CS 2020 section 1001
// Due Date: April 3rd, 2022
// Program: memberList.cpp				       
// This .cpp file defines what the functions created in 
// memberList.h do and what variables they define or return
// to output and change the list of members                                        
//*********************************************************
#include "memberNode.h"
#include "memberList.h"

#include <iostream>
using namespace std;

//****************************************************
// Function: memberList  (Constructor)               *
// This function sets head and tail pointers         *
// to null for the default constructor				 *
//****************************************************
memberList::memberList() {
	head = nullptr;
	tail = nullptr;
}

//****************************************************
// Function: ~memberList  (Destructor)               *
// This function destroys the entire list somewhat   *
// recusively?										 *
//****************************************************
memberList::~memberList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}

//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList& memberList::operator=(memberList& rhs) {
	memberNode* currNode = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currNode != nullptr) {

			PushBack(new memberNode(currNode->getID(), currNode->getName(),
											currNode->getPolicy(), currNode->getYear(),
											currNode->getPremium()));
			currNode = currNode->getNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: memberList(memberList& rhs)                   *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList::memberList(memberList& rhs) {
	memberNode* currNode = rhs.head;                // Copy List

	while (currNode != nullptr) {
		PushBack(new memberNode(currNode->getID(), currNode->getName(),
											currNode->getPolicy(), currNode->getYear(),
											currNode->getPremium()));
		currNode = currNode->getNext();					//Traversal Statement
	}													//Important to point to the next node
}

//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void memberList::PushBack(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		tail->setNext(currNode);
		tail = currNode;
	}
	cout << currNode->getID() << " member added." << endl;
}

//****************************************************
// Function: AddOneMember                            *
// Takes the node passed in and adds new member      * 
// to the beginning of the linked list	             *
//****************************************************
void memberList::AddOneMember(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		currNode->setNext(head);
		head = currNode;
	}
	cout << currNode->getID() << " member added." << endl;
}

//****************************************************
// Function: RemoveOneMember                         *
// This function removes a member with a specific    *
// id from the list and displays a message that the  *
// member was removed from the list             	 *
//****************************************************
void memberList::RemoveOneMember(int id) {
	memberNode* currNode = nullptr;
	memberNode* prevNode = nullptr;
	
	//Scenerio 1 if there is no head node pointer
	if (!head) {
		cout << "The list is empty." << endl;
		cout << id << " is not a member." << endl;
		return;
	}
	
	//Scenerio 2 if the head pointers id equals the id entered to be deleted
	if (head->getID() == id) {
		currNode = head;
		if (head == tail) {
			tail = nullptr;
		}
		head = head->getNext();
		currNode->setNext(nullptr);
		delete currNode;
		cout << id << " member removed." << endl;
	}
	else {                      //Scenerio 3 searches for the id in the linked list and if it is found that member is deleted
		currNode = head;

		while (((currNode) && currNode->getID() != id)) {
			prevNode = currNode;
			currNode = currNode->getNext();
		}

		if (currNode) {
			prevNode->setNext(currNode->getNext());
			currNode->setNext(nullptr);
			if (currNode == tail) {
				tail = prevNode;
			}
			delete currNode;
			cout << id << " member removed." << endl;
		}
		else {        //Scenerio 4 outputs that the member id isn't a member if it can't be found on the linked list
			cout << id << " is not a member." << endl;
		}
	}

}

//****************************************************
// Function: PrintMemberList                         *
// This function prints every member in linked list  *
// and their data.                              	 *
//****************************************************
void memberList::PrintMemberList() {
	memberNode* currNode = head;

	if (currNode == nullptr) {            //Checks if the list is empty and outputs message if it is
		cout << "The list is empty." << endl;
	}
	else {   
		//Outputs the beginning of table below
		cout << "=================================================================================" << endl;
		cout << setw(5) << left << "Id";
		cout << setw(25) << left << "Name";
		cout << setw(15) << left << "policy";
		cout << setw(15) << left << "premium";
		cout << setw(20) << left << "years" << endl;
		cout << setw(5) << left << "--" << setw(25) << left << "----" << setw(15) << left << "------";
		cout << setw(15) << left << "-------" << setw(20) << left << "-----" << endl;
		//Iterates through the list and prints all members below
		while (currNode != nullptr) {
			cout << setw(5) << left << currNode->getID();
			cout << setw(25) << left << currNode->getName();
			cout << setw(15) << left << currNode->getPolicy();
			cout << setw(15) << left << currNode->getPremium();
			cout << setw(20) << left << currNode->getYear() << endl;
			
			currNode = currNode->getNext();
		}
		cout << "=================================================================================" << endl;
	}
	
}

//****************************************************
// Function: PrintPolicy                             *
// This function prints every member in linked list  *
//  with a specific policy and their data.         	 *
//****************************************************
void memberList::PrintPolicy(string policy) {
	//Declared all necessary variables below
	memberNode* currNode = head;
	double premiumSum = 0.0;
	int counter1 = 0;
	int counter2 = 0;
	double premiumAvg;

	//The while loop below uses a counter to see if there are any members who have the policy entered in the parameter
	while (currNode != nullptr) {
		if (currNode->getPolicy() == policy) {
			++counter1;
			break;
		}
		else {
			currNode = currNode->getNext();
		}
	}
	
	//Outputs the beginnning of table below
	cout << "=================================================================================" << endl;
	cout << "                All " << policy << " members" << endl;
	cout << "=================================================================================" << endl;
	cout << setw(5) << left << "Id";
	cout << setw(25) << left << "Name";
	cout << setw(15) << left << "policy";
	cout << setw(15) << left << "premium";
	cout << setw(20) << left << "years" << endl;
	cout << setw(5) << left << "--" << setw(25) << left << "----" << setw(15) << left << "------";
	cout << setw(15) << left << "-------" << setw(20) << left << "-----" << endl;

	//Checks to see if the first counter is 0 or not
	if (counter1 == 0) {
		cout << "Sorry, no " << policy << " members" << endl;
	}
	else {
		//If counter1 isn't 0 then the while loop prints the members who have the same policy as the parameter
		currNode = head;
		while (currNode != nullptr) {
			if (currNode->getPolicy() == policy) {
				cout << setw(5) << left << currNode->getID();
				cout << setw(25) << left << currNode->getName();
				cout << setw(15) << left << currNode->getPolicy();
				cout << setw(15) << left << currNode->getPremium();
				cout << setw(20) << left << currNode->getYear() << endl;
				++counter2;
				premiumSum = premiumSum + currNode->getPremium();
				currNode = currNode->getNext();
			}
			else {
				currNode = currNode->getNext();
			}
		}
	}
	cout << "=================================================================================" << endl;

	//Outputs the average premium for the policy entered below
	if (counter1 > 0) {
		premiumAvg = premiumSum / counter2;
		cout << "---------------------------------------------------------------------------------" << endl;
		cout << "The average " << policy << " premium is: $" << fixed << setprecision(2) << premiumAvg << endl;
		cout << "=================================================================================" << endl;
	}
}

//****************************************************
// Function: PrintYear                               *
// This function prints every member in linked list  *
// that has been with the company for the            *
// amount of years in the parameter value or longer  *
//****************************************************
void memberList::PrintYear(int year) {
	//defined all necessary variables below
	memberNode* currNode = head;
	int counter = 0;



	//While loop below keeps track of a counter to see if there are 0 members who have been there for a certain amount of years
	while (currNode != nullptr) {
		if (currNode->getYear() >= year) {
			++counter;
			break;
		}
		else {
			currNode = currNode->getNext();
		}
	}

	//output table format below
	cout << "=================================================================================" << endl;
	cout << "                Members of at least: " << year << "    years" << endl;
	cout << "=================================================================================" << endl;
	cout << setw(5) << left << "Id";
	cout << setw(25) << left << "Name";
	cout << setw(15) << left << "policy";
	cout << setw(15) << left << "premium";
	cout << setw(20) << left << "years" << endl;
	cout << setw(5) << left << "--" << setw(25) << left << "----" << setw(15) << left << "------";
	cout << setw(15) << left << "-------" << setw(20) << left << "-----" << endl;
	
	//outputs the members who meet the year requirement below if the counter is greater than 0
	if (counter == 0) {
		cout << "Sorry, no member with " << year << " or more years" << endl;
	}
	else {
		currNode = head;
		while (currNode != nullptr) {
			if (currNode->getYear() >= year) {
				cout << setw(5) << left << currNode->getID();
				cout << setw(25) << left << currNode->getName();
				cout << setw(15) << left << currNode->getPolicy();
				cout << setw(15) << left << currNode->getPremium();
				cout << setw(20) << left << currNode->getYear() << endl;
				currNode = currNode->getNext();
			}
			else {
				currNode = currNode->getNext();
			}
		}
	}
	cout << "=================================================================================" << endl;
}

//****************************************************
// Function: PrintLowPremium                         *
// This function will print the member with          *
// the lowest premium                                *
//****************************************************
void memberList::PrintLowPremium() {
	//Declared all necessary variables below
	memberNode* currNode = head;
	int lowestPremium = currNode->getPremium();
	string lowestPremiumName = currNode->getName();

	//Iterates through member list to find the member with the lowest premium
	while (currNode != nullptr) {
		if (currNode->getPremium() < lowestPremium) {
			lowestPremium = currNode->getPremium();
			lowestPremiumName = currNode->getName();
			currNode = currNode->getNext();
		}
		else {
			currNode = currNode->getNext();
		}
	}

	//Outputs the member with lowest premium below
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << lowestPremiumName << " has the lowest premium of " << lowestPremium << " dollar(s)." << endl;
	cout << "=================================================================================" << endl;
}