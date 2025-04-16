#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <vector>
#include <string>
#include <random>

#include "Character.hpp"





class Enemies : public Character
{
public:
    explicit Enemies(const std::string& ImagePath);

    void MoveTowards();
    Model::Direction GetRandomDirection();
    bool TowardHasThings(int NewI, int NewJ) override;
    bool TowardHasThings(Model::Direction NewDirection) override;

    void SetModel(Model::Move NewModel);

    void UpdatePosition() override;
private:
    Model::Move ModelMove = Model::Move::Row_Move;

};




#endif //ENEMIES_HPP
