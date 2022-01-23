#ifndef MAIN_CPP_STATE_PLAY_H
#define MAIN_CPP_STATE_PLAY_H

#include "state_interface.h"
#include "state_play_view.h"

class StatePlay : public StateInterface {
private:
    Board board;
    Snake snake;
    StatePlayView view;

    long long unsigned int scoreLevelGoal;

public:
    explicit StatePlay(GameManager* manager);

    bool IsLevelFinished();

    void InitStateSettings() override;
    void SetScoreGoalPerLevel();

    void HandleInput() override;

    void Update(sf::Time deltaTime) override;
    void UpdateLeftLives();
    void UpdateExitLevelField();
    void UpdateGameStatus();
    void UpdateBoard();
    void UpdateSnake();
    void UpdateCollision();
    void UpdateView();

    void Draw(sf::Time deltaTime) override;

    void ExitStateSettings() override;
};
#endif
