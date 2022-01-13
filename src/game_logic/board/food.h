#ifndef SNAKE_NEW_FOOD_H
#define SNAKE_NEW_FOOD_H

#include "SFML/Graphics.hpp"

enum FoodType {NONE_FOOD, CANE, CHERRY, COOKIE_BROWN,
        COOKIE_CHOCO, COOKIE_PINK, MUSHROOM_BROWN, MUSHROOM_RED};

class Food {
private:
    FoodType type;
    int health;
    int exp;

public:
    Food(FoodType foodType, int xp, int healthPts);

    FoodType GetFoodType() const;
    int GetXP() const;
    int GetHealthPts() const;
};

class Cherry : public Food {
public:
    Cherry();
};
#endif //SNAKE_NEW_FOOD_H
