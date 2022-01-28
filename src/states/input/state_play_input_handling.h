#ifndef MAIN_CPP_STATE_PLAY_INPUT_HANDLING_H
#define MAIN_CPP_STATE_PLAY_INPUT_HANDLING_H

#include "input_handling_interface.h"
#include "snake.h"

class StatePlayInputHandling
        : public InputHandlingInterface {
private:
    Snake& snakeModel;

public:
    StatePlayInputHandling(
            GameManager* gameMgr,
            Snake& snake);

    void TurnUp();
    void TurnRight();
    void TurnDown();
    void TurnLeft();
    void TurnUpdate();

    void Update() override;
};

#endif //MAIN_CPP_STATE_PLAY_INPUT_HANDLING_H
