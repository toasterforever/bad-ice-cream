//
// Created by User on 2025/06/09.
//
#include "CampFire.hpp"

CampFire::CampFire(const std::string& ImagePath): Floor(ImagePath)
{

}
void CampFire::ImageChange(int count)
{
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
void CampFire::TimeUpdate(bool Ice)
{
    if (Ice)
    {
        lastIceTime = std::chrono::steady_clock::now();
    }
    else
    {
        lastUnIceTime=std::chrono::steady_clock::now();
    }
}
void CampFire::ImageUpdate()
{
    if (lastUnIceTime-lastIceTime > cooldownTime)
    {
        ImageChange(0);
        SetFired(true);
    }
    else if (lastUnIceTime-lastIceTime > cooldownTimeReady)
    {
        ImageChange(2);
    }
    else
    {
        SetFired(false);
        ImageChange(1);
    }
}
