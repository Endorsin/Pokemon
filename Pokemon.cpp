#include "Pokemon.h"

Pokemon::Pokemon(){
  name = "noName";
  level = -1;
  lifePoints = -1;
  attackPoints = -1;
}

Pokemon::Pokemon(string inName, int inLevel, int inLifePoints, int inAttackPoints, double inCatchProbability){
  name = inName;
  level = inLevel;
  maxLifePoints = inLifePoints;
  lifePoints = maxLifePoints;
  attackPoints = inAttackPoints;
  catchProbability = inCatchProbability;
}

void Pokemon::PrintInfo(){
  cout << "You have encountered a " << name << ", of level " << level << ", having " << lifePoints << " life points and " << attackPoints << " attack points" << endl;
}

void Pokemon::attackPokemon(Pokemon &pokemon){
  pokemon.SetLifePoints(pokemon.GetLifePoints() - this->GetAttackPoints());
  if(pokemon.GetLifePoints() < 0){
    pokemon.SetLifePoints(0);
  }
}

string Pokemon::GetName(){
  return name;
}
int Pokemon::GetLevel(){
  return level;
}
int Pokemon::GetLifePoints(){
  return lifePoints;
}
int Pokemon::GetAttackPoints(){
  return attackPoints;
}
float Pokemon::GetCatchProbability(){
  return catchProbability;
}
void Pokemon::SetLifePoints(int lifeP){
  lifePoints = lifeP;
}
void Pokemon::HealPokemon(){
  lifePoints = maxLifePoints;
}