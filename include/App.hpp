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

    void TurnOffLevel();
    void TurnOffButton();
    void TurnOffLevelButton();

    void TurnOnLV();
    void TurnOnInterface();
    void ChangeFromLV();

    void LVUpdate();

    void SwitchBGM(size_t newIndex)
    {
        if (newIndex>=m_BGM.size()||newIndex==m_CurrentBGMIndex)
        {
            return;
        }
        m_BGM[m_CurrentBGMIndex]->Pause();
        m_CurrentBGMIndex = newIndex;
        m_BGM[m_CurrentBGMIndex]->Play();
    }

    void ExchangePhase()
    {
        Phase const phase=m_Phase;
        m_Phase=m_LastPhase;
        m_LastPhase=phase;
    }




    std::chrono::steady_clock::time_point lastIceTime;  // 記錄上次創建冰的時間
    std::chrono::steady_clock::time_point lastMouseTime;  // 記錄上次按按鈕的時間
    const std::chrono::milliseconds cooldownTime{300};
    const std::chrono::milliseconds cooldownMouseTime{300};
private:

    enum class Phase {
        Start,
        Manu,
        Help,
        //Pause,
        LV01,LV02,LV03,LV04,LV05,
        LV06,LV07,LV08,LV09,LV10,
        LV11,LV12,LV13,LV14,LV15,
        LV16,LV17,LV18,LV19,LV20,
        LV21,LV22,LV23,LV24,LV25,

        Win,Lose

    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::Start;
    Phase m_LastPhase = Phase::Start;

    Util::Renderer m_Root;

    std::shared_ptr<MainCharacter> m_IceCream;
    std::vector<std::shared_ptr<Fruit>> m_Fruit;
    std::vector<std::shared_ptr<Enemies>> m_Enemies_1; //第1關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_2; //第2關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_3; //第3關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_4; //第4關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_5; //第5關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_6; //第6關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_7; //第7關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_8; //第8關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_9; //第9關
    //std::vector<std::shared_ptr<Enemies>> m_Enemies_10; //第10關


    std::vector<std::shared_ptr<Ice>> m_Ice;
    std::vector<std::shared_ptr<Floor>> m_Floor;
    std::vector<std::shared_ptr<Wall>> m_Wall;

    int m_CurrentBGMIndex = 0;
    std::vector<std::shared_ptr<BackGround>> m_BackGround;
    std::vector<std::shared_ptr<BGM>> m_BGM;

    std::vector<std::shared_ptr<Button>> m_Button;
    std::vector<std::shared_ptr<Button>> m_Level;

    std::vector<std::shared_ptr<Picture>> m_FruitPicture;
    std::vector<std::shared_ptr<Picture>> m_LVLockedPicture;

    std::vector<std::shared_ptr<Text>> m_Texts;


};

#endif
