#include "entity.h"

Player::Player() : LivingEntity(20,0,10,5,"","") {
};

Player::Player(int h, int a, int d, int dd, std::string t, std::string n) :
  LivingEntity(h,a,d,dd,t,n) {
};


Player::~Player(){};
