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
        NextI=i-1;NextJ=j;Map3[NextI][NextJ] = 'F';Map3[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map3[NextI][NextJ] = 'F';
    }

}
void Fruit::MoveRight(){
    this->SetDirection(Model::Direction::Right);

    if (!TowardHasThings(i+1,j))
    {
        NextI=i+1;NextJ=j;Map3[NextI][NextJ] = 'F';Map3[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map3[NextI][NextJ] = 'F';
    }

}
void Fruit::MoveUp(){
    this->SetDirection(Model::Direction::Up);
    if (!TowardHasThings(i,j-1))
    {
        NextJ=j-1;NextI=i;Map3[NextI][NextJ] = 'F';Map3[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map3[NextI][NextJ] = 'F';
    }

}
void Fruit::MoveDown()
{
    this->SetDirection(Model::Direction::Down);
    if (!TowardHasThings(i,j+1))
    {
        NextJ=j+1;NextI=i;Map3[NextI][NextJ] = 'F';Map3[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map3[NextI][NextJ] = 'F';
    }
}
bool Fruit::TowardHasThings(int NewI, int NewJ)
{

    if (Map[NewI][NewJ] == '#'||Map[NewI][NewJ] == 'I'||Map3[NewI][NewJ] == 'F')
    {
        return true;
    }
    return false;


}
