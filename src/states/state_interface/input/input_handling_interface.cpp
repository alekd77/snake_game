#include "input_handling_interface.h"

InputHandlingInterface::InputHandlingInterface(
        GameManager* gameMgr)
        : gameManager(gameMgr),
        renderWindow(this->gameManager->GetWindowToRender()) {}

bool InputHandlingInterface::UpdateCurrentEvent() {
    return this->renderWindow.pollEvent(this->currentEvent);
}