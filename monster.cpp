#include <unistd.h>
#include <cstdlib> 
#include <experimental/random>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "monster.h"
#include "trainer.h"
using namespace std;

Monster::Monster()
{
  this->name = "none";
  this->hp = 0;
  this->atack = 0;
  this->defense = 0;
  this->speed = 0;
  this->type_ = "none";
  this->advantage = "none";
  this->disadvantage = "none";
}

Monster::Monster(std::string name, int hp, int atack, int defense, int speed, std::string type_, std::string advantage, std::string disadvantage)
{
  this->name = name;
  this->hp = hp;
  this->atack = atack;
  this->defense = defense;
  this->speed = speed;
  this->type_ = type_;
  this->advantage = advantage;
  this->disadvantage = disadvantage;
}

Monster::~Monster()
{
}

string Monster::get_name()
{
  return this->name;
}

int Monster::get_hp()
{
  return this->hp;
}

int Monster::get_atack()
{
  return this->atack;
}

int Monster::get_defense()
{
  return this->defense;
}

int Monster::get_speed()
{
  return this->speed;
}

string Monster::get_type()
{
  return this->type_;
}

struct Atack Monster::get_atacks(int index)
{
  return this->atacks[index];
}

void Monster::set_atacks(struct Atack a1, struct Atack a2)
{
  this->atacks[0] = a1;
  this->atacks[1] = a2;
}

void Monster::lower_hp(int value)
{
  this->hp -= value;
}


float Monster::get_advantage(string opp_monst_dis, string opp_monst_adv, int index)
{
  if (this->atacks[index].type_ == opp_monst_dis)
  {
    return 2;
  } else if (this->atacks[index].type_ == opp_monst_adv)
  {
    return 0.5;
  } else 
  {
  return 1;
  }
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////
------------------------------------------------FUNCTIONS-------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
/// TO GENERATE RANDOM NUMBERS ////
std::mt19937 rng;

int randint(int from, int to){
    return std::uniform_int_distribution<int>(from, to)(rng);
}
