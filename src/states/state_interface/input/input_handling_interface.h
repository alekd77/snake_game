#ifndef MAIN_CPP_INPUT_HANDLING_INTERFACE_H
#define MAIN_CPP_INPUT_HANDLING_INTERFACE_H

#include "../game_manager.h"

class InputHandlingInterface {
protected:
    GameManager* gameManager;
    sf::RenderWindow& renderWindow;
    sf::Event currentEvent;
public:
    explicit InputHandlingInterface(GameManager* gameMgr);
    ~InputHandlingInterface() = default;

    bool UpdateCurrentEvent();
    virtual void Update() = 0;
};
#endif //MAIN_CPP_INPUT_HANDLING_INTERFACE_H
