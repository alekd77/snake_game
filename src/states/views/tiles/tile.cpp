#include "tile.h"

Tile::Tile(const sf::Vector2i& size,
           const sf::Vector2i& pos) {
    this->tileSize = size;
    this->tileGridBoardBasedPosition = pos;
    this->tilePixelPosition = {
            this->tileGridBoardBasedPosition.x * this->tileSize.x,
            this->tileGridBoardBasedPosition.y * this->tileSize.y};
}

Tile::~Tile() = default;

const sf::RectangleShape& Tile::GetTileRectangleRef() const {
    return this->tileRectangle;
}

const sf::Vector2i& Tile::GetTileSize() const {
    return this->tileSize;
}

const sf::Vector2i& Tile::GetTileGridBoardBasedPosition() const {
    return this->tileGridBoardBasedPosition;
}

const sf::Vector2i& Tile::GetTilePixelPosition() const {
    return this->tilePixelPosition;
}

void Tile::SetTileFillColor(const sf::Color& color) {
    this->tileRectangle.setFillColor(color);
}

void Tile::SetTileProperties() {
    this->tileRectangle.setSize(
            static_cast<sf::Vector2f>(this->tileSize));
    this->tileRectangle.setPosition(
            static_cast<sf::Vector2f>(this->tilePixelPosition));
}


TexturedTile::TexturedTile(const sf::Vector2i& size,
                           const sf::Vector2i& pos,
                           TexturesManager& texturesMgr)
                           : Tile(size, pos),
                           texturesManager(texturesMgr) {}

void TexturedTile::SetTileTexture(const sf::Texture* texturePtr) {
    this->tileRectangle.setTexture(texturePtr);
}

void TexturedTile::AdjustTileTexture() {}

void TexturedTile::SetTileProperties() {
    Tile::SetTileProperties();
    AdjustTileTexture();
}


BoardFieldTile::BoardFieldTile(const sf::Vector2i& size,
                               const sf::Vector2i& pos,
                               TexturesManager& texturesMgr,
                               char fieldInfo)
                               : TexturedTile(
                                       size, pos,
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

SnakeBodyTile::SnakeBodyTile(const sf::Vector2i& size,
                             const sf::Vector2i& pos,
                             TexturesManager& texturesMgr,
                             bool isHead)
                             : TexturedTile(
                                     size, pos,
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

