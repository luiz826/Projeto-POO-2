#include <iostream>
#include "monster.h"
#include <stack>

#ifndef TRAINER_H_INCLUDED
#define TRAINER_H_INCLUDED

class Monster;

class Trainer
{
  private:
    std::string name;
    int control;
    int len_team;

  public:
    Monster team[3];
    Trainer();
    Trainer(std::string name, Monster team[3]);
    std::string get_name();
    int get_control();
    int get_len_team();
    void increase_control();
};

#endif