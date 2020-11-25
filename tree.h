#pragma once

#include <iostream>
#include <cstring>
#include <fstream>

#include "data.h"

using namespace std;

class Tree{
public:
//Constructor
	Tree();

//Destructor
	~Tree();

//Accessors

//Mutators

//Data Initialization
	void dataInit();

//Public Insert Function
	void insert();

//Public Remove Topic Function
	void removeTopic(char* topic);

//Public Remove Website Function
	void removeSite(char* keyword);

//Public Retrieval Function
	char* retrieve(char* keyword);

//Public Display All Function
	void display();

private:
	struct Node{
		Node(Data* add);
		//~Node();
		Data* faves;
		Node* left;
		Node* right;
	};

	Node* root;
	int   size;

//Private Destroy Function
	void destroy(Node* &start);

//Private Insert Function
	void insert(Node*& start, Data*& add); 

//Private Remove Topic Function
	void removeTopic(char* topic, Node*& start);

//Private Remove Website Function
	void removeSite(char* keyword, Node*& start);

//Remove Node Function
	void removeNode(Node*& start);

//Private Retrieval Function
	char* retrieve(char* keyword, Node* start, char* &website);

//Private Display All Function
	void display(Node* start);

//String Builder Functions
	char* strbuild();
	char* strhelper(ifstream& ifile);

};
