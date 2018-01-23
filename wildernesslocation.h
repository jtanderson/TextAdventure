#ifndef WILDERNESSLOCATION_H
#define WILDERNESSLOCATION_H

#include "worldlocation.h"
#include "util.h"

class WildernessLocation : public WorldLocation {
  public:
    WildernessLocation(int,int);
    WildernessLocation(std::pair<int,int>);
    ~WildernessLocation();

    WorldLocation* connect(int) override;
    void addOptions(std::map<int,std::string>&) override;
    void handleInput(int, std::stack<GameState*>&, Player&, World&) override;
};

#endif
