#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "MainCharacter.hpp"
#include "Enemies.hpp"
#include "Ice.hpp"
#include "Floor.hpp"
#include "Button.hpp"
#include "Fruit.hpp"
#include "Picture.hpp"
#include "Text.hpp"
#include "BGM.hpp"
#include "CampFire.hpp"
#include "Block.hpp"

#include <chrono>

class App {
public:
    enum class State {
        START,
        UPDATE,
        //PAUSE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)
    void ExchangePhase()
    {
        Phase const phase=m_Phase;
        m_Phase=m_LastPhase;
        m_LastPhase=phase;
    }

    void TurnOffLevel();
    void TurnOffButton();
    void TurnOffLevelButton();

    void TurnOnLV();
    void TurnOnInterface();
    void InterfaceChangeFromLV();
    void LVReset();

    void CharacterUpdate();
    void IceCreamUpdate();
    void MapUpdate();
    void EnemiesUpdate();
    void FruitUpdate();
    void KeyUpdate();
    void IceUpdate();
    void CampFireUpdate();
    void BlockUpdate();

    void SwitchBGM(size_t newIndex)
    {
        if (newIndex>=m_BGM.size()||newIndex==m_CurrentBGMIndex)
        {
            return;
        }
        m_BGM[m_CurrentBGMIndex]->Pause();
        m_CurrentBGMIndex = newIndex;
        if (newIndex==0)
        {
            m_BGM[m_CurrentBGMIndex]->Play(-1);
        }
        else
        {
            m_BGM[m_CurrentBGMIndex]->Play(0);
        }
    }

    void FruitUpdate2();
    void FruitCounter();

    bool IsGaming()
    {
        return 1<=static_cast<int>(m_Phase)&&25>=static_cast<int>(m_Phase);
    }

private:

    enum class Phase {
        Start=70,
        Manu=80,
        Help=90,
        //Pause,
        LV01=1,LV02,LV03,LV04,LV05,
        LV06,LV07,LV08,LV09,LV10,
        LV11,LV12,LV13,LV14,LV15,
        LV16,LV17,LV18,LV19,LV20,
        LV21,LV22,LV23,LV24,LV25,

        Win=30,Lose=40

    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::Start;
    Phase m_LastPhase = Phase::Start;

    Util::Renderer m_Root;

    std::shared_ptr<MainCharacter> m_IceCream;
    std::vector<std::shared_ptr<Fruit>> m_Fruit;
    std::vector<std::shared_ptr<Enemies>> m_Enemies;


    std::vector<std::shared_ptr<Ice>> m_Ice;
    std::vector<std::shared_ptr<Floor>> m_Floor;
    std::vector<std::shared_ptr<Floor>> m_Arrow_Up;
    std::vector<std::shared_ptr<Floor>> m_Arrow_Left;
    std::vector<std::shared_ptr<Floor>> m_Arrow_Right;
    std::vector<std::shared_ptr<Floor>> m_Arrow_Down;
    std::vector<std::shared_ptr<Wall>> m_Wall;
    std::vector<std::shared_ptr<Wall>> m_AirWall;
    std::vector<std::shared_ptr<CampFire>> m_CampFire;
    std::vector<std::shared_ptr<Block>> m_IceBlock;
    std::vector<std::shared_ptr<Block>> m_FireBlock;
    std::vector<std::shared_ptr<Block>> m_Fire;

    int m_CurrentBGMIndex = 0;
    std::vector<std::shared_ptr<BackGround>> m_BackGround;
    std::vector<std::shared_ptr<BGM>> m_BGM;

    std::vector<std::shared_ptr<Button>> m_Button;
    std::vector<std::shared_ptr<Button>> m_Level;

    std::vector<std::shared_ptr<Picture>> m_FruitPicture;
    std::vector<std::shared_ptr<Picture>> m_LVLockedPicture;

    std::vector<std::shared_ptr<Text>> m_Texts;


    std::chrono::steady_clock::time_point lastIceTime;  // 記錄上次創建冰的時間
    std::chrono::steady_clock::time_point lastMouseTime;  // 記錄上次按按鈕的時間
    const std::chrono::milliseconds cooldownTime{300};

    int LV_Change = 0;
    int Fruit_Counter = 0;
    std::array<int, 9> Fruit_Counter_Arr;
    std::array<bool, 9> Fruit_Reset_Arr;

    std::vector<Util::Keycode> keyOrder;
    void KeyRelease(Util::Keycode key) {
        keyOrder.erase(std::remove(keyOrder.begin(), keyOrder.end(), key), keyOrder.end());
    }

};

#endif
