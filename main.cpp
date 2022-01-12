#include "src/game_manager.h"
#include "src/states/state_menu.h"
#include "src/game_logic/board/board.h"
#include <iostream>

int main()
{
    GameManager manager;
    manager.GetCurrentState()->Update(sf::seconds(0));

    Board gameBoard;
    gameBoard.SetObstacleOnField(ROCK, {5,1});
    gameBoard.SetFoodOnField(COOKIE_PINK, {7,1});
    gameBoard.SetFoodOnField(COOKIE_PINK, {5,1});
    std::cout << "\n\n" << gameBoard.GetFoodCount() << "\n\n";
    std::cout << "\n\n" << gameBoard.GetObstaclesCount() << "\n\n";
    gameBoard.DebugDisplay();
    std::cout << "\n\n\n\n\n";
    gameBoard.ClearField({5,1});
    gameBoard.ClearField({7,1});
    gameBoard.DebugDisplay();

    std::cout << "\n\n" << gameBoard.GetFoodCount() << "\n\n";
    std::cout << "\n\n" << gameBoard.GetObstaclesCount() << "\n\n";

    return 0;
}