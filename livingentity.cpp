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
  wprintw(Display::text_win, "====== STATS ======\n");
  wprintw(Display::text_win, "Type:     %s\n", type.c_str());
  wprintw(Display::text_win, "Name:     %s\n", name.c_str());
  wprintw(Display::text_win, "HP Max:   %d\n", hp_max);
  wprintw(Display::text_win, "HP Curr:  %d\n", hp_curr);
  wprintw(Display::text_win, "Atk Mod:  %d\n", atk_mod);
  wprintw(Display::text_win, "Armor:    %d\n", armor);
  wprintw(Display::text_win, "Damage:   %d\n", dmg);
  wprintw(Display::text_win, "===================\n");
};

void LivingEntity::attack(LivingEntity& enemy){
  // TODO: D&D style combat rolls
  // TODO: text return/output
  int atk_roll = rand() % 20 + 1;

  wprintw(Display::text_win, "%s rolled %d\n", this->name.c_str(), atk_roll);

  if (atk_roll + atk_mod > enemy.armor + 10){
    wprintw(Display::text_win, "%s hits %s\n", this->name.c_str(), enemy.name.c_str());
    enemy.hp_curr -= this->dmg;
  } else {
    wprintw(Display::text_win, "%s misses %s\n", this->name.c_str(), enemy.name.c_str());
  }
};

void LivingEntity::powerAttack(LivingEntity& enemy){
    // TODO: D&D style combat rolls
    // TODO: text return/output
    int atk_roll = rand() % 20 - 2;
    wprintw(Display::text_win, "%s rolled %d.\n", this->name.c_str(), atk_roll);

    if (atk_roll + atk_mod > enemy.armor + 10){
        wprintw(Display::text_win, "%s managed to hit %s.\n", this->name.c_str(), enemy.name.c_str());
        enemy.hp_curr -= this->dmg + 3;
     }
    else {
        wprintw(Display::text_win, "%s misses %s.\n", this->name.c_str(), enemy.name.c_str());
    }
};
