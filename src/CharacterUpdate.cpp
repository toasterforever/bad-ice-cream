//
// Created by User on 2025/06/04.
//

#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include <random>
static std::random_device rd2;   // 產生隨機種子
static std::mt19937 gen2(rd2());  // 使用 Mersenne Twister 隨機數引擎
static std::uniform_int_distribution<int> dist2(0, 99);  // 產生 0~99 的整數


void App::CharacterUpdate(){
    if (IsGaming()){
        IceCreamUpdate();
        MapUpdate();//Ice Wall AirWall
        EnemiesUpdate();
        FruitUpdate();
    }//CharacterUpdate
}

void App::IceCreamUpdate()
{

        MainCharacterPosition={m_IceCream->GetIJ()};

        KeyUpdate();

        if (!keyOrder.empty())
        {
            m_IceCream->UpdateMovement(keyOrder);

            IceUpdate();
        }

}

void App::MapUpdate()
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
}

void App::EnemiesUpdate()
{
    {

        for (const auto& enemy : m_Enemies_1) {
            if (enemy->GetVisibility())
            {
                enemy->MoveTowards();

                if (enemy->IfCollides(m_IceCream,enemy->GetPosition()))
                {
                    m_IceCream->SetVisible(false);
                }

                if (dist2(gen2) == 0||enemy->GetDirection()==Model::Direction::None)
                {
                    if (enemy->GetModel()!=Model::Move::Auto_Move)
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
            if (fruit->IfCollides(m_IceCream,fruit->GetPosition())&&fruit->GetVisibility()==true)
            {
                fruit->SetVisible(false);
                fruit->SetInGame(false);
                if (i<16)
                {
                    Fruit_Counter_Arr[0]--;
                }
                else if (i<32)
                {
                    Fruit_Counter_Arr[1]--;
                }
                else if (i<36)
                {
                    Fruit_Counter_Arr[2]--;
                }
                else if (i<40)
                {
                    Fruit_Counter_Arr[3]--;
                }
                else if (i<44)
                {
                    Fruit_Counter_Arr[4]--;
                }
                Fruit_Counter--;


            }
            if (fruit->GetModel()!=Model::Move::Dont_Move&&fruit->GetVisibility())
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

void App::KeyUpdate()
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
    if (keyOrder.front()==Util::Keycode::SPACE&&m_IceCream->GetDirection()!=Model::Direction::None&&now - lastIceTime >= cooldownTime)
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
                }

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
                }
                std::cout<<Map[1]<<std::endl<<Map[2]<<std::endl<<Map[3]<<std::endl<<Map[4]<<std::endl<<Map[5]<<std::endl;
                std::cout<<Map[6]<<std::endl<<Map[7]<<std::endl<<Map[8]<<std::endl<<Map[9]<<std::endl<<Map[10]<<std::endl;
                std::cout<<std::endl<<std::endl;
            }

        }



    if (m_Ice[m_IceCream->GetIndex()]->isCreate())
    {
        m_Ice[m_IceCream->GetIndex()]->SetVisible(false);
    }
}