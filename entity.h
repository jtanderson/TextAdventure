#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Entity {
  public:
    Entity(){};
    virtual ~Entity(){};
};

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
    
  public:
    LivingEntity();
    LivingEntity(int, int, int, int, std::string, std::string);
    virtual ~LivingEntity();
    virtual void printStats();
    void attack(LivingEntity&);
    bool isDead();
    void heal(int);
};

class Player : public LivingEntity {
  private:
  protected:
  public:
    Player();
    Player(int, int, int, int, std::string, std::string);
    virtual ~Player();
};

class Npc : public LivingEntity {
  private:
  protected:
  public:
    Npc();
    Npc(int, int, int, int, std::string, std::string);
    virtual ~Npc();
};

#endif
