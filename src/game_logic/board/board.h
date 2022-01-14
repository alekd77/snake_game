#ifndef SNAKE_NEW_BOARD_H
#define SNAKE_NEW_BOARD_H

#include "../../game_manager.h"
#include "obstacles.h"
#include "food.h"

struct Field {
    ObstacleType hasObstacle;
    FoodType hasFood;
    bool isExit;
};

class Board {
private:
    GameManager& gameManager;
    std::vector<std::vector<Field>> board;
    const int width = 40;
    const int height = 30;
    int obstaclesCounter;
    int foodCounter;
    bool isExitAvailable;

public:
    explicit Board(GameManager& manager);

    int GetBoardWidth() const;
    int GetBoardHeight() const;
    bool IsFieldOnBoard (sf::Vector2i pos) const;
    bool IsFieldFree(sf::Vector2i pos) const;
    bool IsLevelExitAvailable() const;
    int GetObstaclesCount() const;
    int GetFoodCount() const;
    char GetFieldInfo(sf::Vector2i pos) const;

    void SetDefaultBoard();
    void CreateLevelCustomizedBoard();
    void SetObstacleOnField(ObstacleType obsType,
                            sf::Vector2i pos);
    void RemoveObstacleFromField(sf::Vector2i pos);
    void SetFoodOnField(FoodType foodType,
                        sf::Vector2i pos);
    void RemoveFoodFromField(sf::Vector2i pos);
    void SetExitFieldEnable();
    void SetFieldAsLevelExit(sf::Vector2i pos);
    void ClearField(sf::Vector2i pos);

    void DebugDisplay() const;
};

#endif