#ifndef NPC_H
#define NPC_H

#include "livingentity.h"
#include "display.h"

class Npc : public LivingEntity {
  private:
  protected:
  public:
    Npc();
    Npc(int, int, int, int, std::string, std::string);
    virtual ~Npc();
};

#endif
