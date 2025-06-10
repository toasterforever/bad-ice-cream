#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <vector>
#include <string>
#include <random>

#include "Character.hpp"
#include <chrono>




class Enemies : public Character
{
public:
    explicit Enemies(const std::string& ImagePath, Model::Move ModelMove,Model::Fired Fired=Model::Fired::None);

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

    bool fired();
    Model::Fired GetFireModel(){return Fired;}

    void ResetTimer()
    {
        lastTime=std::chrono::steady_clock::now();
    }

    char TowardIs(int I,int J)
    {
        return Map[I][J];
    }
    char TowardIs(Model::Direction NewDirection);

    void ChangeImage(int a);
private:
    std::chrono::steady_clock::time_point lastTime;  // 記錄上次創建冰的時間
    const std::chrono::milliseconds cooldownTime{3000};

    Model::Move ModelMove;
    Model::Fired Fired;
    bool Firing=false;
};




#endif //ENEMIES_HPP
