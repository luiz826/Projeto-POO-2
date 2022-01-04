#include <iostream>
#include "monster.h"
#include "trainer.h"
#include "game.h"
#include "fileHandler.h"

using namespace std;

int main(void) 
{
  
  /*Definição de structs de ataque(nome, tipo, dano)*/
  struct Atack av, av1, av2, av3;
      
       /*Atacks */
   av.name = "tackle";
   av.type_ = "normal";
   av.damage = 40;

   av1.name = "ember";
   av1.type_ = "fire";
   av1.damage = 40;

   av2.name = "water_gun";
   av2.type_ = "water";
   av2.damage = 40;

   av3.name = "vine_whip";
   av3.type_ = "grass";
   av3.damage = 45;

     /*Pokemons*/
   /*name, hp, atack, defense, speed, type, advantage, disadvantage, is_user(1 user/ 0 opp)*/
   Monster squirtle = Monster("squirtle", 44*2, 24, 33, 22, "water", "fire", "grass");
   Monster charmander = Monster("charmander", 39*2, 26, 22, 33, "fire","grass","water");
   Monster bulbassaur = Monster("bulbassaur", 45*2, 25, 25, 23, "grass","water","fire");

   /*Seleção de ataques*/
   squirtle.set_atacks(av,av2);
   charmander.set_atacks(av,av1);
   bulbassaur.set_atacks(av,av3);

   Monster team1[] = {squirtle,charmander,bulbassaur};
  
   Trainer red("red",team1);

   Game game(red, 1);
   while (1)
   {
     if (!game.menu())
     {
       break;
     } else
     {
     game.iteration();
     }
   } 

  return 0;
}