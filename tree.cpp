//Taka Masagatani
//CS260
//Fall 2020
//Project 4
//cpp file for BST ADT
//tree.cpp

#include "tree.h"

//Constructor
Tree::Tree(){
	root = nullptr;
	size = 0;
}



Tree::Node::Node(Data* add){
	faves = new Data(add);
	left = nullptr;
	right = nullptr;
}



//Destructor
Tree::~Tree(){
	destroy(root);
}



//Data Initialization
void Tree::dataInit(){
	ifstream infile;

	infile.open("randomdatap4.txt");
	
	while(infile.peek() != '~'){
		Data* add = new Data;
		
		char* topic = strhelper(infile);
		add->setTopic(topic);

		char* keyword = strhelper(infile); 
		add->setKeyword(keyword);

		char* website = strhelper(infile);
		add->setWebsite(website);

		char* summary = strhelper(infile);
		add->setSummary(summary);

		char* review = strhelper(infile);
		add->setReview(review);

		int rating = 0;
		infile >> rating;
		add->setRating(rating);
		
		if(infile.peek() == '\n') infile.get();
	
		insert(root, add);

		delete [] topic;
		delete [] keyword;
		delete [] website;
		delete [] summary;
		delete [] review;

		delete add;

		rating = 0;
		
		size++;
	}
}
	


//Public Insert Function
void Tree::insert(){
	Data* add = new	Data;
	
	char* topic = nullptr;
	char* keyword = nullptr;
	char* website = nullptr;
	char* summary = nullptr;
	char* review = nullptr;
	int   rating = 0;
	
	cout << "Please enter a topic: " << endl;
	topic = strbuild();
	add->setTopic(topic);

	cout << "Please enter a keyword: " << endl;
	keyword = strbuild();
	add->setKeyword(keyword);

	cout << "Please enter the website: " << endl;
	website = strbuild();
	add->setWebsite(website);

	cout << "Please enter a summary: " << endl;
	summary = strbuild();
	add->setSummary(summary);

	cout << "Please enter a review: " << endl;
	review = strbuild();
	add->setReview(review);

	cout << "Please enter a rating(1 - 5): " << endl;
	cin >> rating;
	cin.ignore();
	add->setRating(rating);

	insert(root, add);

	delete [] topic;
	delete [] keyword;
	delete [] website;
	delete [] summary;
	delete [] review;
	rating = 0;

	delete add;

	size++;
}
	


//Public Remove Topic Function
void Tree::removeTopic(char* topic){
	removeTopic(topic, root);
}



//Public Remove Website Function
void Tree::removeSite(char* keyword){
	removeSite(keyword, root);
}



//Public Retrieval Function
char* Tree::retrieve(char* keyword){
	char* website = nullptr;
	retrieve(keyword, root, website);
	if(website != nullptr){
		return website;
	}
	else{
		return nullptr;
	}
}



//Public Display Function
void Tree::display(){
	display(root);
}



//Destroy Function
void Tree::destroy(Node*& start){
	if(start != nullptr){
		destroy(start->left);
		destroy(start->right);

		delete start->faves;
		start->faves = nullptr;
		
		delete start;
		start = nullptr;
	}
}



//Private Insert Function
void Tree::insert(Node*& start, Data*& add){
	if(!start){
		start = new Node(add);
	}
	else if(strcmp(start->faves->getKeyword(), add->getKeyword()) > 0){
		insert(start->left, add);
	}
	else{
		insert(start->right, add);
	}
}



//Private Remove Topic Function
void Tree::removeTopic(char* topic, Node*& start){
	if(start != nullptr){
		removeTopic(topic, start->left);
		removeTopic(topic, start->right);
		int check = strcmp(topic, start->faves->getTopic());
		if(check == 0){	
			removeNode(start);
		}
	}
}



//Private Remove Website Function
void Tree::removeSite(char* keyword, Node*& start){
	if(start != nullptr){
		int check = strcmp(keyword, start->faves->getKeyword());
		if(check == 0){	
			removeNode(start);
			size--;
			return;
		}
	
		else if(check < 0){
			removeSite(keyword, start->left);
		}
		
		else{
			removeSite(keyword, start->right);
		}
	}
}



//Remove Node Function
void Tree::removeNode(Node*& start){
	if(start->left == nullptr && start->right == nullptr){
		delete start->faves;
		start->faves = nullptr;
		delete start;
		start = nullptr;
	}
	else if(start->right == nullptr){
		Node* temp = start;
		start = start->left;
		delete temp->faves;
		temp->faves = nullptr;
		delete temp;
	}
	else if(start->left == nullptr){
		Node* temp = start;
		start = start->right;
		delete temp->faves;
		temp->faves = nullptr;
		delete temp;
	}
	else{
		Node* prev = nullptr;
		Node* curr = start->right;
		if(curr->left == nullptr){
			start->right = curr->right;
		}
		else{
			while(curr->left != nullptr){
				prev = curr;
				curr = curr->left;
			}
			prev->left = curr->right;
		}
		delete start->faves;
		start->faves = curr->faves;
		delete curr;
		return;
	}
}

//Private Retrieval Function
char* Tree::retrieve(char* keyword, Node* start, char* &website){
	if(start != nullptr){
		retrieve(keyword, start->left, website);
		retrieve(keyword, start->right, website);
		
		if(strcmp(keyword, start->faves->getKeyword()) == 0){
			website = new char[strlen(start->faves->getWebsite()) + 1];
			strcpy(website, start->faves->getWebsite());
			return website;
		}
	}
}



//Private Display All Function
void Tree::display(Node* start){
	if(start != nullptr){
		display(start->left);
		start->faves->print();
		display(start->right);
	}
}



//String Building Functions
char* Tree::strbuild(){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(cin.peek() != '\n'){
		buffer = cin.get();
		
		if(string == nullptr){
			
			string = new char[2];
			
			string[0] = buffer;
			
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2]; //Temporary cstring to change output string to right size CArray
			
			strcpy(temp, string);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(string) + 1] = '\0';
			
			delete [] string;
			
			string = temp;
		}
	}
	cin.ignore(); //clear buffer stream
	
	return string;
}



char* Tree::strhelper(ifstream& ifile){
	char buffer = '\0'; //Buffer char to append to end of cstring
	char * string = nullptr; //Buffer cstring to return to where function was called

	while(ifile.peek() != ';'){
		buffer = ifile.get();
		
		if(string == nullptr){
			string = new char[2];
			
			string[0] = buffer;
			
			string[1] = '\0';
		}
		else{
			char * temp = new char[strlen(string) + 2]; //Temporary cstring to change output string to right size CArray
			
			strcpy(temp, string);
			
			temp[strlen(temp)] = buffer;
			
			temp[strlen(string) + 1] = '\0';
			
			delete [] string;
			
			string = temp;
		}
	}
	ifile.ignore(); //clear buffer stream
	
	return string;
}
