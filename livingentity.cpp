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
  printw("====== STATS ======\n");
  printw("Type:     %s\n", type.c_str());
  printw("Name:     %s\n", name.c_str());
  printw("HP Max:   %d\n", hp_max);
  printw("HP Curr:  %d\n", hp_curr);
  printw("Atk Mod:  %d\n", atk_mod);
  printw("Armor:    %d\n", armor);
  printw("Damage:   %d\n", dmg);
  printw("===================\n");
};

void LivingEntity::attack(LivingEntity& enemy){
  // TODO: D&D style combat rolls
  // TODO: text return/output
  int atk_roll = rand() % 20 + 1;

  printw("%s rolled %d\n", this->name.c_str(), atk_roll);

  if (atk_roll + atk_mod > enemy.armor + 10){
    printw("%s hits %s\n", this->name.c_str(), enemy.name.c_str());
    enemy.hp_curr -= this->dmg;
  } else {
    printw("%s misses %s\n", this->name.c_str(), enemy.name.c_str());
  }
};

