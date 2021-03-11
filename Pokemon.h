#pragma once
#include <iostream>
using namespace std;

class Pokemon{
  public:
    // Default and parameterized constuctor for creating Pokemon
    Pokemon();
    Pokemon(string inName, int inLevel, int inLifePoints, int inPowerPoints, double catchProbability);

    // Function to attack an opposing Pokemon
    void attackPokemon(Pokemon &pokemon);
    
    // Printing Pokemon info
    void PrintInfo(); 

    // Accessors and mutators for private attributes
    string GetName();
    int GetLevel();
    int GetLifePoints();
    int GetAttackPoints();
    void SetLifePoints(int lifeP);
    float GetCatchProbability();
    void HealPokemon();

  private:
    // Pokemon attributes
    string name;
    int level;
    int lifePoints;
    int maxLifePoints;
    int attackPoints;
    float catchProbability;

};