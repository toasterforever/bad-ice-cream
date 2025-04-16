//
// Created by User on 2025/03/28.
//

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class BackGround : public Util::GameObject{
public:
    explicit BackGround(const std::string& ImagePath);

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void ResetPosition() { m_Transform.translation = {0, 0}; }

    void SetPosition(const glm::vec2& vec) { m_Transform.translation = vec; }

private:

    std::string m_ImagePath;
};

#endif //BACKGROUND_HPP
