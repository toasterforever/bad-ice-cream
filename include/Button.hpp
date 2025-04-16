//
// Created by User on 2025/04/07.
//

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "BackGround.hpp"
#include "Namespace_Model.hpp"
class Button : public BackGround{
public:
    explicit Button(const std::string& ImagePath,Model::ButtonStyle model);
    bool isClicked(glm::vec2 MousePosition) const;
    void SetPosition(int NewI, int NewJ);
private:
    Model::ButtonStyle model;
    std::string m_ImagePath;
};

#endif //BUTTON_HPP
