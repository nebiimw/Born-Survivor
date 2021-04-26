#include <iostream>
#include <fstream>
#include "tony.h"
#include "room.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>

#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

#define RESET "\033[30m"
#define Red  "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BLACK   "\033[30m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;
//because Tool function is self-defined function which will use < operator, therefore need to define it here
bool operator<(const Tool &a, const Tool &b){
	return (a.tool_num < b.tool_num);
}

//this function is used for printing the enter requirement command
void tony::enter_continue(){
	cout << BLACK <<"Press enter to continue";
	cin.get();
	if (cin.get() == '\n')
        	cout << "\n\n\n\n\n\n\n\n\n\n";
	else
        	cout << "\n\n\n\n\n\n\n\n\n\n";


}

//this function is going to generate random number for the different calling function and show a graph of dice
int tony::dice(int num){
	int step;
	srand( time(0) );
	step = rand() % num + 1;

if (step == 1){
cout <<"\n   ______\n";
cout <<"  /     /\\\n";
cout <<" /  '  /  \\\n";
cout <<"/_____/. . \\\n";
cout <<"\\ .   \\    /\n";
cout <<" \\  ‘. \\  /\n";
cout <<"  \\_____\\/\n\n";
}

if (step == 2){
cout <<"\n   ______\n";
cout <<"  /.    /\\\n";
cout <<" /   . /  \\\n";
cout <<"/____ /  . \\\n";
cout <<"\\ . . \\    /\n";
cout <<" \\ . . \\  /\n";
cout <<"  \\_____\\/\n\n";
}

if (step == 3){ 
cout <<"\n   ______\n";
cout <<"  /.    /\\\n";
cout <<" /  '  /  \\\n";
cout <<"/____'/. . \\\n";
cout <<"\\ . . \\    /\n";
cout <<" \\ . . \\  /\n";
cout <<"  \\_____\\/\n\n";
}

if (step == 4){
cout <<"\n   ______\n";
cout <<"  /.  . /\\\n";
cout <<" /.  . /  \\\n";
cout <<"/_____/  . \\\n";
cout <<"\\ .   \\    /\n";
cout <<" \\   . \\  /\n";
cout <<"  \\_____\\/\n\n";
}

if (step == 5){
cout <<"\n   ______\n";
cout <<"  /.  . /\\\n";
cout <<" /. ‘. /  \\\n";
cout <<"/_____/  . \\\n";
cout <<"\\ .   \\    /\n";
cout <<" \\   . \\  /\n";
cout <<"  \\_____\\/\n\n";
}

if (step == 6){
cout <<"\n   ______\n";
cout <<"  / . . /\\\n";
cout <<" /.`.` /  \\\n";
cout <<"/_____/  . \\\n";
cout <<"\\ .   \\    /\n";
cout <<" \\   . \\  /\n";
cout <<"  \\_____\\/\n\n";
}

	return step;
}


//this function is going to give a base of tools and set the tool-creating requirment 
void  tony::tools_base(){
	
	Tool t;
	t.tool_num = 1;
	t.tool_attack = 3;
	t.name = "spear";
	t.material["stone"] = 1;
	t.material["wood"] = 3;
	t.material["thread"] = 2;
	tools.push_back(t);
	t.material.clear();

        t.tool_num = 2;
	t.tool_attack = 1;
        t.name = "dagger";
        t.material["stone"] = 1;
        t.material["wood"] = 1;
        t.material["thread"] = 1;
        tools.push_back(t);
	t.material.clear();

	t.tool_num = 3;
	t.tool_attack = 4;
        t.name = "shield";
        t.material["board"] = 1;	
	t.material["wood"] = 3;
	t.material["thread"] = 2;
        tools.push_back(t);
	t.material.clear();

}

//this function is going to determine the user's bag whether has sufficient materials to create tools, it calls iterator to count the each neccessary material 
bool tony::enough_material(map<string, int> user, map<string,int> base){
	
	int count = 0;
	map<string, int>::iterator itr;
	map<string, int>::iterator itr_user;
	for (itr = base.begin(); itr != base.end(); itr++){
		cout << (*itr).first <<" " <<(*itr).second<<endl;
		for (itr_user = user.begin(); itr_user != user.end(); itr_user++){              
			if((*itr_user).first == (*itr).first && (*itr_user).second >= (*itr).second)
				count++;
                }
        }
	if (count == 3)
		return true;
	else
		return false;
}
//this function going to make the tools by using map iteration, the tool then increase the character's different power
void tony::make_tool(map<string, int> &user, map<string,int> base){

	map<string, int>::iterator itr;
        map<string, int>::iterator itr_user;
        for (itr = base.begin(); itr != base.end(); itr++){
               for (itr_user = user.begin(); itr_user != user.end(); itr_user++){
                        if((*itr_user).first == (*itr).first)
                        	(*itr_user).second -= (*itr).second;
                }
	}

}

//this function is going to load the user information in the server, if there is any file sane with the given user name, then check and load the saved information
bool tony::load_the_saving(string name){
	
	username = name;

	ifstream fin( username );

	if (fin.fail())
		return false;

	else{
		
		fin >> health;

		fin >> willpower;

		fin >> attack_power;

		fin >> defense;
		
		fin >> position;

		fin >> day;
		
		fin >> user_tools["stone"];

 	        fin >> user_tools["thread"];

	        fin >> user_tools["wood"];

	        fin >> user_tools["board"];

		fin >> hunting_num;
	}
	
	fin.close();
	
	tools_base();
		
	return true;
}
//restart status
void tony::new_story(string name){
	
	tools_base();
		
	username = name;

	health = 10;

	willpower = 10;

	attack_power = 1;

	defense = 0;

	position = 0;

	day = 1;

	user_tools["stone"] = 2;
        user_tools["thread"] = 2;
        user_tools["wood"] = 3;
        user_tools["board"] = 0;
	
	hunting_num = 0;

	cout << BLACK <<"Story background"<< endl << endl;
  
  
        cout << "One day morning when Tony got up, he found himself in the forest.\n\n\n";
        
  	cout << "   ________|M |_____       ____________\n";
	cout << "  /_-               \\    |     \n";
	cout << "  /_-   / @     \\    |__/   \\   \\ \n";
	cout << "  /_-        >   |   |  |     \\  \\ \n";
	cout << "  /_-   \\ @     /    |--|      |  | \n";
	cout << " _/_-______________ /__/_______|  |_______\n";
	cout << " (                |----         |  | \n";
	cout << " (----------------|           .`--'\n";
	cout << "                              `|||| \n";

  
  
        for (int i = 0; i < 3; i++)
        	cout << endl;
  
        cout << "Unfortunately, he gets lost in a fortress which is full of crisis.\n\nYou are going to help Tony escape the forest.\n\n";
        
	enter_continue();
  
        cout << "Every day, you have to make the right decisions to stay in healthy condition.\n\n";

	cout << "If a decision is made wrongly, it potentially leads Tony to face some dangerous situations.\n\n";
	cout << endl;


cout << "       ////// \n";
cout << "      |||||||\n";
cout << "      | , _ |\n";
cout << "   .'.| > < |.'.\n";
cout << " .`  \\|  U  |/   `. \n";
cout << "      |  Д  |\n";
cout << "       \\___/\n";
cout << "      __| |__\n";
cout << "     /       \\\n";
cout << "    | |     | |\n";
cout << "    | |     | |\n";
cout << "    | |_____| | \n";
cout << "    /_|  _  |_\\ \n";
cout << "     ||  |  || \n";
cout << "      |  |  |\n";

  

	cout << endl;

	cout << "Therefore, you should make every decision carefully!!\n\n";
	  
        cout << "Press enter to continue";

    	if (cin.get() == '\n')
        	cout << "\n\n\n\n\n\n\n\n\n\n";
    	else
        	cout << "\n\n\n\n\n\n\n\n\n\n";
}
//once player enter the quit command, save the user's information into the output file
void tony::save_the_game(){
	
	ofstream fout(username);

	if (fout.fail()){
		cout <<"Some problems occur when saving your record!\n";
		return;
	}
	
	fout << health << " ";

	fout << willpower << " ";

	fout << attack_power << " ";

	fout << defense << " ";

	fout << position << " ";

	fout << day << " ";
	
	fout << user_tools["stone"]<< " ";

        fout << user_tools["thread"]<< " ";
	
	fout << user_tools["wood"]<< " ";
        
	fout << user_tools["board"]<< " ";
	
	fout << hunting_num << " ";
	
	fout.close();

	
}
//going to print the current status of the character, where the color is defined in the header
void tony::show_state(){

	cout << BLACK <<"====================== Current state of Tony =========================\n\n";
	
	cout << "Day " << day << endl;
	
	cout << "Position " << position << endl;

	cout  << Red << left << setw(16) << "Health value: ";
	for (int i = 0; i < health; i++)
		cout << HEART << " ";
	cout << "(" << health << ")" << endl;


	cout << GREEN << left << setw(16) << "Willpower: ";
	for (int i = 0; i < willpower; i++)
		cout << "* ";
	cout << "(" << willpower  << ")" << endl;
	
	
	cout << BLUE << left << setw(16) << "Attack power: ";
        for (int i = 0; i < attack_power; i++)
                cout << DIAMOND << " ";
        cout << "(" << attack_power  << ")" << endl;
	

	cout << BLUE << left << setw(16) << "Defense level: ";
        for (int i = 0; i < defense; i++)
                cout << DIAMOND << " ";
        cout << "(" << defense  << ")" << endl;
	
	cout << BLACK;
	cout << "======================================================================\n\n";

}
//this function is every-day option, user need to select one of the option in every day
void tony::show_choice(){

	int choice = 0;

	do{

	if ( !update_state() ){
		break;
	}

	show_state();
	
	cout << RESET;
	cout << "======================================================================\n";
	cout << endl;
	cout << BOLDRED << "1) --- Explore the place\n";
	cout << BLACK << "2) --- Go hunting\n";
	cout << BOLDRED << "3) --- Create tools\n";
	cout << BLACK << "4) --- Move forward\n";
	cout << BOLDRED <<"5) --- Rule\n";
	cout << BLACK << "6) --- Save your record\n";
	cout << BOLDRED << "7) --- Exit the game\n";
	cout << BLACK << endl;
	cout << "===================== Please enter your choice =======================\n";

	cin >> choice;

	switch ( choice ){
		case 1:
			explore(  );
			break;

		case 2:
			hunting( );
			break;

		case 3:
			create( );
			break;

		case 4:
			move( );
			break;

		case 5:
			Map();
			break;

		case 6:
			save_the_game();
			cout << "\nSuccessfully save game progress!\n\n";
			cin.ignore();
			cout << "Press \"Enter\" to continue\n";
			
			cin.ignore();
			cout << "\n\n\n\n\n\n\n\n\n\n";
			break;

		case 7:
		
			break;


		default:
			cout << "Wrong choice! Please enter again.\n";
	
	}
	}while(choice != 7);

}
//this explore function is 
void tony::explore(  ){
	

	srand( time(0) );

	int matter = rand() % 5;

	switch (matter){
		
		case 0:
			cout << "Tony found a apple\n";
			cout << Red;
			cout << " .-./,-.\n";
			cout << "; #     ;\n";
			cout << "\\       /\n";
			cout << " `._,_,'\n\n";

			cout << BLACK;
			cout << "1) Eat - health +3\n";
			cout << "2) Discard\n";

			cin >> matter;
			if (matter == 1){
				health += 3;
				cout <<"Tony ate the apple\n";
				cout << "Health +3\n";
			}
			else
				cout <<"Tony has discarded the apple.\n";
			break;

		case 1:
			cout << "Tony found a mushroom\n";
			cout << BLUE;
			cout <<"   .-'~~~-.\n";
			cout <<" .'o  oOOOo`.\n";
			cout <<":~~~-.oOo   o`.\n";
			cout <<"`. \\ ~-.  oOOo.\n";
			cout <<"  `.; / ~.  OO:\n";
			cout <<"  .'  ;-- `.o.'\n";
			cout <<" ,'  ; ~~--'~\n";
			cout <<" ;  ;\n";
			cout <<" ‘..'\n\n";
			
			cout << RESET;
			cout << "1) Eat - health +5(20%) or health -3(80%)\n";
                        cout << "2) Discard\n";

			cin >> matter;
			if (matter == 1){
				cout <<"Tony ate the mushroom\n";
				
				if (rand()%5 == 1){
					health += 5;
	                                cout << "Health +5\n";
				}
				else{
					health -= 3;
					cout << "Health -3\n";
				}
			}
			else
				cout <<"Tony has discarded the mushroom.\n";
			break;
		
		case 2:
			cout << "Tony found a banana\n";
			cout << YELLOW;
			cout <<"\".           ,#\n";
			cout <<"\\ `-._____,-'=/\n";
			cout << "`._ ----- _,'\n";
			cout <<"    `-----'\n\n";
			
			cout << RESET;
			cout << "1) Eat - health +4(50%) or health -3(50%)\n";
                        cout << "2) Discard\n";

                        cin >> matter;
                        if (matter == 1){
                                cout <<"Tony ate the banana\n";

                                if (rand()%2 == 1){
                                        health += 4;
                                        cout << "Health +4\n";
                                }
                                else{
                                        health -= 3;
                                        cout << "Health -3\n";
                                }
                        }
                        else
                                cout <<"Tony has discarded the banana\n"; 


			break;
		default:
			map<string, int>::iterator itr = user_tools.begin();
			matter =  rand()%4;
			for (int i = 0; i <matter; i++)
				itr++;

			cout << "Tony found some "<< itr->first << "s\n";
			if ( (*itr).first == "thread" ){
				cout <<"          _________     \n";
				cout <<"       ,8dP’’’’’’’’8ba,\n";
				cout <<"     ,88'            `8b,\n";
				cout <<"    ,8'    ,dP’’8b,    `8,\n";
				cout <<"    8'   ,d’      '8,   `8,\n";
				cout <<"    8    d'    _   `8,   `8\n";
				cout <<"    8    8     8    `8    8\n";
				cout <<"    8,   `b, ,aP     8    8 \n";
				cout <<"    `8a    ‘’’’     8'   ,8\n";
				cout <<"      `8a         ,8’   ,8'\n";
				cout <<"        `8a,,__,,d8'   ,8'\n";
				cout <<"           `’’’’'’   ,8'   \n\n";
				
				matter = (rand()%4+1);
				user_tools["thread"] += matter;
				cout << itr->first << " +" << matter <<"\n\n";
			}

			
			if ( (*itr).first == "wood" ){
				cout <<"      v .  \n";
				cout <<"   `-._\\/  \n";
				cout <<"       \\\\  \n";
				cout <<" _\\_.___\\\\,\n";
				cout <<"   `7-,--.`._\n";
				cout <<"   /'     `-.|\n";

				matter = (rand()%5+1);
                                user_tools["wood"] += matter;
                                cout << itr->first << " +" << matter <<"\n\n";


			}

			if ( (*itr).first == "stone"){
				cout <<"   /\\\n";
				cout <<"  /  \\\n";
				cout <<" /    \\\n";
				cout <<" \\____/\n";
				
				matter = (rand()%3+1);
                                user_tools["wood"] += matter;
                                cout << itr->first << " +" << matter <<"\n\n";


			}

			if ( (*itr).first == "board"){
				cout <<"  ______________________ \n"; 
				cout <<"/                       |\n";
				cout <<"||                      |\n";
				cout <<"||                      |\n";
				cout <<"||                      |\n";
				cout <<"||                      |\n";
				cout <<"||                      |\n";
				cout <<"||______________________|\n";
				cout <<"|/______________________/\n";

				user_tools["board"] += 1;
				cout << itr->first << " +1"<<"\n\n";
			}


			break;

	}
	day += 1;
	willpower -= 1;

	cout << "Willpower -1\n";
	cout << "The day is over\n\n";
	enter_continue();
}
//we have a growing monkey as a monster to as a defender of the forest, this function counts the monkey's abilities and increase the abilities 
void tony::hunting(  ){
		
	int monkey_attack = 1 + hunting_num/2;
        int monkey_health = 1 + hunting_num;

	while (monkey_health > 0){

	int choise = 999;
	cout << "\n\n\n\n\n\n\n\n\n";
	
	cout << "Tony encounters a monkey" << endl << endl;

	cout<<"      .=\"=.  \n";
	cout<<"    _/ ^.^ \\_   < COME ON!  \n";
	cout<<"   ( ( oYo ) )    ))   \n";
	cout<<"////|/  \"  \\|    //\n";
	cout<<"|||| \\'\\_/'/    //\n";
	cout<<"\\  ; /`\"\"\"`\\\\  ((\n";
	cout<<" \\ \\/ /_,_\\ \\\\  \\\\\n";
	cout<<"  \\__/_\\_'__/ \\  ))\n";
	cout<<"    /`\\  /`~\\  |//\n";
	cout<<"   / /  /    \\  /\n";
	cout<<",--`,--'\\/\\    /\n";
	cout<<" '-- \"--'  '--'\n\n";
	
	cout  << Red << left << setw(25) << "Health value of monkey: ";
        for (int i = 0; i < monkey_health; i++)
                cout << HEART << " ";
        cout << "(" << monkey_health << ")" << endl;

        cout << BLUE << left << setw(25) << "Attack power: ";
        for (int i = 0; i < monkey_attack; i++)
                cout << DIAMOND << " ";
        cout << "(" << monkey_attack  << ")" << endl;

	show_state();
	
	cout << "Please enter yor choise:\n\n1)Fight\n2)Run\n\n";
	cin >> choise;
	if (choise == 1){
		monkey_health -= attack_power;
		if (defense != 0){
			defense -= monkey_attack;
			if (defense < monkey_attack){
				health += defense;
				defense = 0;
			}
		}
		else
			health -= monkey_attack;
	}
		
	else if (choise == 2){	
		enter_continue();
		break;
	}
	else
		cout << "Wrong demand!\n";
	
	if (health <= 0)
		break;
	if (monkey_health <= 0){
		hunting_num++;
		cout << "Tony won and succeeded in driving the monkey away\n\nThe monkey becomes stronger\n\nWhen Tony beat the monkey next time, he will get more willpower\n\n";
		int addwill = 3 + hunting_num;
		willpower += addwill;
		cout << "Willpower +" << addwill <<"\n\n";
		enter_continue();
	}	
	}
}
//this function is listed in every-day option that allow user to create the tools by calling map iteration
void tony::create(  ){
	int choise;
	cout << endl;
	cout << "Tony's items:\n";
	cout << "Stone: " << user_tools["stone"] << endl;
	cout << "Thread: " << user_tools["thread"] << endl;
	cout << "Wood: " << user_tools["wood"] << endl;
	cout << "Board: " << user_tools["board"] << endl << endl;

	cout << "1) Spear - material requirements: 1 stone, 3 woods and 2 threads\n\n"; 
	cout << "2) Dagger - material requirements: 1 stone, 1 wood and 1 thread\n\n";
	cout << "3) Shield - material requirements: 1 board, 3 wood and 2 thread\n\n";
	cout << "4) Leave\n\n";
	cout << "============= Please enter your choise ============\n";
	cin >> choise;
	
	if ( choise != 4){
	for (int i = 0; i < tools.size(); i++){
		if (tools[i].tool_num == choise){
			cout << BOLDGREEN << "Required materials for creating a " << tools[i].name << ":\n"; 
			if(enough_material(user_tools, tools[i].material)){
				make_tool(user_tools, tools[i].material);

				if (choise == 3){
					defense += tools[i].tool_attack;
					cout << Red << "\nDefense +"<<tools[i].tool_attack<< endl;
				}
				else{
					attack_power += tools[i].tool_attack;
					cout << Red << "\nAttack power +"<<tools[i].tool_attack<< endl;
				}
				willpower += 2;
				cout << Red <<"\nWillpower +2\n";
				cout <<"\nA "<< tools[i].name <<" is created successfully and Tony's state is updated!\n\n";
			}
			else
				cout << RESET <<"\nYou does not have enough materials to create a " <<tools[i].name << "\n\n";
		
		
		}

	}
	enter_continue();
	}
	else
		cout << "\n\n\n\n\n\n\n\n\n\n";
}
//this ever-day option is most important to determine the vitory of the game, we use random variable to generate fortunate dice value then affect the the walking step
void tony::move(){

	srand( time(0) );
	
	int bad_weather = rand() % 10;

	int step;

	switch (bad_weather){
		case 0:
			cout << BLUE << "\nBad weather is coming, we can't move forward today!\n";
			willpower -= 5;
			day += 1;
			
			cout << "Willpower -5\n";
			cout << "The day is over\n\n";

			enter_continue();
			break;

		case 1:
			step = dice(6);
			cout <<  BLUE <<"\nYou have thrown a dice and get a " << step;
			cout << "\n\nHowever, the heavy rain made it difficult for Tony to walk.\nTony took "<< step/2 <<" steps forward.\n";
			willpower -= 3;
			day += 1;
			position += step/2;

			cout << "Willpower -3\n";
			cout << "The day is over\n\n";

			enter_continue();

			break;

		default:
			step = dice(6);
			cout <<  BLUE <<"\nYou have thrown a dice and get a " << step << "\n\nTony took "<< step <<" steps forward.\n";
			position += step;
			willpower -= 1;
			day += 1;
			
			cout << "Willpower -1\n";
			cout << "The day is over\n\n";

			enter_continue();
			break;
	}
}
// to check the status, if the health and willpwoer condtion is failed, then game over, if not, and the character finish the position checking, means he got home
bool tony::update_state(){

	if ( willpower <= 0 ){
		willpower = 0;
		health -= 1;
	}

	if ((health <= 0)||(day>=30)){
		cout << BOLDRED;
		cout << "Tony is dead!\n\n";
		cout <<"                   /////////                \n";
		cout <<"                  |||||||||||               \n";
		cout <<"     _            |  _   _  |           _   \n";
		cout <<"    ( \\           |         |          / )  \n";
		cout <<"     > \"=._       |  X/ \\X  |      _.=\" <   \n";
		cout <<"    (_/\"=._\"=._   |         |  _.=\"_.=\"\\_)  \n";
		cout <<"           \"=._\"-_|    U    |_\"_.=\"         \n";
		cout <<"               \"=_ _|IIIII|__ =\"            \n";
		cout <<"              _.=\"| \\IIIII/ |\"=._           \n";
		cout <<"    _     _.=\"_.=\" \\       /\"=._\"=._     _  \n";
		cout <<"   ( \\_.=\"_.=\"      `-----`     \"=._\"=._/ ) \n";
		cout <<"    > _.=\"                          \"=._ <  \n";
		cout <<"   (_/                                  \\_) \n\n";
		cout << RESET;
		
		enter_continue();
		return false;
	}


	if (position >= 40){
		cout << "Congratulations!Tony finally found his home!\n\n";
		cout <<"                           (   )\n";
		cout <<"                           (    )\n";
		cout <<"                            (    )\n";
		cout <<"                           (    )\n";
		cout <<"                             )  )\n";
		cout <<"                            (  (                  /\\\n";
		cout <<"                             (_)                 /  \\  /\\\n";
		cout <<"                     ________[_]________      /\\/    \\/  \\\n";
		cout <<"            /\\      /\\        ______    \\    /   /\\/\\  /\\/\\\n";
		cout <<"           /  \\    //_\\       \\    /\\    \\  /\\/\\/    \\/    \\\n";
		cout <<"    /\\    / /\\/\\  //___\\       \\__/  \\    \\/\\\n";
		cout <<"   /  \\  /\\/    \\//_____\\       \\ |[]|     \\\n";
		cout <<"  /\\/\\/\\/       //_______\\       \\|__|      \\\n";
		cout <<" /      \\      /XXXXXXXXXX\\                  \\\n";
		cout <<"         \\    /_I_II  I__I_\\__________________\\\n";
		cout <<"                I_I|  I__I_____[]_|_[]_____I\n";
		cout <<"                I_II  I__I_____[]_|_[]_____I\n";
		cout <<"                I II__I  I     XXXXXXX     I\n";
		cout <<"             ~~~~~\"   \"~~~~~~~~~~~~~~~~~~~~~~~~\n";
		return false;

	}
	return true;
}
// print the rule
void tony::Map(){
cout<<"You are going to exit this forest, in order to win this game,"<<endl<<"you should go hunting and go exploring to keep your 'will power'and 'health' stay in a healthy way."<<endl;
cout<<"In the 'Create tools' option, can make your own weapon to prevent the risk of facing some unbeatable animal."<<endl;
cout<<"Tony's bag already has some initial material, but it still unable to create a tool, therefore you should 'go exploring'.";
cout<<"Every-day option has potential risk to lead the character going to a irreversible situations,"<<endl<<"you can create your own waapon prepare for the situation. "<<endl<<"If your will power unfortunately became 0, in the following steps, your health will deduct 1 every day"<<endl<<"If your willpower and health condition is normal, once you go to the right position, you can exit the forest and then win."<<endl;
enter_continue();
}
