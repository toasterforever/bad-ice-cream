#ifndef MAINCHARACTER_HPP
#define MAINCHARACTER_HPP

#include <vector>
#include <string>

#include "Character.hpp"
#include "Util/Input.hpp"

class MainCharacter : public Character
{
public:
    explicit MainCharacter(const std::string& ImagePath);

    void UpdateMovement(std::vector<Util::Keycode> keyOrder);

    bool TowardHasThings(int NewI, int NewJ) override;

    virtual bool IsitIce(int NewI, int NewJ);
private:

};

















#endif //MAINCHARACTER_HPP
