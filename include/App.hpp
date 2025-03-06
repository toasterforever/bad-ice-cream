#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        PAUSE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:
    enum class Phase {
        CHANGE_CHARACTER_IMAGE,
        ABLE_TO_MOVE,
        COLLIDE_DETECTION,
        BEE_ANIMATION,
        OPEN_THE_DOORS,
        COUNTDOWN,
    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::CHANGE_CHARACTER_IMAGE;

    Util::Renderer m_Root;

    std::shared_ptr<AnimatedCharacter> m_IceCream;
    std::shared_ptr<Character> m_Fruit;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_Enemies_1;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_Enemies_2;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_Enemies_3;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_Enemies_4;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_Enemies_5;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_Enemies_6;

    std::vector<std::shared_ptr<Character>> m_Ice;

    std::shared_ptr<PhaseResourceManger> m_PRM;

    bool m_EnterDown = false;
};

#endif
