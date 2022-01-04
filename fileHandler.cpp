#include <iostream>
#include "monster.h"
#include "fileHandler.h"
#include <string>
#include <fstream>

using namespace std;
class Monster;

struct Atack make_atacks(int n)
{
  string result;
  struct Atack atacks; 

  ifstream f("atacks.txt");

  for(int i = 0; i < n; i++)
  {
    getline(f, result);
  }

  atacks.name = result.substr(0, 15);
  atacks.type_ = result.substr(16, 10);
  atacks.damage = stoi(result.substr(27, 2)); 

  return atacks;
}

Monster make_monsters(int n)
{
  string result;
  Monster monster; 

  ifstream f("monsters.txt");

  for(int i = 0; i < n; i++)
  {
    getline(f, result);
  }
  
  monster.name = result.substr(0, 15);
  monster.hp = stoi(result.substr(16, 3));
  monster.atack = stoi(result.substr(20, 3));
  monster.defense = stoi(result.substr(24, 3));
  monster.speed = stoi(result.substr(28, 3));
  monster.type_ = result.substr(32, 10);
  monster.advantage = result.substr(42, 10);
  monster.disadvantage = result.substr(52, 10);

  return monster;
}