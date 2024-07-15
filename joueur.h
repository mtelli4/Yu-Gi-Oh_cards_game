#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "cartes.h"
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Joueur {

  friend bool operator==(const Joueur &j1, const Joueur &j2);

private:
  string _name;        // Nom du joueur
  int _prestige;       //  Prestige du joueur (nombre de points de vie)
  vector<int> _pile; //  Pile de cartes du joueur

public:
  /*--------------  Joueur();
    Constructeur vide
    Construit le joueur Yugi, qui a 25 de prestige et une pile de cartes
    composées des cartes suivantes: MainDroite[1, 0, 0], MainGauche[0, 1, 0],
    Tête [1, -2, 0], Bouche[1, -1, 2], Genou[2, 0, 0]
  */
  Joueur();

  /*-------------  Joueur (string, int, vector<cartes>);
 Constructeur basée sur les informations données
    Construit un Joueur basé sur le nom du joueur,
    le prestige du joueur et la pile de carte du joueur
  */
  Joueur(string, int, vector<int>);

  void sonNom() const;
  void sonPrestige() const;
  int prestige() const;
  void affichage() const;
  void initPile(const vector<carte> &);
  bool aDesCartes() const;
  bool estEnJeu() const;
  void carteSuiv(carte &);
  void ajouterCarte(const vector<carte> &reserve, int indice);
  void jouentUneCarte(Joueur &);
  void melange();
  void affiche();
  void remplirPile(vector<carte>);
  void fillvector();
  void fill(vector<int>);
  void remplirSet(const vector<carte> &);
};
#endif
