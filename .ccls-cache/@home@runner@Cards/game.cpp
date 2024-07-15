#include <iostream>
#include <string>
#include <stdexcept>
#include "game.h"

using namespace std;

// constructeur vide
Joueur::Joueur()
{
    cout << "Initialisation d'un joueur" << endl;
    _name = "Yugi";
    _prestige = 25;
    _pile = vector<cartes>;
}

// constructor
Joueur::Joueur(string name, int prestige, vector<cartes> pile)
{
  cout << "Initialisation d'un joueur" << endl;
  _name = name;
  _prestige = prestige;
  _pile = pile;
}