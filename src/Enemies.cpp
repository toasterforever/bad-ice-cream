//
// Created by User on 2025/03/14.
//
#include "Enemies.hpp"

#include "MainCharacter.hpp"
#include "spdlog/spdlog.h"
#include "Util/Logger.hpp"
Enemies::Enemies(const std::string& ImagePath,Model::Move ModelMove): Character(ImagePath),ModelMove(ModelMove)
{

}
void Enemies::MoveDirection()
{
    switch (GetDirection())
    {
        case Model::Direction::Up:
            MoveUp();break;
        case Model::Direction::Down:
            MoveDown();break;
        case Model::Direction::Left:
            MoveLeft();break;
        case Model::Direction::Right:
            MoveRight();break;
        case Model::Direction::None:
            break;
    }
}
void Enemies::MoveTowards(){
    if (IsMoving())
    {
        UpdatePosition();
        return;
    }

        i = NextI;
        j = NextJ;


    if (ModelMove==Model::Move::Auto_Move)
    {

        SetDirection(AutoMove(MainCharacterPosition));
        MoveDirection();
        return;
    }

    Model::Direction direction = GetDirection();
    if (TowardHasThings(direction))
    {
        if (ModelMove==Model::Move::Row_Move||ModelMove==Model::Move::Column_Move||ModelMove==Model::Move::Around_Move)
        {
            SetDirection(GetRandomDirection());return;
        }

    }
    MoveDirection();
}

Model::Direction Enemies::GetRandomDirection()
{
    static std::random_device rd;   // 產生隨機種子
    static std::mt19937 gen(rd());  // 使用 Mersenne Twister 隨機數引擎
    static std::uniform_int_distribution<int> dist(0, 3);  // 產生 0~3 的整數
    if (ModelMove==Model::Move::Row_Move)
    {
        switch (dist(gen))
        {
        case 0:
        case 1:
            return Model::Direction::Right;
        case 2:
        case 3:
            return Model::Direction::Left;
        }
    }
    if (ModelMove==Model::Move::Column_Move)
    {
        switch (dist(gen))
        {
        case 0:
        case 1:
            return Model::Direction::Up;
        case 2:
        case 3:
            return Model::Direction::Down;
        }
    }
    if (ModelMove==Model::Move::Around_Move||ModelMove==Model::Move::Auto_Move)
    {
        switch (dist(gen)) {
            case 0: return Model::Direction::Up;
            case 1: return Model::Direction::Down;
            case 2: return Model::Direction::Left;
            case 3: return Model::Direction::Right;
        }
    }

    if (ModelMove==Model::Move::Dont_Move)
    {
        return Model::Direction::None;
    }
}

bool Enemies::TowardHasThings(int NewI, int NewJ)
{
    if (Map[NewI][NewJ] == '#'||Map[NewI][NewJ] == 'I'||Map[NewI][NewJ] == 'E')
    {
        return true;
    }
    return false;

}

bool Enemies::TowardHasThings(Model::Direction NewDirection)
{
    switch (NewDirection)
    {
    case Model::Direction::Up:
        return TowardHasThings(i, j-1);
    case Model::Direction::Down:
        return TowardHasThings(i, j+1);
    case Model::Direction::Left:
        return TowardHasThings(i-1, j);
    case Model::Direction::Right:
        return TowardHasThings(i+1, j);
    default:
        return false;
    }
}

void Enemies::UpdatePosition()
{
    glm::vec2 targetPosition = glm::vec2(-330 + cellSize * NextI, 330 - cellSize * NextJ);

    if (glm::distance(m_Transform.translation, targetPosition) > .1f) {
        // 緩慢移動到目標位置
        m_Transform.translation = glm::mix(m_Transform.translation, targetPosition, 0.1f);
    } else {
        // 抵達目標位置後，更新 i, j
        i = NextI;
        j = NextJ;

    }
}
