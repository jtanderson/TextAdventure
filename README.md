# TextAdventure

High level design notes:
- Use pushdown-automata model for game loop
- user input handled by current game state
  - state takes ownership of player and state stack

Class hierarchy:

- GameState (`gamestate.h`) - abstract
  - CombatState (`combatstate.h`, `combatstate.cpp`)
  - TravelState (`travelstate.h`, `travelstate.cpp`)
  - IdleState (`idlestate.h`, `idlestate.cpp`)
- Entity (`entity.h`)
  - LivingEntity (`livingentity.h`, `livingentity.cpp`)
    - Player (`player.h`, `player.cpp`)
    - Npc (`npc.h`, `npc.cpp`)

## TODO

- [x] use ncurses library for user interface
   - http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html
   - [ ] add some sort of map component
   - [ ] add some sort of inventory/equipment/stat visualization
- [ ] richer text/storytelling components
   - [ ] break combat messages up into individual particpants' turns
- [ ] better world generation
- [ ] data structure to store/access world
- [ ] better, more detailed, npc system
- [ ] saving/loading
- [ ] friendly npc's
- [ ] towns/villages/etc.
- [ ] items
- [ ] player inventory
- [ ] combat looting
- [ ] quests
- [ ] dungeons/buildings
- [ ] special items/abilities
- [ ] player death, game ending
- [x] logging system
