#include "state_play.h"
#include <iostream>

StatePlay::StatePlay(GameManager* manager) : StateInterface(manager),
    board(*manager), snake(*manager) {
    this->scoreLevelGoal = 0;
}

void StatePlay::InitStateSettings() {
    std::cout << "\nEntered play state.\n";

    this->gameManager->SetGameStatus(PAUSED);
    this->gameManager->SetCurrentGameLevel(
            this->gameManager->GetCurrentGameLevel() + 1);
    SetScoreGoalPerLevel();
}

void StatePlay::HandleInput() {

}

void StatePlay::Update(sf::Time deltaTime) {
    std::cout << "\nPlay state...\n";

    UpdateGameStatus();
    UpdateLeftLives();
    UpdateBoard();
    UpdateSnake();
    UpdateCollision();

    if (IsLevelFinished())
        ExitStateSettings();
}

void StatePlay::Draw(sf::Time deltaTime) {

}

void StatePlay::ExitStateSettings() {
    if (this->gameManager->GetGameStatus() == FINISHED_LOSS or
            this->gameManager->GetGameStatus() == FINISHED_WIN) {
        //this->gameManager->ChangeState(
        //      std::make_shared<StateLeaderboard>(this->gameManager));
        //this->gameManager->GetCurrentState()->InitStateSettings();
    } else {
        this->gameManager->ChangeState(
                std::make_shared<StatePlay>(this->gameManager));
        this->gameManager->GetCurrentState()->InitStateSettings();
    }

    std::cout << "\nExited play state.\n";
}

bool StatePlay::IsLevelFinished() {
    if (this->gameManager->GetGameStatus() == FINISHED_LOSS)
        return true;

    if (this->gameManager->GetGameStatus() == FINISHED_LEVEL)
        return true;

    if (this->gameManager->GetGameStatus() == FINISHED_WIN)
        return true;

    return false;
}

void StatePlay::SetScoreGoalPerLevel() {
    this->scoreLevelGoal = this->gameManager->GetCurrentScore() +
            this->gameManager->GetCurrentGameLevel() * 40;
}

void StatePlay::UpdateGameStatus() {
    if (this->gameManager->GetLeftLives() < 1)
        this->gameManager->SetGameStatus(FINISHED_LOSS);
}

void StatePlay::UpdateBoard() {
    UpdateExitLevelField();
}

void StatePlay::UpdateSnake() {
    this->snake.Update();
}

void StatePlay::UpdateCollision() {
    // if (collision.isSnakeOnExitField) {
    //      if (this->gameManager->GetCurrentLevel == 50) {
    //          this->gameManager->SetGameStatus(FINISHED_WIN);
    //          return;
    //      }
    //   this->gameManager->SetGameStatus(FINISHED_LEVEL);
    // }
}

void StatePlay::UpdateLeftLives() {
    if (this->snake.GetCurrentHealth() > 0)
        return;

    this->gameManager->SetLeftLives(
            this->gameManager->GetLeftLives() - 1);
    this->gameManager->SetGameStatus(FINISHED_LEVEL);
}

void StatePlay::UpdateExitLevelField() {
    if (this->gameManager->GetCurrentScore() <
            this->scoreLevelGoal)
        return;

    this->board.SetExitFieldEnable();
}