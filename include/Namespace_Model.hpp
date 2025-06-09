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

inline std::vector<std::string> Map2 = {
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
        Up=0,
        Down=1,
        Left=2,
        Right=3,
        None=-1
    };
    enum class PicureSource
    {
        Fruit,
        Locked,
        None
    };

    enum class Block
    {
        Ice,
        Fire
    };

    std::string DirToStr(Model::Direction dir);
    int DirToNum(Model::Direction dir);
    glm::vec2 DirToPos(Model::Direction dir);
}


#endif //NAMESPACE_MODEL_HPP
