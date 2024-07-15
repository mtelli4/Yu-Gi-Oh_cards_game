#include "cartes.h"
#include "jeu.h"
#include "joueur.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>

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

  sort(reserve.begin(), reserve.end(), [](const carte &p1, const carte &p2) {
    return p1.getnom() < p2.getnom();
  });

  // On ferme le fichier
  input.close();
}

using namespace std;

/*int main() {
  fill();
  carte a;
  a.afflong();
  a.affcourt();
  carte c1("c1", 2, 0, 12);
  carte c2("c2", 5, 1, 0);
  cout << c1.degatPhysique(c2) << endl;
  cout << c1.degatMagique(c2) << endl;
  cout << c1 - c2 << endl;
  cout << c1 << endl;
  cout << c2 << endl;
  cout << "*******************************\n\n\n";
  // Création d'un joueur
  Joueur j("Yugi", 25, {});
  Joueur j1("Yugi2", 25, {});

  j.fillvector();
  j.affiche();

  for (int i = 0; i < reserve.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << reserve[i] << "\n";
  };
  cout << "*******************************\n\n\n";
  // Ajout de quelques cartes dans la pile du joueur
  j.ajouterCarte(reserve, 4);
  j.ajouterCarte(reserve, 1);
  j.ajouterCarte(reserve, 2);
  j.ajouterCarte(reserve, 3);
  j.ajouterCarte(reserve, 0);
  j1.ajouterCarte(reserve, 3);
  j1.ajouterCarte(reserve, 2);
  j1.ajouterCarte(reserve, 4);
  j1.ajouterCarte(reserve, 0);
  j1.ajouterCarte(reserve, 1);

  // Récupération de la prochaine carte de la pile du joueur
  carte c;
  j.carteSuiv(c);
  cout << "La prochaine carte de la pile est : " << c << endl;
  j.affichage();
  j1.affichage();
  j.jouentUneCarte(j1);
  j.affichage();
  j1.affichage();
  cout << "La prochaine carte de la pile est : " << c << endl;


  Jeu jeu1(reserve, j, j1);
  jeu1.afficheScores();
  ++jeu1;
  jeu1.afficheScores();
  cout << "*******************************\n\n\n";
  j.affiche();
  j.melange();
  cout << "*******************************\n\n\n";
  j.affiche();
  cout << "*******************************\n\n\n";


  vector<int> rang = construitRang(reserve, 'a', '>');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " va est " <<
reserve[rang[i]].getva() << "\n";
  };
  cout << "*******************************\n\n\n";
  rang = construitRang(reserve, 'a', '<');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " va est " <<
reserve[rang[i]].getva() << "\n";
  };cout << "*******************************\n\n\n";
  rang = construitRang(reserve, 'd', '>');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " vd est " <<
reserve[rang[i]].getvd() << "\n";
  };
  cout << "*******************************\n\n\n";
  rang = construitRang(reserve, 'd', '<');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " vd est " <<
reserve[rang[i]].getvd() << "\n";
  };
  cout << "*******************************\n\n\n";
  rang = construitRang(reserve, 'm', '>');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " vm est " <<
reserve[rang[i]].getvm() << "\n";
  };
  cout << "*******************************\n\n\n";
  rang = construitRang(reserve, 'm', '<');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " vm est " <<
reserve[rang[i]].getvm() << "\n";
  };
  rang = construitRang2(reserve,'<');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " va est " <<
reserve[rang[i]].getva() << " vd est " << reserve[rang[i]].getvd() << " vm est "
<< reserve[rang[i]].getvm() << "\n";
  };
  j1.remplirPile(reserve);
  j1.affiche();
  vector<int> rang = construitRang3(reserve, '>');
  for (int i = 0; i < rang.size(); i++) {
    cout << "Pour i = " << i << " reserve est " << rang[i] << " va est " <<
reserve[rang[i]].score() << "\n";
  };
  cout << "*******************************\n\n\n";
};*/

int main() {
  fill();
  try {

    int m;
    char re;
    cout << "Choose your gamemode : " << endl;
    cout << " 1 for a pvp " << endl;
    cout << " 2 for a pve " << endl;
    cin >> m;

    if (m == 1) {
      string nj1, nj2;
      cout << "Enter your name player 1 : " << endl;
      cin >> nj1;
      cout << "Enter your name player 2 : " << endl;
      cin >> nj2;
      cout << "Rules : " << endl
           << "The game consists of a confrontation between two very "
              "prestigious players \n (they have 25 prestige "
              "points each) each with a stack of 20 cards selected from\n"
              "an identical reserve. Each card has three "
              "characteristics: an attack value, a\ndefense "
              "value, and a magic power. The goal is to reduce the opponent's "
              "prestige \nand defend your own. The winner is the "
              "first player to send their opponent into\nthe mud "
              "(prestige at 0) or have more prestige than their opponent at "
              "the end of\nthe confrontation (when one of the "
              "players no longer has cards or one of the\n"
              "players no longer has prestige)."
           << endl;
      sleep(5);
      Joueur j1(nj1, 25, {});
      Joueur j2(nj2, 25, {});

      do {
        cout << endl << "You will now build your deck " << endl;
        cout << endl
             << "Here is a list of the cards available : " << endl
             << endl;

        for (int i = 0; i < reserve.size(); i++) {
          cout << i << " card is " << reserve[i] << "\n";
        };

        sleep(5);
        int d;

        cout << endl
             << endl
             << nj1 << " Choose how to sort your deck : " << endl;
        cout << " 1 :  Using 'dumb' auto sort which only sorts with attack, "
                "defense or magic"
             << endl;
        cout << " 2 :  Using 'smart' auto sort which sorts using attack, "
                "defense and magic, and you get to choose the importance of "
                "each attribute"
             << endl;
        cout << " 3 :  Using 'score' auto sort which sorts using the combined "
                "attack, defence and magic"
             << endl;
        cout << " 4 :  Manually " << endl;

        cin >> d;
        char type, ordre;
        if (d == 1) {
          do {
            cout << "Would you like to sort using attack, defense or magic? a "
                    "for attack, d for defense, m for magic";
            cin >> type;
            type = tolower(type);
          } while ((type != 'a' && type != 'm' && type != 'd'));
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang(reserve, type, ordre));
          j1.fill(rang1);

          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        } else if (d == 2) {
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang2(reserve, ordre));
          j1.fill(rang1);
          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        } else if (d == 3) {
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang3(reserve, ordre));
          j1.fill(rang1);
          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        } else if (d == 4) {
          j1.fillvector();
          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        }

        sleep(8);
        cout << endl
             << endl
              << nj2 << " turn " << endl;

        cout << endl
             << " 1 :  Using 'dumb' auto sort which only sorts with attack, "
                "defense or magic"
             << endl;
        cout << " 2 :  Using 'smart' auto sort which sorts using attack, "
                "defense and magic, and you get to choose the importance of "
                "each attribute"
             << endl;
        cout << " 3 :  Using 'score' auto sort which sorts using the combined "
                "attack, defence and magic"
             << endl;
        cout << " 4 :  Manually " << endl;

        cin >> d;
        if (d == 1) {
          do {
            cout << "Would you like to sort using attack, defense or magic? a "
                    "for attack, d for defense, m for magic";
            cin >> type;
            type = tolower(type);
          } while ((type != 'a' && type != 'm' && type != 'd'));
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang(reserve, type, ordre));
          j2.fill(rang1);

          cout << "Here is your deck : " << endl << endl;
          j2.affiche();
        } else if (d == 2) {
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang2(reserve, ordre));
          j2.fill(rang1);
          cout << "Here is your deck : " << endl << endl;
          j2.affiche();
        } else if (d == 3) {
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang3(reserve, ordre));
          j2.fill(rang1);
          cout << "Here is your deck : " << endl << endl;
          j2.affiche();
        } else if (d == 4) {
          j2.fillvector();
          cout << "Here is your deck : " << endl << endl;
          j2.affiche();
        }
        Jeu game(reserve, j1, j2);

        sleep(8);
        cout << endl << "===== Start of the game =====" << endl << endl;

        game.getJoueur1().affichage();
        cout << endl;
        game.getJoueur2().affichage();
        cout << endl;
        sleep(5);

        int t = 1;
        
        Joueur winner;
        
        while (!game.fini(winner)) {

          cout << " Turn " << t << " : " << endl << endl;
          ++game;
          t++;
          sleep(5);
          cout << endl;
          game.getJoueur1().affichage();
          cout << endl;
          game.getJoueur2().affichage();
          cout << endl;
          sleep(5);
        }
        if (game.vainqueur() == 1)
          cout << endl
               << "Congrats " << nj1
               << endl;
        else if (game.vainqueur() == -1)
          cout << endl
               << "Congrats " << nj2
               << endl;
        else
          cout << endl
               << "Congrats" << nj1 << " and "
               << nj2 << ", null match"
               << endl;

        cout << endl << "Restart (o for yes) : " << endl;
        cin >> re;
      } while (re == 'o');
    } else if (m == 2) {

      string nj1;
      Joueur j2("IA", 25, {});
      cout << "Enter your name : " << endl;
      cin >> nj1;
      cout << "Rules : " << endl
           << "The game consists of a confrontation between two very "
              "prestigious players \n (they have 25 prestige "
              "points each) each with a stack of 20 cards selected from\n"
              "an identical reserve. Each card has three "
              "characteristics: an attack value, a\ndefense "
              "value, and a magic power. The goal is to reduce the opponent's "
              "prestige \nand defend your own. The winner is the "
              "first player to send their opponent into\nthe mud "
              "(prestige at 0) or have more prestige than their opponent at "
              "the end of\nthe confrontation (when one of the "
              "players no longer has cards or one of the\n"
              "players no longer has prestige)."
           << endl;
      sleep(5);

      do {
        cout << endl << "You will now build your deck " << endl;
        cout << endl
             << "Here is a list of the cards available : " << endl
             << endl;

        for (int i = 0; i < reserve.size(); i++) {
          cout << i << " card is " << reserve[i] << "\n";
        };

        sleep(5);
        int d;
        Joueur j1(nj1, 25, {});
        Joueur j2("IA", 25, {});

        cout << endl
             << endl
             << nj1 << " Choose how to sort your deck : " << endl;
        cout << " 1 :  Using 'dumb' auto sort which only sorts with attack, "
                "defense or magic"
             << endl;
        cout << " 2 :  Using 'smart' auto sort which sorts using attack, "
                "defense and magic, and you get to choose the importance of "
                "each attribute"
             << endl;
        cout << " 3 :  Using 'score' auto sort which sorts using the combined "
                "attack, defence and magic"
             << endl;
        cout << " 4 :  Manually " << endl;

        cin >> d;
        char type, ordre;
        if (d == 1) {
          do {
            cout << "Would you like to sort using attack, defense or magic? a "
                    "for attack, d for defense, m for magic";
            cin >> type;
            type = tolower(type);
          } while ((type != 'a' && type != 'm' && type != 'd'));
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang(reserve, type, ordre));
          j1.fill(rang1);

          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        } else if (d == 2) {
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang2(reserve, ordre));
          j1.fill(rang1);
          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        } else if (d == 3) {
          do {
            cout << "Would you like it to be ascending or descending? < for "
                    "ascending and > for descending \n NB: ascending will stat "
                    "with the lowest possible card and exclude the most "
                    "powerfull";
            cin >> ordre;
          } while ((ordre != '<' && ordre != '>'));
          vector<int> rang1 = (construitRang3(reserve, ordre));
          j1.fill(rang1);
          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        } else if (d == 4) {
          j1.fillvector();
          cout << "Here is your deck : " << endl << endl;
          j1.affiche();
        }
        Jeu game(reserve, j1, j2);

        sleep(8);

        
        game.getJoueur2().remplirSet(reserve);
        game.getJoueur2().melange();

        cout << endl << "IA is choosing cards " << endl;
        sleep(2);
        cout << endl << "===== Start of the game =====" << endl << endl;

        game.getJoueur1().affichage();
        cout << endl;
        game.getJoueur2().affichage();
        cout << endl;
        sleep(5);

        int t = 1;

        Joueur winner;

        while (!game.fini(winner)) {

          cout << " Turn " << t << " : " << endl << endl;
          ++game;
          t++;
          sleep(5);
          cout << endl;
          game.getJoueur1().affichage();
          cout << endl;
          game.getJoueur2().affichage();
          cout << endl;
          sleep(5);
        }
        if (game.vainqueur() == 1)
          cout << endl
               << "Congrats " << nj1 << ", you won ! "
               << endl;
        else if (game.vainqueur() == -1)
          cout << endl
               << "Congrats " << "IA" << ", you won ! "
               << endl;
        else
          cout << endl
               << "Congrats " << nj1 << " et "
               << "IA" << ", null match !"
               << endl;

        cout << endl << "Restart (o for yes) : " << endl;
        cin >> re;

      } while (re == 'o');
    }
  } catch (exception &ex) {
    cerr << ex.what() << endl;
  };

  return 0;
}