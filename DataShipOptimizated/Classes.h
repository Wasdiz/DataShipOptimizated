
#pragma once
using namespace std;

class SpaceShip {
public:
	int speed;
	int fuel;
	int refuel;
	string type;
	string name;
	string HyperJump = " ";
	
	int numberShip = 0;
	string str;
	fstream fs;

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
	void finShip(string name, string type, int speed, int fuel, double refuel,int crew,int profit,string HyperJump)
	{
		fs.open("Data.txt", fstream::in | fstream::out | fstream::app);
		if (!fs.is_open())
		{
			cout << "File not open";
		}
		else
		{
			fs << name << " " << type << " " << speed << " " << fuel << " " << refuel << " "<<crew<<" "<< profit<<"%" << " "<< HyperJump<<" " << "\n";

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
};




