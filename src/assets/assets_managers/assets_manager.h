#ifndef MAIN_CPP_ASSETS_MANAGER_H
#define MAIN_CPP_ASSETS_MANAGER_H

#include "../assets_managers/sprites_manager.h"
#include "../assets_managers/fonts_manager.h"
#include "../assets_managers/sounds_manager.h"

class AssetsManager {
private:
    TexturesManager texturesManager;
    SpritesManger spritesManger;
    FontsManager fontsManager;
    SoundsManager soundsManager;

public:
    AssetsManager();

    void LoadAssets();
};
#endif //MAIN_CPP_ASSETS_MANAGER_H
