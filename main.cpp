#include "src/game_manager.h"
#include "state_menu.h"
#include "board.h"
#include "snake.h"
#include <iostream>

int main()
{
    GameManager manager(true);
    manager.GetCurrentState()->Update(sf::seconds(0));
    manager.GetCurrentState()->Update(sf::seconds(0));
    manager.GetCurrentState()->Update(sf::seconds(0));
    manager.GetCurrentState()->Update(sf::seconds(0));
    manager.SetGameStatus(FINISHED_LEVEL);
    manager.GetCurrentState()->Update(sf::seconds(0));
    manager.SetGameStatus(FINISHED_LEVEL);
    manager.GetCurrentState()->Update(sf::seconds(0));

    return 0;
}