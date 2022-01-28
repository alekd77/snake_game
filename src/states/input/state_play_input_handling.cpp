#include "state_play_input_handling.h"

StatePlayInputHandling::StatePlayInputHandling(
        GameManager* gameMgr,
        Snake& snake)
        : InputHandlingInterface(gameMgr),
        snakeModel(snake) {}

void StatePlayInputHandling::TurnUp() {
    if (this->currentEvent.key.code != sf::Keyboard::Up and
            this->currentEvent.key.code != sf::Keyboard::W)
        return;

    this->snakeModel.Turn({0, -1});
}

void StatePlayInputHandling::TurnRight() {
    if (this->currentEvent.key.code != sf::Keyboard::Right and
            this->currentEvent.key.code != sf::Keyboard::D)
        return;

    this->snakeModel.Turn({1, 0});

}

void StatePlayInputHandling::TurnDown() {
    if (this->currentEvent.key.code != sf::Keyboard::Down and
            this->currentEvent.key.code != sf::Keyboard::S)
        return;

    this->snakeModel.Turn({0, 1});
}

void StatePlayInputHandling::TurnLeft() {
    if (this->currentEvent.key.code != sf::Keyboard::Left and
            this->currentEvent.key.code != sf::Keyboard::A)
        return;

    this->snakeModel.Turn({-1, 0});
}

void StatePlayInputHandling::TurnUpdate() {
    TurnUp();
    TurnRight();
    TurnDown();
    TurnLeft();
}

void StatePlayInputHandling::Update() {
    while (UpdateCurrentEvent()) {
        if (this->currentEvent.type == sf::Event::Closed)
            this->renderWindow.close();

        if (this->currentEvent.type == sf::Event::KeyPressed) {

            if (this->gameManager->GetGameStatus() == PAUSED)
                this->gameManager->SetGameStatus(RUNNING);

            TurnUpdate();
        }
    }
}
