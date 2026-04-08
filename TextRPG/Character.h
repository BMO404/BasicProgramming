#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int level;

public:
    Character(std::string name, int health, int level);
    virtual void attack(Character &target);
    virtual void levelUp();
    // Other common character methods...
};

#endif