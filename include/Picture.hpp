//
// Created by User on 2025/04/17.
//

#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "Util/GameObject.hpp"
#define cellSize 60
class Picture : public Util::GameObject {
public:


    explicit Picture(const std::string& ImagePath);

    Picture(const Picture&) = delete;

    Picture(Picture&&) = delete;

    Picture& operator=(const Picture&) = delete;

    Picture& operator=(Picture&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const int newI, const int newJ);

    void SetPosition(const glm::vec2& newPosition);

    void SetPosition(const int newX);

    void SetVisibility(const bool newVisibility);

    void ResetPosition()
    {
        m_Transform.translation = glm::vec2(0,0);
    }

private:

    std::string m_ImagePath;

};
#endif //PICTURE_HPP
