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

        if (a==16-1)
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
        else if (a==16+16-1)
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
        else if (a==16+16+4-1)
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
        else if (a==16+16+4+4-1)
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
        else if (a==16+16+4+4+4-1)
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
    if (!(static_cast<int>(m_Phase)>=static_cast<int>(Phase::LV01)&&static_cast<int>(m_Phase)<=static_cast<int>(Phase::LV25)))
    {
        for (int a=0; a<m_FruitPicture.size(); a++)
        {
            m_Texts[a]->SetVisible(false);
            m_FruitPicture[a]->SetVisible(false);
        }

    }
}

void App::FruitUpdate()
{
    switch (m_Phase)
    {
        case Phase::LV04:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Fruit_Reset_Arr[1]=true;
                    m_Fruit[16]->SetVisible(true);
                    m_Fruit[17]->SetVisible(true);
                    m_Fruit[18]->SetVisible(true);
                    m_Fruit[19]->SetVisible(true);
                    m_Fruit[20]->SetVisible(true);
                    m_Fruit[21]->SetVisible(true);
                    m_Fruit[22]->SetVisible(true);
                    m_Fruit[23]->SetVisible(true);
                }break;
            }
        case Phase::LV05:
            {
                if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
                {
                    Fruit_Reset_Arr[1]=true;
                    m_Fruit[16]->SetVisible(true);
                    m_Fruit[17]->SetVisible(true);
                    m_Fruit[18]->SetVisible(true);
                    m_Fruit[19]->SetVisible(true);
                    m_Fruit[20]->SetVisible(true);
                    m_Fruit[21]->SetVisible(true);
                    m_Fruit[22]->SetVisible(true);
                    m_Fruit[23]->SetVisible(true);
                }break;
            }
        default:
            break;
    }
}
