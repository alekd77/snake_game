#include "fonts_manager.h"
#include <iostream>
#include <cstring>
#include "experimental/filesystem"

FontsManager::FontsManager() = default;

const std::map<std::string, sf::Font>&
        FontsManager::GetFontsMap() const {
    return this->fontsMap;
}

const sf::Font& FontsManager::GetFontRef(
        const std::string &fontName) const {
    return this->fontsMap.at(fontName);
}

void FontsManager::AddFontToMap(
        const std::string& fontName,
        const std::string& fileName) {
    sf::Font tempFont;

    if (!tempFont.loadFromFile(fileName))
        std::cerr << strerror(errno) << std::endl;

    this->fontsMap[fontName] = tempFont;
}

void FontsManager::LoadFonts() {
    namespace fs = std::experimental::filesystem;

    fs::path fontsDirectoryPath {fs::current_path().parent_path()
            /= "src\\assets\\fonts"};

    // Loop below adds every font
    // from fonts directory to fontsMap
    for(auto const& directoryEntry
            : fs::directory_iterator{fontsDirectoryPath})
        AddFontToMap(directoryEntry.path().stem().string(),
                     directoryEntry.path().string());
}
