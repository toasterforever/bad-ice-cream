//
// Created by User on 2025/06/04.
//

#include "App.hpp"
//Fruit=16+16+4+4+4
inline void App::LVReset()
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
    }

}

void App::TurnOnLV()
{
if (LV_Change==0&&IsGaming())
{
    LV_Change=1;
    LVReset();
    switch (m_Phase)//Fruit=16+16+4+4+4
    {
    case Phase::LV01:{

            {


                Fruit_Counter_Arr[0]=16;


                m_IceCream->SetPosition(1,1);
                for (int a = 0; a < 4; a++)
                {
                    m_Enemies_1[a]->SetVisible(true);
                }
                m_Enemies_1[0]->SetPosition(5,5);
                m_Enemies_1[1]->SetPosition(5,6);
                m_Enemies_1[2]->SetPosition(6,6);
                m_Enemies_1[3]->SetPosition(6,5);

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



            Fruit_Counter_Arr[0]=8;




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

            m_Enemies_1[1]->SetVisible(true);
            m_Enemies_1[2]->SetVisible(true);


            m_Enemies_1[1]->SetPosition(1,7);
            m_Enemies_1[2]->SetPosition(10,4);



            m_Enemies_1[5]->SetVisible(true);
            m_Enemies_1[6]->SetVisible(true);


            m_Enemies_1[5]->SetPosition(7,1);
            m_Enemies_1[6]->SetPosition(4,10);


        }

        break;}
    case Phase::LV03:{
        {



            Fruit_Counter_Arr[0]=4;


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

            m_Enemies_1[8]->SetVisible(true);
            m_Enemies_1[9]->SetVisible(true);
            m_Enemies_1[10]->SetVisible(true);
            m_Enemies_1[11]->SetVisible(true);
            m_Enemies_1[8]->SetPosition(1,1);
            m_Enemies_1[9]->SetPosition(10,1);
            m_Enemies_1[10]->SetPosition(1,10);
            m_Enemies_1[11]->SetPosition(10,10);


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

            Fruit_Counter_Arr={4,8,0,0,0,0,0,0,0};




            m_Enemies_1[8]->SetVisible(true);
            m_Enemies_1[9]->SetVisible(true);
            m_Enemies_1[10]->SetVisible(true);
            m_Enemies_1[11]->SetVisible(true);
            m_Enemies_1[8]->SetPosition(1,1);
            m_Enemies_1[9]->SetPosition(10,1);
            m_Enemies_1[10]->SetPosition(1,10);
            m_Enemies_1[11]->SetPosition(10,10);


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


            m_Fruit[16]->SetVisible(false);
            m_Fruit[17]->SetVisible(false);
            m_Fruit[18]->SetVisible(false);
            m_Fruit[19]->SetVisible(false);
            m_Fruit[20]->SetVisible(false);
            m_Fruit[21]->SetVisible(false);
            m_Fruit[22]->SetVisible(false);
            m_Fruit[23]->SetVisible(false);

            m_Fruit[16+0]->SetInGame(true);
            m_Fruit[16+1]->SetInGame(true);
            m_Fruit[16+2]->SetInGame(true);
            m_Fruit[16+3]->SetInGame(true);
            m_Fruit[20+0]->SetInGame(true);
            m_Fruit[20+1]->SetInGame(true);
            m_Fruit[20+2]->SetInGame(true);
            m_Fruit[20+3]->SetInGame(true);

            m_Fruit[16]->SetPosition(5,5);
            m_Fruit[17]->SetPosition(5,6);
            m_Fruit[18]->SetPosition(5,7);
            m_Fruit[19]->SetPosition(5,4);
            m_Fruit[20]->SetPosition(6,4);
            m_Fruit[21]->SetPosition(6,5);
            m_Fruit[22]->SetPosition(6,6);
            m_Fruit[23]->SetPosition(6,7);

            Fruit_Counter=4+8;

        }


        break;
    }
    case Phase::LV05:{
        {



            m_FruitPicture[0]->SetVisible(true);
            m_FruitPicture[0]->SetPosition(1);
            m_FruitPicture[1]->SetVisible(true);
            m_FruitPicture[1]->SetPosition(2);
            Fruit_Counter_Arr={4,8,0,0,0,0,0,0,0};

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


            m_Fruit[16]->SetVisible(false);
            m_Fruit[17]->SetVisible(false);
            m_Fruit[18]->SetVisible(false);
            m_Fruit[19]->SetVisible(false);
            m_Fruit[20]->SetVisible(false);
            m_Fruit[21]->SetVisible(false);
            m_Fruit[22]->SetVisible(false);
            m_Fruit[23]->SetVisible(false);
            m_Fruit[16+0]->SetInGame(true);
            m_Fruit[16+1]->SetInGame(true);
            m_Fruit[16+2]->SetInGame(true);
            m_Fruit[16+3]->SetInGame(true);
            m_Fruit[20+0]->SetInGame(true);
            m_Fruit[20+1]->SetInGame(true);
            m_Fruit[20+2]->SetInGame(true);
            m_Fruit[20+3]->SetInGame(true);

            m_Fruit[16]->SetPosition(1,1);
            m_Fruit[17]->SetPosition(1,2);
            m_Fruit[18]->SetPosition(1,9);
            m_Fruit[19]->SetPosition(1,10);
            m_Fruit[20]->SetPosition(10,1);
            m_Fruit[21]->SetPosition(10,2);
            m_Fruit[22]->SetPosition(10,9);
            m_Fruit[23]->SetPosition(10,10);


            m_Enemies_1[16]->SetVisible(true);
            m_Enemies_1[16]->SetPosition(10,10);



            m_IceCream->SetPosition(1,1);



            Fruit_Counter=4+8;

        }


        break;
    }

    case Phase::LV06:
        {
            {


            {

                Fruit_Counter_Arr={0,0,4,4,4,0,0,0,0};

                {
                    m_Fruit[32+0]->SetVisible(true);
                    m_Fruit[32+1]->SetVisible(true);
                    m_Fruit[32+2]->SetVisible(true);
                    m_Fruit[32+3]->SetVisible(true);
                    m_Fruit[32+0]->SetInGame(true);
                    m_Fruit[32+1]->SetInGame(true);
                    m_Fruit[32+2]->SetInGame(true);
                    m_Fruit[32+3]->SetInGame(true);


                    m_Fruit[36+0]->SetVisible(true);
                    m_Fruit[36+1]->SetVisible(true);
                    m_Fruit[36+2]->SetVisible(true);
                    m_Fruit[36+3]->SetVisible(true);
                    m_Fruit[40+0]->SetVisible(true);
                    m_Fruit[40+1]->SetVisible(true);
                    m_Fruit[40+2]->SetVisible(true);
                    m_Fruit[40+3]->SetVisible(true);

                    m_Fruit[36+0]->SetInGame(true);
                    m_Fruit[36+1]->SetInGame(true);
                    m_Fruit[36+2]->SetInGame(true);
                    m_Fruit[36+3]->SetInGame(true);
                    m_Fruit[40+0]->SetInGame(true);
                    m_Fruit[40+1]->SetInGame(true);
                    m_Fruit[40+2]->SetInGame(true);
                    m_Fruit[40+3]->SetInGame(true);

                    m_Fruit[32+0]->SetPosition(5, 5);
                    m_Fruit[32+1]->SetPosition(5, 6);
                    m_Fruit[32+2]->SetPosition(6, 5);
                    m_Fruit[32+3]->SetPosition(6, 6);

                    m_Fruit[36+0]->SetPosition(3,3);
                    m_Fruit[36+1]->SetPosition(3,8);
                    m_Fruit[36+2]->SetPosition(8,3);
                    m_Fruit[36+3]->SetPosition(8,8);

                    m_Fruit[40+0]->SetPosition(4,4);
                    m_Fruit[40+1]->SetPosition(4,7);
                    m_Fruit[40+2]->SetPosition(7,4);
                    m_Fruit[40+3]->SetPosition(7,7);
                }
            }//Fruit

            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(10,10);
            }//Enemies

            m_IceCream->SetPosition(1,1);



            Fruit_Counter=4+4+4;

            }

        break;
        }
    case Phase::LV07:
    {
        {
            Fruit_Counter_Arr={0,8,0,0,0,0,0,0,0};

            m_Fruit[16]->SetVisible(true);
            m_Fruit[17]->SetVisible(true);
            m_Fruit[18]->SetVisible(true);
            m_Fruit[19]->SetVisible(true);
            m_Fruit[20]->SetVisible(true);
            m_Fruit[21]->SetVisible(true);
            m_Fruit[22]->SetVisible(true);
            m_Fruit[23]->SetVisible(true);

            m_Fruit[16+0]->SetInGame(true);
            m_Fruit[16+1]->SetInGame(true);
            m_Fruit[16+2]->SetInGame(true);
            m_Fruit[16+3]->SetInGame(true);
            m_Fruit[20+0]->SetInGame(true);
            m_Fruit[20+1]->SetInGame(true);
            m_Fruit[20+2]->SetInGame(true);
            m_Fruit[20+3]->SetInGame(true);

            m_Fruit[16]->SetPosition(5,5);
            m_Fruit[17]->SetPosition(5,6);
            m_Fruit[18]->SetPosition(5,7);
            m_Fruit[19]->SetPosition(5,4);
            m_Fruit[20]->SetPosition(6,4);
            m_Fruit[21]->SetPosition(6,5);
            m_Fruit[22]->SetPosition(6,6);
            m_Fruit[23]->SetPosition(6,7);

        }//Fruit

        {
            m_Enemies_1[8]->SetVisible(true);
            m_Enemies_1[8]->SetPosition(10,10);
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
                m_Fruit[16]->SetVisible(true);
                m_Fruit[17]->SetVisible(true);
                m_Fruit[18]->SetVisible(true);
                m_Fruit[19]->SetVisible(true);
                m_Fruit[16]->SetInGame(true);
                m_Fruit[17]->SetInGame(true);
                m_Fruit[18]->SetInGame(true);
                m_Fruit[19]->SetInGame(true);
                m_Fruit[16]->SetPosition(2,4);
                m_Fruit[17]->SetPosition(2,5);
                m_Fruit[18]->SetPosition(9,6);
                m_Fruit[19]->SetPosition(9,7);
            }//Fruit
            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);
                m_Enemies_1[11]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(2,8);
                m_Enemies_1[9]->SetPosition(2,9);
                m_Enemies_1[10]->SetPosition(7,8);
                m_Enemies_1[11]->SetPosition(7,9);
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
                m_Fruit[40]->SetVisible(false);
                m_Fruit[41]->SetVisible(false);
                m_Fruit[40]->SetInGame(true);
                m_Fruit[41]->SetInGame(true);
                m_Fruit[40]->SetPosition(5,6);
                m_Fruit[41]->SetPosition(6,5);
            }//Fruit
            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(5,5);
                m_Enemies_1[9]->SetPosition(6,6);
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
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);

                m_Enemies_1[8]->SetPosition(9,9);
                m_Enemies_1[9]->SetPosition(7,7);
                m_Enemies_1[10]->SetPosition(5,5);
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

                m_Fruit[0+16]->SetVisible(true);
                m_Fruit[1+16]->SetVisible(true);
                m_Fruit[2+16]->SetVisible(true);
                m_Fruit[3+16]->SetVisible(true);
                m_Fruit[0+16]->SetInGame(true);
                m_Fruit[1+16]->SetInGame(true);
                m_Fruit[2+16]->SetInGame(true);
                m_Fruit[3+16]->SetInGame(true);
                m_Fruit[0+16]->SetPosition(8,2);
                m_Fruit[1+16]->SetPosition(8,3);
                m_Fruit[2+16]->SetPosition(8,4);
                m_Fruit[3+16]->SetPosition(8,5);

                m_Fruit[4+16]->SetVisible(true);
                m_Fruit[5+16]->SetVisible(true);
                m_Fruit[6+16]->SetVisible(true);
                m_Fruit[7+16]->SetVisible(true);
                m_Fruit[4+16]->SetInGame(true);
                m_Fruit[5+16]->SetInGame(true);
                m_Fruit[6+16]->SetInGame(true);
                m_Fruit[7+16]->SetInGame(true);
                m_Fruit[4+16]->SetPosition(8,6);
                m_Fruit[5+16]->SetPosition(8,7);
                m_Fruit[6+16]->SetPosition(8,8);
                m_Fruit[7+16]->SetPosition(8,9);

                m_Fruit[0+8+16]->SetVisible(true);
                m_Fruit[1+8+16]->SetVisible(true);
                m_Fruit[2+8+16]->SetVisible(true);
                m_Fruit[3+8+16]->SetVisible(true);
                m_Fruit[0+8+16]->SetInGame(true);
                m_Fruit[1+8+16]->SetInGame(true);
                m_Fruit[2+8+16]->SetInGame(true);
                m_Fruit[3+8+16]->SetInGame(true);
                m_Fruit[0+8+16]->SetPosition(6,2);
                m_Fruit[1+8+16]->SetPosition(6,3);
                m_Fruit[2+8+16]->SetPosition(6,4);
                m_Fruit[3+8+16]->SetPosition(6,5);

                m_Fruit[4+8+16]->SetVisible(true);
                m_Fruit[5+8+16]->SetVisible(true);
                m_Fruit[6+8+16]->SetVisible(true);
                m_Fruit[7+8+16]->SetVisible(true);
                m_Fruit[4+8+16]->SetInGame(true);
                m_Fruit[5+8+16]->SetInGame(true);
                m_Fruit[6+8+16]->SetInGame(true);
                m_Fruit[7+8+16]->SetInGame(true);
                m_Fruit[4+8+16]->SetPosition(6,6);
                m_Fruit[5+8+16]->SetPosition(6,7);
                m_Fruit[6+8+16]->SetPosition(6,8);
                m_Fruit[7+8+16]->SetPosition(6,9);
            }//Fruit
            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(10,6);
                m_Enemies_1[9]->SetPosition(8,5);
                m_Enemies_1[10]->SetPosition(6,5);
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
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(10,6);
                m_Enemies_1[9]->SetPosition(8,5);
                m_Enemies_1[10]->SetPosition(6,5);
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
                m_Fruit[40+0]->SetVisible(true);
                m_Fruit[40+1]->SetVisible(true);
                m_Fruit[40+2]->SetVisible(true);
                m_Fruit[40+3]->SetVisible(true);
                m_Fruit[40+0]->SetInGame(true);
                m_Fruit[40+1]->SetInGame(true);
                m_Fruit[40+2]->SetInGame(true);
                m_Fruit[40+3]->SetInGame(true);
                m_Fruit[40+0]->SetPosition(5,5);
                m_Fruit[40+1]->SetPosition(5,6);
                m_Fruit[40+2]->SetPosition(6,5);
                m_Fruit[40+3]->SetPosition(6,6);
            }
            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);
                m_Enemies_1[11]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(10,10);
                m_Enemies_1[9]->SetPosition(9,9);
                m_Enemies_1[10]->SetPosition(8,8);
                m_Enemies_1[11]->SetPosition(7,7);
            }
            {
                for (int a=0;a<100;a++)
                {
                    m_IceBlock[a]->SetVisible(true);
                    m_IceBlock[a]->ResetTimer();
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
                m_FireBlock[a]->ResetTimer();
            }
            {
                m_Fruit[40+0]->SetVisible(true);
                m_Fruit[40+1]->SetVisible(true);
                m_Fruit[40+2]->SetVisible(true);
                m_Fruit[40+3]->SetVisible(true);
                m_Fruit[40+0]->SetInGame(true);
                m_Fruit[40+1]->SetInGame(true);
                m_Fruit[40+2]->SetInGame(true);
                m_Fruit[40+3]->SetInGame(true);
                m_Fruit[40+0]->SetPosition(5,5);
                m_Fruit[40+1]->SetPosition(5,6);
                m_Fruit[40+2]->SetPosition(6,5);
                m_Fruit[40+3]->SetPosition(6,6);
            }
            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);
                m_Enemies_1[11]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(10,10);
                m_Enemies_1[9]->SetPosition(9,9);
                m_Enemies_1[10]->SetPosition(8,8);
                m_Enemies_1[11]->SetPosition(7,7);
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
                    m_IceBlock[2*a+1]->ResetTimer();
                    m_FireBlock[2*a]->SetVisible(true);
                    m_FireBlock[2*a]->ResetTimer();
                }
            }
            {
                m_Fruit[40+0]->SetVisible(true);
                m_Fruit[40+1]->SetVisible(true);
                m_Fruit[40+2]->SetVisible(true);
                m_Fruit[40+3]->SetVisible(true);
                m_Fruit[40+0]->SetInGame(true);
                m_Fruit[40+1]->SetInGame(true);
                m_Fruit[40+2]->SetInGame(true);
                m_Fruit[40+3]->SetInGame(true);
                m_Fruit[40+0]->SetPosition(5,5);
                m_Fruit[40+1]->SetPosition(5,6);
                m_Fruit[40+2]->SetPosition(6,5);
                m_Fruit[40+3]->SetPosition(6,6);
            }
            {
                m_Enemies_1[8]->SetVisible(true);
                m_Enemies_1[9]->SetVisible(true);
                m_Enemies_1[10]->SetVisible(true);
                m_Enemies_1[11]->SetVisible(true);
                m_Enemies_1[8]->SetPosition(10,10);
                m_Enemies_1[9]->SetPosition(9,9);
                m_Enemies_1[10]->SetPosition(8,8);
                m_Enemies_1[11]->SetPosition(7,7);
            }
            m_IceCream->SetPosition(1,1);
            Map[m_IceCream->GetI()][m_IceCream->GetJ()]='!';
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
            Fruit_Counter=50;
            Fruit_Counter_Arr[0]=Fruit_Counter;
            break;
        }
    default:
        break;
    }
    }

}
