#include <iostream>
#include "state_play_view.h"

StatePlayView::StatePlayView(GameManager* gameMgr,
                             Board& board,
                             Snake& snake)
                             : StateViewInterface(
                                     gameMgr->GetWindowToRender(),
                                     gameMgr->GetAssetsManagerRef().
                                            GetTexturesManagerRef(),
                                     gameMgr->GetAssetsManagerRef().
                                            GetFontsManagerRef()),
                             gameManager(gameMgr),
                             boardModel(board),
                             snakeModel(snake) {}

std::string StatePlayView::GetHUDTileLeftTimeInfo() const {
    return std::to_string(static_cast<int>(
            this->gameManager->GetCurrentLeftTime().asSeconds()));
}

std::string StatePlayView::GetHUDTileLeftLivesInfo() const {
    return std::to_string(this->gameManager->GetLeftLives());
}

std::string StatePlayView::GetHUDTileCurrentScoreInfo() const {
    return std::to_string(this->gameManager->GetCurrentScore());
}

std::string StatePlayView::GetHUDTileScoreLevelGoalInfo() const {
    return std::to_string(
            this->gameManager->GetCurrentScoreLevelGoal());
}

std::string StatePlayView::GetHUDTileCampaignLevelNumberInfo() const {
    return std::to_string(
            this->gameManager->GetCurrentGameLevel())
                    + " / " + std::to_string(
                    this->gameManager->GetMaxCampaignLevel());
}

void StatePlayView::SetPermanentTiles() {
    for (int y = 0; y < this->boardModel.GetBoardHeight(); ++y)
    {
        for (int x = 0; x < this->boardModel.GetBoardWidth(); ++x)
        {
            char fieldInfo = '_';

            if (this->boardModel.GetFieldInfo({x, y}) == 'W')
                fieldInfo = 'W';

            BoardFieldTile tempBoardTile(
                    this->renderWindow,
                    {30, 30},
                    {x, y},
                    this->texturesManager,
                    fieldInfo);

            tempBoardTile.SetTileProperties();

            this->permanentTiles.push_back(tempBoardTile);
        }
    }
}

void StatePlayView::InitHUDTilesSettings() {
    this->hudTiles.emplace("time",
                           HUDTile(this->renderWindow,
                                   {10, 720},
                                   this->fontsManager,
                                   GetHUDTileLeftTimeInfo(),
                                   this->texturesManager,
                                   TIME));

    this->hudTiles.emplace("lives",
                           HUDTile(this->renderWindow,
                                   {310, 720},
                                   this->fontsManager,
                                   GetHUDTileLeftLivesInfo(),
                                   this->texturesManager,
                                   LIVES));

    this->hudTiles.emplace("score",
                           HUDTile(this->renderWindow,
                                   {610, 720},
                                   this->fontsManager,
                                   GetHUDTileCurrentScoreInfo() + " / "
                                        + GetHUDTileScoreLevelGoalInfo(),
                                   this->texturesManager,
                                   SCORE));

    if (this->gameManager->GetGameMode() == CAMPAIGN)
        this->hudTiles.emplace("level",
                           HUDTile(this->renderWindow,
                                   {910, 720},
                                   this->fontsManager,
                                   "Level: " + GetHUDTileCampaignLevelNumberInfo(),
                                   this->texturesManager,
                                   LEVEL));

    for (auto& hudTile : this->hudTiles)
        hudTile.second.SetTileProperties();
}

void StatePlayView::InitStateViewSettings() {
    SetPermanentTiles();
    UpdateBoardTiles();
    UpdateSnakeTiles();
    InitHUDTilesSettings();
}

void StatePlayView::UpdateBoardTiles() {
    for (int y = 0; y < this->boardModel.GetBoardHeight(); ++y)
    {
        for (int x = 0; x < this->boardModel.GetBoardWidth(); ++x)
        {
            // checks if field of given coord (x, y) is permanent
            if (this->boardModel.GetFieldInfo({x, y}) == '_')
                continue;

            if (this->boardModel.GetFieldInfo({x, y}) == 'W')
                continue;

            BoardFieldTile tempBoardTile(
                    this->renderWindow,
                    {30, 30},
                    {x, y},
                    this->texturesManager,
                    this->boardModel.GetFieldInfo({x, y}));

            tempBoardTile.SetTileProperties();

            this->temporaryTiles.push_back(tempBoardTile);
        }
    }
}

void StatePlayView::UpdateSnakeTiles() {
    bool isHead = true;

    for (const auto& snakeBodyIdxPos : this->snakeModel.GetSnakePos())
    {
        SnakeBodyTile snakeBodyTile(
                this->renderWindow,
                {30, 30},
                snakeBodyIdxPos,
                this->texturesManager,
                isHead);

        snakeBodyTile.SetTileProperties();

        this->temporaryTiles.push_back(snakeBodyTile);

        isHead = false;
    }
}

void StatePlayView::UpdateTemporaryTiles() {
    this->temporaryTiles.clear();
    UpdateBoardTiles();
    UpdateSnakeTiles();
}

void StatePlayView::UpdateHUD() {
    this->hudTiles.at("time").SetTextInfo(
            GetHUDTileLeftTimeInfo());
    this->hudTiles.at("lives").SetTextInfo(
            GetHUDTileLeftLivesInfo());
    this->hudTiles.at("score").SetTextInfo(
            GetHUDTileCurrentScoreInfo() + " / "
                + GetHUDTileScoreLevelGoalInfo());
}

void StatePlayView::UpdateStateView() {
    this->renderWindow.clear();
    UpdateTemporaryTiles();
    UpdateHUD();
}

void StatePlayView::DrawBackground() {

}

void StatePlayView::DrawTiles() {
    for (auto& permanentBoardTile : this->permanentTiles)
        permanentBoardTile.Draw();

    for (auto& temporaryTile : this->temporaryTiles)
        temporaryTile.Draw();
}

void StatePlayView::DrawHUD() {
    for (auto& hudTile : this->hudTiles)
        hudTile.second.Draw();
}

void StatePlayView::DrawStateView() {
    DrawBackground();
    DrawTiles();
    DrawHUD();
}