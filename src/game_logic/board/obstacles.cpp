#include "obstacles.h"

Obstacle::Obstacle(ObstacleType obsType, int obsDamage,
                   bool disappearing, bool repelling) {
    this->type = obsType;
    this->damage = obsDamage;
    this->isDisappearing = disappearing;
    this->isRepelling = repelling;
}

ObstacleType Obstacle::GetObstacleType() const {
    return this->type;
}

int Obstacle::GetDamage() const {
    return this->damage;
}

bool Obstacle::IsDisappearing() const {
    return this->isDisappearing;
}

bool Obstacle::IsRepelling() const {
    return this->isRepelling;
}


Wall::Wall() : Obstacle(WALL,25,
                        false, true) {}

Fence::Fence() : Obstacle(FENCE,40,
                          false, true) {}

Rock::Rock() : Obstacle(ROCK, 40,
                        true, false){}