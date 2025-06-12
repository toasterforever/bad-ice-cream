#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    m_LVLockedPicture[0]->Unlock();

    TurnOnInterface();//InterFace轉換判定跟初始化
    TurnOnLV();//初始化關卡

    FruitCounter();
    FruitUpdate2();//有多餘兩種水果時，讓第二階段水果顯示的函式

    CharacterUpdate();//角色判定
    InterfaceChangeFromLV();//LV換PHASE判定
    switch (m_Phase){
        case Phase::Win:
            SwitchBGM(1);break;
        case Phase::Lose:
            SwitchBGM(2);break;
        default:
            SwitchBGM(0);break;
    }//BGM

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    m_Root.Update();
}
