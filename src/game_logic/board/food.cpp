#include "food.h"

Food::Food(FoodType foodType, int xp, int healthPts) {
    this->type = foodType;
    this->exp = xp;
    this->health = healthPts;
}

FoodType Food::GetFoodType() const {
    return this->type;
}

int Food::GetXP() const {
    return this->exp;
}

int Food::GetHealthPts() const {
    return this->health;
}

Cherry::Cherry() : Food(CHERRY, 10, 10) {}
