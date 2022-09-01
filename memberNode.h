// Program: memberNode.h				       
// This .h file creates a memberNode class that is used 
// in various other cpp files to make the client run                                         
//******************************************************
#pragma once
#ifndef MEMBERNODE_H
#define MEMBERNODE_H


#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class memberNode {
//Defined all public functions for class memberNode below
public:
	memberNode(int id, string name, string policy, int year, int premium);
	~memberNode();
	//Functions below set and getter for ID variable
	int setID(int id);
	int getID();
	//Functions below set and getter for Name variable
	string setName(string name);
	string getName();
	//Functions below set and getter for Policy variable
	string setPolicy(string policy);
	string getPolicy();
	//Functions below set and getter for Year variable
	int setYear(int year);
	int getYear();
	//Functions below set and getter for Premium variable
	int setPremium(int premium);
	int getPremium();
	//Functions below set and getter for memberNode pointer
	memberNode* getNext();
	void setNext(memberNode* currNode);

//Defined all private data variables below
private:
	int id;
	string name;
	string policy;
	int year;
	int premium;
	memberNode* nextNodePtr;
};

#endif
