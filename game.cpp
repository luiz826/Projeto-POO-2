#include <unistd.h>
#include <cstdlib> 
#include <experimental/random>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "game.h"
#include "trainer.h"
#include "monster.h"
#include "fileHandler.h"

using namespace std;

/////////////////////// GAME //////////////////////

Game::Game(Trainer tr1, int mode) : t1(tr1)
{
  this->t1 = tr1;
  this->mode = mode;
}

int Game::menu()
{
  int op, op_mode;
  const int ERROR_NUM = 4;
  cout << "Menu" << endl;
  try
  {
    cout << "1 - Play" << endl;
    cout << "2 - Exit Game" << endl;
    cout << "Choose an option: ";
    cin >> op;
    if (op != 1 && op != 2)
    {
      throw ERROR_NUM;
    } 
  }
  catch (int error)
  {
    if (error == ERROR_NUM)
    {
      cout << "Invalid option! please type 1 to select ""Play"" or 2 to ""Exit Game""." << endl;
    }
  }    


  if (op == 1)
  {
    try
    {
      cout << endl << "Modes" << endl;
      cout << "1 - Versus" << endl << "2 - Tournament" << endl;
      cout << endl << "Choose the mode: ";
      cin >> op_mode;
      if (op_mode != 1 && op_mode != 2)
      {
        throw ERROR_NUM;
      }
      else
      {
        this->mode = op_mode;
        return this->mode;
      }
    } 
    catch (int error)
    {
      if (error == ERROR_NUM)
      {
        cout << "Invalid option! please type 1 to select Versus mode or 2 to select Tournament Mode." << endl;
      }
    }
  } else 
  {
    return 0;
  }
  return 0;
}

int Game::battle(Trainer t1, Trainer t2) 
{
  const int ERROR_NUM = 4;
  while (1)
  {
    struct Atack trainer_atack;
    struct Atack opponent_atack;
    srand((unsigned)time(0)); 
    int ind, opp_dam, train_dam, i=0, ind_opp = randint(0,1);
    
    cout << endl << "\t\t";
    for(int j=t1.get_control(); j < t1.get_len_team(); j++) { cout << "*";}
    cout << " " << t1.get_name() << " - X - " << t2.get_name() << " ";
    for(int k=t2.get_control(); k < t2.get_len_team(); k++) { cout << "*";}
    cout << endl;

    cout << "\n\t\t\t\t\t\t\t\t" << t2.team[t2.get_control()].get_name() << " - " <<  t2.team[t2.get_control()].get_hp();

    cout << "\n\n\t\t\t\t\t" << " X " << endl;
    
    cout << "\n\n" << t1.team[t1.get_control()].get_name() << " - " << t1.team[t1.get_control()].get_hp() << endl;
    

    for (i=0; i<2; i++)
    {
      cout <<"\n"<< i << " - " <<t1.team[t1.get_control()].get_atacks(i).name;
    }
    i = 0;
    try 
    {
      cout << "\n\tChoose atack: ";
      cin >> ind;
      cout <<"\n";
      if (ind != 0 && ind != 1)
      {
        throw ERROR_NUM;
      }
    }
    catch (int error)
    { 
      if(error == ERROR_NUM)
      {
        cout << "Invalid option! please type 0 to select first atack or 1 to select second atack." << endl;
      }
    }
    


    trainer_atack = t1.team[t1.get_control()].get_atacks(ind);
    opponent_atack = t2.team[t2.get_control()].get_atacks(ind_opp);

    opp_dam = (opponent_atack.damage + t2.team[t2.get_control()].get_atack() -t1.team[t1.get_control()].get_defense()) * (t2.team[t2.get_control()].get_advantage(t1.team[t1.get_control()].disadvantage, t1.team[t1.get_control()].advantage, ind_opp));

    if (opp_dam < 0)
    {
      opp_dam = 0;
    }

    train_dam = (trainer_atack.damage + t1.team[t1.get_control()].get_atack() - t2.team[t2.get_control()].get_defense()) * (t1.team[t1.get_control()].get_advantage(t2.team[t2.get_control()].disadvantage, t2.team[t2.get_control()].advantage, ind));
    
    if (train_dam < 0)
    {
      train_dam = 0;
    }

    
    if(t1.team[t1.get_control()].get_speed() >= t2.team[t2.get_control()].get_speed())
    {
      cout<<t1.team[t1.get_control()].get_name()<<" is most faster."<<"\n"<<endl;
      sleep(1);

      cout<<t1.team[t1.get_control()].get_name()<<" atacks with "<<trainer_atack.name<<".\n"<<endl;
      sleep(1);

      cout<<t2.team[t2.get_control()].get_name()<<" atacks with "<<opponent_atack.name<<".\n"<<endl;
      sleep(1);

      // Advantage and disadvantage
      if (t1.team[t1.get_control()].get_advantage(t2.team[t2.get_control()].disadvantage, t2.team[t2.get_control()].advantage, ind) == 2) 
      { 
        cout << t1.team[t1.get_control()].get_name() <<" was supper effective." << endl;
        sleep(1);
      } 
      else if (t1.team[t1.get_control()].get_advantage(t2.team[t2.get_control()].disadvantage,t2.team[t2.get_control()].advantage, ind) == 0.5)
      { 
        cout << t1.team[t1.get_control()].get_name() <<" was not effective.\n" << endl;
        sleep(1);
      } 

      // Advantage and disadvantage
      if (t2.team[t2.get_control()].get_advantage(t1.team[t1.get_control()].disadvantage, t1.team[t1.get_control()].advantage, ind_opp) == 2)
      { 
        cout << t2.team[t2.get_control()].get_name() <<" was supper effective." << endl;
        sleep(1);
      } 
      else if (t2.team[t2.get_control()].get_advantage(t1.team[t1.get_control()].disadvantage, t1.team[t1.get_control()].advantage, ind_opp) == 0.5) 
      { 
        cout << t2.team[t2.get_control()].get_name() <<" was not effective.\n" << endl;
        sleep(1);
      } 

      cout << endl;
  
      t2.team[t2.get_control()].lower_hp(train_dam);
      cout<<t2.team[t2.get_control()].get_name()<<" receive a damage of " <<train_dam<<".\n"<<endl;
      sleep(1);
  
      t1.team[t1.get_control()].lower_hp(opp_dam);
      cout<<t1.team[t1.get_control()].get_name()<<" receive a damage of " <<opp_dam<<".\n"<<endl;
      sleep(1);

      if (t2.team[t2.get_control()].get_hp() <= 0)
      {
        cout << endl << t2.team[t2.get_control()].get_name() << " is out of combat." << endl;
        sleep(1);

        t2.increase_control();
        
        if (t2.get_control() == t2.get_len_team())
        {
          cout << endl << "Trainer won" << endl;
          return 1;
        }
      }

      if (t1.team[t1.get_control()].get_hp() <= 0)
      {
        cout << endl << t1.team[t1.get_control()].get_name() << " is out of combat." << endl;
        sleep(1);
        
        
        t1.increase_control();

        if (t1.get_control() == t1.get_len_team())
        {
          cout << endl << "Opponent won" << endl;
          return 0;
        }
      }

    } 
    else 
    {
      cout<<t2.team[t2.get_control()].get_name()<<" is most faster."<<"\n"<<endl;
      sleep(1);

      cout<<t2.team[t2.get_control()].get_name()<<" atacks with "<<opponent_atack.name<<".\n"<<endl;
      sleep(1);

      cout<<t1.team[t1.get_control()].get_name()<<" atacks with "<<trainer_atack.name<<".\n"<<endl;
      sleep(1); 

       // Advantage and disadvantage
      if (t2.team[t2.get_control()].get_advantage(t1.team[t1.get_control()].disadvantage, t1.team[t1.get_control()].advantage, ind_opp)== 2)
      { 
        cout << t2.team[t2.get_control()].get_name() <<" was supper effective." << endl;
        sleep(1);
      } 
      else if (t2.team[t2.get_control()].get_advantage(t1.team[t1.get_control()].disadvantage, t1.team[t1.get_control()].advantage, ind_opp) == 0.5) 
      { 
        cout << t2.team[t2.get_control()].get_name() <<" was not effective.\n" << endl;
        sleep(1);
      } 

      // Advantage and disadvantage
      if (t1.team[t1.get_control()].get_advantage(t2.team[t2.get_control()].disadvantage, t2.team[t2.get_control()].advantage, ind) == 2) 
      { 
        cout << t1.team[t1.get_control()].get_name() <<" was supper effective." << endl;
        sleep(1);
      } 
      else if (t1.team[t1.get_control()].get_advantage(t2.team[t2.get_control()].disadvantage,t2.team[t2.get_control()].advantage, ind) == 0.5)
      { 
        cout << t1.team[t1.get_control()].get_name() <<" was not effective.\n" << endl;
        sleep(1);
      } 

      cout << endl;


      t1.team[t1.get_control()].lower_hp(opp_dam);
      cout<<t1.team[t1.get_control()].get_name()<<" receive a damage of " <<opp_dam<<".\n"<<endl;
      sleep(1);
      
      t2.team[t2.get_control()].lower_hp(train_dam);
      cout<<t2.team[t2.get_control()].get_name()<<" receive a damage of " <<train_dam<<".\n"<<endl;
      sleep(1);
   

      if (t1.team[t1.get_control()].get_hp() <= 0)
      {
        cout << endl << t1.team[t1.get_control()].get_name() << " is out of combat." << endl;
        sleep(1);
        //control_t1++;
        t1.increase_control();

        if (t1.get_control() == t1.get_len_team())
        {
          cout << endl << "Opponent won" << endl;
          return 0;
        }
      }

      if (t2.team[t2.get_control()].get_hp() <= 0)
      {
        cout << endl << t2.team[t2.get_control()].get_name() << " is out of combat." << endl;
        sleep(1);
      
        t2.increase_control();
        
        if (t2.get_control() == t2.get_len_team())
        {
          cout << endl << "Trainer won" << endl;
          return 1;
        }
      }

    }
    sleep(1);

  }
}

void Game::iteration() 
{
  int N_OF_ATACKS = 15;
  int N_OF_MONSTERS = 14;
  int N_OF_TEAMS = 10;
  
  Monster monsters[N_OF_MONSTERS];
  for (int i = 1; i < N_OF_MONSTERS; i++)
  {
    
    monsters[i-1] = make_monsters(i);
  }
  
  struct Atack atacks[N_OF_ATACKS];
  for (int i = 1; i < N_OF_ATACKS; i++)
  {
    atacks[i-1] = make_atacks(i);
  }

  int count = 1;
  for(int i = 0; i < N_OF_MONSTERS; i++)
  {
    monsters[i].set_atacks(atacks[0], atacks[count]);
    count++;
  }

  Monster teams[][3] = {{monsters[12], monsters[3], monsters[9]},
                          {monsters[1], monsters[2], monsters[11]}, 
                          {monsters[6], monsters[5], monsters[11]}, 
                          {monsters[1], monsters[7], monsters[6]}, 
                          {monsters[8], monsters[5], monsters[4]}, 
                          {monsters[5], monsters[6], monsters[2]}, 
                          {monsters[4], monsters[9], monsters[1]}, 
                          {monsters[9], monsters[1], monsters[4]}, 
                          {monsters[2], monsters[2], monsters[2]}, 
                          {monsters[3], monsters[3], monsters[4]} 
                          };


  Trainer oponents[]  = {Trainer("stephan", teams[0]),
                        Trainer("cameron", teams[1]), 
                        Trainer("ritchie", teams[2]), 
                        Trainer("harrison", teams[3]), 
                        Trainer("trevor", teams[4]), 
                        Trainer("alain", teams[5]), 
                        Trainer("virgil", teams[6]), 
                        Trainer("sawyer", teams[7]), 
                        Trainer("bea", teams[8]), 
                        Trainer("blue", teams[9])};

  if(this->mode == 1) // Versus
  {
    std::string opp;
    cout << "Versus Mode" << endl << endl;
    sleep(1);

    // Escolha do usuario 
    for (int i=0; i<N_OF_TEAMS; i++)
    {
      cout << oponents[i].get_name() << endl;
    }
    cout << "Choose your opponent: ";
    cin >> opp;
    sleep(1);

    if (opp == oponents[0].get_name())
    {
      battle(this->t1, oponents[0]);
    } else if (opp == oponents[1].get_name())
    {
      battle(this->t1, oponents[1]);
    } else if (opp == oponents[2].get_name())
    {
      battle(this->t1, oponents[2]);
    } else if (opp == oponents[3].get_name())
    {
      battle(this->t1, oponents[3]);
    } else if (opp == oponents[4].get_name())
    {
      battle(this->t1, oponents[4]);
    } else if (opp == oponents[5].get_name())
    {
      battle(this->t1, oponents[5]);
    } else if (opp == oponents[6].get_name())
    {
      battle(this->t1, oponents[6]);
    } else if (opp == oponents[7].get_name())
    {
      battle(this->t1, oponents[7]);
    } else if (opp == oponents[8].get_name())
    {
      battle(this->t1, oponents[8]);
    } else if (opp == oponents[9].get_name())
    {
      battle(this->t1, oponents[9]);
    } else 
    {
      cout << "This trainer doesn't exist" << endl << endl;
    }

    sleep(1);
    cout << endl << "End of versus mode!" << endl << endl;
    sleep(3);

  } else if (this->mode == 2) //Tournament
  {
    cout << "Tournament Mode" << endl << endl;
    sleep(1);
    cout << endl << "first battle: " << this->t1.get_name() << " x " << oponents[0].get_name() << endl << endl;
    sleep(2);
    if (battle(this->t1, oponents[0])) 
    {
      sleep(1);
      cout << endl << "second battle: " << this->t1.get_name() << " x " << oponents[3].get_name() << endl << endl;
      sleep(2);
      if (battle(this->t1, oponents[3]))
      {
        sleep(1);
        cout << endl << "third battle: " << this->t1.get_name() << " x " << oponents[6].get_name() << endl << endl;
        sleep(2);
        if (battle(this->t1, oponents[6]))
        {
          sleep(1);
          cout << endl << "final battle: " << this->t1.get_name() << " x " << oponents[9].get_name() << endl << endl;
          sleep(2);
          if (battle(this->t1, oponents[9]))
          {
            sleep(1);
            cout << endl << "Congratulations, you won the tournament!" << endl;
            sleep(3);
          } else{sleep(1); cout << "Game over!" << endl << endl;}
        } else{sleep(1); cout << "Game over!" << endl << endl;}
      } else{sleep(1); cout << "Game over!" << endl << endl;}
    } else{sleep(1); cout << "Game over!" << endl << endl;}

    sleep(1);
    cout << endl << "End of tournament mode!" << endl << endl;
    sleep(3);
  }
}
