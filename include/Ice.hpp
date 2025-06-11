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

    static bool HasThings(int NewI, int NewJ);
private:
    std::string m_ImagePath;

};

#endif //ICE_HPP
