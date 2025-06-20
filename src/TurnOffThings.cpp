//
// Created by User on 2025/06/09.
//

#include "App.hpp"

void App::TurnOffLevel()
{
    {
        for (const auto& enemy : m_Enemies) {
            enemy->SetVisible(false);
            enemy->SetDirection(Model::Direction::None);
        }
        m_IceCream->SetVisible(false);
        m_IceCream->SetDirection(Model::Direction::None);
        for (const auto& Fruit : m_Fruit) {
            Fruit->SetVisible(false);
            Fruit->SetInGame(false);
            Fruit->SetDirection(Model::Direction::None);
        }
    }//Charcter
    {
        for (const auto& Ice : m_Ice) {
            Ice->SetVisible(false);
        }
        for (const auto& Floor : m_Floor) {
            Floor->SetVisible(false);
        }
        for (const auto& Picture : m_FruitPicture) {
            Picture->SetVisible(false);
        }
        for (const auto& Text:m_Texts)
        {
            Text->SetVisible(false);
        }
        for (const auto& wall:m_Wall)
        {
            wall->SetVisible(false);
        }
        for (const auto& wall:m_AirWall)
        {
            wall->SetVisible(false);
        }
    }//BackGround
    {
        for (const auto& CampFire:m_CampFire)
        {
            CampFire->SetVisible(false);
        }
        for (const auto& Block:m_IceBlock)
        {
            Block->SetVisible(false);
        }
        for (const auto& Block:m_FireBlock)
        {
            Block->SetVisible(false);
        }
        for (const auto& Block:m_Fire)
        {
            Block->SetVisible(false);
        }
    }//BackGround that will update
    {
        for (const auto& Arrow:m_Arrow_Left)
        {
            Arrow->SetVisible(false);
        }
        for (const auto& Arrow:m_Arrow_Right)
        {
            Arrow->SetVisible(false);
        }
        for (const auto& Arrow:m_Arrow_Up)
        {
            Arrow->SetVisible(false);
        }
        for (const auto& Arrow:m_Arrow_Down)
        {
            Arrow->SetVisible(false);
        }
    }//Arrow
}

void App::TurnOffButton()
{
    for (const auto& Button : m_Button)
    {
        Button->SetVisible(false);
    }
    m_Texts[9]->SetVisible(false);
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