#ifndef SNAKE_NEW_GAME_MANAGER_H
#define SNAKE_NEW_GAME_MANAGER_H

#include <stack>
#include <queue>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../assets_managers/assets_manager.h"

enum GameMode {GM_NONE, CAMPAIGN, ENDLESS, GM_DEBUG};
enum DifficultyLevel {DL_NONE, EASY, NORMAL, HARD, DL_DEBUG};
enum GameStatus {GS_NONE, RUNNING, PAUSED,
        FINISHED_LOSS, FINISHED_LEVEL, FINISHED_WIN};

class StateInterface;

class GameManager {
private:
    std::stack<std::shared_ptr<StateInterface>> gameStatesStack;
    bool isDebug;
    GameMode gameMode;
    DifficultyLevel difficultyLevel;
    GameStatus gameStatus;
    int currentGameLevel;
    const int maxCampaignLevel = 10;
    sf::Time timePerLevel;
    double levelTargetPointsMultiplier;
    int leftLives;
    long long unsigned int currentScore;

    sf::RenderWindow gameWindow;
    AssetsManager assetsManager;

public:
    explicit GameManager(bool debug);
    ~GameManager();

    void PushState(const std::shared_ptr<StateInterface>& state);
    void PopState();
    void ClearGameStatesStack();
    void ChangeState(const std::shared_ptr<StateInterface>& state);
    void InitGameManagerSettings();

    bool IsDebug() const;
    std::shared_ptr<StateInterface> GetCurrentState() const;
    GameMode GetGameMode() const;
    DifficultyLevel GetDifficultyLevel() const;
    GameStatus GetGameStatus() const;
    int GetCurrentGameLevel() const;
    int GetMaxCampaignLevel() const;
    sf::Time GetTimePerLevel() const;
    double GetLevelTargetPointsMultiplier() const;
    int GetLeftLives() const;
    long long unsigned int GetCurrentScore() const;
    sf::RenderWindow& GetWindowToRender();
    AssetsManager& GetAssetsManagerRef();

    void SetGameMode(GameMode mode);
    void SetDifficultyLevel(DifficultyLevel difficulty);
    void SetGameStatus(GameStatus status);
    void SetCurrentGameLevel(int level);
    void SetTimePerLevel(sf::Time time);
    void SetLevelTargetPointsMultiplier(double multiplier);
    void SetLeftLives(int lives);
    void SetCurrentScore(int score);

    void DisplayBasicGameInfo();

    // View
    void CreateWindow();


    void MainGameLoop();
};
#endif //SNAKE_NEW_GAME_MANAGER_H
