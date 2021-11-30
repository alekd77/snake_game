#include "src/game_manager.h"
#include "src/state_menu.h"
#include <iostream>

int main()
{
    GameManager manager;
    StateMenu menu(&manager);

    std::cout << manager.GetGameMode() << std::endl;
    manager.PushState(std::make_shared<StateMenu>(menu));

    manager.GetCurrentState()->InitStateSettings();
    std::cout << manager.GetGameMode() << std::endl;

    return 0;
}