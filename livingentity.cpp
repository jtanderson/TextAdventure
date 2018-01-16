#include "entity.h"

LivingEntity::LivingEntity() {};

// TODO: consider our life choices with giant parameter lists... maybe use structs... would help with save games
LivingEntity::LivingEntity(int h, int a, int ar, int d, std::string t, std::string n) : hp_max(h), hp_curr(h), atk_mod(a), armor(ar), dmg(d), type(t), name(n) {};

LivingEntity::~LivingEntity(){};

bool LivingEntity::isDead(){
  return hp_curr <= 0;
};

void LivingEntity::heal(int h){
  hp_curr = std::min(hp_curr+h, hp_max);
};

void LivingEntity::printStats(){
  std::cout << "====== STATS ======\n";
  std::cout << "Type:     "  << type << std::endl;
  std::cout << "Name:     "  << name << std::endl;
  std::cout << "HP Max:   "  << hp_max << std::endl;
  std::cout << "HP Curr:  " << hp_curr << std::endl;
  std::cout << "Atk Mod:  " << atk_mod << std::endl;
  std::cout << "Armor:    " << armor << std::endl;
  std::cout << "Damage:   " << dmg << std::endl;
  std::cout << "===================\n";
};

void LivingEntity::attack(LivingEntity& enemy){
  // TODO: D&D style combat rolls
  // TODO: text return/output
  int atk_roll = rand() % 20 + 1;

  std::cout << this->name << " rolled " << atk_roll << std::endl;

  if (atk_roll + atk_mod > enemy.armor + 10){
    std::cout << this->name << " hits " << enemy.name << std::endl;
    enemy.hp_curr -= this->dmg;
  } else {
    std::cout << this->name << " misses " << enemy.name << std::endl;
  }
};

void LivingEntity::powerAttack(LivingEntity& enemy){
    // TODO: D&D style combat rolls
    // TODO: text return/output
    int atk_roll = rand() % 20 - 2;
    std::cout << this->name << " rolled " << atk_roll << std::endl;

    if (atk_roll + atk_mod > enemy.armor + 10){
        std::cout << this->name << " managed to hit " << enemy.name << " with a wild strike!" << std::endl;
        enemy.hp_curr -= this->dmg + 3;
     }
    else {
        std::cout << this->name << " misses " << enemy.name << std::endl;
    }
};
