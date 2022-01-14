#include "board.h"
#include <iostream>

Board::Board(GameManager& manager) : gameManager(manager) {
    this->obstaclesCounter = 0;
    this->foodCounter = 0;
    this->isExitAvailable = false;
    SetDefaultBoard();
    CreateLevelCustomizedBoard();
}

int Board::GetBoardWidth() const {
    return this->width;
}

int Board::GetBoardHeight() const {
    return this->height;
}

bool Board::IsFieldOnBoard(sf::Vector2i pos) const {
    if (pos.x < 0 or pos.x >= this->width)
        return false;

    if (pos.y < 0 or pos.y >= this->height)
        return false;

    return true;
}

bool Board::IsFieldFree(sf::Vector2i pos) const {
    if (this->board.at(pos.x).at(pos.y).hasObstacle != NONE_OBSTACLE)
        return false;

    if (this->board.at(pos.x).at(pos.y).hasFood != NONE_FOOD)
        return false;

    if (this->board.at(pos.x).at(pos.y).isExit)
        return false;

    return true;
}

bool Board::IsLevelExitAvailable() const {
    return this->isExitAvailable;
}

int Board::GetObstaclesCount() const {
    return this->obstaclesCounter;
}

int Board::GetFoodCount() const {
    return this->foodCounter;
}

char Board::GetFieldInfo(sf::Vector2i pos) const {
    if (!IsFieldOnBoard(pos))
        return '#';

    if (this->board.at(pos.x).at(pos.y).isExit)
        return '$';

    switch (this->board.at(pos.x).at(pos.y).hasObstacle) {
        case NONE_OBSTACLE:
            break;
        case WALL:
            return 'W';
        case FENCE:
            return 'F';
        case ROCK:
            return 'R';
    }

    switch (this->board.at(pos.x).at(pos.y).hasFood) {
        case NONE_FOOD:
            break;
        case CANE:
            return 'c';
        case CHERRY:
            return 'h';
        case COOKIE_BROWN:
            return 'b';
        case COOKIE_CHOCO:
            return 'o';
        case COOKIE_PINK:
            return 'p';
        case MUSHROOM_BROWN:
            return 'm';
        case MUSHROOM_RED:
            return 'n';
    }

    return '_';
}

void Board::SetDefaultBoard() {
    std::vector<std::vector<Field>> temp(
            this->width, std::vector<Field>(
                    this->height, {
                        NONE_OBSTACLE,
                        NONE_FOOD,
                        false}));

    this->board = temp;
}

void Board::CreateLevelCustomizedBoard() {
    if (this->gameManager.IsDebug())
        return;
}

void Board::SetObstacleOnField(ObstacleType obsType, sf::Vector2i pos) {
    if (!IsFieldFree(pos))
        return;

    this->board.at(pos.x).at(pos.y).hasObstacle = obsType;
    ++obstaclesCounter;
}

void Board::RemoveObstacleFromField(sf::Vector2i pos) {
    if (IsFieldFree(pos))
        return;

    this->board.at(pos.x).at(pos.y).hasObstacle = NONE_OBSTACLE;
    --obstaclesCounter;
}

void Board::SetFoodOnField(FoodType foodType, sf::Vector2i pos) {
    if (!IsFieldFree(pos))
        return;

    this->board.at(pos.x).at(pos.y).hasFood = foodType;
    ++foodCounter;
}

void Board::RemoveFoodFromField(sf::Vector2i pos) {
    if (IsFieldFree(pos))
        return;

    this->board.at(pos.x).at(pos.y).hasFood = NONE_FOOD;
    --foodCounter;
}

void Board::SetExitFieldEnable() {
    if (this->gameManager.GetGameMode() == CAMPAIGN) {
        SetFieldAsLevelExit({1,1});
        return;
    }

}

void Board::SetFieldAsLevelExit(sf::Vector2i pos) {
    if (!IsFieldFree(pos))
        return;

    this->board.at(pos.x).at(pos.y).isExit = true;
    this->isExitAvailable = true;
}

void Board::ClearField(sf::Vector2i pos) {
    if (IsFieldFree(pos))
        return;

    if (this->board.at(pos.x).at(pos.y).hasObstacle != NONE_OBSTACLE) {
        RemoveObstacleFromField(pos);
        return;
    }

    if (this->board.at(pos.x).at(pos.y).hasFood != NONE_FOOD) {
        RemoveFoodFromField(pos);
        return;
    }

    this->board.at(pos.x).at(pos.y).isExit = false;
    this->isExitAvailable = false;
}

void Board::DebugDisplay() const {
    for (int y = 0; y < this->height; ++y)
    {
        for (int x = 0; x < this->width; ++x)
            std::cout << GetFieldInfo({x, y});

        std::cout << "\n";
    }
}