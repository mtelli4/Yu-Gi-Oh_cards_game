#include "joueur.h"
#include "cartes.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;
extern vector<carte> reserve;

vector<int> dpile = {0,1,2,3,4};

// constructeur vide
Joueur::Joueur() {
  cout << "Initialisation d'un joueur" << endl;
  _name = "Yugi";
  _prestige = 25;
  _pile = dpile;
}

// constructeur
Joueur::Joueur(string name, int prestige, vector<int> pile) {
  cout << "Initialisation d'un joueur" << endl;
  _name = name;
  _prestige = prestige;
  _pile = pile;
}


void Joueur::sonNom() const {
  cout << "Le nom du joueur est: " << _name << endl;
}

void Joueur::sonPrestige() const {
  cout << "Le joueur a " << _prestige << " points de prestige" << endl;
}

int Joueur::prestige() const {
  return _prestige;
}

void Joueur::affichage() const {
  cout << "Le joueur " << _name << " a " << _prestige << " points de prestige, il reste " << _pile.size() << " cartes dans sa pile." << endl;
}

void Joueur::initPile(const vector<carte> &reserve) {
  for (int i = 0; i < 20; i++) {
    _pile.push_back(i);
  }
}

bool Joueur::aDesCartes() const {
  return !_pile.empty();
}

bool Joueur::estEnJeu() const {
  return _prestige > 0;
}

void Joueur::carteSuiv(carte &c) {
  if (aDesCartes()) {
    c = reserve[_pile.back()];
    _pile.pop_back();
  } else {
    throw runtime_error("Le joueur n'a plus de cartes dans sa pile.");
  }
}

void Joueur::ajouterCarte(const vector<carte> &reserve, int indice) {
  _pile.push_back(indice);
}


void Joueur::jouentUneCarte(Joueur &j) {
  cout << "Debug : " << __LINE__ << endl;
  if (aDesCartes() && j.aDesCartes()) {
    int c1 = _pile.front();
    int c2 = j._pile.front();
    cout << "Debug : " << __LINE__ << endl;
    _pile.erase(_pile.begin());
    j._pile.erase(j._pile.begin());

    cout << "Debug : " << __LINE__ << endl;
    cout<< c1 << " "<< c2 << " " << reserve.size() << endl;

    const carte carte1 = reserve[c1];
    const carte carte2 = reserve[c2];
    
    int dp1 = carte1-carte2,
    dp2 = carte2-carte1,
    dm1 = carte1^carte2,
    dm2 = carte2^carte1;
    if(dp1>0)
      dp1=0;
    if(dp2>0)
      dp2=0;
    if(dm1>0)
      dm1=0;
    if(dm2>0)
      dm2=0;
    _prestige += dp2 + dm2;
    j._prestige += dp1 + dm1;
  } else {
    throw runtime_error("Un des joueurs n'a plus de cartes dans sa pile.");
  }
}

bool operator==(const Joueur & j1, const Joueur & j2){
  if (j1._name == j2._name)
    return true;
  else
    return false;
}

void Joueur::melange(){
  shuffle(_pile.begin(), _pile.end(), mt19937{random_device{}()});
}

void Joueur::affiche() {
  for (int i = 0; i < _pile.size(); i++) 
    cout << reserve[_pile[i]] << endl;
}

void Joueur::remplirPile(vector<carte> reserve) {
  // Construit le vecteur de rang en fonction de l'attaque croissante
  _pile = construitRang(reserve, 'a', '>');
  if (_pile.size() > 20) {
        _pile.erase(_pile.begin() + 20, _pile.end());
    }
}

void Joueur::fillvector() {
  cout << "Choose between the possible cards by typing the name of the card : \n";
  vector<string> nom(reserve.size());
  string c;
  for (int i = 0; i < reserve.size(); i++) {
      nom[i] = reserve[i].getnom();
    }
  for (int j=0; j<reserve.size();){
    for (int i = 0; i < nom.size(); i++) {
      cout << nom[i] << " \n";
    }
    cout << endl<<endl;
    cin >> c; //choisir la carte
    cout << endl;
    int index=0;
    bool found = false;
  
    
    while (!found && index<nom.size()) {
        

        if (nom[index] == c) {
            found = true;
            _pile.push_back(index);
            nom[index] = "";
            j++;
            break;
        }
      index++;
    }

    if (!found) {
        cout << c << " is not found or already chosen" << endl;
    } 
  }
  
}

void Joueur::fill(vector<int> card) {
  _pile=card;
  _pile.resize(20);
}

void Joueur::remplirSet(const vector<carte> &s) {
  int i = 0;
  while (i < 20 && i < s.size()) {
    
    _pile.push_back(i);
    i++;
  }
}
