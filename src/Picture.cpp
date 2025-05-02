//
// Created by User on 2025/04/17.
//
#include "Picture.hpp"
#include "Util/Image.hpp"
Picture::Picture(const std::string& ImagePath, Model::PicureSource Model){
    SetImage(ImagePath);
    m_Source=Model;

}

void Picture::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Picture::SetVisibility(const bool newVisibility)
{
    m_Visible=newVisibility;
}

void Picture::SetPosition(const int newI, const int newJ)
{
    if (m_Source==Model::PicureSource::Locked)
    {
        auto const NewPosition = glm::vec2(newI*110-220,newJ*-90+180+50);
        SetPosition(NewPosition);
    }
    else
    {
        m_Transform.translation = glm::vec2(-330+(cellSize*newI),330-(cellSize*newJ));
    }

}

void Picture::SetPosition(const glm::vec2& newPosition)
{
    m_Transform.translation = newPosition;
}

void Picture::SetPosition(const int newX)
{
    m_Transform.translation = glm::vec2(-330+cellSize*newX,-330);
}