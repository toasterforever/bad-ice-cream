#include "Character.hpp"
#include "Util/Image.hpp"


Character::Character(const std::string& ImagePath) {
    SetImage(ImagePath);

}

void Character::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Character::MoveLeft(){
    this->SetDirection(Model::Direction::Left);

    if (!TowardHasThings(i-1,j))
    {
        NextI=i-1;NextJ=j;Map[NextI][NextJ] = 'E';Map[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map[NextI][NextJ] = 'E';
    }

}
void Character::MoveRight(){
    this->SetDirection(Model::Direction::Right);

    if (!TowardHasThings(i+1,j))
    {
        NextI=i+1;NextJ=j;Map[NextI][NextJ] = 'E';Map[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map[NextI][NextJ] = 'E';
    }

}
void Character::MoveUp(){
    this->SetDirection(Model::Direction::Up);
    if (!TowardHasThings(i,j-1))
    {
        NextJ=j-1;NextI=i;Map[NextI][NextJ] = 'E';Map[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map[NextI][NextJ] = 'E';
    }

}
void Character::MoveDown()
{
    this->SetDirection(Model::Direction::Down);
    if (!TowardHasThings(i,j+1))
    {
    NextJ=j+1;NextI=i;Map[NextI][NextJ] = 'E';Map[i][j] = '.';
    }
    else
    {
        NextI=i;NextJ=j;Map[NextI][NextJ] = 'E';
    }
}

bool Character::IsMoving() const {
    glm::vec2 targetPosition = glm::vec2(-330 + cellSize * NextI, 330 - cellSize * NextJ);
    return glm::distance(m_Transform.translation, targetPosition) > .1f;
}

void Character::UpdatePosition() //滑動 而非 等速移動 ，沒甚麼意義，但我喜歡
{
    glm::vec2 targetPosition = glm::vec2(-330 + cellSize * NextI, 330 - cellSize * NextJ);

    if (glm::distance(m_Transform.translation, targetPosition) > .1f) {
        // 緩慢移動到目標位置
        m_Transform.translation = glm::mix(m_Transform.translation, targetPosition, 0.2f);
    } else {
        // 抵達目標位置後，更新 i, j
        i = NextI;
        j = NextJ;
        MainCharacterPosition={i,j};
    }
}

bool Character::TowardHasThings(Model::Direction NewDirection)
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

bool Character::TowardHasThings(int NewI, int NewJ)
{
    if (Map[NewI][NewJ] == '@'||Map[NewI][NewJ] == '#'||Map[NewI][NewJ] == '!')//我對 '@'沒印象，似乎是個不必要程式，但為了避免刪掉後出錯，我決定不動它
    {
        return true;
    }
    return false;

}