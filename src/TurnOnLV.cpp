//
// Created by User on 2025/06/04.
//

#include "App.hpp"
//Fruit=16+16+4+4+4
inline void App::LVReset()
{
    {
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
        Map2={
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
    }//Map
    for (auto& enemy:m_Enemies )
    {
        enemy->ResetTimer();
        enemy->ChangeImage(2);
    }
    {
        for (const auto& Block:m_IceBlock)
        {
            Block->ResetTimer();
        }
        for (const auto& Block:m_FireBlock)
        {
            Block->ResetTimer();
        }
        for (const auto& Block:m_Fire)
        {
            Block->ResetTimer();
        }
    }//Block
    m_Button[4]->SetVisible(true);
    m_Button[5]->SetVisible(true);
    m_Button[6]->SetVisible(true);
    LV_Change = 1;
    for (int a = 0; a < 100; a++)
    {
        m_Floor[a]->SetVisible(true);
        m_Ice[a]->SetVisible(false);
        m_Wall[a]->SetVisible(false);
        m_AirWall[a]->SetVisible(false);
    }
    m_IceCream->SetVisible(true);

    Fruit_Reset_Arr={false,false,false,false,false,false,false,false,false};
    Fruit_Counter = 0;

    Fruit_Counter_Arr = {0};
    for (auto text:m_Texts)
    {
        text->SetText("0");
        text->SetVisible(false);
    }

}

void App::TurnOnLV()
{
if (LV_Change==0&&IsGaming())
{
    LVReset();
    switch (m_Phase)//Fruit=20+20+4+4+4 //enemy 4+4 +8 +4+4+4+4+4 +4 //cross 1 3 around row
    {
    case Phase::LV01:{

            {

                m_IceCream->SetPosition(1,1);
                for (int a = 0; a < 4; a++)
                {
                    m_Enemies[a]->SetVisible(true);
                }
                m_Enemies[0]->SetPosition(5,5);
                m_Enemies[1]->SetPosition(5,6);
                m_Enemies[2]->SetPosition(6,6);
                m_Enemies[3]->SetPosition(6,5);

                m_Fruit[0]->SetVisible(true);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[1]->SetInGame(true);
                m_Fruit[2]->SetInGame(true);
                m_Fruit[3]->SetInGame(true);
                m_Fruit[0]->SetPosition(4, 1);
                m_Fruit[1]->SetPosition(3, 1);
                m_Fruit[2]->SetPosition(7, 1);
                m_Fruit[3]->SetPosition(8, 1);

                m_Fruit[4]->SetVisible(true);
                m_Fruit[5]->SetVisible(true);
                m_Fruit[6]->SetVisible(true);
                m_Fruit[7]->SetVisible(true);
                m_Fruit[4]->SetInGame(true);
                m_Fruit[5]->SetInGame(true);
                m_Fruit[6]->SetInGame(true);
                m_Fruit[7]->SetInGame(true);
                m_Fruit[4]->SetPosition(1, 3);
                m_Fruit[5]->SetPosition(1, 4);
                m_Fruit[6]->SetPosition(1, 7);
                m_Fruit[7]->SetPosition(1, 8);

                m_Fruit[8]->SetVisible(true);
                m_Fruit[9]->SetVisible(true);
                m_Fruit[10]->SetVisible(true);
                m_Fruit[11]->SetVisible(true);
                m_Fruit[8]->SetInGame(true);
                m_Fruit[9]->SetInGame(true);
                m_Fruit[10]->SetInGame(true);
                m_Fruit[11]->SetInGame(true);
                m_Fruit[8]->SetPosition(10, 3);
                m_Fruit[9]->SetPosition(10, 4);
                m_Fruit[10]->SetPosition(10, 7);
                m_Fruit[11]->SetPosition(10, 8);

                m_Fruit[12]->SetVisible(true);
                m_Fruit[13]->SetVisible(true);
                m_Fruit[14]->SetVisible(true);
                m_Fruit[15]->SetVisible(true);
                m_Fruit[12]->SetInGame(true);
                m_Fruit[13]->SetInGame(true);
                m_Fruit[14]->SetInGame(true);
                m_Fruit[15]->SetInGame(true);
                m_Fruit[12]->SetPosition(3, 10);
                m_Fruit[13]->SetPosition(4, 10);
                m_Fruit[14]->SetPosition(7, 10);
                m_Fruit[15]->SetPosition(8, 10);
            }
            break;}
    case Phase::LV02:{

        {

            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
            m_Fruit[0]->SetInGame(true);
            m_Fruit[1]->SetInGame(true);
            m_Fruit[2]->SetInGame(true);
            m_Fruit[3]->SetInGame(true);
            m_Fruit[0]->SetPosition(3, 3);
            m_Fruit[1]->SetPosition(2, 2);
            m_Fruit[2]->SetPosition(2, 9);
            m_Fruit[3]->SetPosition(3, 8);

            m_Fruit[4]->SetVisible(true);
            m_Fruit[5]->SetVisible(true);
            m_Fruit[6]->SetVisible(true);
            m_Fruit[7]->SetVisible(true);
            m_Fruit[4]->SetInGame(true);
            m_Fruit[5]->SetInGame(true);
            m_Fruit[6]->SetInGame(true);
            m_Fruit[7]->SetInGame(true);
            m_Fruit[4]->SetPosition(8, 3);
            m_Fruit[5]->SetPosition(9, 2);
            m_Fruit[6]->SetPosition(9, 9);
            m_Fruit[7]->SetPosition(8, 8);

            m_IceCream->SetPosition(5,5);

            m_Enemies[1]->SetVisible(true);
            m_Enemies[2]->SetVisible(true);


            m_Enemies[1]->SetPosition(1,7);
            m_Enemies[2]->SetPosition(10,4);



            m_Enemies[5]->SetVisible(true);
            m_Enemies[6]->SetVisible(true);


            m_Enemies[5]->SetPosition(7,1);
            m_Enemies[6]->SetPosition(4,10);


        }

        break;}
    case Phase::LV03:{
        {

            m_Ice[10*3+3]->SetVisible(true);
            m_Ice[10*3+4]->SetVisible(true);
            m_Ice[10*3+5]->SetVisible(true);
            m_Ice[10*3+6]->SetVisible(true);

            m_Ice[10*4+3]->SetVisible(true);
            m_Ice[10*5+3]->SetVisible(true);
            m_Ice[10*6+3]->SetVisible(true);

            m_Ice[10*4+6]->SetVisible(true);
            m_Ice[10*5+6]->SetVisible(true);
            m_Ice[10*6+6]->SetVisible(true);

            m_Ice[10*6+4]->SetVisible(true);
            m_Ice[10*6+5]->SetVisible(true);

            m_Ice[10*1+2]->SetVisible(true);
            m_Ice[10*2+1]->SetVisible(true);
            m_Ice[10*1+7]->SetVisible(true);
            m_Ice[10*2+8]->SetVisible(true);

            m_Ice[10*7+1]->SetVisible(true);
            m_Ice[10*8+2]->SetVisible(true);
            m_Ice[10*7+8]->SetVisible(true);
            m_Ice[10*8+7]->SetVisible(true);

            m_Enemies[8]->SetVisible(true);
            m_Enemies[9]->SetVisible(true);
            m_Enemies[10]->SetVisible(true);
            m_Enemies[11]->SetVisible(true);
            m_Enemies[8]->SetPosition(1,1);
            m_Enemies[9]->SetPosition(10,1);
            m_Enemies[10]->SetPosition(1,10);
            m_Enemies[11]->SetPosition(10,10);


            m_IceCream->SetPosition(5,5);

            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
            m_Fruit[0]->SetInGame(true);
            m_Fruit[1]->SetInGame(true);
            m_Fruit[2]->SetInGame(true);
            m_Fruit[3]->SetInGame(true);
            m_Fruit[0]->SetPosition(1, 10);
            m_Fruit[1]->SetPosition(1, 1);
            m_Fruit[2]->SetPosition(10, 1);
            m_Fruit[3]->SetPosition(10, 10);

        }

        break;
    }
    case Phase::LV04:{
        {

            m_Enemies[8]->SetVisible(true);
            m_Enemies[9]->SetVisible(true);
            m_Enemies[10]->SetVisible(true);
            m_Enemies[11]->SetVisible(true);
            m_Enemies[8]->SetPosition(1,1);
            m_Enemies[9]->SetPosition(10,1);
            m_Enemies[10]->SetPosition(1,10);
            m_Enemies[11]->SetPosition(10,10);


            m_IceCream->SetPosition(5,5);

            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
            m_Fruit[0]->SetInGame(true);
            m_Fruit[1]->SetInGame(true);
            m_Fruit[2]->SetInGame(true);
            m_Fruit[3]->SetInGame(true);
            m_Fruit[0]->SetPosition(1, 10);
            m_Fruit[1]->SetPosition(1, 1);
            m_Fruit[2]->SetPosition(10, 1);
            m_Fruit[3]->SetPosition(10, 10);


            m_Fruit[20+0]->SetVisible(false);
            m_Fruit[20+1]->SetVisible(false);
            m_Fruit[20+2]->SetVisible(false);
            m_Fruit[20+3]->SetVisible(false);
            m_Fruit[20+4]->SetVisible(false);
            m_Fruit[20+5]->SetVisible(false);
            m_Fruit[20+6]->SetVisible(false);
            m_Fruit[20+7]->SetVisible(false);

            m_Fruit[20+0]->SetInGame(true);
            m_Fruit[20+1]->SetInGame(true);
            m_Fruit[20+2]->SetInGame(true);
            m_Fruit[20+3]->SetInGame(true);
            m_Fruit[20+4]->SetInGame(true);
            m_Fruit[20+5]->SetInGame(true);
            m_Fruit[20+6]->SetInGame(true);
            m_Fruit[20+7]->SetInGame(true);

            m_Fruit[20+0]->SetPosition(5,5);
            m_Fruit[20+1]->SetPosition(5,6);
            m_Fruit[20+2]->SetPosition(5,7);
            m_Fruit[20+3]->SetPosition(5,4);
            m_Fruit[20+4]->SetPosition(6,4);
            m_Fruit[20+5]->SetPosition(6,5);
            m_Fruit[20+6]->SetPosition(6,6);
            m_Fruit[20+7]->SetPosition(6,7);
        }


        break;
    }
    case Phase::LV05:{
        {




            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
            m_Fruit[0]->SetInGame(true);
            m_Fruit[1]->SetInGame(true);
            m_Fruit[2]->SetInGame(true);
            m_Fruit[3]->SetInGame(true);
            m_Fruit[0]->SetPosition(5, 5);
            m_Fruit[1]->SetPosition(5, 6);
            m_Fruit[2]->SetPosition(6, 5);
            m_Fruit[3]->SetPosition(6, 6);


            m_Fruit[20+0]->SetVisible(false);
            m_Fruit[20+1]->SetVisible(false);
            m_Fruit[20+2]->SetVisible(false);
            m_Fruit[20+3]->SetVisible(false);
            m_Fruit[20+4]->SetVisible(false);
            m_Fruit[20+5]->SetVisible(false);
            m_Fruit[20+6]->SetVisible(false);
            m_Fruit[20+7]->SetVisible(false);
            m_Fruit[20+0]->SetInGame(true);
            m_Fruit[20+1]->SetInGame(true);
            m_Fruit[20+2]->SetInGame(true);
            m_Fruit[20+3]->SetInGame(true);
            m_Fruit[20+4]->SetInGame(true);
            m_Fruit[20+5]->SetInGame(true);
            m_Fruit[20+6]->SetInGame(true);
            m_Fruit[20+7]->SetInGame(true);

            m_Fruit[20+0]->SetPosition(1,1);
            m_Fruit[20+1]->SetPosition(1,2);
            m_Fruit[20+2]->SetPosition(1,9);
            m_Fruit[20+3]->SetPosition(1,10);
            m_Fruit[20+4]->SetPosition(10,1);
            m_Fruit[20+5]->SetPosition(10,2);
            m_Fruit[20+6]->SetPosition(10,9);
            m_Fruit[20+7]->SetPosition(10,10);


            m_Enemies[8+0]->SetVisible(true);
            m_Enemies[8+0]->SetPosition(9,9);
            m_Enemies[8+1]->SetVisible(true);
            m_Enemies[8+1]->SetPosition(8,8);
            m_Enemies[8+2]->SetVisible(true);
            m_Enemies[8+2]->SetPosition(8,9);
            m_Enemies[8+3]->SetVisible(true);
            m_Enemies[8+3]->SetPosition(9,8);
            m_Enemies[8+4]->SetVisible(true);
            m_Enemies[8+4]->SetPosition(5,5);
            m_Enemies[8+5]->SetVisible(true);
            m_Enemies[8+5]->SetPosition(5,6);
            m_Enemies[8+6]->SetVisible(true);
            m_Enemies[8+6]->SetPosition(6,5);
            m_Enemies[8+7]->SetVisible(true);
            m_Enemies[8+7]->SetPosition(6,6);



            m_IceCream->SetPosition(1,1);

        }


        break;
    }

    case Phase::LV06:
        {
            {


            {

                {
                    m_Fruit[40+0]->SetVisible(true);
                    m_Fruit[40+1]->SetVisible(true);
                    m_Fruit[40+2]->SetVisible(true);
                    m_Fruit[40+3]->SetVisible(true);
                    m_Fruit[40+0]->SetInGame(true);
                    m_Fruit[40+1]->SetInGame(true);
                    m_Fruit[40+2]->SetInGame(true);
                    m_Fruit[40+3]->SetInGame(true);


                    m_Fruit[40+4+0]->SetVisible(true);
                    m_Fruit[40+4+1]->SetVisible(true);
                    m_Fruit[40+4+2]->SetVisible(true);
                    m_Fruit[40+4+3]->SetVisible(true);
                    m_Fruit[40+4+4]->SetVisible(true);
                    m_Fruit[40+4+4+1]->SetVisible(true);
                    m_Fruit[40+4+4+2]->SetVisible(true);
                    m_Fruit[40+4+4+3]->SetVisible(true);

                    m_Fruit[40+4+0]->SetInGame(true);
                    m_Fruit[40+4+1]->SetInGame(true);
                    m_Fruit[40+4+2]->SetInGame(true);
                    m_Fruit[40+4+3]->SetInGame(true);
                    m_Fruit[40+4+4+0]->SetInGame(true);
                    m_Fruit[40+4+4+1]->SetInGame(true);
                    m_Fruit[40+4+4+2]->SetInGame(true);
                    m_Fruit[40+4+4+3]->SetInGame(true);

                    m_Fruit[40+0]->SetPosition(5, 5);
                    m_Fruit[40+1]->SetPosition(5, 6);
                    m_Fruit[40+2]->SetPosition(6, 5);
                    m_Fruit[40+3]->SetPosition(6, 6);

                    m_Fruit[40+4+0]->SetPosition(3,3);
                    m_Fruit[40+4+1]->SetPosition(3,8);
                    m_Fruit[40+4+2]->SetPosition(8,3);
                    m_Fruit[40+4+3]->SetPosition(8,8);

                    m_Fruit[40+4+4+0]->SetPosition(4,4);
                    m_Fruit[40+4+4+1]->SetPosition(4,7);
                    m_Fruit[40+4+4+2]->SetPosition(7,4);
                    m_Fruit[40+4+4+3]->SetPosition(7,7);
                }
            }//Fruit

            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[8]->SetPosition(10,10);
            }//Enemies

            m_IceCream->SetPosition(1,1);

            }

        break;
        }
    case Phase::LV07:
    {
        {

            m_Fruit[20+0]->SetVisible(true);
            m_Fruit[20+1]->SetVisible(true);
            m_Fruit[20+2]->SetVisible(true);
            m_Fruit[20+3]->SetVisible(true);
            m_Fruit[20+4]->SetVisible(true);
            m_Fruit[20+5]->SetVisible(true);
            m_Fruit[20+6]->SetVisible(true);
            m_Fruit[20+7]->SetVisible(true);

            m_Fruit[20+0]->SetInGame(true);
            m_Fruit[20+1]->SetInGame(true);
            m_Fruit[20+2]->SetInGame(true);
            m_Fruit[20+3]->SetInGame(true);
            m_Fruit[20+4]->SetInGame(true);
            m_Fruit[20+5]->SetInGame(true);
            m_Fruit[20+6]->SetInGame(true);
            m_Fruit[20+7]->SetInGame(true);

            m_Fruit[20+0]->SetPosition(5,5);
            m_Fruit[20+1]->SetPosition(5,6);
            m_Fruit[20+2]->SetPosition(5,7);
            m_Fruit[20+3]->SetPosition(5,4);
            m_Fruit[20+4]->SetPosition(6,4);
            m_Fruit[20+5]->SetPosition(6,5);
            m_Fruit[20+6]->SetPosition(6,6);
            m_Fruit[20+7]->SetPosition(6,7);

        }//Fruit

        {
            m_Enemies[8]->SetVisible(true);
            m_Enemies[8]->SetPosition(10,10);
        }//Enemies

        {
            m_Wall[10*(4-1)+(4-1)]->SetVisible(true);
            m_Wall[10*(5-1)+(4-1)]->SetVisible(true);
            m_Wall[10*(6-1)+(4-1)]->SetVisible(true);
            m_Wall[10*(7-1)+(4-1)]->SetVisible(true);
            m_Wall[10*(4-1)+(7-1)]->SetVisible(true);
            m_Wall[10*(5-1)+(7-1)]->SetVisible(true);
            m_Wall[10*(6-1)+(7-1)]->SetVisible(true);
            m_Wall[10*(7-1)+(7-1)]->SetVisible(true);

            m_Wall[10*(2-1)+(2-1)]->SetVisible(true);
            m_Wall[10*(3-1)+(2-1)]->SetVisible(true);
        }
        m_IceCream->SetPosition(1,1);
        break;
    }
    case Phase::LV08:
        {
            {
                m_Fruit[20+0]->SetVisible(true);
                m_Fruit[20+1]->SetVisible(true);
                m_Fruit[20+2]->SetVisible(true);
                m_Fruit[20+3]->SetVisible(true);
                m_Fruit[20+0]->SetInGame(true);
                m_Fruit[20+1]->SetInGame(true);
                m_Fruit[20+2]->SetInGame(true);
                m_Fruit[20+3]->SetInGame(true);
                m_Fruit[20+0]->SetPosition(2,4);
                m_Fruit[20+1]->SetPosition(2,5);
                m_Fruit[20+2]->SetPosition(2,8);
                m_Fruit[20+3]->SetPosition(2,9);

                m_Fruit[20+4]->SetVisible(true);
                m_Fruit[20+5]->SetVisible(true);
                m_Fruit[20+6]->SetVisible(true);
                m_Fruit[20+7]->SetVisible(true);
                m_Fruit[20+4]->SetInGame(true);
                m_Fruit[20+5]->SetInGame(true);
                m_Fruit[20+6]->SetInGame(true);
                m_Fruit[20+7]->SetInGame(true);
                m_Fruit[20+4]->SetPosition(4,2);
                m_Fruit[20+5]->SetPosition(4,3);
                m_Fruit[20+6]->SetPosition(4,6);
                m_Fruit[20+7]->SetPosition(4,7);

                m_Fruit[20+8]->SetVisible(true);
                m_Fruit[20+9]->SetVisible(true);
                m_Fruit[20+10]->SetVisible(true);
                m_Fruit[20+11]->SetVisible(true);
                m_Fruit[20+8]->SetInGame(true);
                m_Fruit[20+9]->SetInGame(true);
                m_Fruit[20+10]->SetInGame(true);
                m_Fruit[20+11]->SetInGame(true);
                m_Fruit[20+8]->SetPosition(7,4);
                m_Fruit[20+9]->SetPosition(7,5);
                m_Fruit[20+10]->SetPosition(7,8);
                m_Fruit[20+11]->SetPosition(7,9);

                m_Fruit[20+12]->SetVisible(true);
                m_Fruit[20+13]->SetVisible(true);
                m_Fruit[20+14]->SetVisible(true);
                m_Fruit[20+15]->SetVisible(true);
                m_Fruit[20+12]->SetInGame(true);
                m_Fruit[20+13]->SetInGame(true);
                m_Fruit[20+14]->SetInGame(true);
                m_Fruit[20+15]->SetInGame(true);
                m_Fruit[20+12]->SetPosition(9,2);
                m_Fruit[20+13]->SetPosition(9,3);
                m_Fruit[20+14]->SetPosition(9,6);
                m_Fruit[20+15]->SetPosition(9,7);

            }//Fruit
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);
                m_Enemies[11]->SetVisible(true);
                m_Enemies[8]->SetPosition(2,8);
                m_Enemies[9]->SetPosition(2,9);
                m_Enemies[10]->SetPosition(7,8);
                m_Enemies[11]->SetPosition(7,9);
            }//Enemies
            {
                m_AirWall[10*(2-1)+(2-1)]->SetVisible(true);
                m_AirWall[10*(3-1)+(2-1)]->SetVisible(true);
                m_AirWall[10*(6-1)+(2-1)]->SetVisible(true);
                m_AirWall[10*(7-1)+(2-1)]->SetVisible(true);
                m_AirWall[10*(4-1)+(4-1)]->SetVisible(true);
                m_AirWall[10*(5-1)+(4-1)]->SetVisible(true);
                m_AirWall[10*(8-1)+(4-1)]->SetVisible(true);
                m_AirWall[10*(9-1)+(4-1)]->SetVisible(true);
                m_AirWall[10*(2-1)+(7-1)]->SetVisible(true);
                m_AirWall[10*(3-1)+(7-1)]->SetVisible(true);
                m_AirWall[10*(6-1)+(7-1)]->SetVisible(true);
                m_AirWall[10*(7-1)+(7-1)]->SetVisible(true);
                m_AirWall[10*(4-1)+(9-1)]->SetVisible(true);
                m_AirWall[10*(5-1)+(9-1)]->SetVisible(true);
                m_AirWall[10*(8-1)+(9-1)]->SetVisible(true);
                m_AirWall[10*(9-1)+(9-1)]->SetVisible(true);


            }//AirWall
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV09:
        {
            {
                m_Fruit[0]->SetVisible(true);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[1]->SetInGame(true);
                m_Fruit[2]->SetInGame(true);
                m_Fruit[3]->SetInGame(true);
                m_Fruit[0]->SetPosition(4,4);
                m_Fruit[1]->SetPosition(4,7);
                m_Fruit[2]->SetPosition(7,4);
                m_Fruit[3]->SetPosition(7,7);
                m_Fruit[20+20+4+4+0]->SetVisible(false);
                m_Fruit[20+20+4+4+1]->SetVisible(false);
                m_Fruit[20+20+4+4+0]->SetInGame(true);
                m_Fruit[20+20+4+4+1]->SetInGame(true);
                m_Fruit[20+20+4+4+0]->SetPosition(5,6);
                m_Fruit[20+20+4+4+1]->SetPosition(6,5);
            }//Fruit
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[8]->SetPosition(5,5);
                m_Enemies[9]->SetPosition(6,6);
            }//Enemies
            {
                m_Arrow_Down[(4-1)+(4-1)*10]->SetVisible(true);
                m_Arrow_Down[(4-1)+(5-1)*10]->SetVisible(true);
                m_Arrow_Down[(4-1)+(6-1)*10]->SetVisible(true);
                m_Arrow_Right[(4-1)+(7-1)*10]->SetVisible(true);
                m_Arrow_Right[(5-1)+(7-1)*10]->SetVisible(true);
                m_Arrow_Right[(6-1)+(7-1)*10]->SetVisible(true);
                m_Arrow_Up[(7-1)+(7-1)*10]->SetVisible(true);
                m_Arrow_Up[(7-1)+(6-1)*10]->SetVisible(true);
                m_Arrow_Up[(7-1)+(5-1)*10]->SetVisible(true);
                m_Arrow_Left[(7-1)+(4-1)*10]->SetVisible(true);
                m_Arrow_Left[(6-1)+(4-1)*10]->SetVisible(true);
                m_Arrow_Left[(5-1)+(4-1)*10]->SetVisible(true);
            }//Arrow
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV10:
        {
            {
                m_Fruit[0]->SetVisible(true);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[1]->SetInGame(true);
                m_Fruit[2]->SetInGame(true);
                m_Fruit[3]->SetInGame(true);
                m_Fruit[0]->SetPosition(1,1);
                m_Fruit[1]->SetPosition(5,5);
                m_Fruit[2]->SetPosition(7,7);
                m_Fruit[3]->SetPosition(9,9);
            }//fruit
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);

                m_Enemies[8]->SetPosition(9,9);
                m_Enemies[9]->SetPosition(7,7);
                m_Enemies[10]->SetPosition(5,5);
            }//enemies
            {
                for (int a=1; a<6; a++)
                {
                    for (int aa=1; aa<2*a; aa++)
                    {
                        m_Wall[(a*2-1)+(aa)*10]->SetVisible(true);
                        m_Wall[(aa)+(a*2-1)*10]->SetVisible(true);
                    }
                }
                m_Wall[10-1+(1-1)*10]->SetVisible(true);
                m_Wall[1-1+(10-1)*10]->SetVisible(true);
            }//wall
            m_IceCream->SetPosition(3,3);
            break;
        }

    case Phase::LV11:
        {
            {
                m_Fruit[0]->SetVisible(true);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[1]->SetInGame(true);
                m_Fruit[2]->SetInGame(true);
                m_Fruit[3]->SetInGame(true);
                m_Fruit[0]->SetPosition(3,2);
                m_Fruit[1]->SetPosition(3,3);
                m_Fruit[2]->SetPosition(3,4);
                m_Fruit[3]->SetPosition(3,5);

                m_Fruit[4]->SetVisible(true);
                m_Fruit[5]->SetVisible(true);
                m_Fruit[6]->SetVisible(true);
                m_Fruit[7]->SetVisible(true);
                m_Fruit[4]->SetInGame(true);
                m_Fruit[5]->SetInGame(true);
                m_Fruit[6]->SetInGame(true);
                m_Fruit[7]->SetInGame(true);
                m_Fruit[4]->SetPosition(3,6);
                m_Fruit[5]->SetPosition(3,7);
                m_Fruit[6]->SetPosition(3,8);
                m_Fruit[7]->SetPosition(3,9);

                m_Fruit[0+8]->SetVisible(true);
                m_Fruit[1+8]->SetVisible(true);
                m_Fruit[2+8]->SetVisible(true);
                m_Fruit[3+8]->SetVisible(true);
                m_Fruit[0+8]->SetInGame(true);
                m_Fruit[1+8]->SetInGame(true);
                m_Fruit[2+8]->SetInGame(true);
                m_Fruit[3+8]->SetInGame(true);
                m_Fruit[0+8]->SetPosition(5,2);
                m_Fruit[1+8]->SetPosition(5,3);
                m_Fruit[2+8]->SetPosition(5,4);
                m_Fruit[3+8]->SetPosition(5,5);

                m_Fruit[4+8]->SetVisible(true);
                m_Fruit[5+8]->SetVisible(true);
                m_Fruit[6+8]->SetVisible(true);
                m_Fruit[7+8]->SetVisible(true);
                m_Fruit[4+8]->SetInGame(true);
                m_Fruit[5+8]->SetInGame(true);
                m_Fruit[6+8]->SetInGame(true);
                m_Fruit[7+8]->SetInGame(true);
                m_Fruit[4+8]->SetPosition(5,6);
                m_Fruit[5+8]->SetPosition(5,7);
                m_Fruit[6+8]->SetPosition(5,8);
                m_Fruit[7+8]->SetPosition(5,9);

                m_Fruit[0+20]->SetVisible(true);
                m_Fruit[1+20]->SetVisible(true);
                m_Fruit[2+20]->SetVisible(true);
                m_Fruit[3+20]->SetVisible(true);
                m_Fruit[0+20]->SetInGame(true);
                m_Fruit[1+20]->SetInGame(true);
                m_Fruit[2+20]->SetInGame(true);
                m_Fruit[3+20]->SetInGame(true);
                m_Fruit[0+20]->SetPosition(8,2);
                m_Fruit[1+20]->SetPosition(8,3);
                m_Fruit[2+20]->SetPosition(8,4);
                m_Fruit[3+20]->SetPosition(8,5);

                m_Fruit[4+20]->SetVisible(true);
                m_Fruit[5+20]->SetVisible(true);
                m_Fruit[6+20]->SetVisible(true);
                m_Fruit[7+20]->SetVisible(true);
                m_Fruit[4+20]->SetInGame(true);
                m_Fruit[5+20]->SetInGame(true);
                m_Fruit[6+20]->SetInGame(true);
                m_Fruit[7+20]->SetInGame(true);
                m_Fruit[4+20]->SetPosition(8,6);
                m_Fruit[5+20]->SetPosition(8,7);
                m_Fruit[6+20]->SetPosition(8,8);
                m_Fruit[7+20]->SetPosition(8,9);

                m_Fruit[0+8+20]->SetVisible(true);
                m_Fruit[1+8+20]->SetVisible(true);
                m_Fruit[2+8+20]->SetVisible(true);
                m_Fruit[3+8+20]->SetVisible(true);
                m_Fruit[0+8+20]->SetInGame(true);
                m_Fruit[1+8+20]->SetInGame(true);
                m_Fruit[2+8+20]->SetInGame(true);
                m_Fruit[3+8+20]->SetInGame(true);
                m_Fruit[0+8+20]->SetPosition(6,2);
                m_Fruit[1+8+20]->SetPosition(6,3);
                m_Fruit[2+8+20]->SetPosition(6,4);
                m_Fruit[3+8+20]->SetPosition(6,5);

                m_Fruit[4+8+20]->SetVisible(true);
                m_Fruit[5+8+20]->SetVisible(true);
                m_Fruit[6+8+20]->SetVisible(true);
                m_Fruit[7+8+20]->SetVisible(true);
                m_Fruit[4+8+20]->SetInGame(true);
                m_Fruit[5+8+20]->SetInGame(true);
                m_Fruit[6+8+20]->SetInGame(true);
                m_Fruit[7+8+20]->SetInGame(true);
                m_Fruit[4+8+20]->SetPosition(6,6);
                m_Fruit[5+8+20]->SetPosition(6,7);
                m_Fruit[6+8+20]->SetPosition(6,8);
                m_Fruit[7+8+20]->SetPosition(6,9);
            }//Fruit
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);
                m_Enemies[8]->SetPosition(10,6);
                m_Enemies[9]->SetPosition(8,5);
                m_Enemies[10]->SetPosition(6,5);
            }//Enemies
            {
                m_Wall[(2-1)+(2-1)*10]->SetVisible(true);
                m_Wall[(2-1)+(3-1)*10]->SetVisible(true);
                m_AirWall[(2-1)+(4-1)*10]->SetVisible(true);
                m_AirWall[(2-1)+(5-1)*10]->SetVisible(true);
                m_Wall[(2-1)+(6-1)*10]->SetVisible(true);
                m_Wall[(2-1)+(7-1)*10]->SetVisible(true);
                m_AirWall[(2-1)+(8-1)*10]->SetVisible(true);
                m_AirWall[(2-1)+(9-1)*10]->SetVisible(true);

                m_AirWall[(4-1)+(2-1)*10]->SetVisible(true);
                m_AirWall[(4-1)+(3-1)*10]->SetVisible(true);
                m_Wall[(4-1)+(4-1)*10]->SetVisible(true);
                m_Wall[(4-1)+(5-1)*10]->SetVisible(true);
                m_AirWall[(4-1)+(6-1)*10]->SetVisible(true);
                m_AirWall[(4-1)+(7-1)*10]->SetVisible(true);
                m_Wall[(4-1)+(8-1)*10]->SetVisible(true);
                m_Wall[(4-1)+(9-1)*10]->SetVisible(true);

                m_AirWall[(9-1)+(2-1)*10]->SetVisible(true);
                m_AirWall[(9-1)+(3-1)*10]->SetVisible(true);
                m_Wall[(9-1)+(4-1)*10]->SetVisible(true);
                m_Wall[(9-1)+(5-1)*10]->SetVisible(true);
                m_AirWall[(9-1)+(6-1)*10]->SetVisible(true);
                m_AirWall[(9-1)+(7-1)*10]->SetVisible(true);
                m_Wall[(9-1)+(8-1)*10]->SetVisible(true);
                m_Wall[(9-1)+(9-1)*10]->SetVisible(true);

                m_Wall[(7-1)+(2-1)*10]->SetVisible(true);
                m_Wall[(7-1)+(3-1)*10]->SetVisible(true);
                m_AirWall[(7-1)+(4-1)*10]->SetVisible(true);
                m_AirWall[(7-1)+(5-1)*10]->SetVisible(true);
                m_Wall[(7-1)+(6-1)*10]->SetVisible(true);
                m_Wall[(7-1)+(7-1)*10]->SetVisible(true);
                m_AirWall[(7-1)+(8-1)*10]->SetVisible(true);
                m_AirWall[(7-1)+(9-1)*10]->SetVisible(true);
            }//Wall AirWall
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV12:
        {
            {
                m_Fruit[0]->SetVisible(true);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[1]->SetInGame(true);
                m_Fruit[2]->SetInGame(true);
                m_Fruit[3]->SetInGame(true);
                m_Fruit[0]->SetPosition(5,5);
                m_Fruit[1]->SetPosition(6,5);
                m_Fruit[2]->SetPosition(6,6);
                m_Fruit[3]->SetPosition(5,6);
            }//Fruit
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);
                m_Enemies[8]->SetPosition(10,6);
                m_Enemies[9]->SetPosition(8,5);
                m_Enemies[10]->SetPosition(6,5);
            }
            {
                m_CampFire[0]->SetVisible(true);
                m_CampFire[1]->SetVisible(true);
                m_CampFire[2]->SetVisible(true);
                m_CampFire[3]->SetVisible(true);
                m_CampFire[0]->SetPosition(4,5);
                m_CampFire[1]->SetPosition(4,6);
                m_CampFire[2]->SetPosition(7,5);
                m_CampFire[3]->SetPosition(7,6);

                m_CampFire[4+0]->SetVisible(true);
                m_CampFire[4+1]->SetVisible(true);
                m_CampFire[4+2]->SetVisible(true);
                m_CampFire[4+3]->SetVisible(true);
                m_CampFire[4+0]->SetPosition(5,4);
                m_CampFire[4+1]->SetPosition(5,7);
                m_CampFire[4+2]->SetPosition(6,4);
                m_CampFire[4+3]->SetPosition(6,7);
            }
            {
                m_Wall[(4-1)+(4-1)*10]->SetVisible(true);
                m_Wall[(4-1)+(7-1)*10]->SetVisible(true);
                m_Wall[(7-1)+(4-1)*10]->SetVisible(true);
                m_Wall[(7-1)+(7-1)*10]->SetVisible(true);
            }
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV13:
        {
            {
                m_Fruit[20+20+4+4+0]->SetVisible(true);
                m_Fruit[20+20+4+4+1]->SetVisible(true);
                m_Fruit[20+20+4+4+2]->SetVisible(true);
                m_Fruit[20+20+4+4+3]->SetVisible(true);
                m_Fruit[20+20+4+4+0]->SetInGame(true);
                m_Fruit[20+20+4+4+1]->SetInGame(true);
                m_Fruit[20+20+4+4+2]->SetInGame(true);
                m_Fruit[20+20+4+4+3]->SetInGame(true);
                m_Fruit[20+20+4+4+0]->SetPosition(5,5);
                m_Fruit[20+20+4+4+1]->SetPosition(5,6);
                m_Fruit[20+20+4+4+2]->SetPosition(6,5);
                m_Fruit[20+20+4+4+3]->SetPosition(6,6);
            }
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);
                m_Enemies[11]->SetVisible(true);
                m_Enemies[8]->SetPosition(10,10);
                m_Enemies[9]->SetPosition(9,9);
                m_Enemies[10]->SetPosition(8,8);
                m_Enemies[11]->SetPosition(7,7);
            }
            {
                for (int a=0;a<100;a++)
                {
                    m_IceBlock[a]->SetVisible(true);
                }
            }
            m_IceCream->SetPosition(1,1);
            Map[m_IceCream->GetI()][m_IceCream->GetJ()]='!';
            break;
        }
    case Phase::LV14:
        {
            for (int a=0;a<100;a++)
            {
                m_FireBlock[a]->SetVisible(true);
            }
            {
                m_Fruit[20+20+4+4+0]->SetVisible(true);
                m_Fruit[20+20+4+4+1]->SetVisible(true);
                m_Fruit[20+20+4+4+2]->SetVisible(true);
                m_Fruit[20+20+4+4+3]->SetVisible(true);
                m_Fruit[20+20+4+4+0]->SetInGame(true);
                m_Fruit[20+20+4+4+1]->SetInGame(true);
                m_Fruit[20+20+4+4+2]->SetInGame(true);
                m_Fruit[20+20+4+4+3]->SetInGame(true);
                m_Fruit[20+20+4+4+0]->SetPosition(5,5);
                m_Fruit[20+20+4+4+1]->SetPosition(5,6);
                m_Fruit[20+20+4+4+2]->SetPosition(6,5);
                m_Fruit[20+20+4+4+3]->SetPosition(6,6);
            }
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);
                m_Enemies[11]->SetVisible(true);
                m_Enemies[8]->SetPosition(10,10);
                m_Enemies[9]->SetPosition(9,9);
                m_Enemies[10]->SetPosition(8,8);
                m_Enemies[11]->SetPosition(7,7);
            }
            m_IceCream->SetPosition(1,1);
            Map[m_IceCream->GetI()][m_IceCream->GetJ()]='!';
            break;
        }
    case Phase::LV15:
        {
            {
                for (int a=0;a<50;a++)
                {
                    m_IceBlock[2*a+1]->SetVisible(true);
                    m_FireBlock[2*a]->SetVisible(true);
                }
            }
            {
                m_Fruit[20+20+4+4+0]->SetVisible(true);
                m_Fruit[20+20+4+4+1]->SetVisible(true);
                m_Fruit[20+20+4+4+2]->SetVisible(true);
                m_Fruit[20+20+4+4+3]->SetVisible(true);
                m_Fruit[20+20+4+4+0]->SetInGame(true);
                m_Fruit[20+20+4+4+1]->SetInGame(true);
                m_Fruit[20+20+4+4+2]->SetInGame(true);
                m_Fruit[20+20+4+4+3]->SetInGame(true);
                m_Fruit[20+20+4+4+0]->SetPosition(5,5);
                m_Fruit[20+20+4+4+1]->SetPosition(5,6);
                m_Fruit[20+20+4+4+2]->SetPosition(6,5);
                m_Fruit[20+20+4+4+3]->SetPosition(6,6);
            }
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[10]->SetVisible(true);
                m_Enemies[11]->SetVisible(true);
                m_Enemies[8]->SetPosition(10,10);
                m_Enemies[9]->SetPosition(9,9);
                m_Enemies[10]->SetPosition(8,8);
                m_Enemies[11]->SetPosition(7,7);
            }
            m_IceCream->SetPosition(1,1);
            Map[m_IceCream->GetI()][m_IceCream->GetJ()]='!';
            break;

        }

    case Phase::LV16:
        {
            {
                for (int a=2;a<10;a++)
                {
                    m_Wall[2-1+(a-1)*10]->SetVisible(true);
                    m_Wall[4-1+(a-1)*10]->SetVisible(true);
                    m_Wall[6-1+(a-1)*10]->SetVisible(true);
                    m_Wall[8-1+(a-1)*10]->SetVisible(true);
                    m_Wall[10-1+(a-1)*10]->SetVisible(true);
                }

            }
            {
                for (int a=2;a<10;a++)
                {
                    m_FireBlock[3-1+(a-1)*10]->SetVisible(true);
                    m_FireBlock[5-1+(a-1)*10]->SetVisible(true);
                    m_FireBlock[7-1+(a-1)*10]->SetVisible(true);
                    m_FireBlock[9-1+(a-1)*10]->SetVisible(true);
                }
            }
            {
                m_CampFire[0]->SetVisible(true);
                m_CampFire[1]->SetVisible(true);
                m_CampFire[2]->SetVisible(true);
                m_CampFire[3]->SetVisible(true);
                m_CampFire[4]->SetVisible(true);
                m_CampFire[5]->SetVisible(true);
                m_CampFire[6]->SetVisible(true);
                m_CampFire[7]->SetVisible(true);

                m_CampFire[0]->SetPosition(9,10);
                m_CampFire[1]->SetPosition(7,10);
                m_CampFire[2]->SetPosition(5,10);
                m_CampFire[3]->SetPosition(3,10);
                m_CampFire[4]->SetPosition(3,1);
                m_CampFire[5]->SetPosition(5,1);
                m_CampFire[6]->SetPosition(7,1);
                m_CampFire[7]->SetPosition(9,1);
            }
            {
                m_Fruit[0]->SetVisible(true);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[4]->SetVisible(true);
                m_Fruit[5]->SetVisible(true);
                m_Fruit[6]->SetVisible(true);
                m_Fruit[7]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[1]->SetInGame(true);
                m_Fruit[2]->SetInGame(true);
                m_Fruit[3]->SetInGame(true);
                m_Fruit[4]->SetInGame(true);
                m_Fruit[5]->SetInGame(true);
                m_Fruit[6]->SetInGame(true);
                m_Fruit[7]->SetInGame(true);
                m_Fruit[0]->SetPosition(3,2);
                m_Fruit[1]->SetPosition(3,3);
                m_Fruit[2]->SetPosition(3,4);
                m_Fruit[3]->SetPosition(3,5);
                m_Fruit[4]->SetPosition(3,6);
                m_Fruit[5]->SetPosition(3,7);
                m_Fruit[6]->SetPosition(3,8);
                m_Fruit[7]->SetPosition(3,9);

                m_Fruit[8+0]->SetVisible(true);
                m_Fruit[8+1]->SetVisible(true);
                m_Fruit[8+2]->SetVisible(true);
                m_Fruit[8+3]->SetVisible(true);
                m_Fruit[8+4]->SetVisible(true);
                m_Fruit[8+5]->SetVisible(true);
                m_Fruit[8+6]->SetVisible(true);
                m_Fruit[8+7]->SetVisible(true);
                m_Fruit[8+0]->SetInGame(true);
                m_Fruit[8+1]->SetInGame(true);
                m_Fruit[8+2]->SetInGame(true);
                m_Fruit[8+3]->SetInGame(true);
                m_Fruit[8+4]->SetInGame(true);
                m_Fruit[8+5]->SetInGame(true);
                m_Fruit[8+6]->SetInGame(true);
                m_Fruit[8+7]->SetInGame(true);
                m_Fruit[8+0]->SetPosition(5,2);
                m_Fruit[8+1]->SetPosition(5,3);
                m_Fruit[8+2]->SetPosition(5,4);
                m_Fruit[8+3]->SetPosition(5,5);
                m_Fruit[8+4]->SetPosition(5,6);
                m_Fruit[8+5]->SetPosition(5,7);
                m_Fruit[8+6]->SetPosition(5,8);
                m_Fruit[8+7]->SetPosition(5,9);

                m_Fruit[20+0]->SetVisible(true);
                m_Fruit[20+1]->SetVisible(true);
                m_Fruit[20+2]->SetVisible(true);
                m_Fruit[20+3]->SetVisible(true);
                m_Fruit[20+4]->SetVisible(true);
                m_Fruit[20+5]->SetVisible(true);
                m_Fruit[20+6]->SetVisible(true);
                m_Fruit[20+7]->SetVisible(true);
                m_Fruit[20+0]->SetInGame(true);
                m_Fruit[20+1]->SetInGame(true);
                m_Fruit[20+2]->SetInGame(true);
                m_Fruit[20+3]->SetInGame(true);
                m_Fruit[20+4]->SetInGame(true);
                m_Fruit[20+5]->SetInGame(true);
                m_Fruit[20+6]->SetInGame(true);
                m_Fruit[20+7]->SetInGame(true);
                m_Fruit[20+0]->SetPosition(7,2);
                m_Fruit[20+1]->SetPosition(7,3);
                m_Fruit[20+2]->SetPosition(7,4);
                m_Fruit[20+3]->SetPosition(7,5);
                m_Fruit[20+4]->SetPosition(7,6);
                m_Fruit[20+5]->SetPosition(7,7);
                m_Fruit[20+6]->SetPosition(7,8);
                m_Fruit[20+7]->SetPosition(7,9);

                m_Fruit[20+8+0]->SetVisible(true);
                m_Fruit[20+8+1]->SetVisible(true);
                m_Fruit[20+8+2]->SetVisible(true);
                m_Fruit[20+8+3]->SetVisible(true);
                m_Fruit[20+8+4]->SetVisible(true);
                m_Fruit[20+8+5]->SetVisible(true);
                m_Fruit[20+8+6]->SetVisible(true);
                m_Fruit[20+8+7]->SetVisible(true);
                m_Fruit[20+8+0]->SetInGame(true);
                m_Fruit[20+8+1]->SetInGame(true);
                m_Fruit[20+8+2]->SetInGame(true);
                m_Fruit[20+8+3]->SetInGame(true);
                m_Fruit[20+8+4]->SetInGame(true);
                m_Fruit[20+8+5]->SetInGame(true);
                m_Fruit[20+8+6]->SetInGame(true);
                m_Fruit[20+8+7]->SetInGame(true);
                m_Fruit[20+8+0]->SetPosition(9,2);
                m_Fruit[20+8+1]->SetPosition(9,3);
                m_Fruit[20+8+2]->SetPosition(9,4);
                m_Fruit[20+8+3]->SetPosition(9,5);
                m_Fruit[20+8+4]->SetPosition(9,6);
                m_Fruit[20+8+5]->SetPosition(9,7);
                m_Fruit[20+8+6]->SetPosition(9,8);
                m_Fruit[20+8+7]->SetPosition(9,9);
            }
            {
                m_Enemies[8+0]->SetVisible(true);
                m_Enemies[8+1]->SetVisible(true);
                m_Enemies[8+2]->SetVisible(true);
                m_Enemies[8+3]->SetVisible(true);

                m_Enemies[8+0]->SetPosition(9,5);
                m_Enemies[8+1]->SetPosition(7,6);
                m_Enemies[8+2]->SetPosition(5,6);
                m_Enemies[8+3]->SetPosition(3,6);
            }
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV17:
        {
            {
                for (int a=0;a<100;a++)
                {
                    m_Ice[a]->SetVisible(true);
                }
                m_Ice[0]->SetVisible(false);
                m_Ice[9]->SetVisible(false);
                m_Ice[90]->SetVisible(false);
                m_Ice[99]->SetVisible(false);
                m_Ice[5-1+(5-1)*10]->SetVisible(false);
            }
            {
                m_Enemies[0+16+4]->SetVisible(true);
                m_Enemies[1+16+4]->SetVisible(true);
                m_Enemies[2+16+4]->SetVisible(true);
                m_Enemies[3+16+4]->SetVisible(true);
                m_Enemies[0+16+4]->SetPosition(1,1);
                m_Enemies[1+16+4]->SetPosition(1,10);
                m_Enemies[2+16+4]->SetPosition(10,10);
                m_Enemies[3+16+4]->SetPosition(10,1);
            }
            {
                for (int a=0;a<10;a++)
                {
                    m_Fruit[0*10+a]->SetVisible(true);
                    m_Fruit[1*10+a]->SetVisible(true);
                    m_Fruit[2*10+a]->SetVisible(true);
                    m_Fruit[3*10+a]->SetVisible(true);
                    m_Fruit[0*10+a]->SetInGame(true);
                    m_Fruit[1*10+a]->SetInGame(true);
                    m_Fruit[2*10+a]->SetInGame(true);
                    m_Fruit[3*10+a]->SetInGame(true);
                    m_Fruit[0*10+a]->SetPosition(1,a+1);
                    m_Fruit[1*10+a]->SetPosition(3,a+1);
                    m_Fruit[2*10+a]->SetPosition(8,a+1);
                    m_Fruit[3*10+a]->SetPosition(10,a+1);
                }

            }
            m_IceCream->SetPosition(5,5);
            break;
        }//one
    case Phase::LV18:
        {
            {
                for (int a=0;a<100;a++)
                {
                    m_Ice[a]->SetVisible(true);
                }
                m_Ice[5-1+(2-1)*10]->SetVisible(false);
                m_Ice[6-1+(8-1)*10]->SetVisible(false);
                m_Ice[2-1+(6-1)*10]->SetVisible(false);
                m_Ice[8-1+(5-1)*10]->SetVisible(false);
                m_Ice[5-1+(5-1)*10]->SetVisible(false);
            }
            {
                m_Enemies[0+16+ 4+4]->SetVisible(true);
                m_Enemies[1+16+ 4+4]->SetVisible(true);
                m_Enemies[2+16+ 4+4]->SetVisible(true);
                m_Enemies[3+16+ 4+4]->SetVisible(true);
                m_Enemies[0+16+ 4+4]->SetPosition(5,2);
                m_Enemies[1+16+ 4+4]->SetPosition(6,8);
                m_Enemies[2+16+ 4+4]->SetPosition(2,6);
                m_Enemies[3+16+ 4+4]->SetPosition(8,5);
            }
            {
                for (int a=0;a<10;a++)
                {
                    m_Fruit[0*10+a]->SetVisible(true);
                    m_Fruit[1*10+a]->SetVisible(true);
                    m_Fruit[2*10+a]->SetVisible(true);
                    m_Fruit[3*10+a]->SetVisible(true);
                    m_Fruit[0*10+a]->SetInGame(true);
                    m_Fruit[1*10+a]->SetInGame(true);
                    m_Fruit[2*10+a]->SetInGame(true);
                    m_Fruit[3*10+a]->SetInGame(true);
                    m_Fruit[0*10+a]->SetPosition(a+1,1);
                    m_Fruit[1*10+a]->SetPosition(a+1,3);
                    m_Fruit[2*10+a]->SetPosition(a+1,8);
                    m_Fruit[3*10+a]->SetPosition(a+1,10);
                }

            }
            m_IceCream->SetPosition(5,5);
            break;
        }//three
    case Phase::LV19:
        {
            {
                for (int a=0;a<100;a++)
                {
                    m_Ice[a]->SetVisible(true);
                }
                m_Ice[9-1+(2-1)*10]->SetVisible(false);
                m_Ice[9-1+(9-1)*10]->SetVisible(false);
                m_Ice[2-1+(9-1)*10]->SetVisible(false);
                m_Ice[2-1+(2-1)*10]->SetVisible(false);
                m_Ice[5-1+(5-1)*10]->SetVisible(false);
            }
            {
                m_Enemies[0+16+ 4+4+4]->SetVisible(true);
                m_Enemies[1+16+ 4+4+4]->SetVisible(true);
                m_Enemies[2+16+ 4+4+4]->SetVisible(true);
                m_Enemies[3+16+ 4+4+4]->SetVisible(true);
                m_Enemies[0+16+ 4+4+4]->SetPosition(9,2);
                m_Enemies[1+16+ 4+4+4]->SetPosition(9,9);
                m_Enemies[2+16+ 4+4+4]->SetPosition(2,9);
                m_Enemies[3+16+ 4+4+4]->SetPosition(2,2);
            }
            {
                for (int a=0;a<9;a++)
                {
                    m_Fruit[0*10+a]->SetVisible(true);
                    m_Fruit[1*10+a]->SetVisible(true);
                    m_Fruit[2*10+a]->SetVisible(true);
                    m_Fruit[3*10+a]->SetVisible(true);
                    m_Fruit[0*10+a]->SetInGame(true);
                    m_Fruit[1*10+a]->SetInGame(true);
                    m_Fruit[2*10+a]->SetInGame(true);
                    m_Fruit[3*10+a]->SetInGame(true);
                    m_Fruit[0*10+a]->SetPosition(1+a%3,1+a/3);
                    m_Fruit[1*10+a]->SetPosition(1+a%3,8+a/3);
                    m_Fruit[2*10+a]->SetPosition(8+a%3,1+a/3);
                    m_Fruit[3*10+a]->SetPosition(8+a%3,8+a/3);
                }

            }
            m_IceCream->SetPosition(5,5);
            break;
        }//around
    case Phase::LV20:
        {
            {
                for (int a=0;a<100;a++)
                {
                    m_Ice[a]->SetVisible(true);
                }
                m_Ice[8-1+(2-1)*10]->SetVisible(false);
                m_Ice[9-1+(8-1)*10]->SetVisible(false);
                m_Ice[3-1+(9-1)*10]->SetVisible(false);
                m_Ice[2-1+(3-1)*10]->SetVisible(false);
                m_Ice[5-1+(5-1)*10]->SetVisible(false);
            }
            {
                m_Enemies[0+16+ 4+4+4+4]->SetVisible(true);
                m_Enemies[1+16+ 4+4+4+4]->SetVisible(true);
                m_Enemies[2+16+ 4+4+4+4]->SetVisible(true);
                m_Enemies[3+16+ 4+4+4+4]->SetVisible(true);
                m_Enemies[0+16+ 4+4+4+4]->SetPosition(8,2);
                m_Enemies[1+16+ 4+4+4+4]->SetPosition(9,8);
                m_Enemies[2+16+ 4+4+4+4]->SetPosition(3,9);
                m_Enemies[3+16+ 4+4+4+4]->SetPosition(2,3);
            }
            {
                for (int a=0;a<10;a++)
                {
                    m_Fruit[0*10+a]->SetVisible(true);
                    m_Fruit[1*10+a]->SetVisible(true);
                    m_Fruit[2*10+a]->SetVisible(true);
                    m_Fruit[3*10+a]->SetVisible(true);
                    m_Fruit[0*10+a]->SetInGame(true);
                    m_Fruit[1*10+a]->SetInGame(true);
                    m_Fruit[2*10+a]->SetInGame(true);
                    m_Fruit[3*10+a]->SetInGame(true);
                    m_Fruit[0*10+a]->SetPosition(3,a+1);
                    m_Fruit[1*10+a]->SetPosition(8,a+1);
                    m_Fruit[2*10+a]->SetPosition(a+1,3);
                    m_Fruit[3*10+a]->SetPosition(a+1,8);
                }
                m_Fruit[0*10+3-1]->SetInGame(false);m_Fruit[2*10+3-1]->SetInGame(false);//3,3
                m_Fruit[0*10+8-1]->SetInGame(false);m_Fruit[3*10+3-1]->SetInGame(false);//3,8
                m_Fruit[1*10+3-1]->SetInGame(false);m_Fruit[2*10+8-1]->SetInGame(false);//8,3
                m_Fruit[1*10+8-1]->SetInGame(false);m_Fruit[3*10+8-1]->SetInGame(false);//8,8
            }
            m_IceCream->SetPosition(5,5);
            break;
        }//column and row

    case Phase::LV21:
        {
            {
                for (int a=0;a<100;a++)
                {
                    m_Ice[a]->SetVisible(true);
                }
                m_Ice[4-1+(4-1)*10]->SetVisible(false);
                m_Ice[4-1+(7-1)*10]->SetVisible(false);
                m_Ice[7-1+(4-1)*10]->SetVisible(false);
                m_Ice[7-1+(7-1)*10]->SetVisible(false);
                m_Ice[1-1+(1-1)*10]->SetVisible(false);
            }
            {
                m_Enemies[0+16]->SetVisible(true);
                m_Enemies[1+16]->SetVisible(true);
                m_Enemies[2+16]->SetVisible(true);
                m_Enemies[3+16]->SetVisible(true);
                m_Enemies[0+16]->SetPosition(4,4);
                m_Enemies[1+16]->SetPosition(4,7);
                m_Enemies[2+16]->SetPosition(7,4);
                m_Enemies[3+16]->SetPosition(7,7);
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[0*10+a]->SetVisible(false);
                    m_Fruit[1*10+a]->SetVisible(false);
                    m_Fruit[2*10+a]->SetVisible(true);
                    m_Fruit[3*10+a]->SetVisible(true);
                    m_Fruit[0*10+a]->SetInGame(true);
                    m_Fruit[1*10+a]->SetInGame(true);
                    m_Fruit[2*10+a]->SetInGame(true);
                    m_Fruit[3*10+a]->SetInGame(true);
                    m_Fruit[0*10+a]->SetPosition(1+a/2,1+a%2);
                    m_Fruit[1*10+a]->SetPosition(9+a/2,9+a%2);
                    m_Fruit[2*10+a]->SetPosition(9+a/2,1+a%2);
                    m_Fruit[3*10+a]->SetPosition(1+a/2,9+a%2);
                }
            }
            m_IceCream->SetPosition(1,1);
            break;
        }//Cross
    case Phase::LV22:
        {
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[20+a]->SetVisible(false);
                    m_Fruit[20+a]->SetInGame(true);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetPosition(1+a/2,1+a%2);
                    m_Fruit[4+a]->SetPosition(8+a/2,1+a%2);
                    m_Fruit[8+a]->SetPosition(1+a/2,8+a%2);
                    m_Fruit[12+a]->SetPosition(8+a/2,8+a%2);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a+20]->SetPosition(3+a/2,3+a%2);
                    m_Fruit[4+a+20]->SetPosition(6+a/2,3+a%2);
                    m_Fruit[8+a+20]->SetPosition(3+a/2,6+a%2);
                    m_Fruit[12+a+20]->SetPosition(6+a/2,6+a%2);
                }
            }//fruit
            {
                m_Enemies[0+16+4]->SetVisible(true);
                m_Enemies[1+16+4]->SetVisible(true);
                m_Enemies[2+16+4]->SetVisible(true);
                m_Enemies[3+16+4]->SetVisible(true);
                m_Enemies[0+16+4]->SetPosition(1,1);
                m_Enemies[1+16+4]->SetPosition(1,9);
                m_Enemies[2+16+4]->SetPosition(9,9);
                m_Enemies[3+16+4]->SetPosition(9,1);
            }//enemies
            {
                for (int a=0;a<10;a++)
                {
                    m_Wall[a+90]->SetVisible(true);
                    m_Wall[a*10+9]->SetVisible(true);
                }
                for (int a=0;a<2;a++)
                {
                    m_Wall[5-1+a*10]->SetVisible(true);
                    m_Wall[5-1+(9-1-a)*10]->SetVisible(true);
                    m_Wall[a+(5-1)*10]->SetVisible(true);
                    m_Wall[(9-1-a)+(5-1)*10]->SetVisible(true);
                }
            }//wall
            {
                for (int a=0;a<25;a++)
                {
                    m_Ice[(a%5)+(3-1)+((a/5+(3-1))*10)]->SetVisible(true);
                }
            }//Ice
            m_IceCream->SetPosition(5,5);
            break;
        }
    case Phase::LV23:
        {
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[20+a]->SetVisible(false);
                    m_Fruit[20+a]->SetInGame(true);
                }
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetPosition(1+a%4+((a%4)/2)*6,1+a/4+((a/4)/2)*6);
                    m_Fruit[20+a]->SetPosition(4+a/4,4+a%4);
                }
            }//fruit
            {
                for (int a=8;a<12;a++)
                {
                    m_Enemies[a]->SetVisible(true);
                }
                m_Enemies[8]->SetPosition(4,4);
                m_Enemies[9]->SetPosition(4,7);
                m_Enemies[10]->SetPosition(7,7);
                m_Enemies[11]->SetPosition(7,4);
            }//enemies
            {
                for (int a=0;a<3;a++)
                {
                    m_Wall[(3-1+a/2)+(3-1+a%2)*10 ]->SetVisible(true);
                    m_Wall[(3-1+a/2)+(8-1-a%2)*10 ]->SetVisible(true);
                    m_Wall[(8-1-a/2)+(8-1-a%2)*10 ]->SetVisible(true);
                    m_Wall[(8-1-a/2)+(3-1+a%2)*10 ]->SetVisible(true);
                }
            }//wall
            {
                for (int a=0;a<0;a++)
                {
                    m_Ice[(a%5)+(3-1)+((a/5+(3-1))*10)]->SetVisible(true);
                }
            }//Ice
            m_IceCream->SetPosition(5,5);
            break;
        }
    case Phase::LV24:
        {
            {
                m_Fruit[0]->SetVisible(true);
                m_Fruit[0]->SetInGame(true);
                m_Fruit[0]->SetPosition(10,10);
            }
            {
                m_CampFire[0]->SetVisible(true);
                m_CampFire[0]->SetPosition(1,10);
            }
            {
                m_Enemies[24]->SetVisible(true);
                m_Enemies[24]->SetPosition(10,10);
            }
            {
                m_Ice[10-1+(9-1)*10]->SetVisible(true);
                m_Ice[9-1+(10-1)*10]->SetVisible(true);
                m_Ice[9-1+(9-1)*10]->SetVisible(true);
            }
            {
                m_IceBlock[2]->SetVisible(true);
                m_FireBlock[3]->SetVisible(true);
            }
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV25:
        {
            m_FruitPicture[0]->SetVisible(true);
            m_FruitPicture[0]->SetPosition(1);
            m_FruitPicture[1]->SetVisible(true);
            m_FruitPicture[1]->SetPosition(2);
            m_FruitPicture[2]->SetVisible(true);
            m_FruitPicture[2]->SetPosition(3);
            m_FruitPicture[3]->SetVisible(true);
            m_FruitPicture[3]->SetPosition(4);
            m_FruitPicture[4]->SetVisible(true);
            m_FruitPicture[4]->SetPosition(5);
            m_FruitPicture[5]->SetVisible(true);
            m_FruitPicture[5]->SetPosition(6);
            m_FruitPicture[6]->SetVisible(true);
            m_FruitPicture[6]->SetPosition(7);
            m_IceCream->SetVisible(true);
            break;
        }
    default:
        break;
    }
    MapStart();
}
}
