//
// Created by User on 2025/05/02.
//

#ifndef TEXT_HPP
#define TEXT_HPP

#include "Util/GameObject.hpp"


class Text :public Util::GameObject
{
    public:
        Text(std::string &font, int size, const std::string &text, const Util::Color &color) :Util::Text(font, size, text, color){};
        void SetVisible(bool visible)
        {
            m_Visible = visible;
        }
        void SetPosition(glm::vec2& position)
        {
            m_Transform.translation=position;
        }
    private:
        std::unique_ptr<Core::Texture> m_Texture = nullptr;
        std::unique_ptr<TTF_Font, std::function<void(TTF_Font *)>> m_Font;

        std::string m_Text;
        Util::Color m_Color;
        glm::vec2 m_Size;
};
#endif //TEXT_HPP
