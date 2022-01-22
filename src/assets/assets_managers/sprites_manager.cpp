#include <iostream>
#include "sprites_manager.h"

SpritesManger::SpritesManger(TexturesManager& texturesMgr)
        : texturesManager(texturesMgr) {}

sf::Sprite& SpritesManger::GetSpriteRef(const std::string& spriteName) {
    return this->spritesMap.at(spriteName);
}

void SpritesManger::AddSpriteToMap(const std::string& sourceTextureName,
                                   const std::string& spriteName) {
    sf::Sprite tempSprite;

    tempSprite.setTexture(*this->texturesManager.
        GetTexturesSharedPtrMap().at(sourceTextureName));

    this->spritesMap[spriteName] = tempSprite;
}

void SpritesManger::LoadSprites() {
    for (const auto& texturesMapIdx
            : this->texturesManager.GetTexturesSharedPtrMap())
        AddSpriteToMap(texturesMapIdx.first, texturesMapIdx.first);
}
