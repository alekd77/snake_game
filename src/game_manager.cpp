#include "game_manager.h"
#include "states/state_menu.h"
#include <iostream>
#include <string>

GameManager::GameManager(bool debug) {
    this->isDebug = debug;
    InitGameManagerSettings();
    CreateWindow();

    // Creates init state which is menu and add it to states stack.
    PushState(std::make_shared<StateMenu>(this));
    GetCurrentState()->InitStateSettings();
}

GameManager::~GameManager() {
    ClearGameStatesStack();
}

void GameManager::PushState(const std::shared_ptr<StateInterface>& state) {
    this->gameStatesStack.push(state);
}

void GameManager::PopState() {
    if (this->gameStatesStack.empty())
        return;

    this->gameStatesStack.pop();
}

void GameManager::ClearGameStatesStack() {
    while (!this->gameStatesStack.empty())
        PopState();
}

void GameManager::ChangeState(const std::shared_ptr<StateInterface>& state) {
    PopState();
    PushState(state);
}

void GameManager::InitGameManagerSettings() {
    ClearGameStatesStack();
    this->gameStatus = GS_NONE;
    this->currentGameLevel = 0;
    this->timePerLevel = sf::seconds(0);
    this->levelTargetPointsMultiplier = 0.0;
    this->leftLives = 0;
    this->currentScore = 0;

    if (this->isDebug) {
        this->gameMode = GM_DEBUG;
        this->difficultyLevel = DL_DEBUG;
        return;
    }

    this->gameMode = GM_NONE;
    this->difficultyLevel = DL_NONE;
}

bool GameManager::IsDebug() const {
    return this->isDebug;
}

std::shared_ptr<StateInterface> GameManager::GetCurrentState() const {
    return this->gameStatesStack.top();
}

GameMode GameManager::GetGameMode() const {
    return this->gameMode;
}

DifficultyLevel GameManager::GetDifficultyLevel() const {
    return this->difficultyLevel;
}

GameStatus GameManager::GetGameStatus() const {
    return this->gameStatus;
}

int GameManager::GetCurrentGameLevel() const {
    return this->currentGameLevel;
}

int GameManager::GetMaxCampaignLevel() const {
    return this->maxCampaignLevel;
}

sf::Time GameManager::GetTimePerLevel() const {
    return this->timePerLevel;
}

double GameManager::GetLevelTargetPointsMultiplier() const {
    return this->levelTargetPointsMultiplier;
}

int GameManager::GetLeftLives() const {
    return this->leftLives;
}

long long unsigned int GameManager::GetCurrentScore() const {
    return this->currentScore;
}

sf::Window& GameManager::GetWindowToRender() {
    return this->gameWindow;
}

void GameManager::SetGameMode(GameMode mode) {
    this->gameMode = mode;
}

void GameManager::SetDifficultyLevel(DifficultyLevel difficulty) {
    this->difficultyLevel = difficulty;
}

void GameManager::SetGameStatus(GameStatus status) {
    this->gameStatus = status;
}

void GameManager::SetCurrentGameLevel(int level) {
    this->currentGameLevel = level;
}

void GameManager::SetTimePerLevel(sf::Time time) {
    this->timePerLevel = time;
}

void GameManager::SetLevelTargetPointsMultiplier(double multiplier) {
    this->levelTargetPointsMultiplier = multiplier;
}

void GameManager::SetLeftLives(int lives) {
    this->leftLives = lives;
}

void GameManager::SetCurrentScore(int score) {
    this->currentScore = score;
}

void GameManager::DisplayBasicGameInfo() {
    std::string mode, difficulty, status;

    switch (this->gameMode) {
        case GM_NONE: {
            mode = "GM_NONE";
            break;
        }
        case CAMPAIGN: {
            mode = "CAMPAIGN";
            break;
        }
        case ENDLESS: {
            mode = "ENDLESS";
            break;
        }
        case GM_DEBUG: {
            mode = "GM_DEBUG";
            break;
        }
    }

    switch (this->difficultyLevel) {
        case DL_NONE: {
            difficulty = "DL_NONE";
            break;
        }
        case EASY: {
            difficulty = "EASY";
            break;
        }
        case NORMAL: {
            difficulty = "NORMAL";
            break;
        }
        case HARD: {
            difficulty = "HARD";
            break;
        }
        case DL_DEBUG: {
            difficulty = "DL_DEBUG";
            break;
        }
    }

    switch (this->gameStatus) {
        case GS_NONE: {
            status = "GS_DEBUG";
            break;
        }
        case RUNNING: {
            status = "RUNNING";
            break;
        }
        case PAUSED: {
            status = "PAUSED";
            break;
        }
        case FINISHED_LOSS: {
            status = "FINISHED_LOSS";
            break;
        }
        case FINISHED_LEVEL: {
            status = "FINISHED_LEVEL";
            break;
        }
        case FINISHED_WIN: {
            status = "FINISHED_WIN";
            break;
        }
    }

    std::cout << "\n\n***************************"
    << "\nGame mode: " << mode
    << "\nDifficulty level: " << difficulty
    << "\nGame status: " << status
    << "\nCurrent level: " << this->currentGameLevel
    << "\nTime per level: " << this->timePerLevel.asSeconds()
    << "\nLevel target points multiplier: " << this->levelTargetPointsMultiplier
    << "\nLeft lives: " << this->leftLives
    << "\nCurrent score: " << this->currentScore
    << "\n***************************\n";
}

void GameManager::CreateWindow() {
    this->gameWindow.create(sf::VideoMode(
            1260, 820),
                            "Snake");
    this->gameWindow.setFramerateLimit(60);
}

void GameManager::MainGameLoop() {
    sf::Clock mainLoopClock;

    while (this->gameWindow.isOpen())
    {
        sf::Time frameElapsedTime = mainLoopClock.restart();
        sf::Time deltaTime = frameElapsedTime;

        if (GetCurrentState() == nullptr)
            continue;

        GetCurrentState()->HandleInput();
        GetCurrentState()->Update(deltaTime);
        GetCurrentState()->Draw(deltaTime);

        this->gameWindow.display();
    }
}


