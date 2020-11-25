#include "data.h"

using namespace std;

//Constructor
Data::Data(){
	currTopic = nullptr;
	currKeyword = nullptr;
	currWebsite = nullptr;
	currSummary = nullptr;
	currReview = nullptr;
	currRating = 0;
}



Data::Data(Data* add){
	setTopic(add->getTopic());
	setKeyword(add->getKeyword());
	setWebsite(add->getWebsite());
	setSummary(add->getSummary());
	setReview(add->getReview());
	setRating(add->getRating());
}



//Destructor
Data::~Data(){
	clearData();
}



//Accessors
char* Data::getTopic(){
	return currTopic;
}



char* Data::getKeyword(){
	return currKeyword;
}



char* Data::getWebsite(){
	return currWebsite;
}



char* Data::getSummary(){
	return currSummary;
}



char* Data::getReview(){
	return currReview;
}



int Data::getRating(){
	return currRating;
}



//Mutators
void Data::setTopic(char* topic){
	currTopic = new char[strlen(topic) + 1];
	strcpy(currTopic, topic);
}



void Data::setKeyword(char* keyword){
	currKeyword = new char[strlen(keyword) + 1];
	strcpy(currKeyword, keyword);
}



void Data::setWebsite(char* website){
	currWebsite = new char[strlen(website) + 1];
	strcpy(currWebsite, website);
}



void Data::setSummary(char* summary){
	currSummary = new char[strlen(summary) + 1];
	strcpy(currSummary, summary);
}



void Data::setReview(char* review){
	currReview = new char[strlen(review) + 1];
	strcpy(currReview, review);
}



void Data::setRating(int rating){
	currRating = rating;
}


//Print function
void Data::print(){
	cout << "---" << endl;
	cout << "Keyword: " << currKeyword << endl;
	cout << "Topic: " <<  currTopic << endl;
	cout << "Website: " << currWebsite << endl;
	cout << "Summary: " << currSummary << endl;
	cout << "Review: " << currReview << endl;
	cout << "Rating: " << currRating << endl;
	cout << endl;
}



//Wipe data function
void Data::clearData(){
	if(currTopic != nullptr){
		delete [] currTopic;
		currTopic = nullptr;
	}

	if(currKeyword != nullptr){
		delete [] currKeyword;
		currKeyword = nullptr;
	}

	if(currWebsite != nullptr){
		delete [] currWebsite;
		currWebsite = nullptr;
	}

	if(currSummary != nullptr){
		delete [] currSummary;
		currSummary = nullptr;
	}

	if(currReview != nullptr){
		delete [] currReview;
		currReview = nullptr;
	}

	currRating = 0;
}
