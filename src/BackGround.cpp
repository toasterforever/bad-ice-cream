//
// Created by User on 2025/03/28.
//
#include "BackGround.hpp"
BackGround::BackGround(const std::string& ImagePath) {
    SetImage(ImagePath);

}

void BackGround::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}