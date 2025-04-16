
//
// Created by User on 2025/04/07.
//
#include "Button.hpp"

Button::Button(const std::string& ImagePath,const Model::ButtonStyle model= Model::ButtonStyle::NotDefined): BackGround(ImagePath),model(model)
{

}
bool Button::isClicked(glm::vec2 const MousePosition) const
{
    if (GetVisibility()){
        if (model==Model::ButtonStyle::W200H100)
        {
            if (abs(MousePosition.x-this->GetPosition().x)<=100&&abs(MousePosition.y-this->GetPosition().y)<=50)
            {
                return true;
            }
        }
        if (model==Model::ButtonStyle::W80H80)
        {
            if(abs(MousePosition.x-this->GetPosition().x)<=40&&abs(MousePosition.y-this->GetPosition().y)<=40)
            {
                return true;
            }
        }
        if (model==Model::ButtonStyle::Circle60)
        {
            if(glm::length(glm::vec2(MousePosition-GetPosition()))<=30)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}


void Button::SetPosition(const int NewI, int const NewJ)
{
    if (model==Model::ButtonStyle::W80H80)
    {
        auto const NewPosition = glm::vec2(NewI*110-220,NewJ*-90+180+50);
        BackGround::SetPosition(NewPosition);
    }

}
