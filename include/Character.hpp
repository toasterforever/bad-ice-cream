#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Input.hpp"
#include "Namespace_Model.hpp"
#include <iostream>

inline int cellSize=60;
class Character : public Util::GameObject {
public:


    explicit Character(const std::string& ImagePath);

    int i=0 , j=0 ;int NextI=0,NextJ=0;

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    [[nodiscard]] const glm::vec2 GetIJ() const { return {i,j}; }

    [[nodiscard]] int GetI() const{return i;}

    [[nodiscard]] int GetJ() const{return j;}

    [[nodiscard]] const glm::vec2 GetNextIJ() const { return {NextI,NextJ}; }

    [[nodiscard]] int GetNextI() const{return NextI;}

    [[nodiscard]] int GetNextJ() const{return NextJ;}

    [[nodiscard]] int GetIndex() const{return i-1+(j-1)*10;}

    [[nodiscard]] int GetNextIndex() const{return NextI-1+(NextJ-1)*10;}
    void SetImage(const std::string& ImagePath);

    void SetPosition(int newI, int newJ)
    {
        i = newI;NextI=newI;NextJ=newJ;
        j = newJ;

        m_Transform.translation = glm::vec2(-330+(cellSize*i),330-(cellSize*j));
    }

    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other, glm::vec2 Position) const {
        (void) other;
        if ( abs(other->GetPosition().x - Position.x )<cellSize-20 && abs(other->GetPosition().y - Position.y )<cellSize-20 )
        {
            return true;
        }
        return false;
    }

    virtual void MoveLeft();
    virtual void MoveRight();
    virtual void MoveUp();
    virtual void MoveDown();

    [[nodiscard]] Model::Direction GetDirection() const {return currentDirection;}

    void SetDirection(Model::Direction direction){currentDirection = direction;}

    virtual bool TowardHasThings(int NewI, int NewJ);

    virtual bool TowardHasThings(Model::Direction NewDirection);

    virtual void UpdatePosition();

    bool IsMoving() const;


private:

    std::string m_ImagePath;

    glm::vec2 targetPosition = glm::vec2(-330 + cellSize * NextI, 330 - cellSize * NextJ);

    Model::Direction currentDirection = Model::Direction::None;



};


#endif //CHARACTER_HPP







