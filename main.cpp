/*  Title: Pokemon Game
    Authors: Hugo, Samuel, Kishan
    Date: March 10, 2021
*/

#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"
using namespace std;

void PrintOpenMenu();
int PrintSelectionMenu();

int main() {
  
  // Helper variables
  int option1;
  char option2;
  bool battleOutcome;
  char starterOption;
  string userName;
  bool caughtResult;
  int iteratorWild = 0;
  
  // Creating starter and wild Pokemon
  Pokemon squirtle("Squirtle", 5, 20, 15, 1.0);      // Water
  Pokemon charmander("Charmander", 5, 20, 15, 1.0);  // Fire
  Pokemon bulbasaur("Bulbausaur", 5, 20, 15, 1.0);   // Grass
  Pokemon bellsprout("Bellsprout", 4, 30, 15, 0.9);  // Grass
  Pokemon slowpoke("Slowpoke", 7, 45, 15, 0.8);      // Water
  Pokemon magmar("Magmar", 10, 55, 20, 0.7);         // Fire
  Pokemon pikachu("Pikachu", 20, 100, 20, 0.4);      // Electric
  Pokemon eevee("Eevee", 25, 80, 25, 0.3);           // Normal
  Pokemon pidgey("Pidgey", 15, 60, 15, 0.6);         // Flying
  Pokemon diglett("Diglett", 30, 140, 25, 0.2);      // Ground

  // Entering the Pokemon into the wildDatabase
  vector<Pokemon> wildPokemonDatabase;
  wildPokemonDatabase.push_back(bellsprout);
  wildPokemonDatabase.push_back(slowpoke);
  wildPokemonDatabase.push_back(magmar);
  wildPokemonDatabase.push_back(pikachu);
  wildPokemonDatabase.push_back(eevee);
  wildPokemonDatabase.push_back(pidgey);
  wildPokemonDatabase.push_back(diglett);
  
  // Creating a trainer
  cout << "Please enter your name: " << endl;
  cin >> userName; 
  cout << "Hello " << userName << endl;
  Trainer trainer(userName);

  // Choosing a starter Pokemon
  cout << "Who would you like as a starter ? " << endl;
  cout << "Squirtle ('s'), Charmander('c') or Bulbausaur('b')" << endl;
  cin >> starterOption;
  if(starterOption == 's')
	trainer.catchPokemon(squirtle);
  else if(starterOption == 'c')
	trainer.catchPokemon(charmander);
  else if(starterOption == 'b')
	trainer.catchPokemon(bulbasaur);

  while(starterOption != 's' && starterOption != 'c' && starterOption != 'b'){
	  cout << "Invalid Option! Choose again:" << endl;
	  cin >> starterOption;
  }

  if(starterOption == 's')
  	trainer.catchPokemon(squirtle);
  else if(starterOption == 'c')
  	trainer.catchPokemon(charmander);
  else if(starterOption == 'b')
  	trainer.catchPokemon(bulbasaur);

  // Displaying the menu and offering the user a selection
  PrintOpenMenu();
  option1 = PrintSelectionMenu();
  while(option1 != 4){
    //Roam the wild
    if(option1 == 1){
      Pokemon firstWild = wildPokemonDatabase.at(iteratorWild);
      cout << "While roaming " << endl;
      firstWild.PrintInfo();
      cout << "Would you like to Fight him ('f') or try to catch him('c') ?" << endl;

      cin >> option2;
      while(option2 != 'f' && option2 != 'c'){
        cout << "NOT A VALID OPTION CHOOSE 'f' or 'c'" << endl;
        cin >> option2;
      }
      //Fight
      if(option2 == 'f'){
        battleOutcome = trainer.fightPokemon(firstWild);
        if(battleOutcome){
          cout << "Congratulation, you won the fight !" << endl;
          wildPokemonDatabase.erase(wildPokemonDatabase.begin() + iteratorWild);
        } else {
          cout << "You lost the fight..." << endl;
        }
      //Catch
      } else if(option2 == 'c'){
        //Verify if the player has pokeballs

        //try to catch him
        caughtResult = trainer.catchPokemon(firstWild);
        //if caught, remove the pokemon from the wild (pop_back)
        if(caughtResult){
          cout << "Congratulation, you caught it !" << endl;
          wildPokemonDatabase.erase(wildPokemonDatabase.begin() + iteratorWild);
        }
      }
      //Visit the PokeCenter
    } else if(option1 == 2){
      cout << "Welcome to the PokeCenter, let me heal your Pokemons!" << endl;
      trainer.healAll();
      //Show inventory
    } else if(option1 == 3){
      cout << "Here are your pokemons : " << endl;
      trainer.printMyPokemon();
    }
    option1 = PrintSelectionMenu();
    iteratorWild++;
  }

  // trainer.catchPokemon(bellsprout);
  // trainer.catchPokemon(slowpoke);

  // trainer.printMyPokemon();

  // trainer.catchPokemon(magmar);

  // cout << "--------------------------\n" << endl;
  // trainer.printMyPokemon();

}

void PrintOpenMenu(){
  cout << endl;
  cout << "Graphic Source: https://www.asciiart.eu/video-games/pokemon" << endl;
  cout << "                                  ,'\\" << endl;
  cout << "    _.----.        ____         ,'  _\\   ___    ___     ____" << endl;
  cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. " << endl;
  cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
  cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
  cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
  cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
  cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
  cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
  cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
  cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
  cout << "                                `'                            '-._|" << endl;
  cout << endl;

}

int PrintSelectionMenu(){

  int option;

  cout << "What would you like to do?" << endl;
  cout << "Press '1' to roam the wild" << endl;
  cout << "Press '2' to visit a Pokemon centre" << endl;
  cout << "Press '3' to show your inventory" << endl;
  cout << "Press '4' to quit the game" << endl;
  cout << "Choose an option:" << endl;
  cin >> option;

  while(option != 1 && option != 2 && option != 3 && option != 4){
    cout << "Choose an option:" << endl;
    cin >> option;
  }

  return option;
}
