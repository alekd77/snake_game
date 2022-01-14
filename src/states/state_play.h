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

    void InitStateSettings() override;
    void HandleInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw(sf::Time deltaTime) override;
    void ExitStateSettings() override;

    bool IsLevelFinished();

    void SetScoreGoalPerLevel();

    void UpdateGameStatus();
    void UpdateBoard();
    void UpdateSnake();
    void UpdateCollision();

    void UpdateLeftLives();
    void UpdateExitLevelField();
};
#endif
