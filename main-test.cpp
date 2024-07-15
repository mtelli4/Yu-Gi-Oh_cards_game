/*#include "cartes.h"
#include "jeu.h"
#include "joueur.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

vector<carte> reserve;

void fill() {
  // Ouvre le fichier en lecture
  ifstream input("reserve.txt");

  // Si le fichier est ouvert, on lit chaque ligne
  if (input.is_open()) {
    string ligne;
    while (getline(input, ligne)) {
      // On crée une nouvelle carte et on la remplit à partir de la ligne
      carte carte;
      carte.remplir(ligne);
      // On ajoute la carte à la réserve
      reserve.push_back(carte);
    }
  }

  // On ferme le fichier
  input.close();
}

using namespace std;

int main() {
  fill();
  carte a;
  carte c1("c1", 2, 0, 12);
  carte c2("c2", 5, 1, 0);
  cout << endl << "----- Automatic tests for afflong --------------------------------" << endl; bool ok = true; if (!(a.afflong() == "***************\nNom : Mains nues\n Attaque : 1\nDefense : 1\nMagie :
0\n***************\n"))
  {
    ok = false;
    cout << "Error : a.afflong() = " << a.afflong() << " (expected : Duck)" <<
endl;
  }
  if (ok) cout << "Method getName correct" << endl;
  a.afflong();
  a.affcourt();
  }*/