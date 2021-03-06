#pragma once

#include <iostream>
#include <cstring>

#include "tree.h"

using namespace std;

class AppMgr{
public:
//Constructor
	AppMgr();

//Destructor
	~AppMgr();

//Main User Sided Function
	void start(); 
	
//BST Functions
	void insert();
	void removeTopic();
	void removeWebsite();
	void retrieve();
	void display();

private:
	Tree* favorites;

//Go-to string builder
	char* strbuild();
};

