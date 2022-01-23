#ifndef MAIN_CPP_STATE_VIEW_INTERFACE_H
#define MAIN_CPP_STATE_VIEW_INTERFACE_H

#include "SFML/Graphics.hpp"
#include "assets_manager.h"

class StateViewInterface {
protected:
    sf::RenderWindow& renderWindow;
    TexturesManager& texturesManager;

public:
    StateViewInterface(sf::RenderWindow& window,
                       TexturesManager& texturesMgr)
                       : renderWindow(window),
                       texturesManager(texturesMgr) {}
    virtual ~StateViewInterface() = default;

    virtual void InitStateViewSettings() = 0;
    virtual void UpdateStateView() = 0;
    virtual void DrawStateView() = 0;
};
#endif //MAIN_CPP_STATE_VIEW_INTERFACE_H
