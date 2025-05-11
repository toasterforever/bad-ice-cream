//
// Created by User on 2025/05/02.
//

#ifndef TEXT_HPP
#define TEXT_HPP

#include "spdlog/spdlog.h"
#include "Util/GameObject.hpp"
#include "Util/Color.hpp"
#include "Util/Text.hpp"

class Text :public Util::GameObject
{
    public:
        Text(std::string& text,int a) : GameObject(
        std::make_unique<Util::Text>(GA_RESOURCE_DIR"/Font/Inkfree.ttf", 55,
                                     text,
                                     Util::Color(0,100,150,200)),
                                     100) {
            SetPosition(a);
            m_UtilText = std::dynamic_pointer_cast<Util::Text>(this->m_Drawable);

        }

        void SetPosition(glm::vec2& position)
        {

            m_Transform.translation=position;
        }

        void SetPosition(int I)
        {
            m_Transform.translation = glm::vec2(-320+cellSize*I,-350);
        }
        glm::vec2 GetPosition() const
        {
            return m_Transform.translation;
        }

        void SetText(const std::string &text) {

            if (m_UtilText) {
                m_UtilText->SetText(text);
            } else {
                std::cout<<"Error null"<<std::endl;
            }
        }
    private:
        std::shared_ptr<Util::Text> m_UtilText=nullptr;
};
#endif //TEXT_HPP
