#include "assets_manager.h"

AssetsManager::AssetsManager() : spritesManger(this->texturesManager) {}

void AssetsManager::LoadAssets() {
    this->texturesManager.LoadTextures();
    this->spritesManger.LoadSprites();
    this->fontsManager.LoadFonts();
    this->soundsManager.LoadSounds();
}
