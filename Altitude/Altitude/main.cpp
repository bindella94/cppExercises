#include <iostream>
#include "Altitude.h"



int main() {
	Altitude altitude(4,4);

	std::cout << altitude.getMeanAltitude() << "\n";

	auto result1 = altitude.getBiggerTiles(1, 1);

	for (auto elem : result1) {
		std::cout << elem.xPosition_ << "," << elem.yPosition_ << ":" << elem.altitude_ << "\n";
	}


	auto result2 = altitude.getCardinalNearTiles(3,3);

	for (auto elem : result2) {
		std::cout << "Angle: "<<elem.first<<","<< elem.second.xPosition_ << "," << elem.second.yPosition_ << ":" << elem.second.altitude_ << "\n";
	}
	return  0;
}