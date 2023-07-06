#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "tbg_h.hpp"
using namespace	std;
Player p;
Shelter forest;
Shelter hill;
World w;
vector<int> pos;

//Classes
	//Class Player

		string Player::get_name(){return name;}
		void Player::set_name(string new_name){name = new_name;}

		void Player::set_stick(bool b){stick = b;}
		bool Player::get_stick(){return stick;}

		void Player::set_flare(bool b){flare = b;}
		bool Player::get_flare(){return flare;}

		void Player::set_gun(bool b){gun = b;}
		bool Player::get_gun(){return gun;}

		void Player::set_injured(bool b){injured = b;}
		bool Player::get_injured(){return injured;}

		void Player::set_daysoffood(int change_food){daysoffood = daysoffood + change_food;}
		int Player::get_daysoffood(){return daysoffood;}

		void Player::set_has_shelter(bool b){has_shelter = b;}
		bool Player::get_has_shelter(){return has_shelter;}

	//Class shelters
		void Shelter::set_name(string new_name){shelter_name = new_name;}
		string Shelter::get_name(){return shelter_name;}

		void Shelter::set_location(int new_location){location = new_location;}
		string Shelter::get_location(){return location;}

		void Shelter::set_shelter_build(bool b){build_shelter = b;}
		bool Shelter::get_shelter_build(){return build_shelter;}

	//Class World

		void World::set_searched_shipwreck(bool b){searched_shipwreck = b;}
		bool World::get_searched_shipwreck(){return searched_shipwreck;}

		void World::set_jaguar_attacked(bool b){jaguar_attacked = b;}
		bool World::get_jaguar_attacked(){return jaguar_attacked;}

		void World::set_times_foraged(int i){times_foraged = times_foraged + i;}
		bool World::get_times_foraged(){return times_foraged;}

		void World::set_searched_helicopter(bool b){searched_helicopter = b;}
		bool World::get_searched_helicopter(){return searched_helicopter;}
//Misc
	//Intro
		void intro(){
			string n;
			cout << "Welcome to paradise \n \n" << "please enter your name: \n";
			cin >> n;
			p.set_name(n);
			cout << "Thank you! \n Possible input options appear like this -imput-, you can always go back to your previus position by writing -return- or close the program by writing -exit-  \n Let's begin our journey!\n";
			cout << "\n" << "\n" << "\n";
			cout << "You wake up on a beach, you seem to be allright, but you dont know where you are. \n";

			p.set_daysoffood(0);
			p.set_flare(false);
			p.set_gun(false);
			p.set_stick(false);
			p.set_injured(false);
			p.set_has_shelter(false);
			forest.set_shelter_build(false);
			hill.set_shelter_build(false);
			}
	//ERROR
		void try_again(){cout << "wrong imput, please try again!\n";}
//Shelters
	//Choice of Shelter
		int get_shelter(){
		int shel = 0;
			if (forest.get_shelter_build() == true){shel++;}
			if (hill.get_shelter_build() == true){shel++;}
		
			if (shel == 1){
					if (forest.get_shelter_build() == true){shel = 101;}
					if (hill.get_shelter_build() == true){shel = 102;}
			}
			else{
			cout << "Where do you want to go?\n";
			if (forest.get_shelter_build() == true){cout << "-forest-\n";}
			if (hill.get_shelter_build() == true){cout << "-hill-\n";}
			int i = 0;			
			while(i == 0){
				string d;
				cin >> d;
				cout << "\n";
				if(d == "forest" || d == "-forest-"){
					shel = 101;
					i++;
				}
				else if (d == "hill" || d == "-hill-"){
					shel = 102;
					i++;
				}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else if(d == "return" || d == "-return-"){cout << "Can't return from here! Try again!\n";}
				else {try_again();}
				}
			}
		return shel;
		}
	//101 Forest
		int d101(){
			cout << "You return to your shelter.";

			int n = 2;
				if (p.get_injured() == true){
					cout << "you can rest up here and sleep for a day to heal your wounds. Would you like to do that?\n -yes- -no-\n";
					int i = 0;
					while(i == 0){
						string d;
						cin >> d;
						cout << "\n";
						if(d == "no" || d == "-no-"){
							n = 2;
							i++;
							}

						else if(d == "yes" || d == "-yes-" ){
							p.set_injured(false);
							p.set_daysoffood(-1);
							n = 2;
							if (p.get_daysoffood() < 0){
								n = 69420;
								cout << "You ran out of food!\n";
								}
							i++;
							}
						else if(d == "exit"  || d == "-exit-"){
							exit (EXIT_FAILURE);
							}
						else if(d == "return" || d == "-return-"){
							cout << "Can't return from here! Try again!\n";
							}
						else if(d == "shelter" || d == "-shelter-"){
							if (p.get_has_shelter() == true){
								n = get_shelter();
								i++;
								}
							else {cout <<"You dont have a shelter. Try again!\n";}		
							}

						else {try_again();}
						}
					}	
			return n;
			}
	//102 Hills
		int d102(){
			cout << "You return to your shelter.";

			int n = 4;
				if (p.get_injured() == true){
					cout << "you can rest up here and sleep for a day to heal your wounds. Would you like to do that?\n -yes- -no-\n";
					int i = 0;
					while(i == 0){
						string d;
						cin >> d;
						cout << "\n";
						if(d == "no" || d == "-no-"){
							i++;
							}

						else if(d == "yes" || d == "-yes-" ){
							p.set_injured(false);
							p.set_daysoffood(-1);
							n = 2;
							if (p.get_daysoffood() < 0){
								n = 69420;
								cout << "You ran out of food!\n";
								}
							i++;
							}
						else if(d == "exit"  || d == "-exit-"){
							exit (EXIT_FAILURE);
							}
						else if(d == "return" || d == "-return-"){
							cout << "Can't return from here! Try again!\n";
							}
						else if(d == "shelter" || d == "-shelter-"){
							if (p.get_has_shelter() == true){
								n = get_shelter();
								i++;
								}
							else {cout <<"You dont have a shelter. Try again!\n";}		
							}

						else {try_again();}
						}
					}	
			return n;
			}
//Events
	//1 Beach
		void e1a(){ //Campfire beach
			cout << "You aproach the campfire, it seems to be at least burned out for a couple of days. You can see sticks with witch people prepared food over the fire, but there is nothing usefull here. You return to the beach entrence.\n";
			}
		void e1b(){ //Shipwreck
			if (w.get_searched_shipwreck() == true){
				cout << "You've allready searched the shipwreck. Try again!\n";
				}
			else if(p.get_injured() == true){
				cout << "You're injured and can't swim. Try again!\n";
				}			
			else{
				cout << "You start swiming over to the wrackage. The currents are realy strong but you menage to make it. You explore the wrackage you find: \n 1 Box of flares \n 3 days of food \n\nYou make your way back, while getting out of the water you step on a sea urchin and injure your foot badly. You spend some time to get the stingers out of your foot. You should find shelter, so that you can heal your wound.\n";
				w.set_searched_shipwreck(true);
				p.set_flare(true);
				p.set_daysoffood(+3);
				p.set_injured(true);
				}
			}		
	//2 Forest south
		int e2_3(){
			int n;
			if (w.get_jaguar_attacked() == false){
				w.set_jaguar_attacked(true);
				if (p.get_injured() == true){
					cout << "You venture deeper into the forest, all of the sudden you hear something ratteling. As you turn around you see a Jaguar in a bush right next to you. Since you are heavily injured there is nothing you can do. The jaguar jumps and slices you into pieces.\n";
					n = 69420;
					}
				else {
					if(p.get_gun() == true){
						cout << "You venture deeper into the forest, all of the sudden you hear something ratteling. As you turn around you see a Jaguar in a bush right next to you. You pull draw your pistol and shoot the beast, it makes a loud noise and runs away.\n";
						cout << "You continue walking through the forest, as you start to notice the forests edge in the distance.\n";
						n = 3;
						}

					else if (p.get_flare() == true){
						cout << "You venture deeper into the forest, all of the sudden you hear something ratteling. As you turn around you see a Jaguar in a bush right next to you. You ignite one of your flares and scare away the beast.\n";
						cout << "You continue walking through the forest, as you start to notice the forests edge in the distance.\n";
						n = 3;
						}

					else if (p.get_stick() == true){
						cout << "You venture deeper into the forest, all of the sudden you hear something ratteling. As you turn around a Jaguar jumps at you.\n He rams his teath into your right leg. you feel an intense pain and istinktively bonk the Jaguar on the nose. He lets go of your leg and runs away.\n";
						cout << "You survived but you are heavily injured.\n";
						cout << "You continue walking through the forest, as you start to notice the forests edge in the distance.\n";
						p.set_injured(true);
						n = 3;	
						}

					else{cout << "You venture deeper into the forest, all of the sudden you hear something ratteling. As you turn around a Jaguar jumps at you.\n With no weapon to defend yourself he effordlessly slashes your through.\n";
							n = 69420;
						}
					}
				}
			else{
				cout << "You venture deeper into the forest, all of the sudden you hear something ratteling. As you turn around you see a rabit runing away. You venture deeper and arive at the edge of the forest.";
				n = 3;
				}
			cout << "\n\n";
			return n;	
			}
		void e2a(){
			cout << "You are walking through the fores, trying to stay relatively dry by walking from tree to tree.\n";
			cout << "	1 day of food in nuts and berrys\n";
			if (p.get_stick() == false) {cout << "	A big stick to be used as a weapon\n";}
			cout << "\n \nWhat will you do next? -explore- the forest, -return- to your previus position or -build- a more permanent shelter?\n";
			p.set_stick(true);
			p.set_daysoffood(1); 
			}
		int e2b(){
			int n = 2;
			cout << "You spend the whole day building a shelter in the forest.\n You now own this shelter and you can come back here at any point by writing -shelter-.\n";
			cout << "You use up one day of food.\n";
			if (forest.get_shelter_build() != true){
				forest.set_shelter_build(true);
				p.set_has_shelter(true);
				p.set_daysoffood(-1);
				if (p.get_daysoffood() < 0){n = 69420;
					cout << "You ran out of food!\n";
					}
				}
			else {
				cout << "You've already build a shelter here, please try again!\n";
				}
			cout << "\n\n";
			return n;
			}
	//4 Hills
		void e4a(){
			hill.set_shelter_build(true);
			p.set_has_shelter(true);
			p.set_daysoffood(2);
			cout << "You move through the hilly area and stumble uppon an empty camp with a fire spot, 2 days of food supply and a worn out tent. Even though it has holes, you can use this as a -shelter- and always return here.\n You've gained:\n 2 days of food\n A new shelter\n";
			cout << "As you continue to walk through the hills, you come across a spring. You start to follow the river until you ";
			if(pos.back() != 0){cout << "get back to the plains Area.\n";}
			else{cout << "reach a big plains Area.\n";}
			}
	//6 Lake
		void e6a(){
			w.set_searched_helicopter(true);
			p.set_gun(true);
			cout << "You get closer to the lake, the smoke plume seems to originate from the other side. You get closer and start to make out the shape of an helicopter on fire. The fire seems to have died down and there is only a small flame left. But it produces a lot of smoke. The air gets filled more and more with the stench of burned skintissue, rubber and plastic.\n";
			cout << "The closer you come the stronger the smell gets. You try to hold your breath and you snother the flame with a pice of tarp you found on the ground on the crashsite. You start looking around the helicopter. The cargo area is compleatly empty, apart from debri. As you walk to the front to look into the cockpit you see a half burned pilot corpse impaled on his seat. He must have died on impact.\n";
			cout << "You notice a pistol in his holster, so you reach through the broken window and after a minute of fiddleing you menage to get it out of the holster.\nYou aquired a handgun!\n You continue to search, but you can't find anything else usefull.\n";
			}
	//7-8 Swamp Finally
		int e7_8(){
			int n = 8;
			cout << "You continue to walk through the swamp to get to the other side. When out of no where you notice that you can't get your right foot out of the mud anymore. While struggling you notice the same happened with your left foot and then your fate becomes clear to you! You are starting to sink!\n";
			if (p.get_stick() == true){
				cout << "You quickly use your stick to pull some bushes towards you. You menage to grab them and with a lot of strenght you menage to pull yourself out of your predicament.\n";
				cout << "\n\nYou can tell, it is going to be a long jurney though this swamp. You walk for the whole day and it starts getting dark.\n";
				if (p.get_flare() == true){
					cout << "Good that you found those flares earlyer. You wait until you can bearly see anything anymore and you start igniting one flare after a nother, they light up the gloomy enviroment and you menage to keep on track. You notice something od infront of you, two eyes poke out of the mud and seem to observe you. As you look closer you notice that they seem to move towards you and faster than you could move in this mud.\n";
					if (p.get_gun() == true){
						cout << "With one hand holding the flare, you use the other to pull out your handgun out of your waistband. You prop the arm holding the gun on the am holding the flare and take carefull aim. *GUNSHOT* You missed, but the beast gets scared. It reveals itself, its a crocodile and it runs away as fast as it can.\n\n\n";
						}
					else{
						cout << "You take out your stick and try to defend yourself. But all of the sudden, the two eyes jump out of the mud and reveal to belong to a crocodile. Your stick doesn't help you at all, the crocodile throws you over and ripps you to peaces.\n";
						n = 69420;
						}
					}
				else{cout << "It is getting pitch black dark. Without any surce of light you can't see anything anymore. As you stomble your way through the mud, something burrys its teeth into your legs. It throws you over and ripps you to shreds.\n";
					n = 69420;
					}
				}
			else{cout << "There is nothing around you close enought to grab so you can't pull yourself out. As you struggle you sink deeper and deeper into the mud. Until only your head pokes out. Slowly mud invelopes you compleatly. It covers your eyes and you can't see anymore. As you run out of air you try to breathe deaspratly but the only thing that fills your lungs is mud. You suffocate.\n";
				n = 69420;
				}
			return n;
			}
//Prints	
	//0 begining
		//Main
			void p0m(){
				cout << "There is an cliff infont of you it looks like you could -climb- it and on the -left- side of the beach you can see a forest, the -right- side leads around the cliff.\n";
				if (p.get_daysoffood() == 0) {cout << "The sun hits is burning down on you and makes you aware that you wont make it long without some food. ";}
				cout << "Where do you go?\n";
				}
		//to
			void p0_1(){
				cout << "You hug the wall as you make your way around the cliff. Once you are around it you see a small beach area surounded by almost vertical cliffs.\n";
				}
			void p0_2(){
				cout << "You run over to the forest to find shelter from the rain. As you reach the first trees, you can see that they are absolutely massive.\n In awe you stare upwards at the tree tops towering above you, deflecting the reain away from you.\n";
				}
			void p0_4(){
				cout << "You walk over to the cliff and look up. It is towering over you, it is steep, high and slippery because of the rain, this wont be easy. You start climbing anyway, it is hard and you almost slip twice. But after 20 minutes you reach the top. You stand up and see a hilly area.\n";
				}
	//1 Beach
		//Main
			void p1m(){
				cout << "On the other side of the beach you can see a burned out -campfire-";
				if (w.get_searched_shipwreck() != true){cout << " and in the ocean you can see a wrecked -ship-";}
				cout << ".";
				if (w.get_searched_shipwreck() != true){cout << " It doesn't look familiar to you, you could make your way over to it but swiming there would be realy dangerus.";}
				cout << " Where do you want to go?\n";
				}
		//to
			void p1_0(){
				cout << "You hug the wall as you make your way around the cliff. You are back at the beach you started at.\n";
				}
	//2 Forest south
		//Main
			void p2m(){
				cout << "What will you do next?\n Will you -forage- for food and usefull items, -explore- deeper into the forest";
				if (forest.get_shelter_build() != true){cout << " or will you -build- a permanent shelter";}
				cout << "?\n";
				}
		//to
			void p2_3(){e2_3();}
	//3 Forest north
		//Main
			void p3m(){
				cout << "You decide to walk over to the edge. As you reach it you can start to see a giant plane with grass and flowers infront of you. In the distance you can see a small lake with a big plume of black smoke rising to the sky. To the right of you you can see a steep incline onto a hill. To your left you there is a wast green swamp with almost inpasable terrain.\n";
				cout << "Where do you want to go? into the plains to the -lake-, to the right up the -hill-, -return- or do you want to try your luck in the -swamp-?\n";
			}
		//to
			void p3_4(){
			cout << "You start walking over to the hills. It is a short but steep climb.\n";
			}
			//p3_5(){}
			void p3_6(){
			cout << "You start making your way to the Lake. It is a long way, but there are a ton of interesting flowers aroud you so your mind is occupied and the walk goes over quickly.\n";
			}
			void p3_7(){
			cout << "The swamp is far away, being on the other side of the plains. As you get closer to the swamp see how the ground around you gets less and less unstable.\n";
			}
	//4 Hills
		//Main
			void p4m(){
			cout << "You walk onto a small hill nearby to get a better view. You look to the left and see a big -forest-, straight you see a big smoke plume next to a -lake- and a -swamp- behind that. You can also climb down to the -beach-.\n";
			cout << "Where do you want to go next?\n";
			}
		//to
			void p4_3(){
			cout << "You walk down the hill carefully so you don't trip. After a short walk you reach the forest edge. The forest seems too imposing to walk through it from this side.\n";
			}
			//p4_5(){}
			void p4_6(){
			cout << "You walk down the hill carefully so you don't trip. You start making your way to the Lake. It's a long way, but there are a ton of interesting flowers aroud you so your mind is occupied and the walk goes over quickly.\n";
			}
			void p4_7(){
			cout << "You walk down the hill carefully so you don't trip. The swamp is far away, it's on the other side of the plains. As you get closer to the swamp you see how the ground around you gets less and less unstable.\n";
			}
			void p4_0() {
			cout << "You climb down the cliffside carefully, paying full attention to your grip on the wall so you don't slip. You make it savely to the beach.\n";
			}
	//6 Lake
		//Main
			void p6m(){
			if (w.get_searched_helicopter() != true){e6a();}
			cout << "You walk to the lake and look around, you see -hills- and a -forest- to the south and -swamp-land to the north.\nWhere do you want to go?\n";
			}
		//to
			void p6_3(){
			cout << "After a long walk you reach the forest edge. The forest seems too imposing to walk through it from this side.\n";
			}
			void p6_4(){
			cout << "You start walking to the hills, its quite the distance but it is over quickly after that it is just a short but steep climb.\n";
			}
			void p6_7(){
			cout << " After a short walk to the swamps edge, you reach a point where the ground gets realy unstable.\n";
			}
	//7 Swamp south
		//Main
			void p7m(){
			cout << "It is realy exhausting to continue to walk due to the unstable ground giving away beneath your feet. But you press on and make it to the edge of the swamp. The swamp has a small decline and many rivers and lakes running though it. Are you sure you want to -continue- into the swamp? or would you like to go back to the -lake-, the -hills- or the -forest- to prepare yourself a little more?\n";
			}
		//to
			void p7_3(){cout << "You walk back through the muddy terrain, and walk to the forest\n";}
			void p7_4(){cout << "You walk back through the muddy terrain, and walk to the hills\n";}
			void p7_6(){cout << "You walk back through the muddy terrain, and walk to the lake\n";}
	//8 Swamp north
		//Main
			void p8m(){
				cout << "You reach the other side of the swamp. A georges beach with white sand and palm trees. Exhaused you let yourself fall into the sand. What a journdey. As your flare burnes out you start to notice the stunning night sky above you.\nYou have never seen so many stars on the nightsky in your life.\n";
				cout << "Slowly your eyes start to close and you drift away into sleep...\n\n";
				cout << "After some time a loud foghorn wakes you up, it is still dark, but you can see the sun starting to set. On the water you can see a big containership. You reakt quick and ignite two of your flares.\n";
				cout << "After a couple of minutes the ship uses its horn again and you can make out light signals coming from the deck of the containership. After what feels like half an hour you see a rescue ship coming toward you out of the diraction of the containership. When they land the rescue ship on the shore you get on bord and leave this cursed island behind!\n\n\n";
				cout << "Your jurney ends here " << p.get_name() <<", thanks for playing!\n";
			}
//Desissions
	//0 begining
		int d0(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				p0m();
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "right" || d == "-right-"){
					p0_1();
					i++;
					n = 1;
					}
				else if(d == "left" || d == "-left-" ) {
					p0_2();
					i++;
					n = 2;
					}
				else if(d == "climb" || d == "-climb-"){
					p0_4();
					i++;
					n = 4;
					}
				else if(d == "return" || d == "-return-"){
					cout << "You are already at the beginning and can't return further! Try again!\n";
					}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
						n = get_shelter();
						i++;
						}
					else {cout <<"You dont have a shelter. Try again!\n";}		
					}	
				else {
					try_again();}
				}
				if (r != true){pos.push_back(n);}		
				return n;
			}
	//1 Beach
		int d1(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				p1m();
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "campfire" || d == "-campfire-"){
					r = true;
					e1a();
				}
				else if(d == "ship" || d == "-ship-" ) {
					r = true;
					e1b();	
				}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
				}
				else if(d == "return" || d == "-return-"){
					if (pos.back() != 0){pos.pop_back();}
					n = pos.back();
					cout << "You return to your previus possistion.\n";
					i++;
					r = true;
				}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
					n = get_shelter();
					i++;
					}
					else {cout <<"You dont have a shelter. Try again!\n";}		
				}
				else {
					try_again();
				}
			}
			if (r != true){pos.push_back(n);}		
			return n;
			}
	//2 Forest south
		int d2(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				p2m();	
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "forage" || d == "-forage-"){
					r = true;
					e2a();
					}
				else if(d == "explore" || d == "-explore-" ){
					n = e2_3();
					i++;
					}
				else if(d == "build" || d == "-build-"){
					r = true;
					n = e2b();
					}
				else if(d == "return" || d == "-return-"){
					if (pos.back() != 0){pos.pop_back();}
					n = pos.back();
					cout << "You return to your previus possistion.\n";
					i++;
					r = true;
					}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
					n = get_shelter();
					i++;
					}
					else {cout <<"You dont have a shelter. Try again!\n";}		
					}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else {try_again();}
				}
				if (r != true){pos.push_back(n);}
				return n;
			}
	//3 Forest north
		int d3(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				p3m();
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "lake" || d == "-lake-"){
					i++;
					n = 6;
					}
				else if(d == "hills" || d == "-hills-" ){
					n = 4;
					i++;
					}
				else if (d == "swamp" || d == "-swamp-"){
					n = 7;	
					i++;
					}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else if(d == "return" || d == "-return-"){
					if (pos.back() != 0){pos.pop_back();}
					n = pos.back();
					cout << "You return to your previus possistion.\n";
					i++;
					r = true;
					}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
						n = get_shelter();
						i++;
						}
					else {cout <<"You dont have a shelter. Try again!\n";}		
					}
				else {
					try_again();
					}
				}
			if (r != true){pos.push_back(n);}
			return n;
			}
	//4 Hills
		int d4(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				if (hill.get_shelter_build() != true){e4a();}
				p4m();
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "forest" || d == "-forest-"){
					p4_3();
					i++;
					n = 3;
					}
				else if(d == "lake" || d == "-lake-" ){
					p4_6();
					n = 6;
					i++;
					}
				else if (d == "swamp" || d == "-swamp-"){
					p4_7();
					n = 7;	
					i++;
					}
				else if (d == "beach" || d == "-beach-") {
					p4_0();
					n = 0;
					i++;
				}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else if(d == "return" || d == "-return-"){
					if (pos.back() != 0){pos.pop_back();}
					n = pos.back();
					cout << "You return to your previus possistion.\n";
					i++;
					r = true;
					}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
						n = get_shelter();
						i++;
						}
					else {cout <<"You dont have a shelter. Try again!\n";}		
					}
				else {try_again();}
				}
			if (r != true){pos.push_back(n);}
			return n;
			}
	//6 Lake
		int d6(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				p6m();
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "forest" || d == "-forest-"){
					p6_3();
					i++;
					n = 3;
					}
				else if(d == "hills" || d == "-hills-" ){
					p6_4();
					n = 4;
					i++;
					}
				else if (d == "swamp" || d == "-swamp-"){
					p6_7();
					n = 7;	
					i++;
					}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else if(d == "return" || d == "-return-"){
					if (pos.back() != 0){pos.pop_back();}
					n = pos.back();
					cout << "You return to your previus possistion.\n";
					i++;
					r = true;
					}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
					n = get_shelter();
					i++;
					}
					else {cout <<"You dont have a shelter. Try again!\n";}		
				}
				else {
					try_again();}
			}
			if (r != true){pos.push_back(n);}
			return n;
			}
	//7 Swamp south
		int d7(){
			int i = 0;
			int n = 0;
			bool r = false;
			while(i == 0){
				string d;
				p7m();
				cin >> d;
				r = false;
				cout << "\n";
				if(d == "forest" || d == "-forest-"){
					p7_3();
					i++;
					n = 3;
					}
				else if(d == "hills" || d == "-hills-" ){
					p7_4();
					n = 4;
					i++;
					}
				else if (d == "continue" || d == "-continue-"){
					n = e7_8();	
					i++;
					}
				else if (d == "lake" || d == "-lake-"){
					p7_6();
					n = 7;	
					i++;
					}
				else if(d == "exit"  || d == "-exit-"){
					exit (EXIT_FAILURE);
					}
				else if(d == "return" || d == "-return-"){
					if (pos.back() != 0){pos.pop_back();}
					n = pos.back();
					cout << "You return to your previus possistion.\n";
					i++;
					r = true;
					}
				else if(d == "shelter" || d == "-shelter-"){
					if (p.get_has_shelter() == true){
					n = get_shelter();
					i++;
					}
					else {cout <<"You dont have a shelter. Try again!\n";}		
				}
				else {
					try_again();}
			}
			if (r != true){pos.push_back(n);}
			return n;
			}
	//8 Swamp north
		void d8(){p8m();}