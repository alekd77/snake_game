#include "state_menu.h"
#include "state_play/state_play.h"
#include <iostream>

StateMenu::StateMenu(GameManager* manager)
    : StateInterface(manager) {}

void StateMenu::InitStateSettings() {
    std::cout << "\nEntered menu state.\n";

    if (!this->gameManager->IsDebug())
        return;

    DebugInitSettings();
}

void StateMenu::HandleInput() {

}

void StateMenu::Update(sf::Time deltaTime) {
    std::cout << "\nMenu state...\n";

    if (!IsMenuActive())
        ExitStateSettings();
}

void StateMenu::Draw(sf::Time deltaTime) {

}

void StateMenu::ExitStateSettings() {
    LoadLevelsSettings();

    this->gameManager->ChangeState(
            std::make_shared<StatePlay>(this->gameManager));
    this->gameManager->GetCurrentState()->InitStateSettings();

    std::cout << "\nExited menu state.\n";
}

bool StateMenu::IsMenuActive() const {
    if (this->gameManager->GetGameMode() == GM_NONE)
        return true;

    if (this->gameManager->GetDifficultyLevel() == DL_NONE)
        return true;

    return false;
}

void StateMenu::DebugInitSettings() {
    this->gameManager->SetGameMode(CAMPAIGN);
    this->gameManager->SetDifficultyLevel(NORMAL);
}

void StateMenu::LoadLevelsSettings() {
    DifficultyLevelBasedSettings();
    GameModeBasedSettings();
    this->gameManager->SetCurrentGameLevel(1);
    this->gameManager->SetCurrentScore(0);
}

void StateMenu::GameModeBasedSettings() {
    switch (this->gameManager->GetGameMode()) {
        case GM_NONE:
            return;
        case CAMPAIGN: {
            CampaignModeSettings();
            return;
        }
        case ENDLESS: {
            EndlessModeSettings();
            return;
        }
        case GM_DEBUG:
            return;
    }
}

void StateMenu::CampaignModeSettings() {

}

void StateMenu::EndlessModeSettings() {
    this->gameManager->SetLeftLives(1);
}

void StateMenu::DifficultyLevelBasedSettings() {
    switch (this->gameManager->GetDifficultyLevel()) {
        case DL_NONE:
            return;
        case EASY: {
            EasyDifficultyLevelSettings();
            return;
        }
        case NORMAL: {
            NormalDifficultyLevelSettings();
            return;
        }
        case HARD: {
            HardDifficultyLevelSettings();
            return;
        }
        case DL_DEBUG:
            return;
    }
}

void StateMenu::EasyDifficultyLevelSettings() {
    this->gameManager->SetLeftLives(5);
    this->gameManager->SetTimePerLevel(sf::seconds(60));
    this->gameManager->SetLevelTargetPointsMultiplier(0.3);
}

void StateMenu::NormalDifficultyLevelSettings() {
    this->gameManager->SetLeftLives(3);
    this->gameManager->SetTimePerLevel(sf::seconds(45));
    this->gameManager->SetLevelTargetPointsMultiplier(0.35);
}

void StateMenu::HardDifficultyLevelSettings() {
    this->gameManager->SetLeftLives(1);
    this->gameManager->SetTimePerLevel(sf::seconds(30));
    this->gameManager->SetLevelTargetPointsMultiplier(0.4);
}


