//
// Created by User on 2025/05/16.
//

#include "Namespace_Model.hpp"
#include "Util/Logger.hpp"



std::string Model::DirToStr(Model::Direction dir)
{
    switch (dir)
    {
    case Model::Direction::Up:    return "Up";
    case Model::Direction::Down:  return "Down";
    case Model::Direction::Left:  return "Left";
    case Model::Direction::Right: return "Right";
    case Model::Direction::None:  return "None";
    default:                      return "Unknown";
    }
}

int Model::DirToNum(Model::Direction dir)
{
    switch (dir)
    {
        case Model::Direction::Up:    return 0;
        case Model::Direction::Down:  return 1;
        case Model::Direction::Left:  return 2;
        case Model::Direction::Right: return 3;
        default:                      LOG_DEBUG(DirToStr(dir));
    }
}

glm::vec2 Model::DirToPos(Model::Direction dir)
{
    switch (dir)
    {
        case Model::Direction::Up:    return glm::vec2(0, -1);
        case Model::Direction::Down:  return glm::vec2(0, 1);
        case Model::Direction::Left:  return glm::vec2(-1, 0);
        case Model::Direction::Right: return glm::vec2(1, 0);
        default:                      LOG_DEBUG(DirToStr(dir));
    }
}
