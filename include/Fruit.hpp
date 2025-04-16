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

};

#endif //FRUIT_HPP
