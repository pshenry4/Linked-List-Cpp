// Program: memberList.h				       
// This .h file defines what functions will be used to
// iterate through and change the list of members.                                      
//*********************************************************
#pragma once
#include "memberNode.h"

#include <string>
#include <iostream>
using namespace std;

class memberList {
public:
	memberList();                            //constructor
	memberList(memberList& rhs);             //copy constructor
	~memberList();                           //destructor
	memberList& operator=(memberList& rhs);  //copy assignment function to copy linked list
	void PushBack(memberNode* currNode);     //pushback function to add node to linked list and push back nodes before
	void AddOneMember(memberNode* currNode); //addonemember function to add member to front of linked list
	void RemoveOneMember(int id);            //removeonemember function to remove member with the id in parameter from the list
	void PrintMemberList();                  //printmemberlist function to print all members in list and their data
	void PrintPolicy(string policy);         //printpolicy function to print all members with a specific policy and their data
	void PrintYear(int year);                //printyear function to print all members that have been with the company for parameter amount or longer
	void PrintLowPremium();                  //printlowpremium function to print the member with the lowest premium

private:
	memberNode* head = nullptr;
	memberNode* tail = nullptr;
};
