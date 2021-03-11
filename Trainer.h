#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Pokemon.h"
using namespace std;

class Trainer {
  public:
    // Parameterized constructor to create a trainer
    Trainer(string name);

    /*Try and catch a pokemon depending on the pokemon catch probability 
    * checks if there is space in the user inventory 
    * return true if the catch was succesful
    */
    bool catchPokemon(Pokemon pokemon);

    //Returns the value of member variable myPokemon (vector<Pokemon>)
    vector <Pokemon> getMyPokemon();

    //Print all the info of all the pokemon the user has
    void printMyPokemon();

    //Fight a pokemon with the pokemon chosen, return if you win
    bool fightPokemon(Pokemon pokemon);
    void run();

    /*Ask the user what pokemon he wants to fight with 
    * checks if the user makes a valide choice 
    * return if he won the fight
    */
    int choosePokemon();
    double rollDie();

    void healAll();

    private:
      // Trainer attributes
      string name;
      vector <Pokemon> myPokemon;
};
