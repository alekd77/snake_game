#include "tile.h"

Tile::Tile(sf::RenderWindow& window,
           const sf::Vector2i& size,
           const sf::Vector2i& pos)
           : renderWindow(window) {
    this->tileSize = size;
    this->tilePixelPosition = pos;
    this->tileFillColor = {250, 255, 240, 255};
}

Tile::Tile(sf::RenderWindow& window,
           const sf::Vector2i& size,
           const sf::Vector2i& pos,
           const sf::Color& color)
           : renderWindow(window) {
    this->tileSize = size;
    this->tilePixelPosition = pos;
    this->tileFillColor = color;
}

Tile::~Tile() = default;

void Tile::SetTileProperties() {
    this->tileRectangle.setSize(
            static_cast<sf::Vector2f>(this->tileSize));
    this->tileRectangle.setPosition(
            static_cast<sf::Vector2f>(this->tilePixelPosition));
    this->tileRectangle.setFillColor(this->tileFillColor);
}

void Tile::Draw() {
    this->renderWindow.draw(this->tileRectangle);
}


TexturedTile::TexturedTile(sf::RenderWindow& window,
                           const sf::Vector2i& size,
                           const sf::Vector2i& pos,
                           TexturesManager& texturesMgr)
                           : Tile(window, size, pos),
                           texturesManager(texturesMgr) {}

void TexturedTile::SetTileTexture(const sf::Texture* texturePtr) {
    this->tileRectangle.setTexture(texturePtr);
}

void TexturedTile::AdjustTileTexture() {}

void TexturedTile::SetTileProperties() {
    Tile::SetTileProperties();
    AdjustTileTexture();
}


BoardFieldTile::BoardFieldTile(sf::RenderWindow& window,
                               const sf::Vector2i& size,
                               const sf::Vector2i& tileGridBoardBasedPos,
                               TexturesManager& texturesMgr,
                               char fieldInfo)
                               : TexturedTile(window, size,
                               {tileGridBoardBasedPos.x * size.x,
                                tileGridBoardBasedPos.y * size.y},
                               texturesMgr) {
    this->boardFieldInfo = fieldInfo;
}

void BoardFieldTile::AdjustTileTexture() {
    switch (this->boardFieldInfo) {
        case '_': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("board_grass"));
            break;
        }
        case '$': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("board_signExit"));
            break;
        }
        case 'W': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("obstacle_wall"));
            break;
        }
        case 'F': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("obstacle_fence"));
            break;
        }
        case 'R': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("obstacle_rock"));
            break;
        }
        case 'c': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_cane"));
            break;
        }
        case 'h': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_cherry"));
            break;
        }
        case 'b': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_cookieBrown"));
            break;
        }
        case 'o': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_cookieChoco"));
            break;
        }
        case 'p': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_cookiePink"));
            break;
        }
        case 'm': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_mushroomBrown"));
            break;
        }
        case 'n': {
            SetTileTexture(
                    this->texturesManager.
                            GetTexturePtr("food_mushroomRed"));
            break;
        }
    }
}


SnakeBodyTile::SnakeBodyTile(sf::RenderWindow& window,
                             const sf::Vector2i& size,
                             const sf::Vector2i& tileGridBoardBasedPos,
                             TexturesManager& texturesMgr,
                             bool isHead)
                             : TexturedTile(window, size,
                             {tileGridBoardBasedPos.x * size.x,
                              tileGridBoardBasedPos.y * size.y},
                              texturesMgr) {
    this->isSnakeHead = isHead;
}

void SnakeBodyTile::AdjustTileTexture() {
    if (this->isSnakeHead) {
        SetTileTexture(
                this->texturesManager.
                        GetTexturePtr("snake_head"));
        return;
    }

    SetTileTexture(
            this->texturesManager.
                    GetTexturePtr("snake_body"));
}


InfoTile::InfoTile(sf::RenderWindow& window,
                   const sf::Vector2i& size,
                   const sf::Vector2i& pos,
                   const sf::Color& color,
                   FontsManager& fontsMgr,
                   const std::string& info)
                   : Tile(window, size,
                          pos, color),
                   fontsManager(fontsMgr) {
    this->tileTextInfo = info;
}

void InfoTile::AdjustTextFont() {
    this->tileTextFont = this->fontsManager.GetFontRef(
            "comfortaa_regular");
}

void InfoTile::SetTileProperties() {
    Tile::SetTileProperties();
    this->tileText.setPosition(
            {this->tileRectangle.getGlobalBounds().left + 40,
             this->tileRectangle.getGlobalBounds().top + 40});
    this->tileText.setString(this->tileTextInfo);
    this->tileText.setFillColor(sf::Color::Green);
    AdjustTextFont();
    this->tileText.setFont(this->tileTextFont);
}

void InfoTile::Draw() {
    this->renderWindow.draw(this->tileRectangle);
    this->renderWindow.draw(this->tileText);
}

HUDTile::HUDTile(sf::RenderWindow& window,
                 const sf::Vector2i& pos,
                 FontsManager& fontsMgr,
                 const std::string& info,
                 TexturesManager& texturesMgr,
                 const HUDTileType& type)
                 : InfoTile(window,{200, 100},
                            pos, sf::Color::Yellow,
                            fontsMgr, info),
                            texturesManager(texturesMgr) {
    this->hudTileType = type;
}

void HUDTile::AdjustHUDSprite() {
    if (this->hudTileType == TIME) {
        this->hudTileSprite.setTexture(
                this->texturesManager.GetTextureRef(
                        "hud_clock"));
        return;
    }

    if (this->hudTileType == LIVES) {
        this->hudTileSprite.setTexture(
                this->texturesManager.GetTextureRef(
                        "hud_heart"));
        return;
    }

    this->hudTileSprite.setTexture(
            this->texturesManager.GetTextureRef(
                    "hud_coin"));
}

void HUDTile::SetTileProperties() {
    InfoTile::SetTileProperties();
    AdjustHUDSprite();
    this->hudTileSprite.setPosition(
            this->tileRectangle.getGlobalBounds().left + 10,
            this->tileRectangle.getGlobalBounds().top + 10);
    this->tileText.setPosition(
            {this->hudTileSprite.getPosition().x
                + this->hudTileSprite.getGlobalBounds().width + 10,
             this->hudTileSprite.getPosition().y});
}

void HUDTile::Draw() {
    this->renderWindow.draw(this->tileRectangle);
    this->renderWindow.draw(this->hudTileSprite);
    this->renderWindow.draw(this->tileText);
}