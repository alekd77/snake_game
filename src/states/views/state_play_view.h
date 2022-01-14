#ifndef MAIN_CPP_STATE_PLAY_VIEW_H
#define MAIN_CPP_STATE_PLAY_VIEW_H

#include "board.h"
#include "snake.h"
#include "SFML/Graphics.hpp"

class StatePlayView {
private:
    Board& board;
    Snake& snake;
    sf::Window& window;

public:
    StatePlayView(Board& boardToView, Snake& snakeToView,
                  sf::Window& windowToRender);

    void DrawBackground();
    void DrawBoard();
    void DrawSnake();
    void DrawHUD();

    void Draw();
};
#endif //MAIN_CPP_STATE_PLAY_VIEW_H
