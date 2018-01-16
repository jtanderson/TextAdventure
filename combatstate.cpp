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
  std::cout << "The enemy prepares to attack!\n";
  for(auto i = choices.begin(); i != choices.end(); ++i){
    std::cout << i->first << ". " << i->second << std::endl;
  }
};

void CombatState::handleInput(std::string in, std::stack<GameState*>& stack, Player& p) {
  int choice = stoi(in);
  GameState* tmpState;

  switch(choice){
    case ATTACK_OPTION:
      std::cout << "You attack the enemy...\n";
      p.attack(enemy);
      if (enemy.isDead()){
        std::cout << "The enemy is dead!\n";
        // TODO: state to loot the body(s)?
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
        return;
      }

      std::cout << "The enemy attacks you...\n";
      enemy.attack(p);
      if (p.isDead()){
        // TODO: endGameState
        std::cout << "You have died :(\n";
        exit(0);
      }
      break;
    case FLEE_OPTION:
      std::cout << "You attempt to flee from the fight...\n";
      if (rand()%100 + 1 > 50){
        std::cout << "You successfully retreat from the fight...\n";
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
      } else {
        std::cout << "You could not escape, and the enemy attacks you!\n";
        enemy.attack(p);
      }
      break;
    case POWER_ATTACK_OPTION:
      std::cout << "You swing wildly!\n";
      p.powerAttack(enemy);
      if (enemy.isDead()){
        std::cout << "The enemy is dead!\n";
        // TODO: state to loot the body(s)?
        tmpState = stack.top();
        stack.pop();
        delete tmpState;
        return;
      }

      std::cout << "The enemy attacks you...\n";
      enemy.attack(p);
      if (p.isDead()){
        // TODO: endGameState
        std::cout << "You have died :(\n";
        exit(0);
      }
    default:
      break;
  };

  p.printStats();
  enemy.printStats();
};

