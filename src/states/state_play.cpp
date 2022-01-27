#include "state_play.h"
#include <iostream>

StatePlay::StatePlay(GameManager* manager) : StateInterface(manager),
                board(*manager), snake(*manager),
                view(this->gameManager,
                     this->board,
                     this->snake) {}

bool StatePlay::IsLevelFinished() {
    if (this->gameManager->GetGameStatus() == FINISHED_LOSS)
        return true;

    if (this->gameManager->GetGameStatus() == FINISHED_LEVEL)
        return true;

    if (this->gameManager->GetGameStatus() == FINISHED_WIN)
        return true;

    return false;
}

void StatePlay::InitStateSettings() {
    std::cout << "\nEntered play state.\n";

    this->gameManager->SetGameStatus(PAUSED);
    this->gameManager->SetCurrentGameLevel(
            this->gameManager->GetCurrentGameLevel() + 1);
    this->gameManager->SetCurrentLeftTime(
            this->gameManager->GetTimePerLevel());
    SetScoreGoalPerLevel();
    this->board.InitLevelSettings();
    this->snake.InitLevelSettings();
    this->view.InitStateViewSettings();
}

void StatePlay::SetScoreGoalPerLevel() {
    this->gameManager->SetCurrentScoreLevelGoal(
            this->gameManager->GetCurrentScore() +
                    this->gameManager->GetCurrentGameLevel() * 40);
}

void StatePlay::HandleInput() {

}

void StatePlay::UpdateGameStatus() {
    if (this->gameManager->GetLeftLives() < 1)
        this->gameManager->SetGameStatus(FINISHED_LOSS);
}

void StatePlay::UpdateLeftTime() {}

void StatePlay::UpdateLeftLives() {
    if (this->snake.GetCurrentHealth() > 0)
        return;

    this->gameManager->SetLeftLives(
            this->gameManager->GetLeftLives() - 1);
    this->gameManager->SetGameStatus(FINISHED_LEVEL);
}

void StatePlay::UpdateExitLevelField() {
    if (this->gameManager->GetCurrentScore() <
            this->gameManager->GetCurrentScoreLevelGoal())
        return;

    this->board.SetExitFieldEnable();
}

void StatePlay::UpdateBoard() {
    UpdateExitLevelField();
}

void StatePlay::UpdateSnake(sf::Time deltaTime) {
    this->snake.Update(deltaTime);
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

void StatePlay::UpdateView() {
    this->view.UpdateStateView();
}

void StatePlay::Update(sf::Time deltaTime) {
    if (this->gameManager->GetGameStatus() != RUNNING)
        return;

    std::cout << "\nPlay state...\n";

    UpdateGameStatus();
    UpdateLeftLives();
    UpdateBoard();
    UpdateSnake(deltaTime);
    //UpdateCollision();
    UpdateView();

    if (IsLevelFinished())
        ExitStateSettings();
}

void StatePlay::Draw(sf::Time deltaTime) {
    this->view.DrawStateView();
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