//
// Created by User on 2025/06/04.
//
#include "App.hpp"

void App::FruitCounter()
{
    int counter=0;
    int sum=0;
    for (int a=0; a<m_Fruit.size(); a++)
    {
        if (m_Fruit[a]->InGame())
        {
            counter++;
        }

        if (a==20-1)
        {
            Fruit_Counter_Arr[0]=counter;
            m_Texts[0]->SetText(std::to_string(counter));
            if (Fruit_Counter_Arr[0]==0)
            {
                m_Texts[0]->SetVisible(false);
                m_FruitPicture[0]->SetVisible(false);
            }
            else
            {
                m_Texts[0]->SetVisible(true);
                m_FruitPicture[0]->SetVisible(true);
            }
            sum+=counter;
            counter=0;
        }
        else if (a==20+20-1)
        {
            Fruit_Counter_Arr[1]=counter;
            m_Texts[1]->SetText(std::to_string(counter));
            if (Fruit_Counter_Arr[1]==0)
            {
                m_Texts[1]->SetVisible(false);
                m_FruitPicture[1]->SetVisible(false);
            }
            else
            {
                m_Texts[1]->SetVisible(true);
                m_FruitPicture[1]->SetVisible(true);
            }
            sum+=counter;
            counter=0;
        }
        else if (a==20+20+4-1)
        {
            Fruit_Counter_Arr[2]=counter;
            m_Texts[2]->SetText(std::to_string(counter));
            if (Fruit_Counter_Arr[2]==0)
            {
                m_Texts[2]->SetVisible(false);
                m_FruitPicture[2]->SetVisible(false);
            }
            else
            {
                m_Texts[2]->SetVisible(true);
                m_FruitPicture[2]->SetVisible(true);
            }
            sum+=counter;
            counter=0;
        }
        else if (a==20+20+4+4-1)
        {
            Fruit_Counter_Arr[3]=counter;
            m_Texts[3]->SetText(std::to_string(counter));
            if (Fruit_Counter_Arr[3]==0)
            {
                m_Texts[3]->SetVisible(false);
                m_FruitPicture[3]->SetVisible(false);
            }
            else
            {
                m_Texts[3]->SetVisible(true);
                m_FruitPicture[3]->SetVisible(true);
            }
            sum+=counter;
            counter=0;
        }
        else if (a==20+20+4+4+4-1)
        {
            Fruit_Counter_Arr[4]=counter;
            m_Texts[4]->SetText(std::to_string(counter));
            if (Fruit_Counter_Arr[4]==0)
            {
                m_Texts[4]->SetVisible(false);
                m_FruitPicture[4]->SetVisible(false);
            }
            else
            {
                m_Texts[4]->SetVisible(true);
                m_FruitPicture[4]->SetVisible(true);
            }
            sum+=counter;
            counter=0;
            Fruit_Counter=sum;
        }

    }
    if (!IsGaming())
    {
        for (int a=0; a<m_FruitPicture.size(); a++)
        {
            m_Texts[a]->SetVisible(false);
            m_FruitPicture[a]->SetVisible(false);
        }

    }
}

void App::FruitUpdate2() //有多餘兩種水果時，讓第二階段水果顯示的函式
{
    switch (m_Phase)
    {
        case Phase::LV04:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Fruit_Reset_Arr[1]=true;
                    for (int a=0;a<8;a++)
                    {
                        m_Fruit[20+a]->SetVisible(true);
                    }
                }break;
            }
        case Phase::LV05:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Fruit_Reset_Arr[1]=true;
                    for (int a=0;a<8;a++)
                    {
                        m_Fruit[20+a]->SetVisible(true);
                    }
                }break;
            }
        case Phase::LV09:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[4]==false)
                {
                    Fruit_Reset_Arr[4]=true;
                    m_Fruit[20+20+4+4+0]->SetVisible(true);
                    m_Fruit[20+20+4+4+1]->SetVisible(true);

                }break;
            }
        case Phase::LV21:
            {
                if (Fruit_Counter_Arr[1]==0&&Fruit_Reset_Arr[0]==false)
                {
                    Fruit_Reset_Arr[0]=true;
                    for (int a=0;a<4;a++)
                    {
                        m_Fruit[0*10+a]->SetVisible(true);
                        m_Fruit[1*10+a]->SetVisible(true);
                    }

                }break;
            }
        case Phase::LV22:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Fruit_Reset_Arr[1]=true;
                    for (int a=0;a<16;a++)
                    {
                        m_Fruit[20+a]->SetVisible(true);
                    }

                }break;
            }
        case Phase::LV23:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                    {
                    Fruit_Reset_Arr[1]=true;
                    for (int a=0;a<16;a++)
                    {
                        m_Fruit[20+a]->SetVisible(true);
                    }

                }break;
            }
        case Phase::LV24:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Fruit_Reset_Arr[1]=true;
                    for (int a=0;a<4;a++)
                    {
                        m_Fruit[48+a]->SetVisible(true);
                    }
                }break;
            }
    case Phase::LV25:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Map3 = {
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
                    Fruit_Reset_Arr[1]=true;
                    for (int a=0;a<4;a++)
                    {
                        m_Fruit[42+a]->SetVisible(true);
                    }
                }

                break;
            }
        default:
            break;
    }
}
