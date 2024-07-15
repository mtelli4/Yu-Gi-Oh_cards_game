#include "jeu.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

extern vector<carte> reserve;

Joueur tj1("Yugi",25,{});
Joueur tj2("Yugi2",25,{});


Jeu::Jeu(){
  _pile = {};
  _j1 = tj1;
  _j2 = tj2;
};

Jeu::Jeu(vector<carte> pile, Joueur j1, Joueur j2){
  _pile = pile;
  _j1 = j1;
  _j2 = j2;
};

bool Jeu::fini(Joueur & vainqueur) {
  if (!_j1.estEnJeu() && !_j2.estEnJeu()){
    if(_j1.prestige()>=_j2.prestige())
      vainqueur = _j1;
    else
      vainqueur = _j2;
    return true;
  }
  else if (!_j1.estEnJeu()){
    vainqueur = _j2;
    return true;
  }
  else if(!_j2.estEnJeu()){
    vainqueur = _j1;
    return true;
  }
  return false;
};

int Jeu::vainqueur(){
  Joueur vainqueur;
  fini(vainqueur);
  if (_j1 == vainqueur)
    return 1;
  else if ( _j2 == vainqueur)
    return -1;
  else 
    return 0;
}

Jeu & Jeu::operator++() {
  _j1.jouentUneCarte(_j2);
  return *this;
};

void Jeu::afficheScores() const {
_j1.affichage();
_j2.affichage();
};

// renvoie le joueur1 et permet de le modifier
Joueur &Jeu::getJoueur1() { return _j1; }

// renvoie le joueur2 et permet de le modifier
Joueur &Jeu::getJoueur2() { return _j2; }