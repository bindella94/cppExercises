#include "Altitude.h"
#include <iostream>
void Altitude::setValues()
{
    tiles_.resize(heigth_);

    for (auto i = 0; i < heigth_; ++i) 
        tiles_.at(i).resize(width_);


    for (auto i = 0; i < heigth_; ++i) {
        for (auto j = 0; j < width_; ++j) {
            geography::Tile tile(i, j, i * heigth_ + j);
            tiles_.at(i).at(j) = tile;

        }
    }
}

float Altitude::getMeanAltitude()
{
    auto result = 0;

    for (auto lines : tiles_) {
        for (auto element : lines) {
            result += element.altitude_;
        }
    }
    result = static_cast<float>(result) / static_cast<float>(width_ * heigth_);
    return result;
}

std::vector<std::pair<float, geography::Tile>> Altitude::getCardinalNearTiles(const int& xPosition, const int& yPosition)
{
    std::vector<std::pair<float, geography::Tile>> cardinalElements;
    if(!isPositionOutOfRange(xPosition,yPosition))
    {
        //Give me NORD
        if (!isPositionOutOfRange(xPosition, yPosition - 1)) {
            std::pair<float, geography::Tile> northElement{ geography::direction_NORTH , tiles_.at(xPosition-1).at(yPosition) };
            cardinalElements.push_back(northElement);
        }
        //Give me EAST
        if (!isPositionOutOfRange(xPosition + 1 , yPosition)) {
            std::pair<float, geography::Tile> eastElement{ geography::direction_EAST, tiles_.at(xPosition + 1).at(yPosition) };
            cardinalElements.push_back(eastElement);
        }
        //Give me SOUTH
        if (!isPositionOutOfRange(xPosition, yPosition + 1)) {
            std::pair<float, geography::Tile> southElement{ geography::direction_SOUTH , tiles_.at(xPosition).at(yPosition+1) };
            cardinalElements.push_back(southElement);
        }
        //Give me WEST
        if (!isPositionOutOfRange(xPosition - 1, yPosition)) {
            std::pair<float, geography::Tile> westElement{ geography::direction_WEST , tiles_.at(xPosition-1).at(yPosition) };
            cardinalElements.push_back(westElement);
        }
    }

    return cardinalElements;
}

std::vector<geography::Tile> Altitude::getBiggerTiles(int xPosition, int yPosition)
{
    std::vector< geography::Tile > result;
    geography::Tile centralTile;
    if (!isPositionOutOfRange(xPosition, yPosition)) {

        centralTile = tiles_.at(xPosition).at(yPosition);

        std::cout << "!isPositionOutOfRange:" << centralTile.altitude_ << "\n";

    }
    else {

        std::vector<geography::Tile> defaultResult;
        return defaultResult;

    }
    for (int i = yPosition - 1; i <= yPosition + 1; ++i) {
        for (int j = xPosition - 1; j <= xPosition + 1; ++j) {

            if ((!isCentralPosition(centralTile, xPosition, yPosition) || isPositionOutOfRange(i, j)) && isBiggerThanTheTile(centralTile, tiles_.at(i).at(j))) {

                result.push_back(tiles_.at(i).at(j));

            }
        }
    }

    return result;
}

bool Altitude::isCentralPosition(const geography::Tile& centralTile, const int& x, const int& y)
{
    return false;
}

bool Altitude::isPositionOutOfRange(const int& x, const int& y)
{
    auto result = true;

    std::cout << "Ci entro\n";


    std::cout << tiles_.size() << "," << tiles_.at(0).size() << "\n";

    if (x < tiles_.size() && y < tiles_.at(0).size()) {
        result = false;
    }

    return result;
}

bool Altitude::isBiggerThanTheTile(const geography::Tile& centralTile, const geography::Tile& otherTile)
{
    return centralTile.altitude_ < otherTile.altitude_;
}
