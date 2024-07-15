#ifndef JEU_H
#define JEU_H
#include "cartes.h"
#include "joueur.h"


#include  <iostream>
using namespace std;

class Jeu {

  friend int operator++(const Jeu &);

  vector<carte> _pile;
  Joueur _j1;
  Joueur _j2;

  public:
    Jeu();
    Jeu(vector<carte>,Joueur,Joueur);
    bool fini(Joueur &);
    Jeu & operator++();
    void afficheScores() const;
    int vainqueur();
    Joueur& getJoueur1();
    Joueur& getJoueur2();
};

#endif