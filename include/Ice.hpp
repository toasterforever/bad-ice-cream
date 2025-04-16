#ifndef ICE_HPP
#define ICE_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Wall.hpp"
#include "Character.hpp"

class Ice : public Character {
public:
    explicit Ice(const std::string& ImagePath);

    bool isCreate() const;
    bool isBroke() const;
    bool TowardHasThings(int NewI, int NewJ) override;
private:
    std::string m_ImagePath;

};

#endif //ICE_HPP
