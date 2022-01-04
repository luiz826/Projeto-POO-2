#include <iostream>
#include "monster.h"
#include "trainer.h"
#include <list>

using namespace std;

Trainer::Trainer(string name, Monster team[3]): team{team[0], team[1], team[2]}
{
  this->name = name;
  this->control = 0;
  this->len_team = 3;
  this->team[0] = team[0];
  this->team[1] = team[1];
  this->team[2] = team[2];
};

string Trainer::get_name()
{
  return this->name;
}

int Trainer::get_control()
{
  return this->control;
}
    
int Trainer::get_len_team()
{
  return this->len_team;
}

void Trainer::increase_control()
{
  this->control++; 
}
