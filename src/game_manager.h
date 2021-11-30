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

public:
    GameManager();
    ~GameManager();

    void PushState(const std::shared_ptr<StateInterface>& state);
    void PopState();
    void ClearGameStatesStack();
    void ChangeState(const std::shared_ptr<StateInterface>& state);

    std::shared_ptr<StateInterface> GetCurrentState() const;

    void SetGameMode(GameMode mode);
    void SetDifficultyLevel(DifficultyLevel difficulty);
    void SetGameStatus(GameStatus status);

    const GameMode& GetGameMode() const {return this->gameMode;}
};
#endif //SNAKE_NEW_GAME_MANAGER_H
