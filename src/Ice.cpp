//
// Created by User on 2025/03/14.
//

#include "Ice.hpp"

Ice::Ice(const std::string& ImagePath): Character(ImagePath)
{

}

bool Ice::isCreate() const
{
    return GetVisibility();
}
bool Ice::isBroke() const
{
    return !GetVisibility();
}

bool Ice::TowardHasThings(int const NewI, int const NewJ)
{
    if (Map[NewI][NewJ] == '#'||Map[NewI][NewJ] == 'E')
    {
        return true;
    }
    return false;

}