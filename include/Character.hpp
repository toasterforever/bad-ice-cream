#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Input.hpp"

namespace Util {
    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };
    enum class Model {
        Row_Move,
        Column_Move,
        Around_Move,
        Auto_Move
    };
}


class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath, Util::Model Model=Util::Model::Row_Move):currentModel(Model){};

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        (void) other;
        if ( abs(other->GetPosition().x - this->GetPosition().x )<=35 && abs(other->GetPosition().y - this->GetPosition().y )<=70 )
        {
            return true;
        }
        return false;
    }

    void MoveLeft(){
        SetPosition( GetPosition() + glm::vec2{-5,0} );
        this->SetDirection(Util::Direction::Left);
    }
    void MoveRight(){
        SetPosition( GetPosition() + glm::vec2{5,0} );
        this->SetDirection(Util::Direction::Right);
    }
    void MoveUp(){
        SetPosition( GetPosition() + glm::vec2{0,5} );
        this->SetDirection(Util::Direction::Up);
    }
    void MoveDown(){
        SetPosition( GetPosition() + glm::vec2{0,-5} );
        this->SetDirection(Util::Direction::Down);
    }
    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.

    void Character::OnKeyPress(Util::Keycode key) {
        if (std::find(keyOrder.begin(), keyOrder.end(), key) == keyOrder.end()) {
            keyOrder.push_back(key);
        }
    }
    void Character::OnKeyRelease(Util::Keycode key) {
        keyOrder.erase(std::remove(keyOrder.begin(), keyOrder.end(), key), keyOrder.end());
    }

    void Character::UpdateMovement() {
        if (keyOrder.empty()) return;  // 沒有按鍵時不移動

        switch (keyOrder.front()) {
            case Util::Keycode::W:
            case Util::Keycode::UP:
                this->MoveUp();
                break;
            case Util::Keycode::S:
            case Util::Keycode::DOWN:
                this->MoveDown();
                break;

            case Util::Keycode::A:
            case Util::Keycode::LEFT:
                this->MoveLeft();
                break;
            case Util::Keycode::D:
            case Util::Keycode::RIGHT:
                this->MoveRight();
                break;
        }
    }

    Util::Direction GetDirection() const {
        return currentDirection;
    }

    void SetDirection(Util::Direction direction)
    {
        currentDirection = direction;
    }

    void MoveTowards()
    {
        Util::Direction direction = GetDirection();
        if(direction == Util::Direction::Up){
            MoveUp();
        }
        else if(direction == Util::Direction::Down){
            MoveDown();
        }
        else if(direction == Util::Direction::Left){
            MoveLeft();
        }
        else if(direction == Util::Direction::Right){
            MoveRight();
        }
        if(TowardHasIce()){
            switch(direction){
                case Util::Direction::Up:
                    SetDirection(Util::Direction::Down);
                    break;

                case Util::Direction::Down:
                    SetDirection(Util::Direction::Up);
                    break;
                case Util::Direction::Left:
                    SetDirection(Util::Direction::Right);
                    break;
                case Util::Direction::Right:
                    SetDirection(Util::Direction::Left);
                    break;
            }
        }
    }
private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }
    Util::Model currentModel = Util::Model::Row_Move;
    std::string m_ImagePath;

    std::vector<Util::Keycode> keyOrder;

    Util::Direction currentDirection = Util::Direction::Down;
};


#endif //CHARACTER_HPP







