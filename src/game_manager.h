#ifndef SNAKE_NEW_GAME_MANAGER_H
#define SNAKE_NEW_GAME_MANAGER_H

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class GameManager {
private:
    std::stack<GameState*> gameStatesStack;

public:
    GameManager();
    ~GameManager();

    void PushState(GameState* state);
    void PopState();
    void ClearGameStatesStack();
    void ChangeState(GameState* state);

    GameState* GetCurrentState();
};
#endif //SNAKE_NEW_GAME_MANAGER_H
