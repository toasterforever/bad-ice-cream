//
// Created by User on 2025/05/02.
//

#ifndef TEXT_HPP
#define TEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Color.hpp"
#include "Util/Text.hpp"

class Text :public Util::GameObject
{
    public:
        Text(std::string& text,int a) : GameObject(
        std::make_unique<Util::Text>(GA_RESOURCE_DIR"/Font/Inkfree.ttf", 55,
                                     text,
                                     m_Color=Util::Color(0,100,150,200)),
                                     100) {
            SetPosition(a);

        }

        void SetPosition(glm::vec2& position)
        {
            m_Position=position;
            m_Transform.translation=position;
        }

        void SetPosition(int I)
        {
            m_Position=glm::vec2(-300+cellSize*I,-360);
            m_Transform.translation = glm::vec2(-320+cellSize*I,-350);
        }
        glm::vec2 GetPosition() const
        {
            return m_Position;
        }

        void SetText(const std::string &text) {
            m_Text = text;
        }
    private:
        int size=20;
        std::string m_Text;
        Util::Color m_Color=Util::Color(0,255,255);
    glm::vec2 m_Position;
};
#endif //TEXT_HPP
