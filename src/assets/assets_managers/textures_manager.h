#ifndef MAIN_CPP_TEXTURES_MANAGER_H
#define MAIN_CPP_TEXTURES_MANAGER_H

#include <map>
#include <string>
#include <memory>
#include "SFML/Graphics.hpp"

class TexturesManager {
private:
    std::map<std::string, std::shared_ptr<
            sf::Texture>> texturesSharedPtrMap;
public:
    TexturesManager();

    const std::map<std::string, std::shared_ptr<
            sf::Texture>>& GetTexturesSharedPtrMap() const;
    std::shared_ptr<sf::Texture> GetTextureSharedPtr(
            const std::string& textureName) const;
    void AddTextureSharedPtrToMap(const std::string& textureName,
                                  const std::string& fileName);
    void LoadTextures();
};
#endif //MAIN_CPP_TEXTURES_MANAGER_H
