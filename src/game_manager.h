#ifndef SNAKE_NEW_GAME_MANAGER_H
#define SNAKE_NEW_GAME_MANAGER_H

#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>

enum GameMode {GM_DEBUG, CAMPAIGN, ENDLESS};
enum DifficultyLevel {DL_DEBUG, EASY, NORMAL, HARD};
enum GameStatus {GS_DEBUG, RUNNING, PAUSED,
        FINISHED_LOSS, FINISHED_LEVEL, FINISHED_WIN};

class StateInterface;

class GameManager {
private:
    std::stack<std::shared_ptr<StateInterface>> gameStatesStack;

    GameMode gameMode;
    DifficultyLevel difficultyLevel;
    GameStatus gameStatus;
    int currentGameLevel;
    const int maxCampaignLevel = 50;
    sf::Time timePerLevel;
    double levelTargetPointsMultiplier;
    int leftLives;
    int currentScore;

public:
    GameManager();
    ~GameManager();

    void PushState(const std::shared_ptr<StateInterface>& state);
    void PopState();
    void ClearGameStatesStack();
    void ChangeState(const std::shared_ptr<StateInterface>& state);
    void InitGameManagerSettings();

    std::shared_ptr<StateInterface> GetCurrentState() const;
    GameMode GetGameMode() const;
    DifficultyLevel GetDifficultyLevel() const;
    GameStatus GetGameStatus() const;
    int GetCurrentGameLevel() const;
    int GetMaxCampaignLevel() const;
    sf::Time GetTimePerLevel() const;
    double GetLevelTargetPointsMultiplier() const;
    int GetLeftLives() const;
    int GetCurrentScore() const;

    void SetGameMode(GameMode mode);
    void SetDifficultyLevel(DifficultyLevel difficulty);
    void SetGameStatus(GameStatus status);
    void SetCurrentGameLevel(int level);
    void SetTimePerLevel(sf::Time time);
    void SetLevelTargetPointsMultiplier(double multiplier);
    void SetLeftLives(int lives);
    void SetCurrentScore(int score);

    void DisplayBasicGameInfo();
};
#endif //SNAKE_NEW_GAME_MANAGER_H
