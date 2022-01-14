#include "state_play_view.h"

StatePlayView::StatePlayView(Board& boardToView, Snake& snakeToView,
                             sf::Window& windowToRender) : board(boardToView),
                             snake(snakeToView), window(windowToRender) {}

void StatePlayView::DrawBackground() {

}

void StatePlayView::DrawBoard() {

}

void StatePlayView::DrawSnake() {

}

void StatePlayView::DrawHUD() {

}

void StatePlayView::Draw() {
    DrawBackground();
    DrawBoard();
    DrawSnake();
    DrawHUD();
}