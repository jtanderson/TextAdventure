#ifndef PLAYER_H
#define PLAYER_H

#include <utility> // pair

#include "livingentity.h"
#include "display.h"
#include "util.h"

class Player : public LivingEntity {
  private:
    std::pair<int, int> map_loc;
  protected:
  public:
    Player();
    Player(int, int, int, int, std::string, std::string);
    virtual ~Player();
    void printInventory();
    void lootItem();
    std::pair<int,int> getPos();
    void move(int);
};

#endif
