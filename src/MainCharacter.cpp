//
// Created by User on 2025/03/13.
//

#include "MainCharacter.hpp"

MainCharacter::MainCharacter(const std::string& ImagePath)
    : Character(ImagePath)
{
}

void MainCharacter::UpdateMovement(std::vector<Util::Keycode> keyOrder){

    if (IsMoving())
    {
        UpdatePosition();
        return;
    }

    i = NextI;
    j = NextJ;
    if (keyOrder.empty()||keyOrder.front()==Util::Keycode::SPACE) return;  // 沒有按鍵時不移動
    switch (keyOrder.front()) {
    case Util::Keycode::W:
    case Util::Keycode::UP:
        this->MoveUp();Map[NextI][NextJ]='!';Map[i][j]='.';
        break;
    case Util::Keycode::S:
    case Util::Keycode::DOWN:
        this->MoveDown();Map[NextI][NextJ]='!';Map[i][j]='.';
        break;

    case Util::Keycode::A:
    case Util::Keycode::LEFT:
        this->MoveLeft();Map[NextI][NextJ]='!';Map[i][j]='.';
        break;
    case Util::Keycode::D:
    case Util::Keycode::RIGHT:
        this->MoveRight();Map[NextI][NextJ]='!';Map[i][j]='.';
        break;
    default:
        return;

    }
}

bool MainCharacter::TowardHasThings(int const NewI, int const NewJ)
{
    if (Map[NewI][NewJ] == 'I'||Map[NewI][NewJ] == '#')
    {
        return true;
    }
    return false;

}

bool MainCharacter::IsitIce(int NewI, int NewJ)
{
    if (Map[NewI][NewJ] == 'I')
    {
        return true;
    }return false;
}