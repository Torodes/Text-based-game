#include <iostream>
#include <vector>
using namespace std;

class Player {
	string name;
	bool stick;
	bool flare;
	int daysoffood;
	bool injured;
	bool has_shelter;
	bool gun;

	public:
		string get_name();
		void set_name(string new_name);

		void set_stick(bool b);
		bool get_stick();

		void set_flare(bool b);
		bool get_flare();

		void set_gun(bool b);
		bool get_gun();

		void set_daysoffood(int change_food);
		int get_daysoffood();

		void set_injured(bool b);
		bool get_injured();

		void set_has_shelter(bool b);
		bool get_has_shelter();
	};

class Shelter {
	string shelter_name;
	string location;
	bool build_shelter;

	public:
		void set_name(string new_name);
		string get_name();

		void set_location(int new_location);
		string get_location();
		
		void set_shelter_build(bool b);
		bool get_shelter_build();
	};

class World{
	
	bool searched_shipwreck;
	bool jaguar_attacked;
	int times_foraged;
	bool searched_helicopter;

	public:
		void set_searched_shipwreck(bool b);
		bool get_searched_shipwreck();
	
		void set_jaguar_attacked(bool b);
		bool get_jaguar_attacked();

		void set_times_foraged(int i);
		bool get_times_foraged();

		void set_searched_helicopter(bool b);
		bool get_searched_helicopter();
	};


void intro();

int d0();
int d1();
int d2();
int d3();
int d4();
int d6();
int d7();
void d8();
int d101();
int d102();