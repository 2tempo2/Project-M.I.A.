#include <iostream>
#include <thread>//still dont understand this deep enough
#include <chrono>
#include "Text_Color.h"
#include "M.I.A_Animation.h"


using std::string;
using std::cout;
using std::endl;

class ITEM {
protected:
	string item_name;
	int healthMod;
	int dmgMod;
public:
	ITEM(string n, int h, int d) : item_name(n), healthMod(h), dmgMod(d) {};
	ITEM() : item_name("Default item name"), healthMod(0), dmgMod(0) {};
	
	void itemDetails() const {
		cout << "Item Name: " << item_name << endl;
		cout << "Damage Modifier: " << dmgMod << endl;
		cout << "Health Modifier: " << healthMod << endl;
	}

	int Mods(char mod) const {//note: return value is int, so the parameters expect a char for the switch statement and an integer over all. health and dmg mod are integers, so it always gets one back
		switch (mod) {
		case 'h':
			return healthMod;
			break;
		case 'd':
			return dmgMod;
			break;
		default: return 0;
		}
	}//Returns item modifiers for use
};


class INVENTORY {
protected:
	ITEM item_1;
	ITEM item_2;
	ITEM item_3;
	int count_1;
	int count_2;
	int count_3;
public:
	INVENTORY(ITEM(), ITEM(), ITEM(), int c1, int c2, int c3) :
		item_1(ITEM()), item_2(ITEM()), item_3(ITEM()), count_1(c1), count_2(c2), count_3(c3) {};
	INVENTORY() :
		item_1("Item slot 1 is empty...", 0, 0), 
		item_2("Item slot 2 is empty...", 0, 0),
		item_3("Item slot 3 is empty...", 0, 0),
		count_1(0),
		count_2(0),
		count_3(0) {};

	//put an item in a specific slot
	void SlotItem(ITEM item, int slot) {
		switch (slot) {
		case 1: item_1 = item;
			break;
		case 2: item_2 = item; 
			break;
		case 3: item_3 = item;
			break;
		}
}
	//view what's in an item slot
	void SeeItemSlot(int slot) const {
		switch (slot) {
		case 1:
			cout << "Item Slot 1:" << endl;
			item_1.itemDetails();
			break;
		case 2:
			cout << "Item Slot 2:" << endl;
			item_2.itemDetails();
			break;
		case 3:
			cout << "Item Slot 3:" << endl;
			item_3.itemDetails();
			break;
		}
	}
	

};


class PERSON : public INVENTORY {
protected:
	string name;
	string codename;
	string safeword;
	string weapon;
	int health;
	int damage;

public:
	PERSON(string n, string c, string w, string s, int h, int d) : INVENTORY(), name(n), codename(c), safeword(s), weapon(w), health(h), damage(d) {};
	PERSON() : INVENTORY(), name("Default name"), codename("Default codename"), safeword("Default safeword"), weapon("Fists"), health(100), damage(15) {};



	void attack(PERSON*attacker, PERSON*target) {
		target->health -= attacker->damage;
		cout << "Using " << weapon << ", " << attacker->name << " dealt " << damage << " damage.";
	}

	void addItem(ITEM item, int count, int slot) {
		
		switch (slot) {
		case 1:
			item_1 = item;
			count_1 = count;
			break;
		case 2:
			item_2 = item;
			count_1 = count;
			break;
		case 3:
			item_3 = item;
			count_1 = count;
			break;
		default:
			cout << "addItem Error: incorrect slot.";
			break;
		}


	}
	void useItem(int slot) {
		switch (slot) {
		case 1:
			if (count_1 > 0) {
			health += item_1.Mods('h');
			damage += item_1.Mods('d');
			count_1--;
			}
			else { cout << "Nothing in this item slot."; }
			break;
		case 2:
			if(count_2 > 0) {
			health += item_2.Mods('h');
			damage += item_2.Mods('d');
			count_2--;
			}
			else { cout << "Nothing in this item slot."; }
			break;
		case 3:
			if(count_3 > 0){
			health += item_3.Mods('h');
			damage += item_3.Mods('d');
			count_3--;
			}
			else { cout << "Nothing in this item slot."; }
			break;
		default:
			cout << "Item slot error!";
			break;
		}
		
	}

	void seeGist() const{//for debugging
		cout << "The Gist of: " << name << endl;
		cout << "Health: " << health << endl;
		cout << "Damage: " << damage << endl;
	}
	void seeStats() const {
		cout << "\n\n\n\n";
		cout << "Name: " << name << endl;
		cout << "Codename: " << codename << endl;
		cout << "Safeword: " << safeword << endl;
		cout << "Health: " << health << endl;
		cout << "Weapon: " << weapon << " (" << damage<< " dmg)" << endl << endl;
		cout << "Inventory- " << endl;
		SeeItemSlot(1);
		SeeItemSlot(2);
		SeeItemSlot(3);
		cout << "\n\n\n";
	}

	
	void setHealth(int newHealth) {
		health = newHealth;
	}
	void setName() {
		std::cin >> name;
	}
	string returnName() const{
		return name; 
	}
	void getName() const {
		cout << name;
	}
	string returnCodename() const {
		return codename;
	}
	void setCodename() {
		std::cin >> codename;
	}
	void getCodename() const{
		cout << codename;
	}
	string returnSafeword() {
		return safeword;
	}
	void setSafeword() {
		std::cin >> safeword;
	}
	void getSafeword() const{
		cout << safeword; 
	}



	//make setWeapon for pickup
	//alternative--- make weapon items
};

void randomize(int &num, int min, int max);
void printDelay(const std::string text, std::chrono::milliseconds delay);
void smallWait(const std::chrono::milliseconds delay);

//paths
void secretWait(char wake, int impatience, bool fight, bool specials[], string text, std::chrono::milliseconds wait, std::chrono::milliseconds fast, std::chrono::milliseconds slow, std::chrono::milliseconds normal); 
void safewordPath(PERSON player, std::chrono::milliseconds slow, std::chrono::milliseconds normal, string text, int &choice, int chance);
bool lostInSnow(int &chance, std::string text, std::chrono::milliseconds normal, std::chrono::milliseconds fast, std::chrono::milliseconds halfWait);

int main() {
	int attempt{ 0 };
	int round{ 0 };
	int impatience{ 0 };
	int chance{ 0 };
	char skip = 'D';//skip intro 
	char wake = 'N';
	bool specials[5]{ false };//trackers for special interactions (either  
	//bool conversation = false; 
	bool fight = false;
	bool lost; // tracks if player got lost in snow
	std::string text; //text to be delayed	
	std::chrono::milliseconds wait(1000); //1 second delay
	std::chrono::milliseconds halfWait(500); //0.5s delay
	std::chrono::milliseconds slow(300); //0.3s delay 
	std::chrono::milliseconds normal(100); //.1 second delay
	std::chrono::milliseconds fast(50); //.05 second delay

	

	/*
	specials-
	0- knowledge of mission                
	1- knowledge of codename				//unused
	2- knowledge of real name				//unused
	3- thinks player is crazy (if safeword was used all 3 times in chapter 1)	//unused
	4- player got secret ending (the long wait)
	5- //unused
	*/


	PERSON lazlo("Lazlo", "Adder", "lazlos safeword", "Boot Knife", 75, 35);//guy at campfire//code name is reference to european adder, snake that lives in cold
	PERSON player;
	player.setHealth(54); //injured start for player
	//INVENTORY P_Inventory;//player inventory(might me unnecessary)

	ITEM soju("Soju (alcohol)", -5, 20);
	ITEM beans("Canned Beans", 25, 0);


	//INTRO

	//cout << "skip intro?: ";


	

	text = "\n\n'That's only if the snow doesn't cover everything first.'"; printDelay(text, fast); smallWait(halfWait);
	text = "\n'Watch...'"; printDelay(text, fast); smallWait(wait);
	cout << bright_black;
	text = "\n\n*the agent pulls out a boot knife and places it on the snow*"; printDelay(text, fast); smallWait(halfWait);
	text = "\n*specks of snow quickly begin covering the knife*"; printDelay(text, fast); smallWait(halfWait);
	cout << reset_color;
	text = "\n\n'We have to get there before our heli vanishes.'\n\n"; printDelay(text, fast); smallWait(halfWait);

	cout << "(1) 'You think an entire helicopter will vanish? It's huge!'\n(2) ''\n\n";

	system("pause");


 //animation();





	//std::cin >> skip; std::toupper(skip);
	//sounds: tap on microphone -- usa anthem -- reversed talking
	//system("cls");
	skip = 'N';
	if (skip == 'N') {

		for (int x = 0; x < 3; x++) {
			cout << "Loading"; text = "..."; printDelay(text, fast);
			smallWait(halfWait);
			system("cls");

		}


		cout << "TELL THEM NOTHING";
		smallWait(fast);
		system("cls");


		


		cout << "'Welcome!'\n'Welcome to the\n\n";

		cout << " :::=====    :::    :::====\n";  
		cout << " :::         :::    :::  ===\n";
		cout << " ===         ===    ========\n";
		cout << " ===         ===    ===  ===\n";
		cout << "  ======= == === == ===  === ==\n";

		cout << "\nSecret Operations Initiation!'\n";
		cout << "'It's a pleasure to be working with you all, but first things first.'\n";
		cout << "'We need you to fill out some information about yourself.'\n";
		cout << "'You will be given new identities.'\n";
		cout << "'We wouldn't want to forget the real you, would we?'\n";
		//enter game info

		cout << "\n\nEnter real name: "; player.setName();
		cout << "\n\nEnter  codename: "; player.setCodename();
		cout << "\n\nEnter  safeword (for emergencies): "; player.setSafeword();
		cout << "\n\nWith that out of the way, you will soon get a letter with all the details needed.";
		cout << "\nWe are not taking questions at this time, goodnight.";

		system("cls");


		//mission screen
		text = "\n**1 week later**\n\n\n"; printDelay(text, normal);
		smallWait(normal * 5);

		cout << "  ___________" << endl;
		cout << " |\\   -o-   /|" << endl;
		cout << " | \\_______/ |" << endl;
		cout << " |           |" << endl;
		cout << " |           |" << endl;
		cout << " |   C.I.A.  |" << endl;
		cout << " |           |" << endl;
		cout << " |           |" << endl;
		cout << " |___________|" << endl;

		cout << "\n\n\n";
		smallWait(wait);

		//make the letter ascii snap in but all mission details delay
		text = "Mission: \nWe've received threats from a terrorist group, located on the top of  Lunag Ri  mountain.\n"; printDelay(text, fast);
		text = "Five of you will be sent by helicopter early tomorrow morning.\n"; printDelay(text, fast);
		text = "Your task is to see if they pose any actual danger.\n\n"; printDelay(text, fast);
		text = "Your new identity-\n\n"; printDelay(text, fast);
		text = "Agent Name: "; printDelay(text, fast); player.getCodename();
		text = "\nSafeword: "; printDelay(text, fast); player.getSafeword(); cout << endl;
		smallWait(halfWait);
		text = "\nThe contents of this letter must remain a complete secret.\n\n"; printDelay(text, normal);
		smallWait(halfWait);

		//Wake up
		cout << "\nWake up? (y/n): ";//delay
		
		while (wake == 'N') {
			std::cin >> wake;
			wake = std::toupper(wake);
			switch (wake) {
			case 'Y':
				break;
			case 'N':
				cout << "\n\n....\nWake up?: "; //delay
				break;
			default:
				wake = 'N';
				break;
			}
		}
	};
	system("cls");


	//campfire ascii

	text = "\n\nYou hear the distant pop of a single gunshot."; printDelay(text, fast);
	smallWait(wait);
	text = "\nYou wake up with a pounding headache.\nSnow whips around in the air.\nYou see an agent tending to a campfire.\n"; printDelay(text, fast);

	cout << "\n\n(1) 'Are we already on the mountain?'\n(2) 'What happened?'\n(3) 'My f*cking head!'\n(4)  Attack the agent.\n\n";



	//First Dialogue
	//campfire sound through whole first chapter
	int choice = 0;


	std::cin >> choice;
	switch (choice) {
	case 1:// from "Are we already on the mountain?"
		cout << "\n'That's for damn sure.'\n'Looks like we're gonna be here for a while too...'\n";

		cout << "\n\n(1) 'What makes you say that?'\n(2) 'Why am I bleeding?'\n(3) '"; player.getSafeword(); cout << "!'\n\n";
		//3 should be his fake new obj that leads toward the heli



		std::cin >> choice;

		if ((choice ==1)||(choice == 2)) { cout << "\n'You don't remember?'"; };
		
		switch (choice) { 
		case 1: //from "what makes you say that?"
			cout << "\n'Our helicopter couldn't hold up against the weather.'\n'So we're stranded...'\n'You still remember the mission?'\n\n"
				<< "\n(1) 'No, can you remind me?'\n(2) 'Yes, we still need to find the terrorist camp on this mountain.'"
				<< "\n(3) 'Didn't we have a squad? Why are we alone?'\n(4) 'I don't even know who you are...'\n\n";



			std::cin >> choice; 
			switch (choice) {
			case 1://from "No, can you remind me?"

				choice = 10;

				break;


			case 2://from "Yes, we still need to find the terrorist camp on this mountain."

				//looks impressed, doesnt lie here

				break;


			case 3://from "Didn't we have a squad? Why are we alone?'"
				cout << "\n\n'You were the only person I saw after the crash.'\n'It doesn't change our orders though.'\n'We should check the crash site for more survivors...'\n"
					<< "\n\n(1) 'Let's go check.'\n(2) 'Everyone is dead and we're just supposed to continue?'\n\n";

				std::cin >> choice;
				switch (choice) {
				case 1: //from "Let's go check"

					randomize(chance, 1, 2);

					if (chance == 1) {
						smallWait(wait);
						text = "\n'By the way,'"; printDelay(text, normal);
						smallWait(slow);
						choice = 15;
						chance = 0;
						break;

					}
					break;
				case 2: //from "Everyone is dead and we're just supposed to continue?"
					cout << "\n\n'Well, no. That's why we're checking for survivors.'\n'But still, we need to complete the mission.'\n\n"
						<< "\n(1) 'Fair point.'\n(2) 'We just fell out of the sky. I want to go home.'\n\n";

					std::cin >> choice; 
					switch (choice) {
					case 1: //from "Fair point"

						randomize(chance, 1, 3);
						if (chance == 3) { text = "*the agent is holding back a grin*"; printDelay(text, fast); }
						smallWait(wait);

						break;
					case 2: //from "We just fell out of the sky, i want to go home."
						text = "\n\n'Compose yourself agent.'\n"; printDelay(text, normal); smallWait(wait);
						text = "'You "; printDelay(text, normal); smallWait(halfWait); 
						text = "are"; printDelay(text, slow); smallWait(halfWait);
						text = " home.'\n"; printDelay(text, normal);
						text = "'Let's go look for our guys...'\n"; printDelay(text, normal);
						cout << "\n\n(1) *sigh* 'Alright, let's do this.'\n(2) ''\n(3) 'I think I need a second...'\n";

						std::cin >> choice;
						switch (choice) {
						case 1:
							break;
						case 2:
							break;
						case 3:
							wake = 'N';
							secretWait(wake, impatience, fight, specials, text, wait, fast, slow, normal);
							break;
						default:
							break;
						}

						break;
					default:
						break;
					}


					break;
				default:
					break;
				}

					//responses (1) (2) (3) well, no. that why we're checking for survivors. but still, we need complete the mission.
					//response responses (3) i want to go home -> compose yourself agent. you (are[delay]) home.
				break;


			case 4://from "I don't even know who you are..."
				choice = 10;
				break;


			default:
				break;
			}break;
			




		case 2: //from "why am i bleeding"
			cout << "\n'Our helicopter crashed, you must've hit your head on the way down...'\n'There might've be some bandages in the helicopter\n'We should see what's left.'\n"
				<< "\n(1) 'Good thinking, lets go check.'\n(2) *touch blood* 'Holy shit, I might pass out.'\n(3) 'I need a second...'\n\n"; //lazlo will get impatient with 1 sec wait
				
			std::cin >> choice;
	
			switch (choice) {
			case 1: //from "Good thinking, lets go check."

				randomize(chance, 1, 2); //50-50 chance

				if (chance == 1) {
					smallWait(wait);
					text = "\n'By the way,'"; printDelay(text, normal);
					smallWait(slow);
					choice = 15;
					chance = 0;
					break;
				}

				break;



			case 2: //from "Holy shit I might pass out."

				cout << "\n\n'Here.'\n*he holds out a bottle of liquor*\n'This might help.'\n"
					<< "\n\n(1) *take bottle* 'Thank you'\n(2) *take bottle* 'What now?'\n(3) 'No thanks.'\n(4) 'Alcohol wouldn't help right now...'\n\n";

				std::cin >> choice;
					
				if ((choice == 1) || (choice == 2)) { player.addItem(soju, 1, 1); } 

				switch (choice) {
				case 1: //from "*take bottle* Thank you"
					cout << "\n\nLet's go look for some bandages where we crashed.\n"
						<< "\n\n(1) *drink* 'Ok, let's go check.'\n(2) *drink* 'I still need a sec...'\n(3) 'Ok, let's go check.'\n(4) 'I still need a sec...'\n\n";
					
					std::cin >> choice;

					switch (choice) {

					case 1: // *drink * 'Ok, let's go check.'
						player.useItem(1);
						text = "\n\n*gulp*"; printDelay(text, fast); smallWait(wait);

						// move to chapter 2

						break;

					case 2: // *drink* 'I still need a sec...'
						player.useItem(1);
						text = "\n\n*gulp*"; printDelay(text, fast); smallWait(wait);

						secretWait(wake, impatience, fight, specials, text, wait, fast, slow, normal);
						break;

					case 3: // Ok, let's go check.
						text = "\n\n'Alright.'"; printDelay(text, normal);

						// move to chapter 2

						break;

					case 4: // I still need a sec...
						secretWait(wake, impatience, fight, specials, text, wait, fast, slow, normal);
						break;
					}


					break;
				case 2: //from "*take bottle* What now?"
					cout << "\n\n'Now we must move to the helicopter.' \n'As soon as possible.'";

					cout << "\n\n(1) 'Ok.' *go to helicopter*\n(2) 'What's the rush?'\n\n";

					std::cin >> choice; 
					switch (choice) {

					case 1: // Ok 
						// move to chapter 2
						break;
					case 2: // Whats the rush?
						text = "\n\n'You..."; printDelay(text, normal); smallWait(halfWait);
						text = "you don't look so good..'"; printDelay(text, normal); smallWait(halfWait);

						cout << "\n\n(1) *wipe blood off your lip* 'Good point.'\n\n";

						std::cin >> choice;

						switch (choice) {
						case 1:
							text = "\n\n*you and the agent walk into the blizzard side-by-side*"; printDelay(text, normal);
							// move to chapter 2
							break;

						default:
							cout << "invalid input, stopping game.";

							return 0;
						}
						break;
					}

					break;
				case 3: //from "No thanks"      (fall through to case 4)
				case 4: //from "Alcohol wouldn't help right now"


					break;
				default:
					break;
				}




					//it would be more canon if he only had alcohal at this time, fuck it decision made. beans are found later.
				break;



			case 3: //from "I need a second..."

				smallWait(wait * 2);
				wake = 'N';
				
				secretWait(wake, impatience, fight, specials, text, wait, fast, slow, normal);
				
				break;


			default:
				break;
			}break;



	



		case 3: //from "safeword!"
			
			safewordPath(player, slow, normal, text, choice, chance);//insert safewoed function
			break;
			
		default:
			break;

			//2 option should be we should get you checked out by the heli, there should be a medkit//(thinks your crazy? maybe thats where this is from?)



		}break;//break is here to stop "we crashed pretty bad" from displaying when "we should get you to the heli" displays

		//if you forget to add beans for any option without 






	case 2://from "What happened?" origin 
		cout << "\n'We crashed. Pretty bad too...'";
		cout << "\n\n(1) 'What do you mean, we crashed? We crashed the helicopter?!'\n(2) 'Hold up, rewind a bit further.'\n"
			<< "(3) 'That explains my headache...'\n(4) '"; player.getSafeword(); cout << "!'\n\n";
		//response to 3- *bottle* you probably need this more than will

		std::cin >> choice;
		switch (choice) { 
		case 1:// from "What do you mean, we crashed? We crashed the helicopter?!"
			text = "\n'Yup.'"; printDelay(text, fast); smallWait(normal); 
			cout << "\n'Our ride out of here is buried halfway into the snow right now...'\n'We should check if there are any supplies left from the crash.'\n\n";
			//std::cin >> choice;
			break;

		case 2: // from "Hold up, rewind a bit further."
			cout << "\n\n'The winds are too strong out here.'\n'We've spent the last 6 hours being swept around in the sky.'\n'Landing was impossible but we already spent too much time fighting the wind to go back.'\n'This whole operation was a bad idea.'\n"
				<< "\n\n(1) 'We still need to stop these guys.'\n(2) 'So we're stranded?' \n(3) 'Who planned this mission??'\n\n";

			std::cin >> choice;
			switch (choice) {
				cout << "\n\n\n";

			case 1: //from "We still need to stop these guys"

				cout << "Are you ready to go?\n\n"
					<< "\n(1) *get up* 'Yea, lets get moving.'\n(2) Before we go, what's your name again?\n\n";
				std::cin >> choice;
				switch (choice) {
				case 1:
					//jump to chapter 2
					break;

				case 2:
					cout << "\n\nI'm "; lazlo.getCodename(); cout << ".\n";
					text = "'But since we almost died together\n"; printDelay(text, normal);
					cout << ", I don't mind telling you my real name is "; lazlo.getName(); cout << ".'\n";
					smallWait(wait); 
					cout << "'What about you?'\n\n";

					std::cin >> choice;
					//custom name trap


					break;

				default:
					break;
				}


				break;
			case 2: //from "So we're stranded?"
				cout << "\n\n'Yes, we're stranded.'\n'But we need to keep moving if we're gonna make it out of here.'\n\n";



				break;
			case 3: //from "Who planned this mission anyway??"

				text = "\n\n'It was one of the suits, I don't know who...'\n'It doesn't matter.'\n'We're stuck here and we need to focus.'\n'We need to get to the crash site see what's left.'\n\n"; printDelay(text, normal);
				cout << "\n(1) 'This is ridiculous.'\n(2) 'Alright, lets just do it.'\n\n";
				std::cin >> choice; 
				switch (choice) {
					cout << "\n\n";
				case 1: // from "this is ridiculous"
					
					text = "\nYou don't believe me?"; printDelay(text, normal);
					smallWait(wait);
					cout << "\n\n\n(1) 'I believe you, I just don't want to be stuck on a mountain.'\n(2) 'I think your full of it.'\n(3) 'I'm not sure.'\n\n\n";
					std::cin >> choice;

					switch (choice) {
						cout << "\n\n\n";
						
					case 1: // from " I believe you, i dont want to be stuck on a mountain"
						
						text = "'Ok"; printDelay(text, slow); smallWait(halfWait); text = ", good.'"; printDelay(text, fast); 
						smallWait(wait);
						cout << endl;
						text = "'Let's leave...'"; printDelay(text, fast);
						smallWait(wait);
						

						break;
					case 2: // from "I think you're full of it"
						text = "*the agent stands up*"; printDelay(text, fast);
						smallWait(halfWait);
						text = "\n'Who do you think I am?'\n"; printDelay(text, normal);
						smallWait(halfWait);
						cout << "\n\n(1) You're my partner.\n\n(2) You're my target.\n\n";

						std::cin >> choice;

						switch (choice) {
							cout << "\n\n\n";
						case 1: // from "You're my partner."
							text = "*the agent begins laughing then sits back down*"; printDelay(text, normal);
							smallWait(halfWait);
							text = "Alright then, it's settled! \nLets leave for the crash site."; printDelay(text, normal);
							smallWait(wait);

							break;

						case 2: // from "You're my target."
							text = "*the agent slowly kneels down and pulls up his pants by the ankle*"; printDelay(text, fast);
							smallWait(halfWait);
							text = "\n*he shows you a boot knife*"; printDelay(text, fast);
							smallWait(wait);
							cout << "\n\n" << bright_red;
							text = "'You know, "; printDelay(text, fast); 
							cout << reset_color;
							smallWait(halfWait);
							text = "I have no respect for you "; printDelay(text, fast);
							smallWait(halfWait); 
							text = "or for your country."; printDelay(text, fast);
							smallWait(wait);
							cout << bright_red; 
							text = "\n\nBut you are pretty clever."; printDelay(text, normal);
							smallWait(wait);
							cout << reset_color;
							fight = true;

							break;
						}

						break;
					case 3: // from "I'm not sure"
						break;
					}



					break;
				case 2: // from "Alright, lets just do it."

					text = "\n\n*you and the agent stand up and walk into the blizzard*"; printDelay(text, fast); smallWait(wait);

					break;

				}

				break;

			}

			break;

		case 3: //from "That explains my headache"

			cout << "\n'You'll be alright.'\n'Do you remember our task?'\n\n"
				<< "\n(1) 'Yeah. We're here to spy on some terrorists.'\n(2) 'Yes, and we should get a move on...'\n(3) 'I dont remember, can you remind me?'\n(4) 'I don't even know who you are...'\n\n"; //i dont even know who you are
			std::cin >> choice;
			switch (choice) {
				
			case 1: // from "Yeah. We're here to spy on some terrorists"
				specials[0] = true; //mission knowledge

				cout << "\n\nHmm..."; smallWait(halfWait);
				text = " ... "; printDelay(text, normal); smallWait(halfWait);
				cout << "you seem fine, but we should still check out the crash to see what's left.\n";

				cout << "\n(1) 'Good thinking, let's go see.'\n(2) 'Ok..'\n(3) 'We should stick to the mission instead.'\n";

				cin >> choice;

				switch (choice) {
				case 1://from "good thinking, lets go see."
					//case 1 and 2 result are the same
				case 2:// from "ok"
					randomize(chance, 1, 2); //50-50 chance

					if (chance == 1) {
						smallWait(wait);
						text = "\n'Before we go,'"; printDelay(text, normal);
						smallWait(slow);
						choice = 15;
						chance = 0;
						break;
					}
					break;
				case 3: // from "we should stick to the mission instead."
					text = "\n\n'Our ride out of here is gone...'"; printDelay(text, normal); smallWait(halfWait);
					text = "\n'We need any supplies we can find right now.'"; printDelay(text, normal);

					cout << "\n\n(1) 'True, but we can look later.'\n(2) 'We have strict orders..'\n(3) 'Fair point. It's better to be stranded with supplies.'\n(4) 'That's fair, but let's be quick about it.'\n\n";

					cin >> choice;

					switch (choice) {
					case 1: // from "true, but we can look later"

						text = "\n\n'That's only if the snow doesn't cover everything first.'"; printDelay(text, fast); smallWait(halfWait);
						text = "\n'Watch...'"; printDelay(text, fast); smallWait(wait);
						cout << bright_black;
						text = "\n\n*the agent pulls out a boot knife and places it on the snow*"; printDelay(text, fast); smallWait(halfWait);
						text = "\n*specks of snow quickly begin covering the knife*"; printDelay(text, fast); smallWait(halfWait);
						cout << reset_color;
						text = "\n\n'We have to get there before our heli vanishes.'\n\n"; printDelay(text, fast); smallWait(halfWait);

						cout << "(1) 'You think an entire helicopter will vanish? It's huge!'\n(2) ''\n\n";


							// (1 response) - *the agent looks down at the knife again* *the knife is gone* *he dusts away the snow from where he placed it, revealing the knife* "The helicopter, the supplies, even our footsteps... they'll vanish out here."
							
						break;
					case 2: // from "we have strict orders"

						text = "\n\n'You must've misread something.'\n"; printDelay(text, normal); smallWait(slow*3);
						text = "'They made it clear...'\n"; printDelay(text, fast); smallWait(slow*2);
						cout << "\"";
						text = "Your life is your first priority. Spy until you find something and return to us alive."; patriotic_text(text);
						cout << "\"";
						text = "\n\n'You're injured. This helicopter is our last chance for supplies.'\n\n"; printDelay(text, fast); smallWait(wait);
						cout << "(1) 'I might've underestimated those supplies. Let's go find them.'\n(2) 'Well, now I'm not sure what to do.'\n(3) 'Are you lying to me right now?'";

						switch(choice){}




						//1 
						//2 i wont sit here for you to make up you mind, agent.  *he walks away*  (lost in snow)
						//3 *agents looks mildly surprised* oh, did you think i lied to you?
							//1 no
							//2 yes, and i still do
							//3 i didn't mean to insult you, i just don't remember that. 
								//look, agent, we need to go. now. whether you're concussed or 
							//4 (yellow) why word it like that?
								//because you can change your mind. (wait*2)
									//1 ...let's go get the supplies
									//2 why would i?
									//3 
									//4 *rush for the knife in the snow*


						break;
					case 3: // from "fair point. its better to be stranded with supplies"
						// case 3 and 4 are the same
					case 4: // from "that's fair, but lets be quick about it"

						text = "\n\n'I'm glad we agree.'\n"; printDelay(text, fast); smallWait(halfWait);
						text = "'Let's move...'\n\n"; printDelay(text, fast); smallWait(halfWait);

						break;
					}

					break;
				}
		
				break;
			case 2: // from "Yes, and we should get a move on"


				text = "\n\n'Very true.'"; printDelay(text, fast); smallWait(normal);
				cout << "\n'There might be some supplies left from the crash.\nWe should go check before continuing our mission.'\n\n"; smallWait(normal);

				cout << "(1) 'Good thinking. It could be worth a look.'\n(2) 'Everything is probably burned or destroyed. Let's just follow orders.'\n";

				cin >> choice;

				switch (choice) {
				case 1: // from "Good thinking. It could be worth a look."
					text = "\n\n*the agent stands up*"; printDelay(text, fast); smallWait(halfWait);
					text = "\n'Let's head out...'"; printDelay(text, fast); smallWait(halfWait);
					break;
				case 2: // from "Everything is probably burned or destroyed. Let's just follow orders."
					text = "\n\n'Do you even have your radio?'\n\n"; printDelay(text, fast); smallWait(wait);
					cout << "(1) 'No...'\n\n";

					choice = 0;
					attempt = 0;
					cin >> choice;

					while (choice != 1) {

						switch (choice) {
						case 1: // from "No"

							text = "\n\n'Right...'"; printDelay(text, fast); smallWait(halfWait);
							text = "\n'So look, "; printDelay(text, fast); smallWait(slow);
							text = "we don't know what's out there.'\n"; printDelay(text, fast); smallWait(slow);
							text = "'And if HQ doesn't know that we crashed, "; printDelay(text, fast); smallWait(slow);
							text = "we're f*cked...'\n"; printDelay(text, normal); smallWait(halfWait);
							text = "'Either way, we need to get back to the heli.'\n\n"; printDelay(text, fast); smallWait(halfWait);

							cout << "(1) 'When you put it like that...'\n(2) 'You've clearly had time to think about this.'\n\n"; 

							cin >> choice;

							switch (choice) {
							case 1: // from "When you put it like that..."

								text = "\n\n'So we're on the same page?'"; printDelay(text, fast); smallWait(halfWait);
								text = "\n'Good,"; printDelay(text, fast); smallWait(halfWait);
								text = " let's head out...'"; printDelay(text, fast); smallWait(halfWait);


								break;
							case 2: // from "You've clearly had time to think about this."

								// you were knocked out for quite a while. 

								break;
							}

							break;
						default:
							attempt += 1;
							if (attempt == 1) { cout << "\n\n*you check your vest and find nothing...*"; }
							if (attempt == 2) { cout << "\n\n*you check your belt and find nothing...*"; }
							if (attempt == 3) { cout << "\n\n*you do not have a radio*"; }
							if (attempt == 3) { cout << "\n\n(tip: enter '1' to say \"No, I don't have a radio\")"; }

							choice = 0;
						}

					}
					attempt = 0;
					break;
				}
	


				break;
			case 3: // from "I dont remember, can you remind me?"

				/*
				fake mission - 'activist group' has taken control of the mountain and cia is here to kill (what lazlo thinks of the cia)
				*/


				break;
			case 4: // from "i dont even know who you are"
				choice = 10;
				break;
			default:
				break;

			}
			
			

			break;
		case 4: //from "safeword!"

			safewordPath(player, slow, normal, text, choice, chance);


			break;

		default:
			break;
		}break;







	case 3://from "my fucking head!" origin
			cout << "\n'You're lucky to be alive...'\n"<<"*he holds out a bottle of liquor*\n";
			cout << "\n\n(1) *take bottle*  'Thank you.'\n(2) *take bottle*  'What's your name again?'\n"
				 << "(3) 'I'll be fine, gotta stay sharp.'\n(4) 'No thanks, who even are you?'\n\n";


			std::cin >> choice;

			if ((choice == 1) || (choice == 2)) { player.addItem(soju, 1, 1); }

			switch (choice) {//from "You're lucky to be alive - bottle"
			case 1://from "*take* Thank you"
				cout << "\n'Sure, sure.'\n'Can you walk?'\n\n"
					<< "\n(1) *drink* 'Let's move.'\n(2) *drink* 'Sir, yes sir!'\n(3) *keep bottle* 'Let's move'\n(4) *keep bottle* 'Sir, yes sir!'\n\n";
				std::cin >> choice;


				if ((choice == 1) || (choice == 2)) { player.useItem(1); }

				if ((choice == 2) || (choice == 4)) {
				text = "*the agent smirks,"; printDelay(text, normal); smallWait(slow);
				text = "then stands *"; printDelay(text, normal); smallWait(wait);
				}
				

				break;

			case 2:////from "*take* What's your name again?"

				choice = 15;

				break;



			case 3://from "I'll be fine, gotta stay sharp."


				cout << "\n\n'If you insist...'\n'We should still doublecheck the crash site to get you some meds.'\n"
					<< "\n(1) 'Good idea.'\n(2) 'Why?'\n(3) 'I'm fine. I don't need meds.'\n";
				std::cin >> choice;


				switch (choice) {
				case 1://from "Good idea"
					smallWait(slow);
					cout << "One more thing before we go,\n"; 
					smallWait(wait);


					break;


				case 2://from "Why?"



					break;


				case 3://from "I'm fine. I don't need meds"
					break;
				}break;




			case 4://from "No thanks, who even are you?"

				choice = 10;


				break;


			default:
				break;

			}break;
			
		
			


		case 4: //from "Attack the agent" origin
			fight = true;
			cout << "\nYou lunge at the agent.";
			break;
		default:
			choice = 0;
			std::cin >> choice;
			break;
		}
	//End of Dialogue 1


	//NameTrap 1
	if (choice == 10) { //from "Who even are you?" "I don't even know who you are."
		text = "\n\nYou dont remember?'\n"; printDelay(text, fast); smallWait(halfWait); text = "'Hm..'"; printDelay(text, normal); 
		smallWait(halfWait);
		cout << "\nDo you remember your name?\n\n";
		smallWait(halfWait);
		cout << "\n(1) *stay silent*\n(2) 'Yea, my name is "; player.getName(); 
		cout << "'\n(3) '...I go by "; player.getCodename(); cout << ".'\n(4) *lie* 'I honestly have no clue.'\n\n";
		//switch 4 player is of no use to lazlo if they have amnesia
		std::cin >> choice;

		switch (choice)
		{
		case 1: //from "*stay silent*"

			smallWait(wait);
			text = "\n\n'...'\n"; printDelay(text, slow);
			smallWait(halfWait);
			text = "\n*the agent leans forward*\n"; printDelay(text, normal);
			smallWait(halfWait);
			cout << "\n(1) *stay silent*\n(2) *sigh* 'Sorry, it's hard to trust out here. I'm "; player.getCodename(); cout << ".'\n(3) 'My name is "; player.getName(); cout << ".'\n(4) '"; player.getSafeword(); cout << "!'\n\n\n";
			std::cin >> choice;

			switch (choice) {
			case 1: // from "*stay silent*" x2
				text = "stay silent"; printDelay(text, slow);
				// unfinished, written in flowchart
				break;
			case 2: // from "Sorry, its hard to trust out here. I'm (codename)"
				specials[1] = true; //knowledge of codename
				text = "\n\n*the agent grins*\n'It's alright, "; printDelay(text, normal); text = player.returnCodename(); printDelay(text, slow); text = ".'"; printDelay(text, slow);
				smallWait(halfWait);
				text = "\n'Let's get going...'\n\n"; printDelay(text, normal);

				break;
			case 3:// from "my name is (name)"
				specials[2] = true; //knowledge of name
				text = "*the agent smirks*\n'Nice to meet you "; printDelay(text, normal); smallWait(halfWait); text = player.returnName(); printDelay(text, slow); text = ".'\n\n\n"; printDelay(text, normal);
				cout << "(1) 'Nice to meet you.'\n(2) 'I still haven't gotten your name.'\n\n";
				std::cin >> choice;

				switch (choice) {
					case 1: // from "Nice to meet you"
						break;
					case 2: // from "I still havent gotten your name"
						cout << "\n\n'I'm "; lazlo.getName(); cout << ", codenamed "; lazlo.getCodename(); cout << ".'\n\n\n"
							<< "(1) In case you need to know my codename, it's "; player.getCodename(); cout << ".'\n(2) 'Shouldn't we be headed somewhere?'\n\n";
						std::cin >> choice;

						switch (choice) {
						case 1: // from "In case you need to know my code name"
							text = "\n\n'Any chance you remember your safecode, or saveword?'"; printDelay(text, normal); 
							smallWait(halfWait);
							text = "\n'Whatever its called...'\n\n\n"; printDelay(text, normal);
							smallWait(halfWait);

							cout << "(1) 'Yeah, it's "; player.getSafeword(); cout << ",'\n(2) 'No, I don't.'\n\n\n";
							std::cin >> choice;

							switch (choice) {
							case 1: // from "Yeah, it's (safeword)"
								smallWait(wait);
								text = "*the agent presses a button on his radio*"; printDelay(text, normal); smallWait(halfWait);
								text = "\n'It's "; printDelay(text, normal); text = player.returnSafeword(); printDelay(text, normal); smallWait(wait);

								cout << "\n\n\n(1) "; //pick up here!!!!!!!!!

								break;
							case 2: //from "No, I dont"

								break;
							}
							


							break;
						case 2: // from "Shouldn't we be headed somewhere?"
							text = "Yes!"; printDelay(text, normal);
							smallWait(halfWait);
							text = "\n'If we're going to survive, we'll need supplies from the crash site.'\n\n"; 
							break;

						}


						break;
				}

				break;
			case 4: // from "(safeword)!"
				safewordPath(player, slow, normal, text, choice, chance);
				break;
			default:
				break;
			}break;


		case 2: //from "Yea, my name is..."
			specials[2] = true; //knowledge of name
			text = "\n'Good...'\n"; printDelay(text, slow); 
			text = "'It's good that you remember your name...'\n"; printDelay(text, fast);
			cout << "\n(1) 'Is there something wrong?'\n(2) 'Yup, feels great and all...'\n(3) 'Shouldn't we get going?'\n\n";
			std::cin >> choice;


			switch (choice) {
			case 1: // from "Is there something wrong?"

				break;
			case 2: // from "Yup, feels great and all"

				break;
			case 3: // from "Shouldn't we get going?"

				break;
			}
				
			break;


		case 3: //from "I go by Codename"
				//lazlo will twitch or move or something
			specials[1] = true;
			smallWait(wait);
			text = "\n\n'It's a pleasure to meet you "; printDelay(text, normal); text = player.returnCodename(); printDelay(text, normal); text = ".'\n\n\n"; printDelay(text, normal);
			smallWait(wait);
			cout << "(1) 'Nice to meet you too, agent.' \n(2) 'I still don't know your name.'\n\n";
			std::cin >> choice;

			switch (choice) {

			case 1: // from "Nice to meet you too, agent"
				break;
			case 2: // from "I still don't know your name"
				break;
			}


			break;


		case 4: //from "*lie* 'I honestly have no clue'"

			text = "\n\n'So you... "; printDelay(text, normal); smallWait(halfWait); text = "Ok.'\n"; printDelay(text, slow);
			smallWait(halfWait);
			text = "'You have no idea where you are, or why you are here?'\n"; printDelay(text, normal);
			cout << "\n\n(1) *lie* 'I'm completely lost right now.'\n(2) 'Well, I know we're on a mountain...'\n(3) '"; player.getSafeword(); cout << "!'\n\n";
			std::cin >> choice;

			switch (choice) {
			case 1: //from "*lie* Im completely lost right now"
				text = "\n\n*the agent blankly stares into the fire*\n"; printDelay(text, normal);
				smallWait(wait);
				text = "\n\n*he stands up and walks away, into the blizzard*\n\n\n"; printDelay(text, normal);
				smallWait(halfWait);
				choice = 20;// send to lazlo walking away


				break;
			case 2: //from "Well i know we're on a mountain"
				text = "*the agent sighs*\n"; printDelay(text, normal);
				smallWait(halfWait);
				text = "'Look, we just need to survive right now.'\n'To do that, we need supplies.'\n'We need to go to the helicopter and find supplies...'\n\n"; printDelay(text, fast);
				cout << "\n(1) 'Ok, alright. Let's head out.'\n(2) 'I'm still confused...'\n";
				std::cin >> choice;

				switch (choice) {

				case 1: // from "Ok, alright. Lets head out."
					smallWait(halfWait);
					text = "*the agent stands up*"; printDelay(text, normal);
					smallWait(halfWait);
					text = "*you follow the agent into the blizzard*"; printDelay(text, normal);
					smallWait(wait);
					break;


				case 2: // from "Im still confused"
					smallWait(halfWait);
					text = "\n\n\n*the agent stands up*"; printDelay(text, fast);
					smallWait(halfWait);
					text = "\n\n\n'You have nothing I need.'\n'Try not to freeze.'"; printDelay(text, fast);
					smallWait(halfWait);
					text = "\n*the agent walks into the blizzard*\n\n\n"; printDelay(text, normal);
					smallWait(halfWait);
					 
					choice = 20;

					break;

				default:
					break;
				}
				break;


			case 3: // from "safewprd!"
				safewordPath(player, slow, normal, text, choice, chance);
				break;
			default:
				break;
			}
			
			break;


		default:
			break;
		}
	};
	//nametrap 2
	if (choice == 15) { //from "What's your name?"
		cout << "\n'I'm "; lazlo.getCodename(); cout << ", but my real name is "; lazlo.getName(); 
		cout << ".'\n'You never actually introduced yourself..."

		   	 << "\n\n(1) *say nothing* \n(2) 'My name is "; player.getCodename();
		cout << "'\n(3) 'I'm "; player.getName(); cout << ", codename "; player.getCodename(); cout << ".'\n\n";
		
		std::cin >> choice;
		switch (choice) {


		case 1://from "*say nothing*"
			//(1) *poke fire* //*tiny flame ashes rise from the fire*(at the start of lazlos response)
			break;


		case 2://from "My name is Codename"
			specials[1] = true; //knowledge of codename
			break;


		case 3://from "My real name is ___, Codename ____"
			specials[1 && 2] = true; //knowledge of codename & real name

			break;


		}

	};
	//lazlo left, searching for the lost agent
	if (choice == 20) {
		cout << "(1) *follow the agent*\n(2) *stay by the fire*\n\n\n";

		std::cin >> choice;

		switch (choice) {
		case 1: //from "*follow the agent*"

			smallWait(wait);
			text = "\n\n\n'Go back.'"; printDelay(text, slow);
			smallWait(wait);
			cout << "\n\n\n(1) 'No.'\n(2) 'Where are you going?'\n(3) *go back to the fire*\n\n\n";
			std::cin >> choice;

			switch (choice) {
			case 1: // from "No."
				cout << "option 1 \n\n\n";//written in flowchart
				break;
			case 2: // from "Where are you going?"
				text = "\n\n\n'I've already told you.'\n\n\n"; printDelay(text, normal);
				smallWait(halfWait);
				cout << "(1) 'Why can't I go with you?' \n(2) 'I'm still confused.' \n(3) 'No you didn't.'";
				std::cin >> choice; 

				switch (choice) {
				case 1&&3: // from "why cant i go with you" && "no you didnt"
					smallWait(wait);
					text = "\n\n\n*the agent keeps walking*\n\n\n"; printDelay(text, normal);
					smallWait(wait);
					cout << "(1) 'Come back!'\n(2) *follow the agent*\n(3) *go back to the fire*\n\n";
					std::cin >> choice;

					switch (choice) {
						cout << "\n\n\n";//test 

					case 1: // from "come back!"
						cout << "\n\n\n";
						smallWait(wait);
						text = "\n\n\n*the agent fades into the twirling snow*\n\n\n"; printDelay(text, normal);
						smallWait(halfWait);

						cout << "(1) *follow the agent*\n(2) *go back to the fire*\n\n";
						switch (choice) {
						case 1: // from "*follow the agent*"
							//GRAB PAPER FROM CAR
							//make switch(chance) for if player can find agent
								//if found, fight
								//if lost, lostInSnow()
							break;
						case 2: // from "*go back to the fire*"
							break;
						}


						break;
					case 2: // from "*follow the agent*"
						//switch to find the agent with advantage on chance %
						break;
					case 3: // from "*go back to the fire*" GRAB PAPER FROM CAR
						break;
					default:
						break;
						
					}

						// follow agent will lead to interrupted fight (player saved and wins)
					break;
				case 2: // from "im still confused"
					//check flowchart
					break;
				default:
					break;
				}


					//1 & 2 are the same outcome
				break;
			case 3: // from "*go back to the fire*"
				//randomize(chance, 1, 100); maybe not needed
				lost = lostInSnow(chance, text, normal, fast, halfWait);
				if (lost == false) {
					text = "*after following the glow of the fire, you sit down where you first woke up*\n"; printDelay(text, normal);
					choice = 20;  //to return to fire

				}
				if (lost == true) {
					cout << "\n\ndeath screen from inside main switch block\n\n";
					smallWait(wait);
				}
				break;
			default:
				break;
			}
			break;
		case 2: // from "*stay by the fire*"
			

			break;
		}

	};

	




	choice = 0;
	
	//add system clear here when finished with ch1 to make ascii art and convos look clean

	//Second Dialogue

	if (fight == false) {

		//next dialogue
		cout << "\n\nChapter 2: the walk to the crash site";

	std::cin >> choice;
		switch (choice) {
		case 1:
			cout << "dialogue 2, option 1" << endl;
			break;
		case 2:
			cout << "dialogue 2, option 2" << endl;

			break;
		case 3:
			cout << "dialogue 2, option 3" << endl;

			break;
		default:
			break;
		}

	}

	//if player comments on headache, they get booze(+dmg). if they ask random lore questions, they get beans (++hp, +dmg)
	//end of chapter 1 ,  

	if (impatience >= 3) {

		text = "\n\n'...finally'\n\n";

		smallWait(wait);

	}



	//CHAPTER 2
	// double check in chapter 1: all specials are activated and written on the side to be used (heavily in walk to heli). have playtesters test different outcomes.  
	//chapter 2 will have more weapons because he didnt have time to check. since hes armed but has no info, he will be shocked theres a weapon he didnt find and be nervous to let you grab it
	//end game with player being cornered by a sneaky second terrorist & have an actual agent come up and shoot one of the terrorists, then telling al the true details of what happened
	//during walk to heli- can make a graphic for each stage, with each stage either having red herrings or building up hints toward the story.(ascii art for dead agent covered in smow, options(keep walking, say something, fight). maybe like 3-5 stages for the walk over. stages (1-supplies)(2-dead body)(3-heli with side blown in.) check rails for stage order
	//during walk to heli 2- if impatience is at or above 4 he will tell player to hurry to heli
	//add zipper sound effect here(inbetween chapters) to make leaving camp feel more real

	
	while (fight == true) { 
		
		//system("cls");
		//if (specials[4] == true) {} //secret ending battle
		cout << "-fight is active-";
		round++;
		system("pause");


		//GOOD IDEA: use systerm("cls") and string inputs for attack. you can have a battle screen, showing a picture of the agen that get beat up as his health lowers. sting inputs: attack, see item slot, see item details, see stats(both) 
		//
		// ascii art animation frames can be made into funtions (ex; frameCampfire1() or frameCampfire(int frame#)<-make if statements inside function for different frames)

	}



	system("pause");
	return 0;
}


void secretWait(char wake, int impatience, bool fight, bool specials[], string text, std::chrono::milliseconds wait, std::chrono::milliseconds fast, std::chrono::milliseconds slow, std::chrono::milliseconds normal) {

	
	while (wake == 'N') {

		cout << "\n\nStop waiting? (y/n): ";

		std::cin >> wake;
		wake = std::toupper(wake);


		switch (wake) {
		case 'Y': break;
		case 'N':
			impatience++;
			smallWait(wait * impatience);//should be a neat effect

			switch (impatience) {

			case 1:
				text = "\n\n'You need more time?'\n\n"; printDelay(text, fast);
				break;

			case 2:
				text = "\n\n'....'\n\n'Still need more time?'\n\n"; printDelay(text, normal);
				break;
			case 3:
				text = "\n\n'....'\n\n'We should go...'\n\n"; printDelay(text, slow);
				break;
			case 4:
				text = "\n\n'....'\n\n'You seriously need more time?'\n\n"; printDelay(text, normal);
				break;
			case 5:
				text = "\n\n'....'\n\n'Lets leave.'\n\n"; printDelay(text, slow);
				break;
			case 6: cout << endl << endl; break;
			case 7:
				text = "\n\n\n*radio*\n"; printDelay(text, slow);
				text = "\n~bzzt~\n"; printDelay(text, fast);
				text = "\n'You bringing this guy or what?? They're not dumb, we have to do this quick!'\n"; printDelay(text, normal);
				text = "\n~bzzt~\n"; printDelay(text, fast); smallWait(wait * 2);
				text = "\n*the agent sighs*\n"; printDelay(text, slow); smallWait(wait);
				text = "\n'Sorry it has to be like this.'\n"; printDelay(text, slow); smallWait(wait);
				text = "\n'You weren't supposed to see this coming...'\n\n'But here we are...'\n"; printDelay(text, normal);
				text = "\n'Empty-handed...'\n\n'So I suppose you win...'"; printDelay(text, slow);

				wake = 'Y';
				fight = true;
				specials[4] = true;
				break;
			}

			break;

		default:
			wake = 'N';
			break;
		}



	}
	cout << "You got up from the campfire";


}
//safeword path unfinished
void safewordPath(PERSON player, std::chrono::milliseconds slow, std::chrono::milliseconds normal, string text, int &choice, int chance)
{
	
		cout << "\n*the agent looks confused*\n'Hm? Did you say "; player.getSafeword(); cout << "?'"
			<< "\n\n(1) 'Yes... Do you not know?'\n(2) 'Yes! There's "; player.getSafeword(); cout << " everywhere!!'\n"
			<< "(3) 'You must've misheard me...'\n(4) *distraction* 'What's your name again?'\n\n";


		std::cin >> choice;
		switch (choice) {

		case 1: //from "Yes.. do you not know?"
			break;


		case 2: //from "There's things everywhere!!"
			cout << "\n\n'...'\n'We should get you to the helicopter, there might be a medkit or something.'"
				<< "\n\n(1) *louder* '"; player.getSafeword(); cout << "!!!'\n(2) 'Sure. I must've hit my head...'";
			break;



		case 3: //from "You mustve misheard me"
			cout << "\n'Oh, ok... Hm...'\n'Anyway, we should head to the crash site...'\n'...to find supplies.'\n" //add delay to oh ok
				<< "(1) 'You didn't check for supplies when we crashed?'\n(2) 'Ok, let's get moving.'\n";
			std::cin >> choice;

			switch (choice) {
			case 1://from "you didnt check supplies ? "
				text = "\n\n'...'\n"; printDelay(text, normal);
				cout << "'No. I had to drag you out of there as soon as possible, I thought you were dead.'\n\n"
					<< "(1) 'Oh, ok. We should check before it's too late.'\n(2) 'Sorry, I should've thanked you sooner...'\n(3) 'If you thought I was dead, why save me?'\n";

				std::cin >> choice;
				switch (choice) {
				case 1: //from "Oh, ok. We should check before it's too late."


					randomize(chance, 1, 3);
					if ((chance == 1) || (chance == 2)) { cout << "\n'By the way,\n'"; choice = 15; }// 2/3 chance of lazlo asking for introduction



					break;
				case 2: //from "Sorry, I should've thanked you sooner..."
					text = "\n\n'No need to apologize'\n"; printDelay(text, normal);
					text = "'It was my pleasure.'"; printDelay(text, slow);
					text = "'We should go...'"; printDelay(text, normal);

					break;
				case 3: //from "If you thought I was dead, why save me?"

					break;
				default:
					break;
				}
				//responses (1)(2)(3) my best case scenario was that youd wake up, worst case scenario i would've eaten you.
				// r responses (3) "lets go"
				// r r responses (3) "...", "Alright...", "Understandable."
				break;
			case 2://from "Ok, lets get moving"
				//jump to chapter 2
				break;
			}
			break;



		case 4: //from "Whats your name again?"
			
			choice = 10;// doesnt work***

			break;

		default:
			break;
			
		}
		
	}
void stayByFire() {



}
//give players a warning when using this
bool lostInSnow(int &chance, std::string text,std::chrono::milliseconds normal, std::chrono::milliseconds fast, std::chrono::milliseconds halfWait) { //end with "you successfully"
	
	text = "\n\n\n*after turning around, you notice your footprints filling with snow*\n*you begin walking in the general direction of the fire*\n\n\n"; printDelay(text, fast);
	smallWait(halfWait);
	text = "\n\n\n[[ you have an 80% to survive this ]]\n\n[[ your random number must be above 20 ]]\n[[ getting 90+ will get you there faster ]]"; printDelay(text, fast);
	
	randomize(chance, 1, 100);

	text = "\n[[ you got "; printDelay(text, normal); 
	smallWait(halfWait);
	cout << chance; 
	text = " ]]"; printDelay(text, normal);
	
	if (chance >= 90) {
		
		cout << "\n\nshortcut!";//test
		//specials[6 or something]     // by choosing to walk in a random direction, you somehow find a shortcut back to the fire. you sit down...
		smallWait(halfWait);
		return false;
	}

	if ((chance >= 20)&&(chance < 90)) { //survive //add or if stage 2
		text = "\n\n*you continue walking until you can no longer see tracks*\n*almost completely blinded by snow, you have a gut feeling this is the right direction*\n"; printDelay(text, fast);
		smallWait(halfWait);
		text = "[[ you must try again ]]"; printDelay(text, fast);
		smallWait(halfWait);
		cout << "\n\nunfinished\n\n";
		smallWait(halfWait);


		return false;
	}
	else { //test
		smallWait(halfWait);
		cout << "\n\nYOU GOT LOST IN THE SNOW AND FROZE\n\n";
		smallWait(halfWait);
		return true;
	}
}


void randomize(int &num, int min, int max) //i still dont understand this too deep
{ 

	std::srand(time(0));
	num = std::rand() % max + min;

}


void printDelay(const std::string text, std::chrono::milliseconds delay)
{
	for (char c : text) {
		cout << c << std::flush;
		std::this_thread::sleep_for(delay);
	}
}

void smallWait(const std::chrono::milliseconds delay)
{
	std::this_thread::sleep_for(delay);
}


//things to come back and fix:
/*

* rewrite the intro to better explain the environment. 
	- agent sitting across from fire, tending to fire. 
	- agent has no injuries except for a blood smear on his coat
	- blizzard is intense, but not bad enough to overpower a helicopter.
	- 
* 
* 
* 
*



*/





//works correctly:
/*
wake up
attack
item slots
use item
seeStats
seeGist
seeItemSlot
secret ending (wait convo done)




*/



/*NEEDS WORK-
inventey construstor initializes the item list wrong, see why it somehow works and also correct it



*/


/* Comments During Creation

-This thing is at around 400 lines of code and i still haven't settled on a name. MIA is the top pick so far but im not a big fan. 
 Writing 400 lines of code and story in a project named "inventory practice" doesn't feel right...

-Now at 1700 lines in source code alone, ive finally thought of a name for the main antagonist. 
 I still don't have a name for the full game yet but i keep calling it m.i.a.
	-> "Drakpa", a traditional Tibetan name meaning 'the one who brings trouble' / 'troublemaker'

-
-

*/

//make this work, then on next game make weapons a class like ITEM with setters and getters in a sandbox


