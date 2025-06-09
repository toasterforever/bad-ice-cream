//
// Created by User on 2025/06/09.
//

#ifndef CAMPFIRE_HPP
#define CAMPFIRE_HPP

#include "floor.hpp"

class CampFire : public Floor {
public:
    explicit CampFire(const std::string& ImagePath);
    void ImageUpdate()
    {
        count++;
        if (count==3)
        {
            count=0;
        }
        switch (count)
        {
            case 1:
                SetImage(GA_RESOURCE_DIR"/Image/Background/campfire/campfire_off.png");
            break;
            case 2:
                SetImage(GA_RESOURCE_DIR"/Image/Background/campfire/campfire_ready.png");
            break;
            case 0:
                SetImage(GA_RESOURCE_DIR"/Image/Background/campfire/campfire_on.png");
            break;

        }

    }
private:
    int count=0;
    std::string m_ImagePath;
};

#endif //CAMPFIRE_HPP
