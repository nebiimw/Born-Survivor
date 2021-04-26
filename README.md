# COMP2113-ENGG1340-Group Project
# Project Name: Born Survivor

# Group member:
	
1. Chung Ching Long 3035641516
2. Wong Yung Kwan 3035706067

## Game Description:
Born survivor is a text-based fortress adventure RPG(role-playing game). In the beginning of this game, the main character who called Tony gets lost in a fortress which is full of crisis. The player is going to help Tony escape the inexperienced area. Every day, the player ought to make the right decisions to stay in healthy condition. If some decision is made wrongly, it potentially leads the character to face some dangerous situations, for example eating poisonous food and a beast! If you are lucky enough, come and help misfortune Tony!
	

## Instruction 


*	Firstly, you need to create or login your account.
*	On the home page, the player can see the body conditions of the character. 
	*	Health value: It is a player-specific feature that represents the physical health condition of Tony and regulates Tony’s certain abilities. If the hunger value is below a certain level, it may cause unexpected events that hinder the player's escape plan and even worse death occurs when Tony's health is depleted. However, this value can be managed by the player's activity that means the player should make the right decisions to keep the value in a good state.               						
	*	Willpower: This value represents the mental health condition of Tony which will affect the health value if the mental value is at a low level. Every time a day passes or some special events like a storm occur, the value will decrease. 
*	Every morning, the player can decide what Tony should do during the day until Tony has successfully escaped the forest and the game is completed.
	*	Option 1: Explore the place (find some foods or useful materials.)
	*	Option 2: Go hunting (beat the naugty monkey to recover the willpower)
	*	Option 3: Create tools (make some weapons or shield by using the materials collected in option 1.)
	*	Option 4: Move forward (ranomly move forward and unexpected events may happen to hinder the player's escape plan)
*	Players will be given the option to exit the game and save his progress on the home page.
 
## List of features
*	Dynamic memory management:
	*	To store the player’s username and his playing progress using dynamic memory manipulation in files.
	*	To store the tool's create method using dynamic memory manipulation in files.
*	Data structures for storing game status:
	*	To create a class() function to initialize the basic information of Tony. 
	*	To utilize integer array, struct, class, STL containers and pointer to save the game progress.
	*	Different tools need different materials to created which stored in a struct with vector.
*	File input/output:
	*	Files shall be used to store the player's game progress and output it in txt files.
	*	File userdata_base is used to store different user's username and their password.
*	Program codes in multiple files:
	*	Main.cpp includes major functions like allowing players to decide what Tony to do in the next step.
	*	Main.cpp can keep showing Tony’s health value, attack power, defense level and willpower.
	*	Main.cpp will have different files like decision.h, tony.h and so on.
*	Generation of random game sets or events: 
	*	Outcomes of random draw of dice determine various events of the game that Tony will encounter and various materials that Tony can find to make different tools.
 
 



