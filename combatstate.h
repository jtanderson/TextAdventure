#ifndef COMBATSTATE_H
#define COMBATSTATE_H

#include <iostream>
#include <stdlib.h>
#include "gamestate.h" // GameState
#include "entity.h" // Player, Npc

class CombatState : public GameState {
  private:
    Npc enemy;

    enum Choices {
      ATTACK_OPTION = 1,
      FLEE_OPTION   = 2
    };
  public:
    CombatState();
    void printOptions() override;
    void handleInput(std::string, std::stack<GameState*>&, Player&) override;
};

#endif
