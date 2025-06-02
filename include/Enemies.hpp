#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <vector>
#include <string>
#include <random>

#include "Character.hpp"





class Enemies : public Character
{
public:
    explicit Enemies(const std::string& ImagePath, Model::Move ModelMove);

    void MoveTowards();
    void MoveDirection();
    Model::Direction GetRandomDirection();
    bool TowardHasThings(int NewI, int NewJ) override;
    bool TowardHasThings(Model::Direction NewDirection) override;

    void SetModel(Model::Move NewModel){ModelMove=NewModel;}
    Model::Move GetModel(){return ModelMove;}

    void UpdatePosition() override;

    Model::Direction AutoMove(glm::vec2 MainPosition);

    bool AutoMoveTest(Model::Direction Now, Model::Direction New, glm::vec2 NowPos);

private:
    Model::Move ModelMove;

};




#endif //ENEMIES_HPP
