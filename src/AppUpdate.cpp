#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md
    if (Util::Input::IsKeyPressed(Util::Keycode::A) ||
        Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        m_IceCream->MoveLeft();
        }
    if (Util::Input::IsKeyPressed(Util::Keycode::D) ||
        Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        m_IceCream->MoveRight();
        }
    if (Util::Input::IsKeyPressed(Util::Keycode::W) ||
        Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        m_IceCream->MoveUp();
        }
    if (Util::Input::IsKeyPressed(Util::Keycode::S) ||
        Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        m_IceCream->MoveDown();
        }
    for (int i=0; i<2; i++)
    {
        m_Enemies_1.push_back(std::make_shared<AnimatedCharacter>(GA_RESOURCE_DIR"/Image/Character/door_close.png"));
    }
    // for (int i = 0; i < 3; ++i) {
    //     m_Door.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/door_close.png"));
    //     m_Door[i]->SetZIndex(5);
    //     m_Door[i]->SetPosition({205.5f - 80.f * i, -3.5f});
    //     m_Door[i]->SetVisible(false);
    //     m_Root.AddChild(m_Door[i]);
    //
    // }
    // std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) { door->SetVisible(false); });
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
