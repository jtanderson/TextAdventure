#ifndef IDLESTATE_H
#define IDLESTATE_H

#include<iostream>
#include<stdlib.h>
#include "gamestate.h"
#include "player.h"
#include "travelstate.h"

class IdleState : public GameState {
  private:
    enum Choices {
      CONTINUE_OPTION = '1',
      LEAVE_OPTION    = '2'
    };

  public:
    IdleState();
    ~IdleState();

    void printOptions() override;

    void handleInput(int,std::stack<GameState*>&,Player&,World&) override;
};

#endif
