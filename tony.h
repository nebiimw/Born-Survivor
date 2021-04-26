#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Tool{
 
          int tool_num;
	
	  int tool_attack;

          string name;
  
          map<string, int> material;
 	
 };
        
struct Animal{
	
	int num;
	
	int attack;
	
	int health;

};



class tony{
	
public:
	
	int health;

	int attack_power;

	int willpower;

	int defense;
	
	int position;
	
	int day;

	map<string, int> user_tools;

	bool load_the_saving( string name );

	void new_story( string name );

	void save_the_game();

	string username;

	void enter_continue();

	void show_state();

	void show_choice();
  
        void explore();
	
	void hunting();
        
	void create();

        void move();
 
        void Map();

	bool update_state();
	
	bool enough_material(map<string,int> user, map<string, int> base);

	void make_tool(map<string,int> &user, map<string, int> base);

	void tools_base();
	vector<Tool> tools;

	int dice(int num);

	int hunting_num;

};

