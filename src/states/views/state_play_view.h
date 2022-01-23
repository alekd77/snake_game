#ifndef MAIN_CPP_STATE_PLAY_VIEW_H
#define MAIN_CPP_STATE_PLAY_VIEW_H

#include "state_view_interface.h"
#include "board.h"
#include "snake.h"
#include "tile.h"

class StatePlayView : public StateViewInterface {
private:
    Board& boardModel;
    Snake& snakeModel;

    std::vector<Tile> permanentBoardTiles;
    std::vector<Tile> temporaryBoardTiles;
    std::vector<Tile> snakeTiles;

public:
    StatePlayView(sf::RenderWindow& window,
                  TexturesManager& texturesMgr,
                  Board& board, Snake& snake);

    void InitStateViewSettings() override;
    void SetPermanentBoardTiles();

    void UpdateStateView() override;
    void UpdateTemporaryBoardTiles();
    void UpdateSnakeTiles();

    void DrawStateView() override;
    void DrawBackground();
    void DrawBoard();
    void DrawSnake();
    void DrawHUD();
};
#endif //MAIN_CPP_STATE_PLAY_VIEW_H
