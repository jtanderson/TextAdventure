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
  wprintw(Display::text_win, "The enemy prepares to attack!\n");
  for(auto i = choices.begin(); i != choices.end(); ++i){
    wprintw(Display::text_win, "%d. %s\n", i->first, i->second.c_str());
  }
};

void CombatState::handleInput(int choice, std::stack<GameState*>& stack, Player& p) {
  GameState* tmpState;

  switch(choice){
    case ATTACK_OPTION:
      wprintw(Display::text_win, "You attack the enemy...\n");
      p.attack(enemy);
      if (enemy.isDead()){
        wprintw(Display::text_win, "The enemy is dead!\n");
        // TODO: state to loot the body(s)?
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
        return;
      }

      wprintw(Display::text_win, "The enemy attacks you...\n");
      enemy.attack(p);
      if (p.isDead()){
        // TODO: endGameState
        wprintw(Display::text_win, "You have died :(\n");
        endwin();
        exit(0);
      }
      break;
    case FLEE_OPTION:
      wprintw(Display::text_win, "You attempt to flee from the fight...\n");
      if (rand()%100 + 1 > 50){
        wprintw(Display::text_win, "You successfully retreat from the fight...\n");
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
      } else {
        wprintw(Display::text_win, "You could not escape, and the enemy attacks you!\n");
        enemy.attack(p);
      }
      break;
    case POWER_ATTACK_OPTION:
      wprintw(Display::text_win, "You swing wildly!\n");
      p.powerAttack(enemy);
      if (enemy.isDead()){
        wprintw(Display::text_win, "The enemy is dead!\n");
        // TODO: state to loot the body(s)?
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
        return;
      }

      wprintw(Display::text_win, "The enemy attacks you...\n");
      enemy.attack(p);
      if (p.isDead()){
        // TODO: endGameState
        wprintw(Display::text_win, "You have died :(\n");
        endwin();
        exit(0);
      }
    default:
      break;
  };

  p.printStats();
  enemy.printStats();
};

