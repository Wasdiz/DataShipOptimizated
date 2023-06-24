
#pragma once
using namespace std;
class ShipCrew :public SpaceShip
{
public:
	int crew;

	int cost;
	int profit;
	void passengerProfit() {

		profit = (crew - cost) / cost * 100;

	}



};