//
// Created by User on 2025/04/18.
//

#ifndef BGM_HPP
#define BGM_HPP


#include "Util/BGM.hpp"

class BGM:public Util::BGM
{
    public:
        BGM(const std::string &path): Util::BGM(path)
        {
            Mix_VolumeMusic(volume);
        }

    private:
        int volume=32;

};
#endif //BGM_HPP
