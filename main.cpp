#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Cinco.h"


int main(){
  srand(time(0));
  Cinco game;
  game.play();

  return 0;
}

