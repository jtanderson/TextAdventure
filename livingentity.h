#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include <string>
#include "entity.h"
#include "display.h"

class LivingEntity : public Entity {
  protected:
    int hp_max = 0;
    int hp_curr = 0;
    int atk_mod = 0;
    int armor = 0;
    int dmg = 0;
    std::string type;
    std::string name;
    // TODO: inventory
    Inventory inv;
    
  public:
    LivingEntity();
    LivingEntity(int, int, int, int, std::string, std::string);
    virtual ~LivingEntity();
    virtual void printStats();
    void attack(LivingEntity&);
    void powerAttack(LivingEntity&);
    bool isDead();
    void heal(int);
};

#endif
