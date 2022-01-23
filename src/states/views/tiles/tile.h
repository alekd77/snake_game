#ifndef MAIN_CPP_TILE_H
#define MAIN_CPP_TILE_H

#include "SFML/Graphics.hpp"
#include <memory>

class Tile {
private:
    sf::RectangleShape tileRect;

public:
    Tile();
    const sf::RectangleShape& GetTileRectRef() const;
    sf::Vector2i GetTilePosition() const;
    sf::Vector2i GetTileSize() const;
    void SetTilePosition(sf::Vector2i pos);
    void SetTileSize(sf::Vector2i size);
    void SetTileTexture(const sf::Texture* texturePtr);
    void SetTileFillColor(const sf::Color& color);
};

class InfoTile : public Tile {
private:
    std::string text;
    sf::Font font;
public:
    InfoTile() = default;
};

class HUDTile : public InfoTile {
private:
    sf::Sprite hudSprite;

};

class Button : public InfoTile {

};
#endif //MAIN_CPP_TILE_H
