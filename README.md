# TextAdventure

A text-based RPG meant to experiment with code abstraction and procedural content generation

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
- WorldLocation (`worldlocation.h`)
  - RoadLocation (`roadlocation.h`)
  - WildernessLocation (`wildernesslocation.h`)

## TODO

- [x] use ncurses library for user interface
   - http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html
   - [x] add some sort of map component
   - [x] add some sort of inventory/equipment/stat visualization
- [ ] More detailed map locations (road, landmarks, etc.)
- [ ] richer text/storytelling components
   - [ ] break combat messages up into individual particpants' turns
- [ ] better world generation
   - See http://www.github.com/jtanderson/MapGen for some experimental efforts
- [x] data structure to store/access world
- [ ] better, more detailed, npc system
- [ ] saving/loading
- [ ] friendly npc's
- [ ] towns/villages/etc.
- [ ] items
- [x] player inventory
- [x] combat looting
- [ ] quests?
- [ ] dungeons/buildings
- [ ] special items/abilities
- [ ] player death, game ending
- [x] logging system
