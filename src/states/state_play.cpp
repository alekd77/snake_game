#include "state_play.h"
#include <iostream>

StatePlay::StatePlay(GameManager* manager) : StateInterface(manager),
                board(*manager), snake(*manager),
                view(this->gameManager,
                     this->board,
                     this->snake),
                inputHandling(
                        this->gameManager,
                        this->snake) {}

bool StatePlay::IsLevelFinished() {
    if (this->gameManager->GetGameStatus() == FINISHED_GAME)
        return true;

    if (this->gameManager->GetGameStatus() == FINISHED_LEVEL_LOSS)
        return true;

    if (this->gameManager->GetGameStatus() == FINISHED_LEVEL_WIN)
        return true;

    return false;
}

void StatePlay::SetScoreGoalPerLevel() {
    this->gameManager->SetCurrentScoreLevelGoal(
            this->gameManager->GetCurrentScore() +
                this->gameManager->GetCurrentGameLevel() * 40);
}

void StatePlay::InitStateSettings() {
    std::cout << "\nEntered play state.\n";

    this->gameManager->SetGameStatus(PAUSED);
    this->gameManager->SetCurrentLeftTime(
            this->gameManager->GetTimePerLevel());
    SetScoreGoalPerLevel();
    this->board.InitLevelSettings();
    this->snake.InitLevelSettings();
    this->view.InitStateViewSettings();
}

void StatePlay::HandleInput() {
    this->inputHandling.Update();
}

void StatePlay::UpdateGameStatus() {
    if (this->gameManager->GetLeftLives() < 1) {
        this->gameManager->SetGameStatus(FINISHED_GAME);
        return;
    }

    if (this->gameManager->GetCurrentGameLevel() >
            this->gameManager->GetMaxCampaignLevel()) {
        this->gameManager->SetGameStatus(FINISHED_GAME);
        return;
    }

    if (!this->snake.IsSnakeAlive()) {
        if (this->gameManager->GetLeftLives() > 1)
            this->gameManager->SetGameStatus(FINISHED_LEVEL_LOSS);
        else
            this->gameManager->SetGameStatus(FINISHED_GAME);

        return;
    }

    if (this->gameManager->GetCurrentLeftTime()
            <= sf::seconds(0)) {
        if (this->gameManager->GetLeftLives() > 1)
            this->gameManager->SetGameStatus(FINISHED_LEVEL_LOSS);
        else
            this->gameManager->SetGameStatus(FINISHED_GAME);

        return;
    }
}

void StatePlay::UpdateLeftTime() {
    this->gameManager->SetCurrentLeftTime(
            this->gameManager->GetCurrentLeftTime()
                    - this->levelElapsedTime.getElapsedTime());
    this->levelElapsedTime.restart();
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

}

void StatePlay::UpdateView() {
    this->view.UpdateStateView();
}

void StatePlay::Update(sf::Time deltaTime) {
    UpdateGameStatus();

    if (IsLevelFinished()) {
        ExitStateSettings();
        return;
    }

    if (this->gameManager->GetGameStatus() != RUNNING) {
        this->levelElapsedTime.restart();
        return;
    }

    //std::cout << "\nPlay state...\n";

    UpdateLeftTime();
    UpdateBoard();
    UpdateSnake(deltaTime);
    //UpdateCollision();
    UpdateView();
}

void StatePlay::Draw(sf::Time deltaTime) {
    this->view.DrawStateView();
}

void StatePlay::FinishedLevelWinSettings() {
    this->gameManager->SetCurrentGameLevel(
            this->gameManager->GetCurrentGameLevel() + 1);
}

void StatePlay::FinishedLevelLossSettings() {
    this->gameManager->SetLeftLives(
            this->gameManager->GetLeftLives() - 1);
}

void StatePlay::FinishedLevelSettings() {
    if (this->gameManager->GetGameStatus() == FINISHED_LEVEL_WIN)
        FinishedLevelWinSettings();
    else
        FinishedLevelLossSettings();

    this->gameManager->ChangeState(
            std::make_shared<StatePlay>(this->gameManager));
    this->gameManager->GetCurrentState()->InitStateSettings();
}

void StatePlay::FinishedGameSettings() {
    this->gameManager->GetWindowToRender().close();
    //this->gameManager->ChangeState(
    //      std::make_shared<StateLeaderboard>(this->gameManager));
    //this->gameManager->GetCurrentState()->InitStateSettings();
}

void StatePlay::ExitStateSettings() {
    if (this->gameManager->GetGameStatus() == FINISHED_GAME)
        FinishedGameSettings();
    else
        FinishedLevelSettings();

    std::cout << "\nExited play state.\n";
}