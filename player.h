#ifndef PLAYER_H
#define PLAYER_H

#include "livingentity.h"
#include "display.h"

class Player : public LivingEntity {
  private:
  protected:
  public:
    Player();
    Player(int, int, int, int, std::string, std::string);
    virtual ~Player();
    void printInventory();
};

#endif
