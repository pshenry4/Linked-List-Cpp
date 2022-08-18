//Program #4 - BGInsurance Program
// Programmer: Parker Henry
// Class: CS 2020 section 1001
// Due Date: April 3rd, 2022
// Program: memberNode.cpp				       
// This .cpp file defines what the functions created in 
// memberNode.h do and what variables they define or return                                        
//*********************************************************
#include "memberNode.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

//***********************************************************
// Function: memberNode constructor                         *
// This function creates a default node                     *
// that allocates memory for a member's info                *
//***********************************************************
memberNode::memberNode(int id, string name, string policy, int year, int premium) {
	this->id = id;
	this->name = name;
	this->policy = policy;
	this->year = year;
	this->premium = premium;
	this->nextNodePtr = nullptr;
}

//*******************************************************
// Function: memberNode destructor                      *
// This function deallocates memory that was created    *
// from the memberNode constructor                      *
//*******************************************************
memberNode::~memberNode() {
	if (nextNodePtr != nullptr) {
		cout << id << " member removed." << endl;
		delete nextNodePtr;
		nextNodePtr = nullptr;
	}
	else {
		cout << id << " member removed." << endl;
		delete nextNodePtr;
	}

}

//****************************************************
// Function: setID & getID                           *
// This group of functions set the member's id
// as well as get the member's id after it is set.	 *
//****************************************************
int memberNode::setID(int id) {
	return this->id = id;
}
int memberNode::getID() {
	return this->id;
}

//****************************************************
// Function: setName & getName                       *
// This group of functions set the member's name
// as well as get the member's name after it is set. *
//****************************************************
string memberNode::setName(string name) {
	return this->name = name;
}
string memberNode::getName() {
	return this->name;
}

//***********************************************************
// Function: setPolicy & getPolicy                          *
// This group of functions set the member's policy they have*
// as well as get the member's policy after it is set.      *
//***********************************************************
string memberNode::setPolicy(string policy) {
	return this->policy = policy;
}
string memberNode::getPolicy() {
	return this->policy;
}

//**********************************************************
// Function: setYear & getYear                             *
// This group of functions set the member's policy year    *
// as well as get the member's policy year after it is set.*
//**********************************************************
int memberNode::setYear(int year) {
	return this->year = year;
}
int memberNode::getYear() {
	return this->year;
}

//********************************************************
// Function: setPremium & setPremium                     *
// This group of functions set the member's premium      *
// as well as get the member's premium after it is set.	 *
//********************************************************
int memberNode::setPremium(int premium) {
	return this->premium = premium;
}
int memberNode::getPremium() {
	return this->premium;
}

//****************************************************
// Function: getNext                                 *
// This function returns a node pointer to the next  *
// node in the linked list                      	 *
//****************************************************
memberNode* memberNode::getNext() {
	return this->nextNodePtr;
}

//****************************************************
// Function: setNext                                 *
// This function returns a node pointer to the node  *
// entered in the parameter                      	 *
//****************************************************
void memberNode::setNext(memberNode* currNode) {
	nextNodePtr = currNode;
}	