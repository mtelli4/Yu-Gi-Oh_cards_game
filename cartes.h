#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class carte {
  // Déclaration des opérateurs de surcharge en tant que fonctions amies
  friend int operator-(const carte &c1, const carte &c2);
  friend int operator^(const carte &c1, const carte &c2);
  friend ostream &operator<<(ostream &os, const carte &c);

private:
  string _nom;   // Nom de la carte
  int _va;       // Valeur d'attaque
  int _vd;       // Valeur de défense
  int _vm;       // Valeur de magie

public:
  // Constructeur par défaut
  carte();

  // Constructeur avec paramètres
  carte(string nom, int va, int vd, int vm);

  // Affichage long de la carte
  void afflong() const;

  // Affichage court de la carte
  void affcourt() const;

  // Fonction membre pour calculer les dégâts physiques
  int degatPhysique(const carte &) const;

  // Fonction membre pour calculer les dégâts magiques
  int degatMagique(const carte &) const;

  // Fonction membre pour creer les cartes avec le fichier .txt
  void remplir(const string & );

  int getva() const;
  int getvd() const;
  int getvm() const;
  int score() const;
  string getnom() const;
};

// construitRang() retourne un vecteur ou rang[0] est la carte la plus/moin puissante et rang[n] l'inverse
vector<int> construitRang(vector<carte>,char,char);

void sortascending(vector<pair<int, int>>,vector<int>&);
void sortdescending(vector<pair<int, int>>,vector<int>&);
vector<int> construitRang2(vector<carte>,char);
vector<int> construitRang3(vector<carte>,char);

#endif
