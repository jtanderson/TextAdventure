#ifndef COMBATSTATE_H
#define COMBATSTATE_H

#include <iostream>
#include <stdlib.h>
#include "gamestate.h" // GameState
#include "player.h" // Player
#include "npc.h" // Npc

class CombatState : public GameState {
  private:
    Npc enemy;

    enum Choices {
      ATTACK_OPTION = '1',
      FLEE_OPTION   = '2',
      POWER_ATTACK_OPTION = '3'
    };
  public:
    CombatState();
    void printOptions() override;
    void handleInput(int, std::stack<GameState*>&, Player&, World&) override;
};

#endif
