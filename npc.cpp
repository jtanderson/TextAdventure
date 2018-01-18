#include "npc.h"

Npc::Npc(){};

Npc::Npc(int h, int a, int d, int dd, std::string t, std::string n) :
  LivingEntity(h,a,d,dd,t,n) {
};

Npc::~Npc(){};
