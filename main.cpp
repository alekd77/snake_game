#include "src/game_manager.h"
#include "src/state_menu.h"
#include <iostream>

int main()
{
    GameManager manager;
    manager.GetCurrentState()->Update(sf::seconds(0));

    return 0;
}