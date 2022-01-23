#ifndef MAIN_CPP_TEXTURES_MANAGER_H
#define MAIN_CPP_TEXTURES_MANAGER_H

#include <map>
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"

class TexturesManager {
private:
    std::map<std::string, sf::Texture> texturesMap;
public:
    TexturesManager();

    const std::map<std::string, sf::Texture>& GetTexturesMap() const;
    const sf::Texture* GetTexturePtr(
            const std::string& textureName) const;
    const sf::Texture& GetTextureRef(
            const std::string& textureName) const;
    void AddTextureToMap(const std::string& textureName,
                         const std::string& fileName);
    void LoadTextures();
};
#endif //MAIN_CPP_TEXTURES_MANAGER_H
