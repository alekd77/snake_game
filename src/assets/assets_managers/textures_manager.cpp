#include "textures_manager.h"
#include "experimental/filesystem"
#include <iostream>
#include <cstring>

TexturesManager::TexturesManager() = default;

const std::map<std::string, std::shared_ptr<sf::Texture>>&
    TexturesManager::GetTexturesSharedPtrMap() const {
    return this->texturesSharedPtrMap;
}

std::shared_ptr<sf::Texture> TexturesManager::GetTextureSharedPtr(
        const std::string& textureName) const {
    return this->texturesSharedPtrMap.at(textureName);
}

void TexturesManager::AddTextureSharedPtrToMap(
        const std::string& textureName,
        const std::string& fileName) {
    sf::Texture tempTexture;

    if (!tempTexture.loadFromFile(fileName))
        std::cerr << strerror(errno) << std::endl;

    std::shared_ptr<sf::Texture> textureSharedPtr =
            std::make_shared<sf::Texture>(tempTexture);

    this->texturesSharedPtrMap[textureName] = textureSharedPtr;
}

void TexturesManager::LoadTextures() {
    namespace fs = std::experimental::filesystem;

    fs::path texturesDirectoryPath {fs::current_path().parent_path()
                                            /= "src\\assets\\textures"};

    // Loop below adds shared ptr of every texture
    // from textures directory to texturesSharedPtrMap
    for(auto const& directoryEntry: fs::directory_iterator{texturesDirectoryPath})
        AddTextureSharedPtrToMap(directoryEntry.path().stem().string(),
                                 directoryEntry.path().string());
}