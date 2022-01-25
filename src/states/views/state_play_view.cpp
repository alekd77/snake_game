#include <iostream>
#include "state_play_view.h"

StatePlayView::StatePlayView(sf::RenderWindow& window,
                             TexturesManager& texturesMgr,
                             Board& board, Snake& snake)
                             : StateViewInterface(window,
                                                  texturesMgr),
                             boardModel(board),
                             snakeModel(snake) {}

void StatePlayView::InitStateViewSettings() {
    SetPermanentBoardTiles();
}

void StatePlayView::SetPermanentBoardTiles() {
    for (int y = 0; y < this->boardModel.GetBoardHeight(); ++y)
    {
        for (int x = 0; x < this->boardModel.GetBoardWidth(); ++x)
        {
            BoardFieldTile tempBoardTile(
                    {30, 30},
                    {x, y},
                    this->texturesManager,
                    this->boardModel.GetFieldInfo({x, y}));

            tempBoardTile.SetTileProperties();

            this->permanentBoardTiles.push_back(tempBoardTile);
        }
    }
}

void StatePlayView::UpdateStateView() {
    UpdateTemporaryBoardTiles();
    UpdateSnakeTiles();
}

void StatePlayView::UpdateTemporaryBoardTiles() {

}

void StatePlayView::UpdateSnakeTiles() {
    this->snakeTiles.clear();
    bool isHead = true;

    for (const auto& snakeBodyIdxPos : this->snakeModel.GetSnakePos())
    {
        SnakeBodyTile snakeBodyTile(
                {30, 30},
                snakeBodyIdxPos,
                this->texturesManager,
                isHead);

        snakeBodyTile.SetTileProperties();

        this->snakeTiles.push_back(snakeBodyTile);

        isHead = false;
    }
}

void StatePlayView::DrawStateView() {
    DrawBackground();
    DrawBoard();
    DrawSnake();
    DrawHUD();
}

void StatePlayView::DrawBackground() {

}

void StatePlayView::DrawBoard() {
    for (const auto& permanentBoardTile : this->permanentBoardTiles)
        this->renderWindow.draw(permanentBoardTile.GetTileRectangleRef());
}

void StatePlayView::DrawSnake() {
    for (const auto& snakeBodyTile : this->snakeTiles)
        this->renderWindow.draw(snakeBodyTile.GetTileRectangleRef());
}

void StatePlayView::DrawHUD() {

}