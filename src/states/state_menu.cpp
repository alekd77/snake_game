#include "state_menu.h"
#include <iostream>

StateMenu::StateMenu(GameManager* manager)
    : StateInterface(manager) {}

void StateMenu::InitStateSettings() {
    std::cout << "\nEntered menu state.\n";
    DebugInitSettings();
}

void StateMenu::DebugInitSettings() {
    this->gameManager->SetGameMode(CAMPAIGN);
    this->gameManager->SetDifficultyLevel(NORMAL);
}

void StateMenu::HandleInput() {

}

void StateMenu::Update(sf::Time deltaTime) {
    if (!IsMenuActive())
        ExitStateSettings();
}

void StateMenu::Draw(sf::Time deltaTime) {

}

void StateMenu::ExitStateSettings() {
    LoadLevelsSettings();

    std::cout << "\nExited menu state.\n";

    //this->gameManager->ChangeState(std::make_shared<StatePlay>(this->gameManager));
    //this->gameManager->GetCurrentState()->InitStateSettings();
}

bool StateMenu::IsMenuActive() const {
    if (this->gameManager->GetGameMode() == GM_DEBUG)
        return true;

    if (this->gameManager->GetDifficultyLevel() == DL_DEBUG)
        return true;

    return false;
}

void StateMenu::LoadLevelsSettings() {
    GameModeBasedSettings();
    DifficultyLevelBasedSettings();

    this->gameManager->SetGameStatus(PAUSED);
    this->gameManager->SetCurrentGameLevel(1);
    this->gameManager->SetCurrentScore(0);

    if (this->gameManager->GetGameMode() == ENDLESS)
        this->gameManager->SetLeftLives(1);
}

void StateMenu::GameModeBasedSettings() {
    if (this->gameManager->GetGameMode() == CAMPAIGN) {
        CampaignModeSettings();
        return;
    }

    EndlessModeSettings();
}

void StateMenu::CampaignModeSettings() {

}

void StateMenu::EndlessModeSettings() {

}

void StateMenu::DifficultyLevelBasedSettings() {
    if (this->gameManager->GetDifficultyLevel() == EASY) {
        EasyDifficultySettings();
        return;
    }

    if (this->gameManager->GetDifficultyLevel() == NORMAL) {
        NormalDifficultySettings();
        return;
    }

    HardDifficultySettings();
}

void StateMenu::EasyDifficultySettings() {
    this->gameManager->SetLeftLives(5);
    this->gameManager->SetTimePerLevel(sf::seconds(60));
    this->gameManager->SetLevelTargetPointsMultiplier(0.3);
}

void StateMenu::NormalDifficultySettings() {
    this->gameManager->SetLeftLives(3);
    this->gameManager->SetTimePerLevel(sf::seconds(45));
    this->gameManager->SetLevelTargetPointsMultiplier(0.35);
}

void StateMenu::HardDifficultySettings() {
    this->gameManager->SetLeftLives(1);
    this->gameManager->SetTimePerLevel(sf::seconds(30));
    this->gameManager->SetLevelTargetPointsMultiplier(0.4);
}


