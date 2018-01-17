#include "combatstate.h"

CombatState::CombatState(){
  combatProbability = 0;

  enemy = Npc(10,5,0,3,"orc","fluffy");

  enemy.printStats();

  choices[ATTACK_OPTION] = "Attack the enemy.";
  choices[FLEE_OPTION]   = "Try to run away.";
  choices[POWER_ATTACK_OPTION] = "Swing wildly.";
};

void CombatState::printOptions() {
  printw("The enemy prepares to attack!\n");
  for(auto i = choices.begin(); i != choices.end(); ++i){
    printw("%d. %s\n", i->first, i->second.c_str());
  }
};

void CombatState::handleInput(int choice, std::stack<GameState*>& stack, Player& p) {
  GameState* tmpState;

  switch(choice){
    case ATTACK_OPTION:
      printw("You attack the enemy...\n");
      p.attack(enemy);
      if (enemy.isDead()){
        printw("The enemy is dead!\n");
        // TODO: state to loot the body(s)?
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
        return;
      }

      printw("The enemy attacks you...\n");
      enemy.attack(p);
      if (p.isDead()){
        // TODO: endGameState
        printw("You have died :(\n");
        endwin();
        exit(0);
      }
      break;
    case FLEE_OPTION:
      printw("You attempt to flee from the fight...\n");
      if (rand()%100 + 1 > 50){
        printw("You successfully retreat from the fight...\n");
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
      } else {
        printw("You could not escape, and the enemy attacks you!\n");
        enemy.attack(p);
      }
      break;
    case POWER_ATTACK_OPTION:
      printw("You swing wildly!\n");
      p.powerAttack(enemy);
      if (enemy.isDead()){
        printw("The enemy is dead!\n");
        // TODO: state to loot the body(s)?
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
        return;
      }

      printw("The enemy attacks you...\n");
      enemy.attack(p);
      if (p.isDead()){
        // TODO: endGameState
        printw("You have died :(\n");
        endwin();
        exit(0);
      }
    default:
      break;
  };

  p.printStats();
  enemy.printStats();
};

