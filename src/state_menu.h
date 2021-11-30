#ifndef SNAKE_NEW_STATE_MENU_H
#define SNAKE_NEW_STATE_MENU_H

#include "state_interface.h"

class StateMenu : public StateInterface {
public:
    explicit StateMenu(GameManager* manager)
        : StateInterface(manager) {};
    void InitStateSettings() override;
    void HandleInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw(sf::Time deltaTime) override;
    void ExitStateSettings() override;

};
#endif //SNAKE_NEW_STATE_MENU_H
