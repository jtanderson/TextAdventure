#ifndef PLAYER_H
#define PLAYER_H

#include "livingentity.h"
#include "display.h"
#include <utility> // pair

class Player : public LivingEntity {
  private:
    std::pair<int, int> map_loc;
  protected:
  public:
    Player();
    Player(int, int, int, int, std::string, std::string);
    virtual ~Player();
    void printInventory();
    std::pair<int,int> getPos();
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
};

#endif
