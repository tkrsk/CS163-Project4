#include "appmgr.h"

using namespace std;

//Constructor
AppMgr::AppMgr(){
	favorites = new Tree;
	favorites->dataInit();
}



//Destructor
AppMgr::~AppMgr(){
	delete favorites;
	favorites = nullptr;
}



//App Management function
void AppMgr::start(){

	int command;

	cout << "(0) To Exit.\n(1) Add a new website.\n(2) Remove all websites from a certain topic.\n(3) Remove a certain website." << endl;
	cout << "(4) Retrieve a website of a certain keyword.\n(5) Show all websites." << endl;
	cout << "What would you like to do?" << endl;
	cin >> command;
	while (!cin.good()){ //Checks for valid integer input
    	cin.clear();
	    cin.ignore();
		cout << "Please enter a valid number!" << endl;
		cin >> command;
	}
	cin.ignore();

	while(command > 0 && command <= 5){
		while (!cin.good()){ //Checks for valid integer input
    		cin.clear();
	    	cin.ignore();
			cout << "Please enter a valid number!" << endl;
			cin >> command;
		}
		if(command == 1){
			insert();
		}

		else if(command == 2){
			removeTopic();
		}

		else if(command == 3){
			removeWebsite();
		}

		else if(command == 4){
			retrieve();
		}

		else if(command == 5){
			display();
		}
		
		cout << "(0) To Exit.\n(1) Add a new website.\n(2) Remove all websites from a certain topic.\n(3) Remove a certain website." << endl;
		cout << "(4) Retrieve a website of a certain keyword.\n(5) Show all websites." << endl;
		cout << "What would you like to do?" << endl;
		cin >> command;
		cin.ignore();
	}
	cout << "Good Bye!" << endl;
}



//BST Functions
//Add New Resource Function
void AppMgr::insert(){
	favorites->insert();
}



//Remove Topic function
void AppMgr::removeTopic(){
	cout << "Please enter a topic to remove all websites related to this topic: " << endl;
	char* topic = strbuild();

	favorites->removeTopic(topic);

	cout << "Removed all websites related to the topic!" << endl;

	delete [] topic;
}



//Remove Website function
void AppMgr::removeWebsite(){
	cout << "Please enter a keyword to remove the website related to that keyword: " << endl;
	char* keyword = strbuild();

	favorites->removeSite(keyword);

	cout << "Removed website related to the keyword!" << endl;

	delete [] keyword;
}



//Retrieval function
void AppMgr::retrieve(){
	cout << "Please enter a keyword to retrieve a website: " << endl;
	char* search = strbuild(); //Char array for topic to use for search

	char* website = favorites->retrieve(search);
	
	if(website != nullptr){	
		cout << "Website found for keyword: " << website << endl;
	}
	else cout << "Nothing under that topic was found!" << endl;

	delete [] search;
	delete [] website;
}



//Display function
void AppMgr::display(){
	favorites->display();
}



//My go-to cstring building function to save lines of code in other functions
char* AppMgr::strbuild(){
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
