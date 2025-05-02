#include "App.hpp"
#include "TurnOffThings.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include <chrono>

#include <random>


std::chrono::steady_clock::time_point lastIceTime;  // 記錄上次創建冰的時間
std::chrono::steady_clock::time_point lastMouseTime;  // 記錄上次按按鈕的時間
const std::chrono::milliseconds cooldownTime{300};
const std::chrono::milliseconds cooldownMouseTime{300};
std::vector<Util::Keycode> keyOrder;
void KeyRelease(Util::Keycode key) {
    keyOrder.erase(std::remove(keyOrder.begin(), keyOrder.end(), key), keyOrder.end());
}

static std::random_device rd2;   // 產生隨機種子
static std::mt19937 gen2(rd2());  // 使用 Mersenne Twister 隨機數引擎
static std::uniform_int_distribution<int> dist2(0, 99);  // 產生 0~99 的整數
int LV_Change = 0;
int Fruit_Counter = 0;
std::array<int, 9> Fruit_Counter_Arr;
std::array<bool, 9> Fruit_Reset_Arr;
void App::Update() {
    const auto now = std::chrono::steady_clock::now();
    m_LVLockedPicture[0]->Unlock();
    switch (m_Phase){
        case Phase::Start:{
            const auto mousePosition = Util::Input::GetCursorPosition();
            m_BackGround[1]->SetVisible(true);//title
            m_Button[0]->SetVisible(true);//Manu
            m_Button[1]->SetVisible(true);//Help

            if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime)
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
            const auto mousePosition = Util::Input::GetCursorPosition();
            m_BackGround[2]->SetVisible(true);//Interface_Help
            m_Button[2]->SetVisible(true);//Back

            if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime)
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
                const auto mousePosition = Util::Input::GetCursorPosition();
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
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime)
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
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime)
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
                break;
            }
        case Phase::Win:{
                const auto mousePosition = Util::Input::GetCursorPosition();
                m_BackGround[4]->SetVisible(true);
                m_Button[7]->SetVisible(true);
                m_Button[8]->SetVisible(true);
                m_Button[9]->SetVisible(true);
                LV_Change = 0;
                m_LVLockedPicture[static_cast<int>(m_LastPhase) -static_cast<int>(Phase::LV01)+1]->Unlock();
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime)
                {
                    if (m_Button[7]->isClicked(mousePosition))
                    {

                        lastMouseTime = now;
                        m_BackGround[4]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=Phase::Manu;
                        m_LastPhase=Phase::Win;
                    }
                    if (m_Button[8]->isClicked(mousePosition))
                    {

                        lastMouseTime = now;
                        m_BackGround[4]->SetVisible(false);
                        TurnOffButton();

                        m_Phase=m_LastPhase;
                        m_LastPhase=Phase::Win;
                    }
                    if (m_Button[9]->isClicked(mousePosition))
                    {

                        lastMouseTime = now;
                        m_BackGround[4]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=static_cast<Phase>(static_cast<int>(m_LastPhase) + 1);
                        m_LastPhase=Phase::Win;
                    }
                }
                break;
            }
        case Phase::Lose:{
                const auto mousePosition = Util::Input::GetCursorPosition();
                m_BackGround[5]->SetVisible(true);
                m_Button[7]->SetVisible(true);
                m_Button[8]->SetVisible(true);
                m_Button[9]->SetVisible(true);
                LV_Change = 0;
                if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime)
                {
                    if (m_Button[7]->isClicked(mousePosition))
                    {

                        lastMouseTime = now;
                        m_BackGround[5]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=Phase::Manu;
                        m_LastPhase=Phase::Lose;
                    }
                    if (m_Button[8]->isClicked(mousePosition))
                    {

                        lastMouseTime = now;
                        m_BackGround[5]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=m_LastPhase;
                        m_LastPhase=Phase::Lose;
                    }
                    if (m_Button[9]->isClicked(mousePosition))
                    {

                        lastMouseTime = now;
                        m_BackGround[5]->SetVisible(false);
                        TurnOffButton();
                        m_Phase=static_cast<Phase>(static_cast<int>(m_LastPhase) + 1);
                        m_LastPhase=Phase::Lose;
                    }
                }
                break;
            }
        case Phase::LV01:
        case Phase::LV02:
        case Phase::LV03:
        case Phase::LV04:
        case Phase::LV05:
        case Phase::LV06:
        case Phase::LV07:
        case Phase::LV08:
        case Phase::LV09:
        case Phase::LV10:
        case Phase::LV11:
        case Phase::LV12:
        case Phase::LV13:
        case Phase::LV14:
        case Phase::LV15:
        case Phase::LV16:
        case Phase::LV17:
        case Phase::LV18:
        case Phase::LV19:
        case Phase::LV20:
        case Phase::LV21:
        case Phase::LV22:
        case Phase::LV23:
        case Phase::LV24:
        case Phase::LV25:{
            const auto mousePosition = Util::Input::GetCursorPosition();

            if (Fruit_Counter==0)
            {
                TurnOffButton();
                m_LastPhase=m_Phase;
                m_Phase=Phase::Win;
                TurnOffLevel();
                break;
            }
            if (!m_IceCream->GetVisibility())
            {
                TurnOffButton();
                m_LastPhase=m_Phase;
                m_Phase=Phase::Lose;
                TurnOffLevel();
                break;
            }
            if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime&&m_Button[4]->isClicked(mousePosition))
            {
                TurnOffButton();
                lastMouseTime = now;
                LV_Change=0;
                break;
            }
            if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime&&m_Button[5]->isClicked(mousePosition))
            {
                lastMouseTime = now;
                TurnOffButton();
                m_LastPhase=m_Phase;
                m_Phase=Phase::Help;
                break;
            }
            if (Util::Input::IsKeyPressed(Util::Keycode::MOUSE_LB)&&now - lastMouseTime >= cooldownMouseTime&&m_Button[6]->isClicked(mousePosition))
            {
                lastMouseTime = now;
                TurnOffButton();
                m_LastPhase=m_Phase;
                m_Phase=Phase::Manu;
                LV_Change=0;
                TurnOffLevel();
                break;
            }
            break;
        }
        default:
            break;
    }//Phase Change

    switch (m_Phase){
        case Phase::Win:
            SwitchBGM(1);break;
        case Phase::Lose:
            SwitchBGM(2);break;
        default:
            SwitchBGM(0);break;
    }//BGM

    switch (m_Phase)
    {
    case Phase::LV01:{
            if (LV_Change == 0)
            {
                m_Button[4]->SetVisible(true);
                m_Button[5]->SetVisible(true);
                m_Button[6]->SetVisible(true);
                m_FruitPicture[0]->SetVisible(true);
                m_FruitPicture[0]->SetPosition(1);
                Fruit_Counter_Arr[0]=16;
                LV_Change = 1;
                for (int a = 0; a < 100; a++)
                {
                    m_Floor[a]->SetVisible(true);
                    m_Ice[a]->SetVisible(false);
                }
                m_IceCream->SetVisible(true);
                m_IceCream->SetPosition(1,1);
                for (int a = 0; a < 4; a++)
                {
                    m_Enemies_1[a]->SetVisible(true);
                }
                Fruit_Counter=16;
                m_Enemies_1[0]->SetPosition(5,5);
                m_Enemies_1[1]->SetPosition(5,6);
                m_Enemies_1[2]->SetPosition(6,6);
                m_Enemies_1[3]->SetPosition(6,5);

                m_Fruit[0]->SetVisible(true);
                m_Fruit[0]->SetPosition(4, 1);
                m_Fruit[1]->SetVisible(true);
                m_Fruit[1]->SetPosition(3, 1);
                m_Fruit[2]->SetVisible(true);
                m_Fruit[2]->SetPosition(7, 1);
                m_Fruit[3]->SetVisible(true);
                m_Fruit[3]->SetPosition(8, 1);

                m_Fruit[4]->SetVisible(true);
                m_Fruit[4]->SetPosition(1, 3);
                m_Fruit[5]->SetVisible(true);
                m_Fruit[5]->SetPosition(1, 4);
                m_Fruit[6]->SetVisible(true);
                m_Fruit[6]->SetPosition(1, 7);
                m_Fruit[7]->SetVisible(true);
                m_Fruit[7]->SetPosition(1, 8);

                m_Fruit[8]->SetVisible(true);
                m_Fruit[8]->SetPosition(10, 3);
                m_Fruit[9]->SetVisible(true);
                m_Fruit[9]->SetPosition(10, 4);
                m_Fruit[10]->SetVisible(true);
                m_Fruit[10]->SetPosition(10, 7);
                m_Fruit[11]->SetVisible(true);
                m_Fruit[11]->SetPosition(10, 8);

                m_Fruit[12]->SetVisible(true);
                m_Fruit[12]->SetPosition(3, 10);
                m_Fruit[13]->SetVisible(true);
                m_Fruit[13]->SetPosition(4, 10);
                m_Fruit[14]->SetVisible(true);
                m_Fruit[14]->SetPosition(7, 10);
                m_Fruit[15]->SetVisible(true);
                m_Fruit[15]->SetPosition(8, 10);
            }
            if (Fruit_Counter_Arr[0]==0)
            {
                m_FruitPicture[0]->SetVisible(false);
            }
            break;}
    case Phase::LV02:{
        if (LV_Change == 0)
        {
            m_Button[4]->SetVisible(true);
            m_Button[5]->SetVisible(true);
            m_Button[6]->SetVisible(true);
            m_FruitPicture[0]->SetVisible(true);
            m_FruitPicture[0]->SetPosition(1);
            Fruit_Counter_Arr[0]=8;
            LV_Change = 1;
            for (int a = 0; a < 100; a++)
            {
                m_Floor[a]->SetVisible(true);
                m_Ice[a]->SetVisible(false);
            }


            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
            m_Fruit[0]->SetPosition(3, 3);
            m_Fruit[1]->SetPosition(2, 2);
            m_Fruit[2]->SetPosition(2, 9);
            m_Fruit[3]->SetPosition(3, 8);

            m_Fruit[4]->SetVisible(true);
            m_Fruit[5]->SetVisible(true);
            m_Fruit[6]->SetVisible(true);
            m_Fruit[7]->SetVisible(true);
            m_Fruit[4]->SetPosition(8, 3);
            m_Fruit[5]->SetPosition(9, 2);
            m_Fruit[6]->SetPosition(9, 9);
            m_Fruit[7]->SetPosition(8, 8);
            Fruit_Counter=8;



            m_IceCream->SetVisible(true);
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
        if (Fruit_Counter_Arr[0]==0)
        {
            m_FruitPicture[0]->SetVisible(false);
        }
        break;}
    case Phase::LV03:{
        if (LV_Change == 0){
            m_Button[4]->SetVisible(true);
            m_Button[5]->SetVisible(true);
            m_Button[6]->SetVisible(true);
            m_FruitPicture[0]->SetVisible(true);
            m_FruitPicture[0]->SetPosition(1);
            Fruit_Counter_Arr[0]=8;
            LV_Change = 1;
            for (int a = 0; a < 100; a++)
            {
                m_Floor[a]->SetVisible(true);
                m_Ice[a]->SetVisible(false);
            }
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

            m_IceCream->SetVisible(true);
            m_IceCream->SetPosition(5,5);

            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
            m_Fruit[0]->SetPosition(1, 10);
            m_Fruit[1]->SetPosition(1, 1);
            m_Fruit[2]->SetPosition(10, 1);
            m_Fruit[3]->SetPosition(10, 10);
            Fruit_Counter=4;

        }
        if (Fruit_Counter_Arr[0]==0)
        {
            m_FruitPicture[0]->SetVisible(false);
        }
        break;
    }
    case Phase::LV04:{
        if (LV_Change == 0){
            m_Button[4]->SetVisible(true);
            m_Button[5]->SetVisible(true);
            m_Button[6]->SetVisible(true);
            m_FruitPicture[0]->SetVisible(true);
            m_FruitPicture[0]->SetPosition(1);
            m_FruitPicture[1]->SetVisible(true);
            m_FruitPicture[1]->SetPosition(2);
            Fruit_Counter_Arr={4,8,0,0,0,0,0,0,0};
            Fruit_Reset_Arr={false,false,false,false,false,false,false,false,false};
            LV_Change = 1;
            for (int a = 0; a < 100; a++)
            {
                m_Floor[a]->SetVisible(true);
                m_Ice[a]->SetVisible(false);
            }

            m_Enemies_1[8]->SetVisible(true);
            m_Enemies_1[9]->SetVisible(true);
            m_Enemies_1[10]->SetVisible(true);
            m_Enemies_1[11]->SetVisible(true);
            m_Enemies_1[8]->SetPosition(1,1);
            m_Enemies_1[9]->SetPosition(10,1);
            m_Enemies_1[10]->SetPosition(1,10);
            m_Enemies_1[11]->SetPosition(10,10);

            m_IceCream->SetVisible(true);
            m_IceCream->SetPosition(5,5);

            m_Fruit[0]->SetVisible(true);
            m_Fruit[1]->SetVisible(true);
            m_Fruit[2]->SetVisible(true);
            m_Fruit[3]->SetVisible(true);
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
        if (Fruit_Counter>=8)
        {
            Fruit_Counter_Arr[0]=Fruit_Counter-8;
        }
        if (Fruit_Counter_Arr[0]==0&&Fruit_Reset_Arr[1]==false)
        {
            Fruit_Reset_Arr[1]=true;
            m_FruitPicture[0]->SetVisible(false);
            m_Fruit[16]->SetVisible(true);
            m_Fruit[17]->SetVisible(true);
            m_Fruit[18]->SetVisible(true);
            m_Fruit[19]->SetVisible(true);
            m_Fruit[20]->SetVisible(true);
            m_Fruit[21]->SetVisible(true);
            m_Fruit[22]->SetVisible(true);
            m_Fruit[23]->SetVisible(true);
        }
        break;
    }
    default:
        break;
    }//LV初始化

    switch (m_Phase)
    {
        case Phase::LV01:
        case Phase::LV02:
        case Phase::LV03:
        case Phase::LV04:
        case Phase::LV05:
        case Phase::LV06:
        case Phase::LV07:
        case Phase::LV08:
        case Phase::LV09:
        case Phase::LV10:
        case Phase::LV11:
        case Phase::LV12:
        case Phase::LV13:
        case Phase::LV14:
        case Phase::LV15:
        case Phase::LV16:
        case Phase::LV17:
        case Phase::LV18:
        case Phase::LV19:
        case Phase::LV20:
        case Phase::LV21:
        case Phase::LV22:
        case Phase::LV23:
        case Phase::LV24:
        case Phase::LV25:{
            {


                for (int i=1;i<11;i++)
                {
                    for (int j=1;j<11;j++)
                    {
                        if (m_Ice[(i-1)+(j-1)*10]->isCreate()==true)
                        {
                            Map[i][j]='I';
                        }
                        else
                        {
                            if (Map[i][j]=='I')
                            {
                                Map[i][j]='.';
                            }
                        }
                    }

                }
            }//Ice
            {
                if (Util::Input::IsKeyPressed(Util::Keycode::A)) {keyOrder.push_back(Util::Keycode::A);}
                else KeyRelease(Util::Keycode::A);
                if (Util::Input::IsKeyPressed(Util::Keycode::D)) {keyOrder.push_back(Util::Keycode::D);}
                else KeyRelease(Util::Keycode::D);
                if (Util::Input::IsKeyPressed(Util::Keycode::S)) {keyOrder.push_back(Util::Keycode::S);}
                else KeyRelease(Util::Keycode::S);
                if (Util::Input::IsKeyPressed(Util::Keycode::W)) {keyOrder.push_back(Util::Keycode::W);}
                else KeyRelease(Util::Keycode::W);
                if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {keyOrder.push_back(Util::Keycode::UP);}
                else KeyRelease(Util::Keycode::UP);
                if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {keyOrder.push_back(Util::Keycode::DOWN);}
                else KeyRelease(Util::Keycode::DOWN);
                if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {keyOrder.push_back(Util::Keycode::LEFT);}
                else KeyRelease(Util::Keycode::LEFT);
                if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {keyOrder.push_back(Util::Keycode::RIGHT);}
                else KeyRelease(Util::Keycode::RIGHT);
                if (Util::Input::IsKeyPressed(Util::Keycode::SPACE)){keyOrder.push_back(Util::Keycode::SPACE);}
                else KeyRelease(Util::Keycode::SPACE);

                if (!keyOrder.empty())
                {
                    if (keyOrder.front()==Util::Keycode::SPACE&&m_IceCream->GetDirection()!=Model::Direction::None)
                    {
                        if (now - lastIceTime >= cooldownTime)
                        {
                            int NewX=m_IceCream->GetNextI(), NewY=m_IceCream->GetNextJ();
                            Model::Direction const direction=m_IceCream->GetDirection();
                            if (NewX==m_IceCream->GetI() && NewY==m_IceCream->GetJ())
                            {
                                switch (direction)
                                {
                                case Model::Direction::Up:
                                    NewY=NewY-1;break;
                                case Model::Direction::Down:
                                    NewY=NewY+1;break;
                                case Model::Direction::Left:
                                    NewX=NewX-1;break;
                                case Model::Direction::Right:
                                    NewX=NewX+1;break;
                                case Model::Direction::None:
                                    LOG_WARN("direction=none in Ice");break;
                                }

                            }
                            if (m_IceCream->IsMoving())
                            {
                                switch (direction)
                                {
                                case Model::Direction::Up:
                                    NewY=NewY-1;break;
                                case Model::Direction::Down:
                                    NewY=NewY+1;break;
                                case Model::Direction::Left:
                                    NewX=NewX-1;break;
                                case Model::Direction::Right:
                                    NewX=NewX+1;break;
                                case Model::Direction::None:
                                    LOG_WARN("direction=none in Ice");
                                }
                            }
                            if ( ((!m_IceCream->TowardHasThings(NewX,NewY)&&Map[NewX][NewY]!='E')||m_IceCream->IsitIce(NewX,NewY) )&&!(NewX<1 || NewX>10 || NewY<1 || NewY>10))
                            {
                                lastIceTime = now;
                                LOG_DEBUG(m_IceCream->GetIJ());
                                LOG_DEBUG(m_IceCream->GetNextIJ());
                                const bool CreateOrBroke=m_Ice[(NewX-1)+(NewY-1)*10]->GetVisibility();

                                while (true)
                                {

                                    if (m_Ice[(NewX-1)+(NewY-1)*10]->isCreate()==CreateOrBroke&&!m_Ice[(NewX-1)+(NewY-1)*10]->TowardHasThings(NewX,NewY))
                                    {
                                        m_Ice[(NewX-1)+(NewY-1)*10]->SetVisible(!CreateOrBroke);
                                    }
                                    else
                                    {
                                        break;
                                    }

                                    switch (direction)
                                    {
                                    case Model::Direction::Up:

                                        NewY=NewY-1;break;
                                    case Model::Direction::Down:

                                        NewY=NewY+1;break;
                                    case Model::Direction::Left:

                                        NewX=NewX-1;break;
                                    case Model::Direction::Right:

                                        NewX=NewX+1;break;
                                    case Model::Direction::None:
                                        LOG_WARN("direction=none in Ice");
                                    }
                                    if (NewX<1 || NewX>10 || NewY<1 || NewY>10)
                                    {
                                        break;
                                    }


                                }
                                std::cout<<Map[1]<<std::endl<<Map[2]<<std::endl<<Map[3]<<std::endl<<Map[4]<<std::endl<<Map[5]<<std::endl;
                                std::cout<<Map[6]<<std::endl<<Map[7]<<std::endl<<Map[8]<<std::endl<<Map[9]<<std::endl<<Map[10]<<std::endl;
                                std::cout<<std::endl<<std::endl;

                            }
                        }
                    }

                m_IceCream->UpdateMovement(keyOrder);
                if (m_Ice[m_IceCream->GetI()-1+(m_IceCream->GetJ()-1)*10]->isCreate())
                {
                    m_Ice[m_IceCream->GetI()-1+(m_IceCream->GetJ()-1)*10]->SetVisible(false);
                }
                }
            }//IceCream
            {

                for (const auto& enemy : m_Enemies_1) {
                    if (enemy->GetVisibility())
                    {
                        enemy->MoveTowards();

                        if (enemy->IfCollides(m_IceCream,enemy->GetPosition()))
                        {
                            m_IceCream->SetVisible(false);
                        }

                        if (dist2(gen2) == 0)
                        {
                            enemy->SetDirection(enemy->GetRandomDirection());
                        }
                    }

                }
            }//Enemies
            {
                for (const auto& fruit : m_Fruit)
                {
                    if (fruit->IfCollides(m_IceCream,fruit->GetPosition())&&fruit->GetVisibility()==true)
                    {
                        fruit->SetVisible(false);
                        Fruit_Counter--;
                        LOG_DEBUG(fruit->GetIJ());
                        LOG_DEBUG(Fruit_Counter);
                        LOG_DEBUG(Fruit_Counter_Arr[0]);
                        LOG_DEBUG(Fruit_Counter_Arr[1]);
                    }
                }
            }
            {
                {
                    //     Map= {
                    //         "############",//0
                    //         "#..........#",//1
                    //         "#..........#",//2
                    //         "#..........#",//3
                    //         "#..........#",//4
                    //         "#..........#",//5
                    //         "#..........#",//6
                    //         "#..........#",//8
                    //         "#..........#",//8
                    //         "#..........#",//9
                    //         "#..........#",//10
                    //         "############"//11
                    //         // "012345678901"
                    //     };
                    //     for (const auto& ice : m_Ice) {
                    //         if (ice->isCreate())
                    //         {
                    //             Map[ice->GetNextI()][ice->GetJ()]= 'I';
                    //         }
                    //     }
                    //
                    //     for (const auto& enemy : m_Enemies_1) {
                    //         if (enemy->GetVisibility())
                    //         {
                    //             Map[enemy->GetNextI()][enemy->GetJ()]= 'E';
                    //         }
                    //     }
                }//MapUpdate
            }//廢案



            break;
        }
        default:
            break;
    }//CharacterUpdate


    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
