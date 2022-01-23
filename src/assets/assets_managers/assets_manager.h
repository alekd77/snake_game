#ifndef MAIN_CPP_ASSETS_MANAGER_H
#define MAIN_CPP_ASSETS_MANAGER_H

#include "SFML/Graphics.hpp"
#include "../assets_managers/textures_manager.h"
#include "../assets_managers/fonts_manager.h"
#include "../assets_managers/sounds_manager.h"

class AssetsManager {
private:
    TexturesManager texturesManager;
    FontsManager fontsManager;
    SoundsManager soundsManager;

public:
    AssetsManager();

    TexturesManager& GetTexturesManagerRef();
    FontsManager& GetFontsManagerRef();
    SoundsManager& GetSoundsManagerRef();

    void LoadAssets();
};
#endif //MAIN_CPP_ASSETS_MANAGER_H
