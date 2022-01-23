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
            Tile tempBoardTile;
            tempBoardTile.SetTileSize({30, 30});
            tempBoardTile.SetTilePosition({x * 30, y * 30});

            if (this->boardModel.GetFieldInfo({x, y}) == 'W') {
                tempBoardTile.SetTileTexture(
                        this->texturesManager.GetTexturePtr(
                                "obstacle_wall"));
            } else {
            tempBoardTile.SetTileTexture(
                    this->texturesManager.GetTexturePtr(
                            "board_grass"));
            }

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

    for (const auto& snakeIdx : this->snakeModel.GetSnakePos())
    {
        Tile snakeTile;
        snakeTile.SetTileSize({30, 30});
        snakeTile.SetTilePosition({snakeIdx.x * 30,
                                   snakeIdx.y * 30});

        if (isHead) {
            snakeTile.SetTileTexture(
                    this->texturesManager.GetTexturePtr(
                            "snake_head"));
            isHead = false;
        } else {
            snakeTile.SetTileTexture(
                    this->texturesManager.GetTexturePtr(
                            "snake_body"));
        }

        this->snakeTiles.push_back(snakeTile);
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
        this->renderWindow.draw(permanentBoardTile.GetTileRectRef());
}

void StatePlayView::DrawSnake() {
    for (const auto& snakeBodyTile : this->snakeTiles)
        this->renderWindow.draw(snakeBodyTile.GetTileRectRef());
}

void StatePlayView::DrawHUD() {

}