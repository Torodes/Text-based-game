#include <iostream>
#include <vector>
#include "tbg_h.hpp"
using namespace	std;
int days_of_food;
int num;
extern vector<int> pos;
int main(){

	intro();
	pos.push_back(0);
	int i = 0;
	int n = 0;
	while (i == 0){
		switch (n){
			case 0:
				n = d0();
				break;

			case 1:
				n = d1();
				break;

			case 2:
				n = d2();
				break;

			case 3:
				n = d3();
				break;

			case 4:
				n = d4();
				break;

			case 6:
				n = d6();
				break;

			case 7:
				n = d7();
				break;

			case 8:
				d8();
				i++;
				break;

			case 101:
				n = d101();
				break;

			case 102:
				n = d102();
				break;

			case 420:
				cout << "this path is not implemented yet. \n";
				i++;
				break;
		
			case 69420:
				cout << "GAME OVER! You died, get gud mate!\n";
				i++;
				break;

			default:
				cout << "error to default";
				i++;
				break;
		
		}
	}
	cin >> num;
	return 0;
}