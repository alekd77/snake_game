#include "textures_manager.h"
#include "experimental/filesystem"
#include <iostream>
#include <cstring>

TexturesManager::TexturesManager() = default;

const std::map<std::string, sf::Texture>&
    TexturesManager::GetTexturesMap() const {
    return this->texturesMap;
}

const sf::Texture* TexturesManager::GetTexturePtr(
        const std::string& textureName) const {
    return &this->texturesMap.at(textureName);
}

const sf::Texture& TexturesManager::GetTextureRef(
        const std::string& textureName) const {
    return this->texturesMap.at(textureName);
}

void TexturesManager::AddTextureToMap(
        const std::string& textureName,
        const std::string& fileName) {
    sf::Texture tempTexture;

    if (!tempTexture.loadFromFile(fileName))
        std::cerr << strerror(errno) << std::endl;

    this->texturesMap[textureName] = tempTexture;
}

void TexturesManager::LoadTextures() {
    namespace fs = std::experimental::filesystem;

    fs::path texturesDirectoryPath {fs::current_path().parent_path()
                                            /= "src\\assets\\textures"};

    // Loop below adds every texture
    // from textures directory to texturesMap
    for(auto const& directoryEntry
        : fs::directory_iterator{texturesDirectoryPath})
        AddTextureToMap(directoryEntry.path().stem().string(),
                        directoryEntry.path().string());
}