//
// Created by User on 2025/03/28.
//

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <string>

#include "BackGround.hpp"
#include "Util/GameObject.hpp"
#include "Character.hpp"


class Floor : public BackGround {
public:
    explicit Floor(const std::string& ImagePath);
    int GetIndex()
    {
        return i-1+(j-1)*10;
    }
    int GetI()
    {
        return i;
    }
    int GetJ(){
        return j;
    }
    void SetPosition(int const newI, int const newJ)
    {
        i=newI;j=newJ;
        m_Transform.translation = glm::vec2(-330+(cellSize*newI),330-(cellSize*newJ));
    }
private:
    int i,j;
    std::string m_ImagePath;
};

#endif //FLOOR_HPP
