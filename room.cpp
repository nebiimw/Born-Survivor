#include <iostream>
#include "room.h"

using namespace std;
// this function is using the struct and vector setted in room.h file to give the login information to the user
int room::welcome()
{	
	user_choice.clear();

	user_choice.push_back("SIGN UP A NEW ACCOUNT");

	user_choice.push_back("ALREADY HAVE AN ACCOUNT - SIGN IN");

	user_choice.push_back("QUIT THE GAME");

	return print_what_to_do();

}


// this function is going to determine user input is under the given range and load into the function with inputted number 
int room::print_what_to_do(){
	
	int what_to_do = 20;
	cout << "-------- Please enter the your choice --------" << endl;

	while(what_to_do ==  20){
		cout << endl;
		for (int i = 0; i < user_choice.size(); i++){
			
			cout << i << ") --- " << user_choice[i] << endl;

		}
		cout << endl;
		cout << "--------- Please enter the your choice --------" << endl;

		cin >> what_to_do;

		if ( what_to_do < 0 || what_to_do > 2 ){
		
			cout << "------------- Wrong choice - Out of range -------------" << endl;
		
			what_to_do = 20;
		}
	}

	cout << endl;

	return what_to_do;

}



