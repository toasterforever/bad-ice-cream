#include "App.hpp"
#include <iostream>
#include "Util/Logger.hpp"
#include <random>
#include <cstring>

void App::Start()
{
    LOG_TRACE("Start");
    static std::random_device rd3;   // 產生隨機種子
    static std::mt19937 gen3(rd3());  // 使用 Mersenne Twister 隨機數引擎
    static std::uniform_int_distribution<int> dist3(0, 19);  // 產生 0~19 的整數

    {
        m_BGM.push_back(std::make_shared<BGM>(GA_RESOURCE_DIR"/BGM/main.mp3"));
        m_BGM.push_back(std::make_shared<BGM>(GA_RESOURCE_DIR"/BGM/success.mp3"));
        m_BGM.push_back(std::make_shared<BGM>(GA_RESOURCE_DIR"/BGM/fail.mp3"));
        m_BGM[0]->Play();

    }//BGM

    {
        m_BackGround.push_back(std::make_shared<BackGround>(GA_RESOURCE_DIR"/Image/Background/Interface/Interface_Background.png"));
        m_BackGround[0]->ResetPosition();
        m_BackGround[0]->SetZIndex(1);
        m_BackGround[0]->SetVisible(true);
        m_Root.AddChild(m_BackGround[0]);

        m_BackGround.push_back(std::make_shared<BackGround>(GA_RESOURCE_DIR"/Image/Background/Interface/Title_BadIceCream.png"));
        m_BackGround[1]->SetPosition({0,200});
        m_BackGround[1]->SetZIndex(100);
        m_BackGround[1]->SetVisible(true);
        m_Root.AddChild(m_BackGround[1]);

        m_BackGround.push_back(std::make_shared<BackGround>(GA_RESOURCE_DIR"/Image/Background/Interface/Interface_Help.png"));
        m_BackGround[2]->ResetPosition();
        m_BackGround[2]->SetZIndex(50);
        m_BackGround[2]->SetVisible(false);
        m_Root.AddChild(m_BackGround[2]);

        m_BackGround.push_back(std::make_shared<BackGround>(GA_RESOURCE_DIR"/Image/Background/Interface/Interface_None.png"));
        m_BackGround[3]->ResetPosition();
        m_BackGround[3]->SetZIndex(50);
        m_BackGround[3]->SetVisible(false);
        m_Root.AddChild(m_BackGround[3]);

        m_BackGround.push_back(std::make_shared<BackGround>(GA_RESOURCE_DIR"/Image/Background/Interface/Interface_WIN.png"));
        m_BackGround[4]->ResetPosition();
        m_BackGround[4]->SetZIndex(50);
        m_BackGround[4]->SetVisible(false);
        m_Root.AddChild(m_BackGround[4]);
        m_BackGround.push_back(std::make_shared<BackGround>(GA_RESOURCE_DIR"/Image/Background/Interface/Interface_LOSE.png"));
        m_BackGround[5]->ResetPosition();
        m_BackGround[5]->SetZIndex(50);
        m_BackGround[5]->SetVisible(false);
        m_Root.AddChild(m_BackGround[5]);
    }//background

    {
        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_PLAY.png",Model::ButtonStyle::W200H100));
        m_Button[0]->BackGround::SetPosition({0,-50});
        m_Button[0]->SetZIndex(100);
        m_Button[0]->SetVisible(true);
        m_Root.AddChild(m_Button[0]);

        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_HELP.png",Model::ButtonStyle::W200H100));
        m_Button[1]->BackGround::SetPosition({0,-200});
        m_Button[1]->SetZIndex(100);
        m_Button[1]->SetVisible(true);
        m_Root.AddChild(m_Button[1]);

        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_BACK.png",Model::ButtonStyle::W200H100));
        m_Button[2]->BackGround::SetPosition({0,-230});
        m_Button[2]->SetZIndex(100);
        m_Button[2]->SetVisible(false);
        m_Root.AddChild(m_Button[2]);

        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_MANU.png",Model::ButtonStyle::W200H100));
        m_Button[3]->BackGround::SetPosition({330,330});
        m_Button[3]->SetZIndex(100);
        m_Button[3]->SetVisible(false);
        m_Root.AddChild(m_Button[3]);

        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Circle_REPLAY.png",Model::ButtonStyle::Circle60));
        m_Button[4]->BackGround::SetPosition({210,330});
        m_Button[4]->SetZIndex(100);
        m_Button[4]->SetVisible(false);
        m_Root.AddChild(m_Button[4]);
        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Circle_HELP.png",Model::ButtonStyle::Circle60));
        m_Button[5]->BackGround::SetPosition({270,330});
        m_Button[5]->SetZIndex(100);
        m_Button[5]->SetVisible(false);
        m_Root.AddChild(m_Button[5]);
        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Circle_MANU.png",Model::ButtonStyle::Circle60));
        m_Button[6]->BackGround::SetPosition({330,330});
        m_Button[6]->SetZIndex(100);
        m_Button[6]->SetVisible(false);
        m_Root.AddChild(m_Button[6]);

        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_MANU.png",Model::ButtonStyle::Circle60));
        m_Button[7]->BackGround::SetPosition({0,100});
        m_Button[7]->SetZIndex(100);
        m_Button[7]->SetVisible(false);
        m_Root.AddChild(m_Button[7]);
        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_REPLAY.png",Model::ButtonStyle::Circle60));
        m_Button[8]->BackGround::SetPosition({0,-50});
        m_Button[8]->SetZIndex(100);
        m_Button[8]->SetVisible(false);
        m_Root.AddChild(m_Button[8]);
        m_Button.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Button/Button_NEXT.png",Model::ButtonStyle::Circle60));
        m_Button[9]->BackGround::SetPosition({0,-200});
        m_Button[9]->SetZIndex(100);
        m_Button[9]->SetVisible(false);
        m_Root.AddChild(m_Button[9]);

    }//button

    {

        std::string str="0";
        m_Texts.push_back(std::make_shared<Text>(str,1));
        m_Root.AddChild(m_Texts[0]);
        m_Texts[0]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,2));
        m_Root.AddChild(m_Texts[1]);
        m_Texts[1]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,3));
        m_Root.AddChild(m_Texts[2]);
        m_Texts[2]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,4));
        m_Root.AddChild(m_Texts[3]);
        m_Texts[3]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,5));
        m_Root.AddChild(m_Texts[4]);
        m_Texts[4]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,6));
        m_Root.AddChild(m_Texts[5]);
        m_Texts[5]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,7));
        m_Root.AddChild(m_Texts[6]);
        m_Texts[6]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,8));
        m_Root.AddChild(m_Texts[7]);
        m_Texts[7]->SetVisible(false);
        m_Texts.push_back(std::make_shared<Text>(str,9));
        m_Root.AddChild(m_Texts[8]);
        m_Texts[8]->SetVisible(false);

        m_Texts.push_back(std::make_shared<Text>(str,5));
        m_Root.AddChild(m_Texts[9]);
        m_Texts[9]->SetVisible(false);
    }//Text

    {
        for (int a = 0; a < 25; ++a) {
            m_Level.push_back(std::make_shared<Button>(GA_RESOURCE_DIR"/Image/Background/Level/NEW/LV"+(a + 1 < 10 ? "0" + std::to_string(a + 1) : std::to_string(a + 1))+".png",Model::ButtonStyle::W80H80));
            m_Level[a]->SetZIndex(60);
            m_Level[a]->SetPosition(a%5, a/5);//a=(X-1)+(Y-1)*10
            m_Level[a]->SetVisible(false);
            m_Root.AddChild(m_Level[a]);
        }
    }//LV

    {
        m_IceCream = std::make_shared<MainCharacter>(GA_RESOURCE_DIR"/Image/Character/IceCream.png");
        m_IceCream->SetPosition(1,1);
        m_IceCream->SetZIndex(49);
        m_IceCream->SetVisible(false);
        m_Root.AddChild(m_IceCream);
    }//IceCream
    {
        for (int a = 0; a < 4; ++a) {
            m_Enemies_1.push_back(std::make_shared<Enemies>(GA_RESOURCE_DIR"/Image/Character/Toaster1.png",Model::Move::Row_Move));
            m_Enemies_1[a]->SetZIndex(8);
            m_Enemies_1[a]->SetPosition(a+1, 1);
            m_Enemies_1[a]->SetVisible(false);
            m_Root.AddChild(m_Enemies_1[a]);
        }
        for (int a = 0; a < 4; ++a) {
            m_Enemies_1.push_back(std::make_shared<Enemies>(GA_RESOURCE_DIR"/Image/Character/咖啡機.png",Model::Move::Column_Move));
            m_Enemies_1[4+a]->SetZIndex(8);
            m_Enemies_1[4+a]->SetPosition(a+1, 1);
            m_Enemies_1[4+a]->SetVisible(false);
            m_Root.AddChild(m_Enemies_1[4+a]);
        }
        for (int a = 0; a < 4; ++a) {
            m_Enemies_1.push_back(std::make_shared<Enemies>(GA_RESOURCE_DIR"/Image/Character/瓦斯爐.png",Model::Move::Around_Move));
            m_Enemies_1[8+a]->SetZIndex(8);
            m_Enemies_1[8+a]->SetPosition(a+1, 1);
            m_Enemies_1[8+a]->SetVisible(false);
            m_Root.AddChild(m_Enemies_1[8+a]);
        }
        for (int a = 0; a < 4; ++a) {
            m_Enemies_1.push_back(std::make_shared<Enemies>(GA_RESOURCE_DIR"/Image/Character/咖啡機.png",Model::Move::Auto_Move));
            m_Enemies_1[a+12]->SetZIndex(8);
            m_Enemies_1[a+12]->SetPosition(1, a+1);
            m_Enemies_1[a+12]->SetVisible(false);
            m_Root.AddChild(m_Enemies_1[a+12]);
        }
        // for (int a = 0; a < 10; ++a) {
        //     m_Enemies_1.push_back(std::make_shared<Enemies>(GA_RESOURCE_DIR"/Image/Character/微波爐.png"));
        //     m_Enemies_1[a+20]->SetZIndex(8);
        //     m_Enemies_1[a+20]->SetPosition(a+1, a+1);
        //     m_Enemies_1[a+20]->SetVisible(false);
        //     m_Root.AddChild(m_Enemies_1[a+20]);
        // }
    }//Enemies
    {
        for (int a = 0; a < 16; ++a) {
            m_Fruit.push_back(std::make_shared<Fruit>(GA_RESOURCE_DIR"/Image/Character/Fruit/Lemon.png"));
            m_Fruit[a]->SetZIndex(5);
            m_Fruit[a]->SetPosition(a+1, 1);
            m_Fruit[a]->SetVisible(false);
            m_Root.AddChild(m_Fruit[a]);
        }
        for (int a = 0; a < 16; ++a) {
            m_Fruit.push_back(std::make_shared<Fruit>(GA_RESOURCE_DIR"/Image/Character/Fruit/櫻桃.png"));
            m_Fruit[16+a]->SetZIndex(5);
            m_Fruit[16+a]->SetPosition(a+1, 1);
            m_Fruit[16+a]->SetVisible(false);
            m_Root.AddChild(m_Fruit[16+a]);
        }
        for (int a = 0; a < 4; ++a) {
            m_Fruit.push_back(std::make_shared<Fruit>(GA_RESOURCE_DIR"/Image/Character/Fruit/水蜜桃.png"));
            m_Fruit[32+a]->SetModel(Model::Move::Column_Move);
            m_Fruit[32+a]->SetZIndex(5);
            m_Fruit[32+a]->SetPosition(a+1, 1);
            m_Fruit[32+a]->SetVisible(false);
            m_Root.AddChild(m_Fruit[32+a]);
        }
        for (int a = 0; a < 4; ++a) {
            m_Fruit.push_back(std::make_shared<Fruit>(GA_RESOURCE_DIR"/Image/Character/Fruit/火龍果.png"));
            m_Fruit[36+a]->SetModel(Model::Move::Row_Move);
            m_Fruit[36+a]->SetZIndex(5);
            m_Fruit[36+a]->SetPosition(a+1, 1);
            m_Fruit[36+a]->SetVisible(false);
            m_Root.AddChild(m_Fruit[36+a]);
        }
        for (int a = 0; a < 4; ++a) {
            m_Fruit.push_back(std::make_shared<Fruit>(GA_RESOURCE_DIR"/Image/Character/Fruit/草莓.png"));
            m_Fruit[40+a]->SetModel(Model::Move::Around_Move);
            m_Fruit[40+a]->SetZIndex(5);
            m_Fruit[40+a]->SetPosition(a+1, 1);
            m_Fruit[40+a]->SetVisible(false);
            m_Root.AddChild(m_Fruit[40+a]);
        }
    }//Fruit
    {
        for (int a = 0; a < 100; ++a) {
            m_Ice.push_back(std::make_shared<Ice>(GA_RESOURCE_DIR"/Image/Background/wall/ice_brick_wall60.png"));
            m_Ice[a]->SetZIndex(7);
            m_Ice[a]->SetPosition(a%10+1, a/10+1);//a=(X-1)+(Y-1)*10
            m_Ice[a]->SetVisible(false);
            m_Root.AddChild(m_Ice[a]);

            m_Wall.push_back(std::make_shared<Wall>(GA_RESOURCE_DIR"/Image/Background/wall/red_brick_wall.png"));
            m_Wall[a]->SetZIndex(7);
            m_Wall[a]->SetPosition(a%10+1, a/10+1);
            m_Wall[a]->SetVisible(false);
            m_Root.AddChild(m_Wall[a]);

            if (dist3(gen3) == 0)
            {
                m_Floor.push_back(std::make_shared<Floor>(GA_RESOURCE_DIR"/Image/Background/floor/detailed_snow.png"));
            }
            else if (dist3(gen3) == 1)
            {
                m_Floor.push_back(std::make_shared<Floor>(GA_RESOURCE_DIR"/Image/Background/floor/random_piles_snow.png"));
            }
            else if (dist3(gen3) == 2)
            {
                m_Floor.push_back(std::make_shared<Floor>(GA_RESOURCE_DIR"/Image/Background/floor/raised_snow_piles.png"));
            }
            else
            {
                m_Floor.push_back(std::make_shared<Floor>(GA_RESOURCE_DIR"/Image/Background/floor/fine_lines_snow.png"));
            }
            m_Floor[a]->SetZIndex(2);
            m_Floor[a]->SetPosition(a%10+1, a/10+1);//a=(X-1)+(Y-1)*10
            m_Floor[a]->SetVisible(false);
            m_Root.AddChild(m_Floor[a]);
        }
    }//Ice, floor and wall

    {

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/Lemon.png",Model::PicureSource::Fruit));
        m_FruitPicture[0]->SetZIndex(90);
        m_FruitPicture[0]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[0]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/櫻桃.png",Model::PicureSource::Fruit));
        m_FruitPicture[1]->SetZIndex(90);
        m_FruitPicture[1]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[1]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/水蜜桃.png",Model::PicureSource::Fruit));
        m_FruitPicture[2]->SetZIndex(5);
        m_FruitPicture[2]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[2]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/火龍果.png",Model::PicureSource::Fruit));
        m_FruitPicture[3]->SetZIndex(5);
        m_FruitPicture[3]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[3]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/草莓.png",Model::PicureSource::Fruit));
        m_FruitPicture[4]->SetZIndex(5);
        m_FruitPicture[4]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[4]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/葡萄.png",Model::PicureSource::Fruit));
        m_FruitPicture[5]->SetZIndex(5);
        m_FruitPicture[5]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[5]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/西洋梨.png",Model::PicureSource::Fruit));
        m_FruitPicture[6]->SetZIndex(5);
        m_FruitPicture[6]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[6]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/西瓜.png",Model::PicureSource::Fruit));
        m_FruitPicture[7]->SetZIndex(5);
        m_FruitPicture[7]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[7]);

        m_FruitPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Character/Fruit/香蕉.png",Model::PicureSource::Fruit));
        m_FruitPicture[8]->SetZIndex(5);
        m_FruitPicture[8]->SetVisibility(false);
        m_Root.AddChild(m_FruitPicture[8]);

        for (int a=0;a<50;a++)
        {
            m_LVLockedPicture.push_back(std::make_shared<Picture>(GA_RESOURCE_DIR"/Image/Background/Level/NEW/LOCK.png",Model::PicureSource::Locked));
            m_LVLockedPicture[a]->SetZIndex(65);
            m_LVLockedPicture[a]->SetPosition(a%5, a/5);
            m_LVLockedPicture[a]->SetVisible(false);
            m_Root.AddChild(m_LVLockedPicture[a]);
        }

    }//Picture

    {
    //     m_FruitPicture.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/Fruit/香蕉.png"));
    //     m_FruitPicture[0]->SetZIndex(90);
    //     m_FruitPicture[0]->SetPosition(5,5);
    //     m_FruitPicture[0]->SetVisible(true);
    //     LOG_DEBUG("m_FruitPicture Created");
    //     LOG_DEBUG(m_FruitPicture[0]->GetZIndex());
    //     LOG_DEBUG(m_FruitPicture[0]->GetPosition());
    }//debug

    m_CurrentState = State::UPDATE;
}
