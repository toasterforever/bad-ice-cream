//
// Created by User on 2025/06/04.
//

#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include <random>

#include "Util/Logger.hpp"
static std::random_device rd2;   // 產生隨機種子
static std::mt19937 gen2(rd2());  // 使用 Mersenne Twister 隨機數引擎
static std::uniform_int_distribution<int> dist2(0, 99);  // 產生 0~99 的整數


void App::CharacterUpdate(){
    if (IsGaming()){
        IceCreamUpdate();
        MapUpdate();//Ice Wall AirWall
        EnemiesUpdate();
        FruitUpdate();
        CampFireUpdate();
        BlockUpdate();
    }//CharacterUpdate
}

void App::IceCreamUpdate()
{

    MainCharacterPosition={m_IceCream->GetIJ()};


    if (m_Ice[m_IceCream->GetIndex()]->isCreate())
    {
        m_Ice[m_IceCream->GetIndex()]->SetVisible(false);
    }
    KeyUpdate();

    if (m_IceCream->IsMoving())
    {
        m_IceCream->UpdatePosition();
    }
    else if (!keyOrder.empty())
    {
        m_IceCream->UpdateMovement(keyOrder);

        IceUpdate();
    }


}

void App::MapUpdate() //冰塊物件的偵測
{
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
}

void App::EnemiesUpdate()
{
    {
        for (const auto& enemy : m_Enemies) {
            if (enemy->GetVisibility())
            {

                if (enemy->fired()&&!enemy->IsMoving())
                {
                    switch (enemy->GetFireModel())  //根據Model不同，決定放火方式
                    {
                    case Model::Fired::One:
                        {
                            switch (enemy->GetDirection())
                            {
                                case Model::Direction::Left:
                                    {
                                        if (!m_Fire[enemy->GetIndex()-1]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()-1]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()-1]->ResetTimer();
                                        }
                                        break;
                                    }
                                case Model::Direction::Right:
                                    {
                                        if (!m_Fire[enemy->GetIndex()+1]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+1]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+1]->ResetTimer();
                                        }
                                        break;
                                    }
                                case Model::Direction::Up:
                                    {
                                        if (!m_Fire[enemy->GetIndex()-10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()-10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()-10]->ResetTimer();
                                        }
                                        break;
                                    }
                                case Model::Direction::Down:
                                    {
                                        if (!m_Fire[enemy->GetIndex()+10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+10]->ResetTimer();
                                        }
                                        break;
                                    }
                            }

                            break;
                        }
                    case Model::Fired::Three:
                        {
                            switch (enemy->GetDirection())
                            {
                            case Model::Direction::Left:
                                {
                                    if (!m_Fire[enemy->GetIndex()-1]->GetVisibility())
                                    {
                                        m_Fire[enemy->GetIndex()-1]->SetVisible(true);
                                        m_Fire[enemy->GetIndex()-1]->ResetTimer();
                                    }
                                    if (enemy->GetJ()>1)
                                    {
                                        if (m_Ice[enemy->GetIndex()-1-10]->GetVisibility()&&!m_Fire[enemy->GetIndex()-1-10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()-1-10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()-1-10]->ResetTimer();
                                        }
                                    }
                                    if (enemy->GetJ()<10)
                                    {
                                        if (m_Ice[enemy->GetIndex()-1+10]->GetVisibility()&&!m_Fire[enemy->GetIndex()-1+10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()-1+10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()-1+10]->ResetTimer();
                                        }
                                    }
                                    break;
                                }
                            case Model::Direction::Right:
                                {
                                    if (!m_Fire[enemy->GetIndex()+1]->GetVisibility())
                                    {
                                        m_Fire[enemy->GetIndex()+1]->SetVisible(true);
                                        m_Fire[enemy->GetIndex()+1]->ResetTimer();
                                    }

                                    if (enemy->GetJ()>1)
                                    {
                                        if (m_Ice[enemy->GetIndex()+1-10]->GetVisibility()&&!m_Fire[enemy->GetIndex()+1-10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+1-10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+1-10]->ResetTimer();
                                        }
                                    }
                                    if (enemy->GetJ()<10)
                                    {
                                        if (m_Ice[enemy->GetIndex()+1+10]->GetVisibility()&&!m_Fire[enemy->GetIndex()+1+10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+1+10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+1+10]->ResetTimer();
                                        }
                                    }
                                    break;
                                }
                            case Model::Direction::Up:
                                {
                                    if (!m_Fire[enemy->GetIndex()-10]->GetVisibility())
                                    {
                                        m_Fire[enemy->GetIndex()-10]->SetVisible(true);
                                        m_Fire[enemy->GetIndex()-10]->ResetTimer();
                                    }

                                    if (enemy->GetI()>1)
                                    {
                                        if (m_Ice[enemy->GetIndex()-1-10]->GetVisibility()&&!m_Fire[enemy->GetIndex()-1-10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()-1-10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()-1-10]->ResetTimer();
                                        }
                                    }
                                    if (enemy->GetI()<10)
                                    {
                                        if (m_Ice[enemy->GetIndex()+1-10]->GetVisibility()&&!m_Fire[enemy->GetIndex()+1-10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+1-10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+1-10]->ResetTimer();
                                        }
                                    }
                                    break;
                                }
                            case Model::Direction::Down:
                                {
                                    if (!m_Fire[enemy->GetIndex()+10]->GetVisibility())
                                    {
                                        m_Fire[enemy->GetIndex()+10]->SetVisible(true);
                                        m_Fire[enemy->GetIndex()+10]->ResetTimer();
                                    }

                                    if (enemy->GetI()>1)
                                    {
                                        if (m_Ice[enemy->GetIndex()-1+10]->GetVisibility()&&!m_Fire[enemy->GetIndex()-1+10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()-1+10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()-1+10]->ResetTimer();
                                        }
                                    }
                                    if (enemy->GetI()<10)
                                    {
                                        if (m_Ice[enemy->GetIndex()+1+10]->GetVisibility()&&!m_Fire[enemy->GetIndex()+1+10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+1+10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+1+10]->ResetTimer();
                                        }
                                    }
                                    break;
                                }
                            }

                            break;
                        }
                    case Model::Fired::Around:
                        {
                            for (int a=-1;a<2;a++)
                            {
                                for (int aa=-1;aa<2;aa++)
                                {
                                    if ((enemy->GetI()+a>0&&enemy->GetI()+a<11)&&(enemy->GetJ()+aa>0&&enemy->GetJ()+aa<11))
                                    {
                                        if (m_Ice[enemy->GetIndex()+a+aa*10]->GetVisibility()&&!m_Fire[enemy->GetIndex()+a+aa*10]->GetVisibility())
                                        {
                                            m_Fire[enemy->GetIndex()+a+aa*10]->SetVisible(true);
                                            m_Fire[enemy->GetIndex()+a+aa*10]->ResetTimer();
                                        }
                                    }
                                }
                            }
                            break;
                        }
                    case Model::Fired::Column_Row:
                        {
                            int a=enemy->GetI();
                            int b=enemy->GetJ();
                            int c;
                            switch (enemy->GetDirection())
                            {
                                case Model::Direction::Up:
                                    {
                                        while (true)
                                        {
                                            if (b<1)
                                            {
                                                break;
                                            }
                                            c=(a-1)+(b-1)*10;
                                            if (b==enemy->GetJ())
                                            {
                                                b--;continue;
                                            }
                                            if (c<0||c>99){std::cout<<c<<std::endl;}

                                            if(m_Ice[c]->GetVisibility()&&!m_Fire[c]->GetVisibility())
                                            {
                                                m_Fire[c]->SetVisible(true);
                                                m_Fire[c]->ResetTimer();
                                            }
                                            else if (!m_Ice[c]->GetVisibility())
                                            {
                                                break;
                                            }
                                            b--;

                                        }
                                        break;
                                    }
                                case Model::Direction::Down:
                                    {
                                        while (true)
                                        {
                                            if (b>10)
                                            {
                                                break;
                                            }
                                            c=(a-1)+(b-1)*10;
                                            if (b==enemy->GetJ())
                                            {
                                                b++;continue;
                                            }
                                            if (c<0||c>99){std::cout<<c<<std::endl;}
                                            if(m_Ice[c]->GetVisibility()&&!m_Fire[c]->GetVisibility())
                                            {
                                                m_Fire[c]->SetVisible(true);
                                                m_Fire[c]->ResetTimer();
                                            }
                                            else if (!m_Ice[c]->GetVisibility())
                                            {
                                                break;
                                            }
                                            b++;

                                        }
                                        break;
                                    }
                                case Model::Direction::Left:
                                    {
                                        while (true)
                                        {
                                            c=(a-1)+(b-1)*10;
                                            if (a==enemy->GetI())
                                            {
                                                a--;continue;
                                            }
                                            if (c<0||c>99){std::cout<<c<<std::endl;}
                                            if(m_Ice[c]->GetVisibility()&&!m_Fire[c]->GetVisibility())
                                            {
                                                m_Fire[c]->SetVisible(true);
                                                m_Fire[c]->ResetTimer();
                                            }
                                            else if (!m_Ice[c]->GetVisibility())
                                            {
                                                break;
                                            }
                                            a--;
                                            if (a<1||!m_Ice[c]->GetVisibility())
                                            {
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                case Model::Direction::Right:
                                    {
                                        while (true)
                                        {
                                            c=(a-1)+(b-1)*10;
                                            if (a==enemy->GetI())
                                            {
                                                a++;continue;
                                            }
                                            if (c<0||c>99){std::cout<<c<<std::endl;}
                                            if(m_Ice[c]->GetVisibility()&&!m_Fire[c]->GetVisibility())
                                            {
                                                m_Fire[c]->SetVisible(true);
                                                m_Fire[c]->ResetTimer();
                                            }
                                            else if (!m_Ice[c]->GetVisibility())
                                            {
                                                break;
                                            }
                                            a++;
                                            if (a>10||!m_Ice[c]->GetVisibility())
                                            {
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                default:
                                    break;
                            }
                            break;
                        }
                    case Model::Fired::Cross:
                        {
                            int c=enemy->GetIndex();
                            while (true)
                            {
                                c-=10;
                                if (c<0||c>99)
                                {
                                    break;
                                }
                                if (m_Ice[c]->GetVisibility())
                                {
                                    if (!m_Fire[c]->GetVisibility())
                                    {
                                        m_Fire[c]->SetVisible(true);
                                        m_Fire[c]->ResetTimer();
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                            c=enemy->GetIndex();
                            while (true)
                            {
                                c+=10;
                                if (c<0||c>99)
                                {
                                    break;
                                }
                                if (m_Ice[c]->GetVisibility())
                                {
                                    if (!m_Fire[c]->GetVisibility())
                                    {
                                        m_Fire[c]->SetVisible(true);
                                        m_Fire[c]->ResetTimer();
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                            c=enemy->GetIndex();
                            while (true)
                            {
                                c+=1;
                                if (c%10==0)
                                {
                                    break;
                                }
                                if (m_Ice[c]->GetVisibility())
                                {
                                    if (!m_Fire[c]->GetVisibility())
                                    {
                                        m_Fire[c]->SetVisible(true);
                                        m_Fire[c]->ResetTimer();
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                            c=enemy->GetIndex();
                            while (true)
                            {
                                c-=1;
                                if (c%10==9)
                                {
                                    break;
                                }
                                if (m_Ice[c]->GetVisibility())
                                {
                                    if (!m_Fire[c]->GetVisibility())
                                    {
                                        m_Fire[c]->SetVisible(true);
                                        m_Fire[c]->ResetTimer();
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                            break;
                        }
                    case Model::Fired::None:
                        {
                            break;
                        }
                    }
                }

                enemy->MoveTowards();

                if (enemy->IfCollides(m_IceCream,enemy->GetPosition()))
                {
                    m_IceCream->SetVisible(false);
                }

                if (dist2(gen2) == 0||enemy->GetDirection()==Model::Direction::None)  //1%機率隨機轉彎
                {
                    if (!enemy->fired())//&&enemy->GetModel()!=Model::Move::Auto_Move
                    {
                        enemy->SetDirection(enemy->GetRandomDirection());
                    }

                }
            }
        }
    }//Enemies
}

void App::FruitUpdate()
{
    {
        for (size_t i = 0; i < m_Fruit.size(); ++i)
        {
            auto& fruit = m_Fruit[i];// 安全地使用 index，遍歷不會錯
            if (fruit->IfCollides(m_IceCream,fruit->GetPosition())&&fruit->GetVisibility()==true)//冰淇淋吃冰塊
            {
                fruit->SetVisible(false);
                fruit->SetInGame(false);
                Map3[fruit->GetI()-1][fruit->GetJ()-1]='.';

            }
            if (fruit->GetModel()!=Model::Move::Dont_Move&&fruit->GetVisibility())//冰淇淋移動判定
            {
                if (!m_Ice[fruit->GetIndex()]->isCreate())
                {
                    fruit->MoveTowards();
                }

                if (dist2(gen2) == 0||fruit->GetDirection()==Model::Direction::None)
                {
                    fruit->SetDirection(fruit->GetRandomDirection());
                }
            }
        }
    }//Fruit
}

void App::KeyUpdate()//鍵盤輸入
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
}

void App::IceUpdate()
{
    const auto now = std::chrono::steady_clock::now();
    if (keyOrder.front()==Util::Keycode::SPACE&&                //按壓空白鍵
        m_IceCream->GetDirection()!=Model::Direction::None&&    //主角有面向方向
        now - lastIceTime >= cooldownTime)                      //冷卻時間
        {
            int NewX=m_IceCream->GetNextI(), NewY=m_IceCream->GetNextJ();
            Model::Direction direction=m_IceCream->GetDirection();
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
                    default:break;
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
                    default:
                        break;
                }

            }
            if (NewX<1||NewX>10||NewY<1||NewY>10)
            {
                return;
            }
            const bool CreateOrBroke=m_Ice[(NewX-1)+(NewY-1)*10]->GetVisibility();
            while (true)
            {
                if (!Ice::HasThings(NewX, NewY))
                {
                    lastIceTime = now;

                    if (m_Ice[(NewX-1)+(NewY-1)*10]->isCreate()==CreateOrBroke)
                    {
                        m_Ice[(NewX-1)+(NewY-1)*10]->SetVisible(!CreateOrBroke);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
                {
                    if (m_Arrow_Down[Character::GetIndex(NewX,NewY)]->GetVisibility())
                    {
                        direction=Model::Direction::Down;
                    }
                    else if  (m_Arrow_Up[Character::GetIndex(NewX,NewY)]->GetVisibility())
                    {
                        direction=Model::Direction::Up;
                    }
                    else if  (m_Arrow_Left[Character::GetIndex(NewX,NewY)]->GetVisibility())
                    {
                        direction=Model::Direction::Left;
                    }
                    else if  (m_Arrow_Right[Character::GetIndex(NewX,NewY)]->GetVisibility())
                    {
                        direction=Model::Direction::Right;
                    }
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
                    default:break;
                }
            }

        }
}

void App::CampFireUpdate()
{
    for (const auto& CampFire: m_CampFire)
    {
        if (!CampFire->GetVisibility())
        {
            continue;
        }
        CampFire->TimeUpdate(m_Ice[CampFire->GetIndex()]->GetVisibility());
        CampFire->ImageUpdate();//圖片更換  2000單位時間準備復燃 3000單位時間復燃
        if (
            abs(m_IceCream->GetPosition().x-CampFire->GetPosition().x)<40&&
            abs(m_IceCream->GetPosition().y-CampFire->GetPosition().y)<40
            )
        {
            if (CampFire->GetFired())//如果著火，且主角碰到他，就死亡
            {
                m_IceCream->SetVisible(false);
            }
        }
    }
}

void App::BlockUpdate()
{
    for (const auto& Block:m_IceBlock)
    {
        if (!Block->GetVisibility())
        {
            continue;
        }
        Block->TimeUpdate(m_Ice[Block->GetIndex()]->GetVisibility());
        if (Block->ChangeIce()&&Map[Block->GetI()][Block->GetJ()]=='.')//冷卻時間到，且沒有其他物件，就製作冰塊
        {
            m_Ice[Block->GetIndex()]->SetVisible(true);
        }
    }
    m_IceBlock[m_IceCream->GetIndex()]->ResetTimer();
    for (const auto& Block:m_FireBlock)
    {
        if (!Block->GetVisibility())
        {
            continue;
        }
        Block->TimeUpdate(m_Ice[Block->GetIndex()]->GetVisibility());
        if (Block->ChangeIce())//冷卻時間到，且冰塊存在，融化冰塊
        {
            m_Ice[Block->GetIndex()]->SetVisible(false);
        }
    }
    for (const auto& Block:m_Fire)
    {
        if (!Block->GetVisibility())
        {
            continue;
        }
        Block->TimeUpdate(Block->GetVisibility());
        if (!Block->ChangeIce())                                //如果時間到，跟冰塊一起消失
        {
            Block->SetVisible(false);
            m_Ice[Block->GetIndex()]->SetVisible(false);
        }
        if (!m_Ice[Block->GetIndex()]->GetVisibility())         //冰塊消失就不用融化了，一起消失   適用於主角在融化到一半的時候破壞冰塊
        {
            Block->ResetTimer();
            Block->SetVisible(false);
        }

    }
}

void App::MapStart()
{
    {
        for (const auto& wall : m_Wall)
        {
            if (wall->GetVisibility())
            {
                Map[wall->GetI()][wall->GetJ()]='#';
            }
        }
        for (const auto& wall : m_AirWall)
        {
            if (wall->GetVisibility())
            {
                Map2[wall->GetI()][wall->GetJ()]='A';
            }
        }

    }//Wall
    for (auto& enemy:m_Enemies)
    {
        if (enemy->GetVisibility())
        {
            Map[enemy->GetI()][enemy->GetJ()]='E';
        }
    }
    for (auto& fruit:m_Fruit)
    {
        if (fruit->GetVisibility())
        {
            Map3[fruit->GetI()][fruit->GetJ()]='F';
        }
    }
}
