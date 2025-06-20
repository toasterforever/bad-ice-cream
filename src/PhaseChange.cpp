//
// Created by User on 2025/06/04.
//

#include "App.hpp"



void App::TurnOnInterface()
{
    if (!IsGaming())
    {
        const auto now = std::chrono::steady_clock::now();
        const auto mousePosition = Util::Input::GetCursorPosition();
        switch (m_Phase){
            case Phase::Start:{
                m_BackGround[1]->SetVisible(true);//title
                m_Button[0]->SetVisible(true);//Manu
                m_Button[1]->SetVisible(true);//Help

                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime)
                {
                    if (m_Button[0]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[1]->SetVisible(false);//title
                        TurnOffButton();
                        m_Phase=Phase::Manu;
                        m_LastPhase=Phase::Start;
                    }
                    else if (m_Button[1]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[1]->SetVisible(false);//title
                        TurnOffButton();
                        m_Phase=Phase::Help;
                        m_LastPhase=Phase::Start;
                    }
                }
                break;
            }
            case Phase::Help:{
                m_BackGround[2]->SetVisible(true);//Interface_Help
                m_Button[2]->SetVisible(true);//Back

                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime)
                {
                    if (m_Button[2]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[2]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=m_LastPhase;
                        m_LastPhase=Phase::Help;
                        if (m_Phase != Phase::Start)
                        {
                            m_Button[4]->SetVisible(true);
                            m_Button[5]->SetVisible(true);
                            m_Button[6]->SetVisible(true);
                        }
                    }
                }
                break;
            }
            case Phase::Manu:
            {
                m_BackGround[3]->SetVisible(true);//Interface_None
                m_Button[2]->SetVisible(true);//Back
                for (int a = 0; a < 25; a++)
                {
                    m_Level[a]->SetVisible(true);
                    if (m_LVLockedPicture[a]->CheckLocked())
                    {
                        m_LVLockedPicture[a]->SetVisible(true);
                    }
                }
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime)
                {
                    if (Util::Input::IsKeyPressed(Util::Keycode::LCTRL)||Util::Input::IsKeyPressed(Util::Keycode::RCTRL))
                    {
                        for (int a=0;a<25;a++)
                        {
                            if (m_Level[a]->isClicked(mousePosition)&&m_LVLockedPicture[a]->CheckLocked())
                            {
                                lastMouseTime = now;
                                m_LVLockedPicture[a]->Unlock();
                                m_LVLockedPicture[a]->SetVisible(false);
                                break;
                            }
                        }
                    }
                }
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime)
                {
                    if (m_Button[2]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[3]->SetVisible(false);
                        TurnOffButton();
                        TurnOffLevelButton();
                        m_Phase=Phase::Start;
                        m_LastPhase=Phase::Manu;
                    }
                    for (int a=0;a<25;a++)
                    {
                        if (m_Level[a]->isClicked(mousePosition))
                        {
                            if (m_LVLockedPicture[a]->CheckLocked())
                            {
                                m_Texts[9]->SetVisible(true);
                                m_Texts[9]->SetText("level "+(a + 1 < 10 ? "0" + std::to_string(a + 1) : std::to_string(a + 1))+" is locked");
                                break;
                            }
                            else
                            {
                                lastMouseTime = now;
                                m_BackGround[3]->SetVisible(false);
                                TurnOffButton();
                                TurnOffLevelButton();
                                m_Phase= static_cast<Phase>(static_cast<int>(Phase::LV01) + a);
                                m_LastPhase=Phase::Manu;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case Phase::Win:
            {
                m_BackGround[4]->SetVisible(true);
                m_Button[7]->SetVisible(true);
                m_Button[8]->SetVisible(true);
                m_Button[9]->SetVisible(true);
                LV_Change =false;
                m_LVLockedPicture[static_cast<int>(m_LastPhase) -static_cast<int>(Phase::LV01)+1]->Unlock();
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime)
                {
                    if (m_Button[7]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[4]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=Phase::Manu;
                        m_LastPhase=Phase::Win;
                        m_Texts[9]->SetVisible(false);
                    }
                    if (m_Button[8]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[4]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=m_LastPhase;
                        m_LastPhase=Phase::Win;
                        m_Texts[9]->SetVisible(false);
                    }
                    if (m_Button[9]->isClicked(mousePosition))
                    {
                        if (static_cast<int>(m_LastPhase)-static_cast<int>(Phase::LV01)+1!=25)
                        {
                            lastMouseTime = now;
                            m_BackGround[4]->SetVisible(false);
                            TurnOffButton();
                            m_Phase=static_cast<Phase>(static_cast<int>(m_LastPhase) + 1);
                            m_LastPhase=Phase::Win;
                        }
                        else
                        {
                            m_Texts[9]->SetVisible(true);
                            m_Texts[9]->SetText("There is no another level");
                        }
                    }
                }
                break;
            }
            case Phase::Lose:
            {
                m_BackGround[5]->SetVisible(true);
                m_Button[7]->SetVisible(true);
                m_Button[8]->SetVisible(true);
                m_Button[9]->SetVisible(true);
                LV_Change = false;
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime)
                {
                    if (m_Button[7]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[5]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=Phase::Manu;
                        m_LastPhase=Phase::Lose;
                        m_Texts[9]->SetVisible(false);
                    }
                    if (m_Button[8]->isClicked(mousePosition))
                    {
                        lastMouseTime = now;
                        m_BackGround[5]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=m_LastPhase;
                        m_LastPhase=Phase::Lose;
                        m_Texts[9]->SetVisible(false);
                    }
                    if (m_Button[9]->isClicked(mousePosition))
                    {
                        if (!m_LVLockedPicture[static_cast<int>(m_LastPhase)-static_cast<int>(Phase::LV01)+1]->CheckLocked())
                        {
                            lastMouseTime = now;
                            m_BackGround[5]->SetVisible(false);
                            TurnOffButton();
                            m_Phase=static_cast<Phase>(static_cast<int>(m_LastPhase) + 1);
                            m_LastPhase=Phase::Lose;
                        }
                        else
                        {
                            m_Texts[9]->SetVisible(true);
                            m_Texts[9]->SetText("Next level is locked");
                        }
                    }
                }
                break;
            }
            default:
                break;
    }
    }
}

void App::InterfaceChangeFromLV()
{
    if (IsGaming())
    {
        const auto now = std::chrono::steady_clock::now();
        const auto mousePosition = Util::Input::GetCursorPosition();
        if (Fruit_Counter==0)
        {
            TurnOffButton();
            m_LastPhase=m_Phase;
            m_Phase=Phase::Win;
            TurnOffLevel();
        }
        if (!m_IceCream->GetVisibility()&&Fruit_Counter>0)
        {
            TurnOffButton();
            m_LastPhase=m_Phase;
            m_Phase=Phase::Lose;
            TurnOffLevel();
        }
        if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime&&m_Button[4]->isClicked(mousePosition))
        {
            TurnOffButton();
            lastMouseTime = now;
            LV_Change=false;
            TurnOffLevel();
        }
        if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime&&m_Button[5]->isClicked(mousePosition))
        {
            lastMouseTime = now;
            TurnOffButton();
            m_LastPhase=m_Phase;
            m_Phase=Phase::Help;
        }
        if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownTime&&m_Button[6]->isClicked(mousePosition))
        {
            lastMouseTime = now;
            TurnOffButton();
            m_LastPhase=m_Phase;
            m_Phase=Phase::Manu;
            LV_Change=false;
            TurnOffLevel();
        }
    }
}