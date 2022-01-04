#include <iostream>
#include "monster.h"

#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

class Monster;
using namespace std;

struct Atack make_atacks(int n);
Monster make_monsters(int n);

#endif