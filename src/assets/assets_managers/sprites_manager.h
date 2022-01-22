#ifndef MAIN_CPP_SPRITES_MANAGER_H
#define MAIN_CPP_SPRITES_MANAGER_H

#include "../assets_managers/textures_manager.h"

class SpritesManger {
private:
    TexturesManager texturesManager;
    std::map<std::string, sf::Sprite> spritesMap;

public:
    explicit SpritesManger(TexturesManager& texturesMgr);

    sf::Sprite& GetSpriteRef(const std::string& spriteName);
    void AddSpriteToMap (const std::string& sourceTextureName,
                         const std::string& spriteName);
    void LoadSprites();
};

#endif //MAIN_CPP_SPRITES_MANAGER_H
