#include "snake.h"
#include <cmath>
#include <iostream>

Snake::Snake(GameManager& manager) : gameManager(manager) {
    this->currentDirection = {0, 0};
    this->currentVelocity = 0.0;
    this->currentHealth = 0;
}

const std::deque<sf::Vector2i>& Snake::GetSnakePos() const {
    return this->snakePos;
}

sf::Vector2i Snake::GetCurrentSnakeHeadPos() const {
    return this->snakePos.front();
}

float Snake::GetCurrentVelocity() const {
    return this->currentVelocity;
}

int Snake::GetCurrentHealth() const {
    return this->currentHealth;
}

bool Snake::IsSnakeAlive() const {
    if (this->currentHealth > 0)
        return true;

    return false;
}

void Snake::InitLevelSettings() {
    this->currentVelocity = 5.0;
    this->currentHealth = 100;
    this->currentDirection = {1, 0};
    SetInitSnakePos();
    this->posUpdateElapsedTime.restart();
    this->previousTurnElapsedTime.restart();
}

void Snake::SetInitSnakePos() {
    if (this->gameManager.GetGameMode() == CAMPAIGN) {
        this->tempSnakePos.push_front({1, 1});
        this->tempSnakePos.push_front({2, 1});
        this->tempSnakePos.push_front({3, 1});
        this->snakePos.push_front({1, 1});
        this->snakePos.push_front({2, 1});
        this->snakePos.push_front({3, 1});
    }
}

void Snake::SetCurrentVelocity(float velocity) {
    this->currentVelocity = velocity;

}

void Snake::SetCurrentHealth(int health) {
    this->currentHealth = health;
}

sf::Vector2f Snake::GetDistanceCoveredBetweenFrames(
        sf::Time deltaTime) const {
    return {static_cast<float>(this->currentDirection.first) *
                    this->currentVelocity * deltaTime.asSeconds(),
            static_cast<float>(this->currentDirection.second) *
                    this->currentVelocity * deltaTime.asSeconds()};
}

void Snake::UpdateTemporaryGridBasedPos(sf::Time deltaTime) {
    sf::Vector2f tempPos(this->tempSnakePos.front().x,
                         this->tempSnakePos.front().y);

    tempPos += GetDistanceCoveredBetweenFrames(deltaTime);

    this->tempSnakePos.push_front(tempPos);
    this->tempSnakePos.pop_back();
}

bool Snake::IsPosUpdateAvailable() const {
    /* returns true if snake head temp pos
     is different than the next body part pos */

    if (std::floor(this->tempSnakePos.front().x) -
            std::floor(this->tempSnakePos[1].x) != 0)
        return true;

    if (std::floor(this->tempSnakePos.front().y) -
            std::floor(this->tempSnakePos[1].y) != 0)
        return true;

    return false;
}

void Snake::UpdatePos() {
    sf::Vector2i newPos(
            std::floor(this->tempSnakePos.front().x),
            std::floor(this->tempSnakePos.front().y));

    this->snakePos.push_front(newPos);
    this->snakePos.pop_back();
}

void Snake::Move(sf::Time deltaTime) {
    UpdateTemporaryGridBasedPos(deltaTime);

    if (IsPosUpdateAvailable()) {
        UpdatePos();
        this->posUpdateElapsedTime.restart();
    }
}

bool Snake::IsTurnAvailable(std::pair<int, int> direction) const {
   // turn is not available if the previous one
   // was executed before updating snake pos
   if (this->previousTurnElapsedTime.getElapsedTime() <
            this->posUpdateElapsedTime.getElapsedTime())
        return false;

    // direction interval can only be set as -1 <= x <= 1
    if (direction.first < -1 or direction.first > 1)
        return false;

    if (direction.second < -1 or direction.second > 1)
        return false;


    // disable turning diagonally
    if (direction.first != 0 and direction.second != 0)
        return false;


    // disable turning on a dime
    if (direction.first == -1 * currentDirection.first)
        return false;

    if (direction.second == -1 * currentDirection.second)
        return false;

    return true;
}

void Snake::Turn(std::pair<int, int> direction) {
    if (!IsTurnAvailable(direction))
        return;

    this->currentDirection = direction;
    this->previousTurnElapsedTime.restart();
}

void Snake::Update(sf::Time deltaTime) {
    Move(deltaTime);
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
