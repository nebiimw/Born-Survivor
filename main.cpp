#include <iostream>
#include <string>
#include <fstream>
#include "room.h"
#include "tony.h"
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

#define Red     "\033[31m" 
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BLACK   "\033[30m"

using namespace std;




void register_account();

bool login_account( string &username );

bool enter_the_game( string &username );

void exit();

void load_user_data( map< string, string > &data );

void save_user_data( map< string, string > &data );

string press_any_key;
	
void make_space();

void play();


//main function to call play() start the game
int main(){
	
	play();

	return 0;

}


// this function is going to load the user information in to map tony, then determine the different provided options, then run the option
void play(){

	
	string username;
	if ( enter_the_game( username ) ){
		exit();
		return;	
	}

	for (int i = 0; i < 4; i++)
		cout << endl;


tony tony;
if ( !tony.load_the_saving( username ) ){
	tony.new_story( username );
	tony.save_the_game();
}
tony.show_choice();

exit();
}
//show the leaving information to the user once the user quit the game or finish the game playing 
void exit(){
	cout << BOLDCYAN;
	cout << "Thank you for playing the game, hope you enjoy the game. Good Bye!" << endl;
	cout << "\n\n";
	cout << BOLDBLUE;
	cout << "         ///// \n";
        cout << "        |||||||\n";
	cout << "        | - - |\n";
	cout << "        | ^ ^ |\n";
	cout << "       \\|  U  |/    \n";
	cout << "        |  o  |\n";
	cout << " |||     \\___/\n";
	cout << " \\  /   __| |__\n";
	cout << "  \\/\\  /       \\\n";
	cout << "   \\ \\/ |     | |\n";
	cout << "    \\__/|     | |\n";
	cout << "        |_____| | \n";
	cout << "        |     |\n\n";
	cout << BLACK;
	return;

}
//this function is going to print the welcoming message to user, and require user input the login or registe
bool enter_the_game( string &username ){
	
	cout << endl;
	cout << "=======================================================" << endl;
	cout << "============== Welcome to Born Survivor ===============" << endl;
	cout << "=======================================================" << endl;
	cout << BOLDCYAN;
	cout << " ___                 ___              _         \n";  
 	cout << "| _ ) ___ _ _ _ _   / __|_  _ _ ___ _(_)_ _____ _ _ \n";
 	cout << "| _ \\/ _ \\ '_| ' \\  \\__ \\ || | '_\\ V / \\ V / _ \\ '_|\n";
 	cout << "|___/\\___/_| |_||_| |___/\\_,_|_|  \\_/|_|\\_/\\___/_| \n";
	cout << endl;
	cout << BOLDBLUE;
	cout << "                            ||||||\n"; 
	cout << "                            |||||||\n"; 
	cout << "                            |-  -||\n"; 
	cout << Red <<"           (        "<< BOLDBLUE <<"        |o  o |-\n"; 
	cout << Red <<"                       "<< BOLDBLUE <<"     | U   |/\n"; 
	cout << Red <<"            )            "<< BOLDBLUE <<"   | -   |\n"; 
	cout << Red <<"           (  (       "<< BOLDBLUE <<"       \\___/\n"; 
	cout << Red <<"               )       "<< BOLDBLUE <<"      /'-'-\n"; 
	cout << Red <<"         (      (     "<< BOLDBLUE <<"    .__|    |\n"; 
	cout << Red <<"          ) /\\ -((   "<< BOLDBLUE <<"    (_|__   ||\n"; 
	cout << Red <<"        (  // | (`)    "<< BOLDBLUE <<"  ((  `'--||\n"; 
	cout << Red <<"      _ - /_/ \\\\-- _    "<< BOLDBLUE <<"  \\\\ \\-._/_|\n"; 
	cout << Red <<"     (_ -// | \\ \\-  \\ "<< BOLDBLUE <<"   <__\\_\\`--'|\n"; 
	cout << Red <<"     ( `/__ _  __\\, )  "<< BOLDBLUE <<"    <__-'___'\n"; 
	cout << Red <<"        (_ )_)(_)_) \n\n"; 
	cout << BLACK;
	for (int i = 0; i < 2; i++)
  	      cout << BLACK << endl;
	while ( true ){
		
		room room;
		int what_to_do = room.welcome();

		switch ( what_to_do ){

			case 0:
		 		register_account();	
				break;
			
			case 1:
				if ( login_account( username ) )
					return false;
					break;	

			default:
				return true;
			}
		}
}
//use map iteration to linkage different user's input, then link them as username and password, then check from server
//if the user name is already exist, then return the error message
void register_account(){

	cout << "Sign UP: " << endl;

	map< string, string> data;
	load_user_data( data );
	string username;
	string password, password_confirm;
	bool username_can_use = false;

	while ( true ){
		
		if ( !username_can_use ){
		cout << "Create a username: ";
		
		cin >> username;

		if ( data.count( username ) )
			cout << "Username \""<< username << "\" has already used." << endl << endl;
		else 
			username_can_use = true;
		
		}
		
		if ( username_can_use ){
			cout << "Please enter a password: ";
			
			cin >> password;

			cout << "Confirm your password - Please enter again: ";

			cin >> password_confirm;

			if (password == password_confirm )
				break;
			else
				cout << "Your confirm password is different to the previous one - Please do it again" << endl << endl << endl; 
		}
	}

	data[ username ] = password;
	
	save_user_data( data );

	cout << Red << "\nRegister Success\n\n\n\n" << BLACK << endl;
}


//this function using map function to check the server's information and compare with user's input by load_user_data function , 
//Once the login information is correct, then run the game
bool login_account ( string &username ){
	
	cout << "Sign In: " << endl;

	map< string, string> data;
        load_user_data( data );
        string password;
	
	cout << "Please enter your username: ";

	cin >> username;

	cout << "Please enter your password: ";

	cin >> password;

	if (data.count( username ) == 0 ){
		cout << "Account (username) does not exist\n\n\n\n" << endl;
		return false;
	}
   
	else if ( data[username] != password ){
		cout << "Wrong password" << endl<< endl<< endl<< endl;
		return false;
	}
	else {
		cout << "Login success" << endl<< endl<< endl<< endl;
		return true;
	}
}


// this function is going to check the existness of the username file, if exist then check the password
void load_user_data( map< string, string > &data)
{	
	string username;
	ifstream fin("user_database");

	while (fin >> username)
	{
		string password;
		fin >> password;
		
		data[username] = password;
	}
	fin.close();
}
//save and alter the output user's information file
void save_user_data( map< string, string > &data)
{
	ofstream fout("user_database");

	for (auto i : data)
	{
		fout << i.first << " " << i.second;
			fout << endl;
	}

	fout.close();
}
