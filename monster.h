#include <iostream>

#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

class Trainer;

struct Atack
{
  std::string name;
  std::string type_;
  int damage;
};


class Monster
{
  public:
    std::string name;
    int hp;
    int atack;
    int defense;
    int speed;
    std::string type_;
    struct Atack atacks[2];

 // public:
    std::string advantage;
    std::string disadvantage;
    Monster();
    Monster(std::string name, int hp, int atack, int defense, int speed, std::string type_, std::string advantage, std::string disadvantage);
    virtual ~Monster();
    
    std::string get_name();
    int get_hp();
    int get_atack();
    int get_defense();
    int get_speed();
    std::string get_type();
    struct Atack get_atacks(int index);
    void set_atacks(struct Atack, struct Atack);
    void lower_hp(int value);
    float get_advantage(std::string opp_monst_dis, std::string opp_monst_adv, int index);
};

void battle(Trainer t1, Trainer t2);

int randint(int from, int to);


#endif