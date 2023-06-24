#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Classes.h"
#include "ScrewClass.h"
#include <ctime>



using namespace std;




std::vector<std::string> split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

bool compareColumns(const std::string& str1, const std::string& str2, int column) {
	std::vector<std::string> values1 = split(str1, ' ');
	std::vector<std::string> values2 = split(str2, ' ');
	if (values1.size() <= column || values2.size() <= column) {
		return false;
	}
	return values1[column] < values2[column];
}



SpaceShip* Ship = new SpaceShip;
ShipCrew* screw = new ShipCrew;

int userChoose;
void DisplayMenu() {

	cout << "------------------------" << endl;
	cout << "1: create ship" << endl;
	cout << "2: show all ships" << endl;
	cout << "3: sort Ship" << endl;
	cout << "4: delete ship" << endl;
	cout << "5: exit" << endl;
	cout << "choose action -> ";
	cin >> userChoose;
	cout << "------------------------" << endl;
	cout << endl;
}





void CreateShip() {

	cout << "Enter name: ";
	string userShipName;
	cin >> userShipName;
	screw->name = userShipName;
	cout << endl;

	cout << "Enter Type: ";
	string userShipType;
	cin >> userShipType;
	screw->type = userShipType;
	cout << endl;

	cout << "Enter speed: ";
	int userShipSpeed;
	cin >> userShipSpeed;
	screw->speed = userShipSpeed;
	cout << endl;

	cout << "Enter Amount fuel: ";
	int userShipFuel;
	cin >> userShipFuel;
	screw->fuel = userShipFuel;
	cout << endl;

	cout << "Enter additional fuel tanks ";
	int userShipRefuel = 0;
	cin >> userShipRefuel;
	screw->refuel = userShipRefuel;
	cout << endl;

	cout << "Enter number of crew ";
	int userCrew = 0;
	cin >> userCrew;
	screw->crew = userCrew;
	
	int cost = rand() % 100 + 1;
	screw->cost = cost;

	screw->passengerProfit();
	

	cout << endl;

	cout << "Enter does the ship have hyperjump(yes/no) ";
	string userHyperJump;
	cin >> userHyperJump;

	if (userHyperJump =="yes")
	{
		screw->HyperJump = userHyperJump;
	}
	else if (userHyperJump == "no")
	{
		screw->HyperJump = userHyperJump;
	}
	else
	{
		cout << "Wrong entered info";
	}
	cout << endl;

	

	Ship->finShip(screw->name, screw->type, screw->speed, screw->fuel, screw->refuel, screw->crew, screw->profit, screw->HyperJump);
}

void ShowAllShip() {

	Ship->foutShip();

	cout << endl;

}

ifstream inputFile("Data.txt");
	vector<std::string> lines;
	string line;

	

void sortShip() {
int columnToSort = 0;
	cout << "Enter number of colum to sort: ";
	cin >> columnToSort;
	columnToSort = columnToSort - 1;

	while (getline(inputFile, line))
	{
		lines.push_back(line);
	}
	inputFile.close();


	sort(lines.begin(), lines.end(), [columnToSort](const std::string& str1, const std::string& str2)
		{
			return compareColumns(str1, str2, columnToSort);
		});

	screw->outsortShip(lines);

	screw->foutSortShip();
}

int userShipSpeedEdit;

int userChoiseEdit;



int delstr;


int main() {
	srand(time(NULL));
	do
	{
		system("cls");
		DisplayMenu();
		switch (userChoose)
		{

		case 1: {
			system("cls");
			CreateShip();
			break;
		}
		case 2: {
			system("cls");
			ShowAllShip();
			cout << "Press any key to go menu";
			
			break;
		}
		case 3: {
			system("cls");
			sortShip();

			break;
		}
		case 4: {
			system("cls");
			cin >> delstr;
			screw->delShip(delstr);
			break;
		}
		
		case 5: {
			system("cls");
			cout << "Goodbye";
			break;
		}
		
		
		default: {
			cout << "Wrong action";
			break;
		}
		}

	} while (userChoose != 5);


}



