//
// Created by User on 2025/04/10.
//

#include "Fruit.hpp"

Fruit::Fruit(const std::string& ImagePath):Enemies(ImagePath,Model::Move::Dont_Move)
{

}

void Fruit::MoveLeft(){
    this->SetDirection(Model::Direction::Left);

    if (!TowardHasThings(i-1,j))
    {
        NextI=i-1;NextJ=j;
        // this->SetPosition(i-1,j);
    }
    else
    {
        NextI=i;NextJ=j;
    }

}
void Fruit::MoveRight(){
    this->SetDirection(Model::Direction::Right);

    if (!TowardHasThings(i+1,j))
    {
        NextI=i+1;NextJ=j;
        // this->SetPosition(i+1,j);
    }
    else
    {
        NextI=i;NextJ=j;
    }

}
void Fruit::MoveUp(){
    this->SetDirection(Model::Direction::Up);
    if (!TowardHasThings(i,j-1))
    {
        NextJ=j-1;NextI=i;
        // this->SetPosition(i,j-1);
    }
    else
    {
        NextI=i;NextJ=j;
    }

}
void Fruit::MoveDown()
{
    this->SetDirection(Model::Direction::Down);
    if (!TowardHasThings(i,j+1))
    {
        // this->SetPosition(i,j+1);
        NextJ=j+1;NextI=i;
    }
    else
    {
        NextI=i;NextJ=j;
    }
}