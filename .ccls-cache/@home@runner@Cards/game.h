#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class cartes {
  string _nom;
  int _va; //valeur d'attaque
  int _vd; //valeur de defense
  int _vm; //valeur puissance magique

public:
    cartes();
    cartes(string,int,int,int);
    afflong();
    affco
};

#endif