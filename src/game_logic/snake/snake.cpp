#include "snake.h"
#include <iostream>

Snake::Snake(GameManager& manager) : gameManager(manager) {
    this->currentVelocity = 0;
    this->currentHealth = 0;
}

const std::deque<sf::Vector2i>& Snake::GetSnakePos() const {
    return this->snakePos;
}

sf::Vector2i Snake::GetCurrentSnakeHeadPos() const {
    return this->snakePos.front();
}

int Snake::GetCurrentVelocity() const {
    return this->currentVelocity;
}

int Snake::GetCurrentHealth() const {
    return this->currentHealth;
}

void Snake::InitLevelSettings() {
    this->currentVelocity = 10;
    this->currentHealth = 100;
    SetInitSnakePos();
    SetInitDirection();
}

void Snake::SetInitSnakePos() {
    if (this->gameManager.GetGameMode() == CAMPAIGN) {
        this->snakePos.push_front({1, 1});
        this->snakePos.push_front({2, 1});
        this->snakePos.push_front({3, 1});
    }
}

void Snake::SetInitDirection() {
    if (this->gameManager.GetGameMode() == CAMPAIGN)
        this->currentDirection = {1, 0};
}

void Snake::SetCurrentVelocity(bool subtract, int velocity) {
    if (this->currentVelocity <= 5 or
            this->currentVelocity >= 15)
        return;

    if (subtract)
        this->currentVelocity -= velocity;

    this->currentVelocity += velocity;
}

void Snake::SetCurrentHealth(bool subtract, int health) {
    if (this->currentHealth <= 0 or
        this->currentHealth >= 100)
        return;

    if (subtract)
        this->currentHealth -= health;

    this->currentHealth += health;
}

void Snake::Move() {
    this->snakePos.push_front({
            this->snakePos.front().x + currentDirection.first,
            this->snakePos.front().y + currentDirection.second});
    this->snakePos.pop_back();
}

void Snake::Turn(std::pair<int, int> direction) {
    // direction interval can only be set as -1 <= x <= 1
    if (direction.first < -1 or direction.first > 1)
        return;

    if (direction.second < -1 or direction.second > 1)
        return;

    // disable turning diagonally
    if (direction.first != 0 and direction.second != 0)
        return;

    // disable turning on a dime
    if (direction.first == -1 * currentDirection.first)
        return;

    if (direction.second == -1 * currentDirection.second)
        return;

    this->currentDirection = direction;
}

void Snake::Update() {
    Move();
}

void Snake::DebugDisplay(int width, int height) {
    bool isSnakeOnField;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            isSnakeOnField = false;

            for (auto & idx : this->snakePos)
                if (idx.x == x and
                        idx.y == y) {
                    std::cout << 'S';
                    isSnakeOnField = true;
                }

            if (!isSnakeOnField)
                std::cout << '_';
        }
        std::cout << '\n';
    }
}
