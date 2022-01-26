#ifndef MAIN_CPP_TILE_H
#define MAIN_CPP_TILE_H

#include "SFML/Graphics.hpp"
#include "textures_manager.h"
#include "fonts_manager.h"

class Tile {
private:
    sf::Vector2i tileSize;
    sf::Vector2i tilePixelPosition;
    sf::Color tileFillColor;
protected:
    sf::RenderWindow& renderWindow;
    sf::RectangleShape tileRectangle;
public:
    Tile(sf::RenderWindow& window,
         sf::Vector2i size,
         sf::Vector2i pos);
    Tile(sf::RenderWindow& window,
         sf::Vector2i size,
         sf::Vector2i pos,
         sf::Color color);
    ~Tile();
    virtual void SetTileProperties();
    virtual void Draw();
};


class TexturedTile : public Tile {
protected:
    TexturesManager& texturesManager;
public:
    TexturedTile(sf::RenderWindow& window,
                 sf::Vector2i size,
                 sf::Vector2i pos,
                 TexturesManager& texturesMgr);
    void SetTileTexture(const sf::Texture* texturePtr);
    virtual void AdjustTileTexture();
    void SetTileProperties() override;
};


class BoardFieldTile : public TexturedTile {
private:
    char boardFieldInfo;
public:
    BoardFieldTile(sf::RenderWindow& window,
                   sf::Vector2i size,
                   sf::Vector2i tileGridBoardBasedPos,
                   TexturesManager& texturesMgr,
                   char fieldInfo);
    void AdjustTileTexture() override;
};


class SnakeBodyTile : public TexturedTile {
private:
    bool isSnakeHead;
public:
    SnakeBodyTile(sf::RenderWindow& window,
                  sf::Vector2i size,
                  sf::Vector2i tileGridBoardBasedPos,
                  TexturesManager& texturesMgr,
                  bool isHead);
    void AdjustTileTexture() override;
};


class InfoTile : public Tile {
private:
    std::string tileTextInfo;
    sf::Font tileTextFont;
protected:
    FontsManager& fontsManager;
    sf::Text tileText;
public:
    InfoTile(sf::RenderWindow& window,
             sf::Vector2i size,
             sf::Vector2i pos,
             sf::Color color,
             FontsManager& fontsMgr,
             const std::string& info);
    virtual void AdjustTextFont();
    void SetTextInfo(const std::string& info);
    void SetTileProperties() override;
    void Draw() override;
};

enum HUDTileType {TIME, LIVES, SCORE};

class HUDTile : public InfoTile {
private:
    HUDTileType hudTileType;
    sf::Sprite hudTileSprite;
protected:
    TexturesManager& texturesManager;
public:
    HUDTile(sf::RenderWindow& window,
            sf::Vector2i pos,
            FontsManager& fontsMgr,
            const std::string& info,
            TexturesManager& texturesMgr,
            HUDTileType type);
    void AdjustHUDSprite();
    void SetTileProperties() override;
    void Draw() override;
};

class Button : public InfoTile {

};
#endif //MAIN_CPP_TILE_H
