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
    }
    m_IceCream->SetVisible(false);
    for (const auto& Ice : m_Ice) {
        Ice->SetVisible(false);
    }
    for (const auto& Floor : m_Floor) {
        Floor->SetVisible(false);
    }
    for (const auto& Fruit : m_Fruit) {
        Fruit->SetVisible(false);
    }
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
}

#endif //TURNOFFTHINGS_HPP
