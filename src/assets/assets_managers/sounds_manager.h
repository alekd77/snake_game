#ifndef MAIN_CPP_SOUNDS_MANAGER_H
#define MAIN_CPP_SOUNDS_MANAGER_H

#include <map>
#include <string>
//#include "SFML/Audio.hpp"

class SoundsManager {
private:
    //std::map<std::string, sf::Sound> soundsMap;

public:
    SoundsManager();

    void LoadSounds();
};
#endif //MAIN_CPP_SOUNDS_MANAGER_H
