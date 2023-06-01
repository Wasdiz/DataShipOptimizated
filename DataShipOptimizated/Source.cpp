# include <iostream>
#include <cstdlib>
# include <vector>
#include <string>
#include <conio.h>

using namespace std;

class SpaceShip {
public:

	int speed;
	int fuel;
	int refuel;
	string type;
	string name;

	SpaceShip(string n, string t, int s, int f, int r) {

		name = n;
		type = t;
		speed = s;
		fuel = f;
		refuel = r;

	}
	friend ostream& operator<<(ostream& os, const SpaceShip& ss) {
		os << ss.name << " | " << ss.type << " type "<<" | " << ss.speed << " speed " << " | " << ss.fuel << " fuel "<<" | " << ss.refuel << " not refuel" << endl;
		return os;

	}
};
vector <SpaceShip> UserShips;
SpaceShip* Ship = new SpaceShip("","",0,0,0);
int userChoose;
void DisplayMenu() {
	
		cout << "------------------------" << endl;
		cout << "1: create ship" << endl;
		cout << "2: show all ships" << endl;
		cout << "3: edit ship" << endl;
		cout << "4: delete ship" << endl;
		cout << "5: save ship(relese in tomorow)" << endl;
		cout << "6: exit" << endl;
		cout << "choose action -> ";
		cin >> userChoose;
		cout << "------------------------" << endl;
		cout << endl;
	}





void CreateShip() {

	cout << "Enter name: ";
	string userShipName;
	cin >> userShipName;
	Ship->name = userShipName;
	cout << endl;

	cout << "Enter Type: ";
	string userShipType;
	cin >> userShipType;
	Ship->type = userShipType;
	cout << endl;

	cout << "Enter speed: ";
	int userShipSpeed;
	cin >> userShipSpeed;
	Ship->speed = userShipSpeed;
	cout << endl;

	cout << "Enter Amount fuel: ";
	int userShipFuel;
	cin >> userShipFuel;
	Ship->fuel = userShipFuel;
	cout << endl;
	int userShipRefuel = userShipSpeed / (userShipFuel * 2);
	
	Ship->refuel = userShipRefuel;

	UserShips.push_back(SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel));
}

void ShowAllShip() {

	for (int i = 0; i < UserShips.size();i++) {

		cout << UserShips[i];

	}

	cout << endl;

}
int userChooseShipToEdit;
int userShipSpeedEdit;
int PersonalSelectCreateShipChoose;
int userChoiseEdit;
void PersonalSelectCreateShip() {
	do
	{
	cout << UserShips[userChooseShipToEdit] << endl;
	cout << "1: Name" << endl;
	cout << "2: Type" << endl;
	cout << "3: Speed" << endl;
	cout << "4: Fuel" << endl;
	cout << "5: Exit" << endl;
	cout << "Set action: ";
	cin >> PersonalSelectCreateShipChoose;
	system("cls");
	switch (PersonalSelectCreateShipChoose)
	{
	case 1: {
		cout << UserShips[userChooseShipToEdit] << endl;
		cout << "Name -> ";
		string userShipNameEdit;
		cin >> userShipNameEdit;
		Ship->name = userShipNameEdit;
		UserShips.at(userChooseShipToEdit) = SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel);
		cout << endl;
		system("cls");
		break;
	}
	case 2: {
		cout << UserShips[userChooseShipToEdit] << endl;
		cout << "Type -> ";
		string userShipTypeEdit;
		cin >> userShipTypeEdit;
		Ship->type = userShipTypeEdit;
		UserShips.at(userChooseShipToEdit) = SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel);
		cout << endl;
		system("cls");
		break;
	}
	case 3: {
		cout << UserShips[userChooseShipToEdit] << endl;
		cout << "Speed -> ";
		cin >> userShipSpeedEdit;
		Ship->speed = userShipSpeedEdit;
		UserShips.at(userChooseShipToEdit) = SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel);
		cout << endl;
		system("cls");
		break;
	}
	case 4: {
		cout << UserShips[userChooseShipToEdit] << endl;
		cout << "Fuel -> ";
		int userShipFuelEdit;
		int userShipRefuelEdit;
		cin >> userShipFuelEdit;
		Ship->fuel = userShipFuelEdit;
		cout << endl;
		userShipRefuelEdit = userShipSpeedEdit / (userShipFuelEdit * 2);
		Ship->refuel = userShipRefuelEdit;
		UserShips.at(userChooseShipToEdit) = SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel);
		system("cls");
		break;
	}
	case 5: {
		/*cout << "Edit saved: ";
		cout << endl;*/
		break;
		
	}
	default: {
		cout << "Wrong action" << endl;
		system("cls");
		break;
	}
	}
	} while (PersonalSelectCreateShipChoose !=5);


}

void EditShip() {

	ShowAllShip();

	cout << "Choose ship: ";
	cin >> userChooseShipToEdit;
	userChooseShipToEdit--;

	system("cls");

	PersonalSelectCreateShip();

	UserShips.at(userChooseShipToEdit) = SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel);
}

void remove(){

	}

void DeleteShip() {

	ShowAllShip();

	cout << "Choose ship: ";
	cin >> userChooseShipToEdit;
	userChooseShipToEdit--;

	system("cls");

	UserShips.erase(UserShips.begin()+ userChooseShipToEdit);
}




int main() {
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
			_getch();
			break;
		}
		case 3: {
			system("cls");
			EditShip();
			break;
		}
		case 4: {
			system("cls");
			DeleteShip();
			break;
		}
		case 5: {



		}
		case 6: {
			system("cls");
			cout << "Goodbye";
			break;
		}
		default: {
			cout << "Wrong action";
			break;
		}
		}

	} while (userChoose != 6);

	
}