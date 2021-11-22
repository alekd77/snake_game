#include "game_manager.h"

GameManager::GameManager() {
    ClearGameStatesStack();

}

GameManager::~GameManager() {
    ClearGameStatesStack();
}

void GameManager::PushState(GameState* state) {
    this->gameStatesStack.push(state);
}

void GameManager::PopState() {
    if (this->gameStatesStack.empty())
        return;

    this->gameStatesStack.pop();
}

void GameManager::ClearGameStatesStack() {
    while (!this->gameStatesStack.empty())
        PopState();
}

void GameManager::ChangeState(GameState* state) {
    PopState();
    PushState(state);
}

GameState* GameManager::GetCurrentState() {
    return this->gameStatesStack.top();
}
