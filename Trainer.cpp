#include "Trainer.h"

Trainer::Trainer(string name){
  this->name = name;
}

vector <Pokemon> Trainer::getMyPokemon(){
  return myPokemon;
}

//Catch the pokemon in param base on probability of succes, return if was catched
bool Trainer::catchPokemon(Pokemon pokemon){
  bool caught = false;
  
  if(myPokemon.size() < 6){
    if(pokemon.GetCatchProbability() > rollDie()){
      myPokemon.push_back(pokemon);
      caught = true;
    }
    else{
      cout << "You didn't catch it..." << endl;
    }
  }else{
    cout << "Your pokemon invnetory is full !" << endl;
  }
  return caught;
}

//Prints all the pokemon tu trainer has
void Trainer::printMyPokemon(){
  cout << "Hello " << name << " your current Pokemon are:\n" << endl;
  int i = 1;
  for(Pokemon p : myPokemon){
    cout << i << "- " << p.GetName() << endl;
    cout << "Level: " << p.GetLevel() << endl;
    cout << "Life points: " << p.GetLifePoints() << endl;
    cout << "Power points: " << p.GetAttackPoints() << endl << endl;
    i++;
  }
}

bool Trainer::fightPokemon(Pokemon pokemon){
  bool win = false;
  int index = choosePokemon();

  while(myPokemon.at(index).GetLifePoints() > 0){
    myPokemon.at(index).attackPokemon(pokemon);

    if(pokemon.GetLifePoints() <= 0){
      win = true;
      break;
    }else{

      pokemon.attackPokemon(myPokemon.at(index));
    }   
  }
  return win;
}

int Trainer::choosePokemon(){
  int choice = 0;
  do{
    this->printMyPokemon();
    cout << "Choose a pokemon:"  << endl;
    cin >> choice;

    if(choice > 0 && (size_t)choice < myPokemon.size() + 1){
      if(myPokemon.at(choice - 1).GetLifePoints() > 0){
        break;
      }else{
        cout << "This pokemon cannot fight (no life points left)" << endl;
      }
    }else{
      cout << "Invalid choice (must be 1 to 6)" << endl;
    }
  }while(1);
  return choice - 1;
}

void Trainer::healAll(){
  for(size_t i = 0; i < myPokemon.size(); i++){
    myPokemon.at(i).HealPokemon();
  }
}

double Trainer::rollDie(){
  srand (static_cast <unsigned> (time(0)));
  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}