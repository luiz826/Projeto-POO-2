#include <iostream>
#include "trainer.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Trainer;

class Game
{
  public:
    int mode; // 1 = Versus, 2 = Tournament
    Trainer t1;
    
    Game(Trainer tr1, int mode);
    int menu(void);
    int battle(Trainer t1, Trainer t2);
    void iteration();
};


#endif