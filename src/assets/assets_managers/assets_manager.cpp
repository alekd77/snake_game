#include "assets_manager.h"

AssetsManager::AssetsManager() = default;

TexturesManager& AssetsManager::GetTexturesManagerRef() {
    return this->texturesManager;
}

FontsManager& AssetsManager::GetFontsManagerRef() {
    return this->fontsManager;
}

SoundsManager& AssetsManager::GetSoundsManagerRef() {
    return this->soundsManager;
}

void AssetsManager::LoadAssets() {
    this->texturesManager.LoadTextures();
    this->fontsManager.LoadFonts();
    this->soundsManager.LoadSounds();
}