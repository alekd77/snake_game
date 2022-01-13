#ifndef SNAKE_NEW_STATE_MENU_H
#define SNAKE_NEW_STATE_MENU_H

#include "state_interface.h"

class StateMenu : public StateInterface {
public:
    explicit StateMenu(GameManager* manager);

    void InitStateSettings() override;
    void DebugInitSettings();
    void HandleInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw(sf::Time deltaTime) override;
    void ExitStateSettings() override;

    bool IsMenuActive() const;

    void LoadLevelsSettings();
    void GameModeBasedSettings();
    void CampaignModeSettings();
    void EndlessModeSettings();
    void DifficultyLevelBasedSettings();
    void EasyDifficultySettings();
    void NormalDifficultySettings();
    void HardDifficultySettings();
};
#endif //SNAKE_NEW_STATE_MENU_H
