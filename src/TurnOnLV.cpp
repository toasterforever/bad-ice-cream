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
    LV_Change = true;
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
if (!LV_Change&&IsGaming())
{
    LVReset();
    switch (m_Phase)//Fruit=20+20+4+4+4 //enemy 4+4 +8 +4+4+4+4+4 +4 //cross 1 3 around row
    {
    case Phase::LV01:{
        {
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                }
                m_Fruit[0]->SetPosition(3, 1);
                m_Fruit[1]->SetPosition(4, 1);
                m_Fruit[2]->SetPosition(7, 1);
                m_Fruit[3]->SetPosition(8, 1);

                m_Fruit[4]->SetPosition(1, 3);
                m_Fruit[5]->SetPosition(1, 4);
                m_Fruit[6]->SetPosition(1, 7);
                m_Fruit[7]->SetPosition(1, 8);

                m_Fruit[8]->SetPosition(10, 3);
                m_Fruit[9]->SetPosition(10, 4);
                m_Fruit[10]->SetPosition(10, 7);
                m_Fruit[11]->SetPosition(10, 8);

                m_Fruit[12]->SetPosition(3, 10);
                m_Fruit[13]->SetPosition(4, 10);
                m_Fruit[14]->SetPosition(7, 10);
                m_Fruit[15]->SetPosition(8, 10);
            }//Fruit

            for (int a = 0; a < 4; a++)
            {
                m_Enemies[a]->SetVisible(true);
                m_Enemies[a]->SetPosition(5+a%2,5+a/2);
            }
            m_IceCream->SetPosition(1,1);
        }
        break;}
    case Phase::LV02:{
        {
            {
                for (int a=0;a<8;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(2+(a%2==0?0:7)+(a/4==1?1:0)*(a%2==0?1:-1), 2+(a%4<2?0:7)+(a/4==1?1:0)*(a%4<2?1:-1));
                }
            }//Fruit

            {
                for (int a=2;a<6;a++)
                {
                    m_Enemies[a]->SetVisible(true);
                }
                m_Enemies[3]->SetPosition(1,7);
                m_Enemies[4]->SetPosition(10,4);

                m_Enemies[5]->SetPosition(7,1);
                m_Enemies[6]->SetPosition(4,10);
            }//Enemy
            m_IceCream->SetPosition(5,5);
        }
        break;}
    case Phase::LV03:{
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Ice[10*3+3+a]->SetVisible(true);
                    m_Ice[10*(3+a)+3]->SetVisible(true);
                    m_Ice[10*(3+a)+6]->SetVisible(true);
                    m_Ice[10*6+3+a]->SetVisible(true);
                }
                for (int a=0;a<8;a++)
                {
                    m_Ice[1+10*1+(a<4?1:0)*(a%2==0?-1:1)+(a/4==0?0:1)*(a%4<2?1:-1)*10+(a%2?0:7)+(a%4-1>0?70:0)]->SetVisible(true);
                }
            }//Ice

            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(1+a%2*9,1+a/2*9);
                }
            }

            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(1+a%2*9,1+a/2*9);
                }
            }
            m_IceCream->SetPosition(5,5);
        }
        break;
    }
    case Phase::LV04:{
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(1+a%2*9,1+a/2*9);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(1+a%2*9,1+a/2*9);
                }
                for (int a=0;a<8;a++)
                {
                    m_Fruit[20+a]->SetVisible(false);
                    m_Fruit[20+a]->SetInGame(true);
                    m_Fruit[20+a]->SetPosition(5+a/4,4+a%4);
                }
            }
            m_IceCream->SetPosition(5,5);
        }
        break;
    }
    case Phase::LV05:{
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(5+a%2,5+a/2);
                }
                for (int a=0;a<8;a++)
                {
                    m_Fruit[20+a]->SetVisible(false);
                    m_Fruit[20+a]->SetInGame(true);
                    m_Fruit[20+a]->SetPosition(1+a/4*9,1+a%4+(a%4>1?6:0));
                }
            }

            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Fruit[8+a]->SetInGame(true);
                    m_Fruit[8+a]->SetPosition(5+a%2,5+a/2);
                    m_Enemies[8+4+a]->SetVisible(true);
                    m_Fruit[8+4+a]->SetInGame(true);
                    m_Fruit[8+4+a]->SetPosition(8+a%2,8+a/2);
                }
            }
            m_IceCream->SetPosition(1,1);
        }
        break;
    }

    case Phase::LV06:
        {
            {
                for (int a=0;a<12;a++)
                {
                    m_Fruit[40+a]->SetVisible(true);
                    m_Fruit[40+a]->SetInGame(true);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[40+a]->SetPosition(5+a%2,5+a/2);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[40+4+a]->SetPosition(3+a%2*5,3+a/2*5);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[40+8+a]->SetPosition(4+a%2*3,4+a/2*3);
                }
            }//Fruit

        {
            m_Enemies[8]->SetVisible(true);
            m_Enemies[8]->SetPosition(10,10);
        }//Enemies

        m_IceCream->SetPosition(1,1);
        break;
        }
    case Phase::LV07:
    {
        {
            for (int a=0;a<8;a++)
            {
                m_Fruit[20+a]->SetVisible(true);
                m_Fruit[20+a]->SetInGame(true);
                m_Fruit[20+a]->SetPosition(5+a/4,4+a%4);
            }
        }//Fruit

        {
            m_Enemies[8]->SetVisible(true);
            m_Enemies[8]->SetPosition(10,10);
        }//Enemies

        {
            for (int a=0;a<8;a++)
            {
                m_Wall[(4-1+a/4*3)+10*(4-1+a%4)]->SetVisible(true);
            }
            m_Wall[10*(2-1)+(2-1)]->SetVisible(true);
            m_Wall[10*(3-1)+(2-1)]->SetVisible(true);
        }
        m_IceCream->SetPosition(1,1);
        break;
    }
    case Phase::LV08:
        {
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[20+a]->SetVisible(true);
                    m_Fruit[20+a]->SetInGame(true);
                }
                for (int a=0;a<8;a++)
                {
                    m_Fruit[20+a]->SetPosition(2+a/4*5,4+a%4+(a%4>1?2:0));
                    m_Fruit[20+8+a]->SetPosition(4+a/4*5,2+a%4+(a%4>1?2:0));
                }

            }//Fruit
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(2+a%2*5,8+a/2);
                }
            }//Enemies
            {
                for (int a=0;a<8;a++)
                {
                    m_AirWall[4+a/4*5-1+(4+a%4+(a%4>1?2:0)-1)*10]->SetVisible(true);
                    m_AirWall[(2+a%4+(a%4>1?2:0)-1)*10+2+a/4*5-1]->SetVisible(true);
                }
            }//AirWall
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV09:
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(4+a%2*3,4+a/2*3);
                }
                for (int a=0;a<2;a++)
                {
                    m_Fruit[20+20+4+4+a]->SetVisible(false);
                    m_Fruit[20+20+4+4+a]->SetInGame(true);
                    m_Fruit[20+20+4+4+a]->SetPosition(5+a,6-a);
                }
            }//Fruit
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[9]->SetVisible(true);
                m_Enemies[8]->SetPosition(5,5);
                m_Enemies[9]->SetPosition(6,6);
            }//Enemies
            {
                for (int a=0;a<3;a++)
                {
                    m_Arrow_Down[(4-1)+(4-1+a)*10]->SetVisible(true);
                    m_Arrow_Right[(4-1+a)+(7-1)*10]->SetVisible(true);
                    m_Arrow_Up[(7-1)+(7-1-a)*10]->SetVisible(true);
                    m_Arrow_Left[(7-1-a)+(4-1)*10]->SetVisible(true);
                }
            }//Arrow
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV10:
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(3+a*2+(a==0?-2:0),3+a*2+(a==0?-2:0));
                }
            }//fruit
            {
                for (int a=0;a<3;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(5+a*2,5+a*2);
                }
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
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(3+a/8*2,2+a%8);
                }

                for (int a=0;a<16;a++)
                {
                    m_Fruit[20+a]->SetVisible(true);
                    m_Fruit[20+a]->SetInGame(true);
                    m_Fruit[20+a]->SetPosition(6+(a/8)*2,2+a%8);
                }
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
                for (int a=0;a<8;a++)
                {
                    m_Wall[(2+a/4*5-1)+(4+a%4+(a%4>1?2:0)-1)*10]->SetVisible(true);
                    m_Wall[(4+a/4*5-1)+(2+a%4+(a%4>1?2:0)-1)*10]->SetVisible(true);
                }
                for (int a=0;a<8;a++)
                {
                    m_AirWall[4+a/4*5-1+(4+a%4+(a%4>1?2:0)-1)*10]->SetVisible(true);
                    m_AirWall[(2+a%4+(a%4>1?2:0)-1)*10+2+a/4*5-1]->SetVisible(true);
                }
            }//Wall AirWall
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV12:
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(5+a%2,5+a/2);
                }
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
                for (int a=0;a<4;a++)
                {
                    m_CampFire[a]->SetVisible(true);
                    m_CampFire[a]->SetPosition(4+a%2*3,5+a/2);
                }
                for (int a=0;a<4;a++)
                {
                    m_CampFire[a+4]->SetVisible(true);
                    m_CampFire[a+4]->SetPosition(5+a%2,4+(a/2)*3);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Wall[(3+a%2*3)+(3+a/2*3)*10]->SetVisible(true);
                }
            }
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV13:
        {
            {
                for (int a=0;a<4;a++)
                {
                    m_Fruit[20+20+4+4+a]->SetVisible(true);
                    m_Fruit[20+20+4+4+a]->SetInGame(true);
                    m_Fruit[20+20+4+4+a]->SetPosition(5+a%2,5+a/2);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(7+a,7+a);
                }
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
                for (int a=0;a<4;a++)
                {
                    m_Fruit[20+20+4+4+a]->SetVisible(true);
                    m_Fruit[20+20+4+4+a]->SetInGame(true);
                    m_Fruit[20+20+4+4+a]->SetPosition(5+a%2,5+a/2);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(7+a,7+a);
                }
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
                for (int a=0;a<4;a++)
                {
                    m_Fruit[20+20+4+4+a]->SetVisible(true);
                    m_Fruit[20+20+4+4+a]->SetInGame(true);
                    m_Fruit[20+20+4+4+a]->SetPosition(5+a%2,5+a/2);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(7+a,7+a);
                }
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
                    for (int aa=1;aa<6;aa++)
                    {
                        m_Wall[aa*2-1+(a-1)*10]->SetVisible(true);
                    }
                    for (int aa=0;aa<4;aa++)
                    {
                        m_FireBlock[aa*2+3-1+(a-1)*10]->SetVisible(true);
                    }
                }

                for (int a=0;a<8;a++)
                {
                    m_CampFire[a]->SetVisible(true);
                    m_CampFire[a]->SetPosition(3+a%4*2,1+(a/4)*9);
                }
            }
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(3+(a/8)*2,2+a%8);
                }
                for (int a=0;a<16;a++)
                {
                    m_Fruit[20+a]->SetVisible(true);
                    m_Fruit[20+a]->SetInGame(true);
                    m_Fruit[20+a]->SetPosition(7+(a/8)*2,2+a%8);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(3+a*2,6);
                }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[16+4+a]->SetVisible(true);
                    m_Enemies[16+4+a]->SetPosition(1+(a/2)*9,1+a%2*9);
                }
            }
            {
                for (int a=0;a<10;a++)
                {
                    for (int aa=0;aa<4;aa++)
                    {
                        m_Fruit[aa*10+a]->SetVisible(true);
                        m_Fruit[aa*10+a]->SetInGame(true);
                        m_Fruit[aa*10+a]->SetPosition((aa<2?5:6)+(aa<2?-1:1)*(aa%2==0?2:4),a+1);
                    }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[16+4+4+a]->SetVisible(true);
                }
                m_Enemies[0+16+ 4+4]->SetPosition(5,2);
                m_Enemies[1+16+ 4+4]->SetPosition(6,8);
                m_Enemies[2+16+ 4+4]->SetPosition(2,6);
                m_Enemies[3+16+ 4+4]->SetPosition(8,5);
            }
            {
                for (int a=0;a<10;a++)
                {
                    for (int aa=0;aa<4;aa++)
                    {
                        m_Fruit[aa*10+a]->SetVisible(true);
                        m_Fruit[aa*10+a]->SetInGame(true);
                        m_Fruit[aa*10+a]->SetPosition(a+1,(aa<2?5:6)+(aa<2?-1:1)*(aa%2==0?2:4));
                    }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[a+16+ 4+4+4]->SetVisible(true);
                    m_Enemies[a+16+ 4+4+4]->SetPosition(2+(a/2)*7,2+a%2*7);
                }
            }
            {
                for (int a=0;a<9;a++)
                {
                    for (int aa=0;aa<4;aa++)
                    {
                        m_Fruit[aa*10+a]->SetVisible(true);
                        m_Fruit[aa*10+a]->SetInGame(true);
                        m_Fruit[aa*10+a]->SetPosition(aa%2*7+1+a%3,(aa/2)*7+1+a/3);
                    }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[a+16+ 4+4+4+4]->SetVisible(true);
                }
                m_Enemies[0+16+ 4+4+4+4]->SetPosition(8,2);
                m_Enemies[1+16+ 4+4+4+4]->SetPosition(9,8);
                m_Enemies[2+16+ 4+4+4+4]->SetPosition(3,9);
                m_Enemies[3+16+ 4+4+4+4]->SetPosition(2,3);
            }
            {
                for(int aa=0;aa<4;aa++)
                {
                    for (int a=0;a<10;a++)
                    {
                        m_Fruit[aa*10+a]->SetVisible(true);
                        m_Fruit[aa*10+a]->SetInGame(true);
                        m_Fruit[aa*10+a]->SetPosition( (aa<2? aa%2*5+3:a+1),(aa<2? a+1:aa%2*5+3)  );
                    }
                    for (int a=0;a<2;a++)
                    {
                        m_Fruit[aa*10+2+a*5]->SetInGame(false);
                    }
                }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[a+16]->SetVisible(true);
                    m_Enemies[a+16]->SetPosition(4+(a/2)*3,4+(a%2)*3);
                }
            }
            {
                for (int a=0;a<4;a++)
                {
                    for (int aa=0;aa<4;aa++)
                    {
                        m_Fruit[aa*10+a]->SetVisible(true);
                        m_Fruit[aa*10+a]->SetInGame(true);
                        m_Fruit[aa*10+a]->SetPosition(1+a/2+(aa/2)*8,1+a%2+(aa%2)*8);
                    }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[a+16+4]->SetVisible(true);
                    m_Enemies[a+16+4]->SetPosition(1+(a/2)*8,1+a%2*8);
                }
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
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(4+(a/2)*3,4+(a%2)*3);
                }
            }//enemies
            {
                for (int a=0;a<3;a++)
                {
                    for (int aa=0;aa<4;aa++)
                    {
                        m_Wall[ 2+(aa/2)*5 +(aa/2==0?1:-1)*(a/2) + ((2+(aa%2)*5 )+(aa%2==0?1:-1)*(a%2))*10]->SetVisible(true);
                    }
                }
            }//wall
            m_IceCream->SetPosition(5,5);
            break;
        }
    case Phase::LV24:
        {
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(6+a%4,6+a/4);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[48+a]->SetVisible(false);
                    m_Fruit[48+a]->SetInGame(true);
                    m_Fruit[48+a]->SetPosition(1+a%2*4,1+a/2*4);
                }

            }//Fruit
            {
                for (int a=0;a<25;a++)
                {
                    m_FireBlock[a%5*10+a/5]->SetVisible(true);
                    m_FireBlock[a%5*10+a/5+55]->SetVisible(true);
                    m_IceBlock[a%5*10+a/5+50]->SetVisible(true);
                    m_IceBlock[a%5*10+a/5+5]->SetVisible(true);

                }

            }//Block
            {
                for (int a=0;a<4;a++)
                {
                    m_Enemies[8+a]->SetVisible(true);
                    m_Enemies[8+a]->SetPosition(6+(a%2)*4,6+(a/2)*4);
                }
            }//enemy
            m_IceCream->SetPosition(1,1);
            break;
        }
    case Phase::LV25:
        {
            {
                for (int a=0;a<16;a++)
                {
                    m_Fruit[a]->SetVisible(true);
                    m_Fruit[a]->SetInGame(true);
                    m_Fruit[a]->SetPosition(4+a%4,4+a/4);
                }
                for (int a=0;a<4;a++)
                {
                    m_Fruit[42+a]->SetVisible(false);
                    m_Fruit[42+a]->SetInGame(true);
                    m_Fruit[42+a]->SetPosition(4+((a+1)/2==1?3:0),4+(a%2==0?3:0));
                }
            }//Fruit
            {
                for (int a=4;a<10;a++)
                {
                    for (int aa=0;aa<10;aa++)
                    {
                        m_Wall[(a<7? a-4:a)+aa*10]->SetVisible(true);
                        m_Wall[(a<7? a-4:a)*10+aa]->SetVisible(true);
                    }
                }
            }//Wall
            {
                m_Enemies[8]->SetVisible(true);
                m_Enemies[8]->SetPosition(4,4);
            }
            m_IceCream->SetPosition(7,7);
        }
    default:
        break;
    }
    MapStart();
}
}