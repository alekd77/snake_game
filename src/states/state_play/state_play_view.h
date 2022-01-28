#ifndef MAIN_CPP_STATE_PLAY_VIEW_H
#define MAIN_CPP_STATE_PLAY_VIEW_H

#include "state_view_interface.h"
#include "board/board.h"
#include "snake/snake.h"
#include "tiles/tile.h"

class StatePlayView : public StateViewInterface {
private:
    GameManager* gameManager;
    Board& boardModel;
    Snake& snakeModel;
    std::vector<Tile> permanentTiles;
    std::vector<Tile> temporaryTiles;
    std::map<std::string, HUDTile> hudTiles;

public:
    StatePlayView(GameManager* gameMgr,
                  Board& board,
                  Snake& snake);

    std::string GetHUDTileLeftTimeInfo() const;
    std::string GetHUDTileLeftLivesInfo() const;
    std::string GetHUDTileCurrentScoreInfo() const;
    std::string GetHUDTileScoreLevelGoalInfo() const;
    std::string GetHUDTileCampaignLevelNumberInfo() const;

    void SetPermanentTiles();
    void InitHUDTilesSettings();
    void InitStateViewSettings() override;

    void UpdateBoardTiles();
    void UpdateSnakeTiles();
    void UpdateTemporaryTiles();
    void UpdateHUD();
    void UpdateStateView() override;

    void DrawBackground();
    void DrawTiles();
    void DrawHUD();
    void DrawStateView() override;
};
#endif //MAIN_CPP_STATE_PLAY_VIEW_H
