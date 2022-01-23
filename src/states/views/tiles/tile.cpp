#include "tile.h"

Tile::Tile() = default;

const sf::RectangleShape& Tile::GetTileRectRef() const {
    return this->tileRect;
}

sf::Vector2i Tile::GetTilePosition() const {
    return static_cast<sf::Vector2i>(
            this->tileRect.getPosition());
}

sf::Vector2i Tile::GetTileSize() const {
    return static_cast<sf::Vector2i>(
            this->tileRect.getSize());
}

void Tile::SetTilePosition(sf::Vector2i pos) {
    this->tileRect.setPosition(static_cast<sf::Vector2f>(pos));
}

void Tile::SetTileSize(sf::Vector2i size) {
    this->tileRect.setSize(static_cast<sf::Vector2f>(size));
}

void Tile::SetTileTexture(const sf::Texture* texturePtr) {
    this->tileRect.setTexture(texturePtr);
}

void Tile::SetTileFillColor(const sf::Color& color) {
    this->tileRect.setFillColor(color);
}