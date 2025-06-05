//
// Created by User on 2025/06/04.
//

#include "App.hpp"

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
        switch (m_Phase)
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


            m_Enemies_1[12]->SetVisible(true);
            m_Enemies_1[12]->SetPosition(10,10);



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
                    m_Fruit[32+0]->SetPosition(5, 5);
                    m_Fruit[32+1]->SetPosition(5, 6);
                    m_Fruit[32+2]->SetPosition(6, 5);
                    m_Fruit[32+3]->SetPosition(6, 6);

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

                    m_Fruit[36+0]->SetPosition(4,4);
                    m_Fruit[36+1]->SetPosition(4,7);
                    m_Fruit[36+2]->SetPosition(7,4);
                    m_Fruit[36+3]->SetPosition(7,7);

                    m_Fruit[40+0]->SetPosition(3,3);
                    m_Fruit[40+1]->SetPosition(3,8);
                    m_Fruit[40+2]->SetPosition(8,3);
                    m_Fruit[40+3]->SetPosition(8,8);
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
