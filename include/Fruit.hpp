//
// Created by User on 2025/04/10.
//

#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Enemies.hpp"

class Fruit : public Enemies
{
    public:
        explicit Fruit(const std::string& ImagePath);
        void MoveLeft() override ;
        void MoveRight()override ;
        void MoveUp()override ;
        void MoveDown()override ;
        bool TowardHasThings(int NewI, int NewJ)override ;
};

#endif //FRUIT_HPP
