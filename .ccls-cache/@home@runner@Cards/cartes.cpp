#include "cartes.h"
#include "tuple"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

carte::carte() {
  _nom = "Mains nues";
  _va = 1;
  _vd = 1;
  _vm = 0;
};

carte::carte(string nom, int va, int vd, int vm) {
  _nom = nom;
  _va = va;
  _vd = vd;
  _vm = vm;
};

void carte::afflong() const {
  cout << "***************\n"
       << "Nom : " << _nom << "\nAttaque : " << _va << "\nDefense : " << _vd
       << "\nMagie : " << _vm << "\n***************\n";
}

void carte::affcourt() const {
  cout << _nom << " [ " << _va << " ; " << _vd << " ; " << _vm << " ]\n";
}

int carte::degatPhysique(const carte &autreCarte) const {
  // Si la valeur d'attaque de la carte est supérieure à la valeur d'attaque de
  // l'autre carte, les dégâts sont égaux à la différence entre la défense de
  // l'autre carte et l'attaque de la carte cible
  if (_va > autreCarte._va) {
    return autreCarte._vd - _va;
  } else if (_va < autreCarte._va) {
    return autreCarte._va - _vd;
  }
  return 0;
}

int carte::degatMagique(const carte &autreCarte) const {
  if (_vm > autreCarte._vm) {
    return autreCarte._vm - _vm;
  } else if (_vm < autreCarte._vm) {
    return autreCarte._vm - _vm;
  }
  return 0;
}

// Opérateur d'infériorité pour calculer les dégâts physiques
int operator-(const carte &c1, const carte &c2) { return c1.degatPhysique(c2); }

// Opérateur de puissance pour calculer les dégâts magiques
int operator^(const carte &c1, const carte &c2) { return c1.degatMagique(c2); }

// Opérateur << pour afficher une carte sur une ligne
ostream &operator<<(ostream &os, const carte &c) {
  os << c._nom << " [ " << c._va << " ; " << c._vd << " ; " << c._vm << " ]";
  return os;
}

void carte::remplir(const string &ligne) {
  // On utilise un stringstream pour parser la ligne
  stringstream ss(ligne);

  // On lit chaque champ séparé par une virgule dans la ligne
  getline(ss, _nom, ',');
  ss >> _va;
  ss.ignore();
  ss >> _vd;
  ss.ignore();
  ss >> _vm;
};

int carte::getva() const { return _va; }

int carte::getvd() const { return _vd; }

int carte::getvm() const { return _vm; }

int carte::score() const { return _va + _vd + _vm; }

int getv(char c, const carte &carte) {
  if (c == 'a') {
    return carte.getva();
  } else if (c == 'd') {
    return carte.getvd();
  } else {
    return carte.getvm();
  }
}

void sortAscending(char c, const vector<carte> &cartes, vector<int> &rang) {
  sort(rang.begin(), rang.end(), [&](const auto &p1, const auto &p2) {
    return getv(c, cartes[p1]) > getv(c, cartes[p2]);
  });
}

void sortDescending(char c, const vector<carte> &cartes, vector<int> &rang) {
  sort(rang.begin(), rang.end(), [&](int p1, int p2) {
    return getv(c, cartes[p1]) < getv(c, cartes[p2]);
  });
}

vector<int> construitRang(vector<carte> cartes, char type, char order) {
  vector<int> rang(cartes.size());
  for (int i = 0; i < rang.size(); ++i)
    rang[i] = i;
  // Trie le vecteur de cartes en fonction de la valeur d'attaque croissante
  if (order == '>') {
    sortAscending(type, cartes, rang);
  } else {
    sortDescending(type, cartes, rang);
  }
  return rang;
};

void smartSortAscending(vector<tuple<int, int, int>> &v, vector<int> &rang,
                        char a, char b, char c) {
  sort(rang.begin(), rang.end(),
       [&](const auto &p1, const auto &p2) { return v[p1] > v[p2]; });
};

void smartSortDescending(vector<tuple<int, int, int>> &v, vector<int> &rang,
                         char a, char b, char c) {
  sort(rang.begin(), rang.end(),
       [&](const auto &p1, const auto &p2) { return v[p1] < v[p2]; });
};

vector<int> construitRang2(vector<carte> cartes, char type) {
  vector<int> rang(cartes.size());
  for (int i = 0; i < rang.size(); ++i)
    rang[i] = i;
  vector<tuple<int, int, int>> v;
  char a, b, c;
  cout << "Quel est la statistique la plus importante? a pour attaque, m pour "
          "magie, d pour defense\n";
  do {
    cin >> a;
    a= tolower(a);
  } while (a != 'a' && a != 'm' && a != 'd');
  cout << "Quel est deuxieme la statistique la plus importante? a pour "
          "attaque, m pour magie, d pour defense\n";
  do {
    cin >> b;
    b = tolower(b);
  } while (b != 'a' && b != 'm' && b != 'd' && b != a);
  switch (a) {
  case 'a':
    if (b == 'm')
      c = 'd';
    else
      c = 'm';
    break;
  case 'm':
    if (b == 'a')
      c = 'd';
    else
      c = 'a';
    break;
  case 'd':
    if (b == 'a')
      c = 'm';
    else
      c = 'a';
    break;
  }
  for (int i = 0; i < rang.size(); ++i) {
    v.push_back(
        make_tuple(getv(a, cartes[i]), getv(b, cartes[i]), getv(c, cartes[i])));
  }
  if (type == '>') {
    smartSortAscending(v, rang, a, b, c);
  } else
    smartSortDescending(v, rang, a, b, c);
  return rang;
}

void ScoreSortAscending(const vector<int> &v, vector<int> &rang) {
  sort(rang.begin(), rang.end(),
       [&](const auto &p1, const auto &p2) { return v[p1] > v[p2]; });
}

void ScoreSortDescending(const vector<int> &v, vector<int> &rang) {
  sort(rang.begin(), rang.end(), [&](int p1, int p2) { return v[p1] < v[p2]; });
}

vector<int> construitRang3(vector<carte> cartes, char ordre) {
  vector<int> rang(cartes.size());
  for (int i = 0; i < rang.size(); ++i)
    rang[i] = i;
  vector<int> v(cartes.size());
  for (int i = 0; i < v.size(); i++) {
    v[i] = cartes[i].score();
  }
  if (ordre == '>') {
    ScoreSortAscending(v, rang);
  } else
    ScoreSortDescending(v, rang);
  return rang;
}

string carte::getnom() const
{
  return _nom;
}