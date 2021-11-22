#ifndef SNAKE_NEW_GAME_STATE_H
#define SNAKE_NEW_GAME_STATE_H

#include "game_manager.h"

class GameState {
private:
    GameManager* gameManager;

public:
    explicit GameState(GameManager* manager) : gameManager(manager) {};
    ~GameState() = default;

    virtual void InitStateSettings() = 0;
    virtual void HandleInput() = 0;
    virtual void Update(sf::Time deltaTime) = 0;
    virtual void Draw(sf::Time deltaTime) = 0;
    virtual void ExitStateSettings() = 0;
};
#endif //SNAKE_NEW_GAME_STATE_H
