#ifndef WALL_HPP
#define WALL_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Character.hpp"


class Wall : public Character {
public:
    explicit Wall(const std::string& ImagePath);

private:
    std::string m_ImagePath;
};

#endif //WALL_HPP
