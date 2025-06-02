//
// Created by User on 2025/04/12.
//

#ifndef TURNOFFTHINGS_HPP
#define TURNOFFTHINGS_HPP

#include "App.hpp"

void App::TurnOffLevel()
{

    for (const auto& enemy : m_Enemies_1) {
        enemy->SetVisible(false);
        enemy->SetDirection(Model::Direction::None);
    }
    m_IceCream->SetVisible(false);
    m_IceCream->SetDirection(Model::Direction::None);
    for (const auto& Ice : m_Ice) {
        Ice->SetVisible(false);
    }
    for (const auto& Floor : m_Floor) {
        Floor->SetVisible(false);
    }
    for (const auto& Fruit : m_Fruit) {
        Fruit->SetVisible(false);
        Fruit->SetDirection(Model::Direction::None);
    }
    for (const auto& Picture : m_FruitPicture) {
        Picture->SetVisible(false);
    }
    for (const auto& Text:m_Texts)
    {
        Text->SetVisible(false);
    }
    Map={
        "############",//0
        "#..........#",//1
        "#..........#",//2
        "#..........#",//3
        "#..........#",//4
        "#..........#",//5
        "#..........#",//6
        "#..........#",//8
        "#..........#",//8
        "#..........#",//9
        "#..........#",//10
        "############"//11
        // "012345678901"
    };
}

void App::TurnOffButton()
{
    for (const auto& Button : m_Button)
    {
        Button->SetVisible(false);
    }
}

void App::TurnOffLevelButton()
{
    for (const auto& LevelButton : m_Level)
    {
        LevelButton->SetVisible(false);
    }

    for (const auto& Locked : m_LVLockedPicture)
    {
        Locked->SetVisible(false);
    }
}

#endif //TURNOFFTHINGS_HPP
