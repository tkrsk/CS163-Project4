//Taka Masagatani
//CS260
//Fall 2020
//Project 4
//Header file for data module
//data.h
#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Data{
public:
//Constructor 
	Data();
	Data(Data* add);

//Destructor
	~Data();

//Accessors
	char* getTopic();
	char* getKeyword();
	char* getWebsite();
	char* getSummary();
	char* getReview();
	int   getRating();

//Mutators
	void setTopic(char* topic);
	void setKeyword(char* keyword); 
	void setWebsite(char* website);
	void setSummary(char* summary);
	void setReview(char* review);
	void setRating(int rating);

//Print function
	void print();

//Wipe data function
	void clearData();

private:
	char* currTopic;
	char* currKeyword;
	char* currWebsite;
	char* currSummary;
	char* currReview;
	int   currRating;
};

