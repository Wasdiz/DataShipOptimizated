# include <iostream>
#include <cstdlib>
# include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Source.h"


using namespace std;

class SpaceShip {
public:

	int speed;
	int fuel;
	int refuel;
	string type;
	string name;
	string str;
	int numberShip = 0;

	fstream fs;

	SpaceShip(string n, string t, int s, int f, int r) {

		name = n;
		type = t;
		speed = s;
		fuel = f;
		refuel = r;

	}
	

	void finShip(string name, string type, int speed, int fuel, double refuel)
	{
		fs.open("Data.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "File not open";
		}
		else
		{
			fs << name << " " << type << " " << speed << " " << fuel << " " << refuel << " " << "\n";

		}
		fs.close();

	}

	void foutShip()
	{
		fs.open("Data.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "File not open";
		}
		else
		{
			str = " ";
			numberShip = 0;

			while (!fs.eof())
			{
				numberShip++;
				cin.ignore();
				getline(fs, str);
				cout << numberShip << " " << str;
			}

		}
		fs.close();
	}

	void delShip(int delstr)
	{
		

		fstream file("Data.txt", ios::in | ios::out);

		if (file.is_open()) {
			ofstream temp("temp.txt");

			string line;
			int delstrtest = 0;
			while (getline(file, line))
			{
				delstrtest++;
				if (delstr != delstrtest) {
					temp << line << endl;
				}
			}

			file.close();
			temp.close();

			remove("Data.txt");
			rename("temp.txt", "Data.txt");

			cout << "Line removed from file." << endl;
		}
		else
		{
			cout << "Unable to open file." << endl;
		}
	}

	void foutSortShip()
	{
		fs.open("sorted_data.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла!";
		}
		else
		{
			str = " ";
			numberShip = 0;

			while (!fs.eof())
			{
				numberShip++;
				cin.ignore();
				getline(fs, str);
				cout << numberShip << " " << str;
			}

		}
		fs.close();
	}

	void outsortShip(vector<string> lines)
	{
		ofstream outputFile("sorted_data.txt");
		for (const auto& line : lines)
		{
			outputFile << line << endl;
		}
		outputFile.close();
	}

};

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
		return false; // Некорректные данные
	}
	return values1[column] < values2[column];
}

vector <SpaceShip> UserShips;
SpaceShip* Ship = new SpaceShip("", "", 0, 0, 0);
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

	cout << "Enter additional fuel tanks ";
	int userShipRefuel = 0;
	cin >> userShipRefuel;
	Ship->refuel = userShipRefuel;

	UserShips.push_back(SpaceShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel));

	Ship->finShip(Ship->name, Ship->type, Ship->speed, Ship->fuel, Ship->refuel);
}

void ShowAllShip() {

	Ship->foutShip();

	cout << endl;

}
int userChooseShipToEdit;
int userShipSpeedEdit;
int PersonalSelectCreateShipChoose;
int userChoiseEdit;




int delstr;


int main() {
	ifstream inputFile("Data.txt");
	vector<std::string> lines;
	string line;

	int columnToSort = 0;
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

			Ship->outsortShip(lines);

			Ship->foutSortShip();

			break;
		}
		case 4: {
			system("cls");
			cin >> delstr;
			Ship->delShip(delstr);
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

	} while (userChoose != 6);


}



