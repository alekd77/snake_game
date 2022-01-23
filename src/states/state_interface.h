#ifndef SNAKE_NEW_STATE_INTERFACE_H
#define SNAKE_NEW_STATE_INTERFACE_H

#include "../game_manager.h"

class StateInterface {
protected:
    GameManager* gameManager;

public:
    explicit StateInterface(GameManager* manager)
        : gameManager(manager) {};
    virtual ~StateInterface() = default;

    virtual void InitStateSettings() = 0;
    virtual void HandleInput() = 0;
    virtual void Update(sf::Time deltaTime) = 0;
    virtual void Draw(sf::Time deltaTime) = 0;
    virtual void ExitStateSettings() = 0;
};
#endif //SNAKE_NEW_STATE_INTERFACE_H
