#include "player.h"

Player::Player() : LivingEntity(20,0,10,5,"","") {
  map_loc = std::make_pair(0,0);
};

Player::Player(int h, int a, int d, int dd, std::string t, std::string n) :
  LivingEntity(h,a,d,dd,t,n) {
};

Player::~Player(){};

void Player::printInventory(){
  inv.display();
};

void Player::lootItem() {
  int newGold = rand() % 10;
  inv.addGold(newGold);

  Item newItem;
  inv.addItem(newItem);
}

std::pair<int,int> Player::getPos(){
  return map_loc;
}

void Player::move(int d){
  map_loc = Util::getSide(map_loc,d);
}
