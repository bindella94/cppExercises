#pragma once
#include <vector>
namespace geography
{
struct Tile
{
	Tile(const int& xPosition, const int& yPosition, const int& altitude) :
		xPosition_(xPosition), yPosition_(yPosition), altitude_(altitude)
	{

	}
	Tile() = default;


	Tile (const Tile& other) = default;
	int xPosition_;
	int yPosition_;
	float altitude_;
};


constexpr float direction_NORTH = 0.0f;
constexpr float direction_EAST = 90.0f;
constexpr float direction_SOUTH = 180.0f;
constexpr float direction_WEST = 270.0f;
};


class Altitude
{
public:
	Altitude(const int& width, const int heigth) :
		width_(width), heigth_(heigth)

	{
		setValues();
	}

	void  setValues();


	float getMeanAltitude();

	// 0  = N, 90 = E, S = 180, W = 270
	std::vector< std::pair < float, geography::Tile>> getCardinalNearTiles(const int& xPosition,const int& yPosition);


	std::vector< geography::Tile > getBiggerTiles(int xPosition, int yPosition);


	bool isCentralPosition(const geography::Tile& centralTile, const int& x, const int& y);

	bool isPositionOutOfRange(const int& x, const int& y);

	bool isBiggerThanTheTile(const geography::Tile& centralTile, const geography::Tile& otherTile);

private:
	int width_;
	int heigth_;

	std::vector< std::vector < geography::Tile >  > tiles_;
};

