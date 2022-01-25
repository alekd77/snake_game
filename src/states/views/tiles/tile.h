#ifndef MAIN_CPP_TILE_H
#define MAIN_CPP_TILE_H

#include "SFML/Graphics.hpp"
#include "textures_manager.h"

class Tile {
private:
    sf::Vector2i tileSize;
    sf::Vector2i tileGridBoardBasedPosition;
    sf::Vector2i tilePixelPosition;
protected:
    sf::RectangleShape tileRectangle;
public:
    Tile(const sf::Vector2i& size,
         const sf::Vector2i& pos);
    ~Tile();
    const sf::RectangleShape& GetTileRectangleRef() const;
    const sf::Vector2i& GetTileSize() const;
    const sf::Vector2i& GetTileGridBoardBasedPosition() const;
    const sf::Vector2i& GetTilePixelPosition() const;
    void SetTileFillColor(const sf::Color& color);
    virtual void SetTileProperties();
};


class TexturedTile : public Tile {
protected:
    TexturesManager& texturesManager;
public:
    TexturedTile(const sf::Vector2i& size,
                 const sf::Vector2i& pos,
                 TexturesManager& texturesMgr);
    void SetTileTexture(const sf::Texture* texturePtr);
    virtual void AdjustTileTexture();
    void SetTileProperties() override;
};


class BoardFieldTile : public TexturedTile {
private:
    char boardFieldInfo;
public:
    BoardFieldTile(const sf::Vector2i& size,
                   const sf::Vector2i& pos,
                   TexturesManager& texturesMgr,
                   char fieldInfo);
    void AdjustTileTexture() override;
};


class SnakeBodyTile : public TexturedTile {
private:
    bool isSnakeHead;
public:
    SnakeBodyTile(const sf::Vector2i& size,
                  const sf::Vector2i& pos,
                  TexturesManager& texturesMgr,
                  bool isHead);
    void AdjustTileTexture() override;
};

//class InfoTile : public Tile {
//private:
//    std::string text;
//    sf::Font font;
//public:
//    InfoTile() = default;
//};
//
//class HUDTile : public InfoTile {
//private:
//    sf::Sprite hudSprite;
//
//};
//
//class Button : public InfoTile {
//
//};
#endif //MAIN_CPP_TILE_H
