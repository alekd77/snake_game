#ifndef MAIN_CPP_STATE_PLAY_H
#define MAIN_CPP_STATE_PLAY_H

#include "state_interface.h"
#include "state_play_view.h"

class StatePlay : public StateInterface {
private:
    Board board;
    Snake snake;
    StatePlayView view;

public:
    explicit StatePlay(GameManager* manager);

    bool IsLevelFinished();

    void SetScoreGoalPerLevel();
    void InitStateSettings() override;

    void HandleInput() override;

    void UpdateGameStatus();
    void UpdateLeftTime();
    void UpdateLeftLives();
    void UpdateExitLevelField();
    void UpdateBoard();
    void UpdateSnake(sf::Time deltaTime);
    void UpdateCollision();
    void UpdateView();
    void Update(sf::Time deltaTime) override;

    void Draw(sf::Time deltaTime) override;

    void ExitStateSettings() override;
};
#endif
