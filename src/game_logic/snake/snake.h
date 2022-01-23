#ifndef SNAKE_NEW_SNAKE_H
#define SNAKE_NEW_SNAKE_H

#include "../../game_manager.h"
#include <deque>

enum BuffType {SPEED, HEALTH, XP};

class Snake {
private:
    GameManager& gameManager;
    std::deque<sf::Vector2i> snakePos;
    std::pair<int, int> currentDirection;
    int currentVelocity;
    int currentHealth;

public:
    explicit Snake(GameManager& manager);

    const std::deque<sf::Vector2i>& GetSnakePos() const;
    sf::Vector2i GetCurrentSnakeHeadPos() const;
    int GetCurrentVelocity() const;
    int GetCurrentHealth() const;

    void InitLevelSettings();
    void SetInitSnakePos();
    void SetInitDirection();
    void SetCurrentVelocity(bool subtract, int velocity);
    void SetCurrentHealth(bool subtract, int health);

    void Move();
    void Turn(std::pair<int, int> direction);

    void Update();

    void DebugDisplay(int width, int height);
};

#endif
