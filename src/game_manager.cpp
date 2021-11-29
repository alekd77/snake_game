#include "game_manager.h"

GameManager::GameManager() {
    ClearGameStatesStack();
    this->gameMode = GM_DEBUG;
    this->difficultyLevel = DL_DEBUG;
    this->gameStatus = GS_DEBUG;

}

GameManager::~GameManager() {
    ClearGameStatesStack();
}

void GameManager::PushState(const std::shared_ptr<StateInterface>& state) {
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

void GameManager::ChangeState(const std::shared_ptr<StateInterface>& state) {
    PopState();
    PushState(state);
}

const std::shared_ptr<StateInterface>& GameManager::GetCurrentState() const {
    return this->gameStatesStack.top();
}

void GameManager::SetGameMode(GameMode mode) {
    this->gameMode = mode;
}

void GameManager::SetDifficultyLevel(DifficultyLevel difficulty) {
    this->difficultyLevel = difficulty;
}

void GameManager::SetGameStatus(GameStatus status) {
    this->gameStatus = status;
}
