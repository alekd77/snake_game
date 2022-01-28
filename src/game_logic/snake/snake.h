#ifndef SNAKE_NEW_SNAKE_H
#define SNAKE_NEW_SNAKE_H

#include "../../game_manager.h"
#include <deque>

enum BuffType {SPEED, HEALTH, XP};

class Snake {
private:
    GameManager& gameManager;
    std::deque<sf::Vector2f> tempSnakePos;
    std::deque<sf::Vector2i> snakePos;
    std::pair<int, int> currentDirection;
    float currentVelocity;
    int currentHealth;
    sf::Clock posUpdateElapsedTime;
    sf::Clock previousTurnElapsedTime;

public:
    explicit Snake(GameManager& manager);

    bool IsSnakeAlive() const;

    const std::deque<sf::Vector2i>& GetSnakePos() const;
    sf::Vector2i GetCurrentSnakeHeadPos() const;
    float GetCurrentVelocity() const;
    int GetCurrentHealth() const;

    void InitLevelSettings();
    void SetInitSnakePos();
    void SetCurrentVelocity(float velocity);
    void SetCurrentHealth(int health);

    sf::Vector2f GetDistanceCoveredBetweenFrames(
            sf::Time deltaTime) const;
    void UpdateTemporaryGridBasedPos(sf::Time deltaTime);
    bool IsPosUpdateAvailable() const;
    void UpdatePos();
    void Move(sf::Time deltaTime);

    bool IsTurnAvailable(std::pair<int, int> direction) const;
    void Turn(std::pair<int, int> direction);

    void Update(sf::Time deltaTime);

    void DebugDisplay(int width, int height);
};

#endif
