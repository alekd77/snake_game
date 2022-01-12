#ifndef SNAKE_NEW_OBSTACLES_H
#define SNAKE_NEW_OBSTACLES_H

#include "SFML/Graphics.hpp"

enum ObstacleType {NONE_OBSTACLE, WALL, FENCE, ROCK};

class Obstacle {
private:
    ObstacleType type;
    int damage;
    bool isDisappearing;
    bool isRepelling;

public:
    Obstacle(ObstacleType obsType, int obsDamage,
             bool disappearing, bool repelling);

    ObstacleType GetObstacleType() const;
    int GetDamage() const;
    bool IsDisappearing() const;
    bool IsRepelling() const;
};

class Wall : public Obstacle {
public:
    Wall();
};

class Fence : public Obstacle {
public:
    Fence();
};

class Rock : public Obstacle {
public:
    Rock();
};

#endif //SNAKE_NEW_OBSTACLES_H
