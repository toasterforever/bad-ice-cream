//
// Created by User on 2025/04/10.
//

#ifndef NAMESPACE_MODEL_HPP
#define NAMESPACE_MODEL_HPP

#include <string>
#include "Util/Input.hpp"

inline std::vector<std::string> Map = {
    "############",//0
    "#..........#",//1
    "#..........#",//2
    "#..........#",//3
    "#..........#",//4
    "#..........#",//5
    "#..........#",//6
    "#..........#",//8
    "#..........#",//8
    "#..........#",//9
    "#..........#",//10
    "############"//11
    // "012345678901"
};

inline glm::vec2 MainCharacterPosition;//讓敵人追蹤的目標

namespace Model {
    enum class Move {
        Row_Move,
        Column_Move,
        Around_Move,
        Auto_Move,
        Dont_Move
    };
    enum class ButtonStyle {
        W200H100,
        W80H80,
        Circle60,
        NotDefined
    };
    enum class Direction {
        Up=1,
        Down=2,
        Left=3,
        Right=4,
        None=-1
    };
    enum class PicureSource
    {
        Fruit,
        Locked,
        None
    };
}
#endif //NAMESPACE_MODEL_HPP
