#ifndef MAIN_CPP_FONTS_MANAGER_H
#define MAIN_CPP_FONTS_MANAGER_H

#include <map>
#include <string>
#include "SFML/Graphics.hpp"

class FontsManager {
private:
    std::map<std::string, sf::Font> fontsMap;

public:
    FontsManager();
    const std::map<std::string, sf::Font>& GetFontsMap() const;
    const sf::Font& GetFontRef(
            const std::string& fontName) const;
    void AddFontToMap(const std::string& fontName,
                      const std::string& fileName);
    void LoadFonts();
};

#endif //MAIN_CPP_FONTS_MANAGER_H
