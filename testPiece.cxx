/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

// Vérifie la validité des coordonneeonnées saisie
bool coordonneeonneeValide(string coordonnee){
    if(coordonnee.length() == 2){
        coordonnee[0] = toupper(coordonnee[0]);
        if(coordonnee[0] >= 'A' && coordonnee[0] <= 'H' && coordonnee[1] >= '1' && coordonnee[1] <= '8'){
            return true;
        }
    }
    return false;
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  string origine, destination;
  int origX, origY, destX, destY;
  int nbTour = 1;
  bool tourBlanc = true;

  JoueurBlanc jb;
  JoueurNoir jn;

  jb.affiche();
  jn.affiche();

  Echiquier e;
  jb.placerPieces(e);
  jn.placerPieces(e);


  e.affiche();

  while(!jb.isMat() && !jn.isMat()){

      if(tourBlanc){
        cout << endl << "TOUR DU JOUEUR BLANC  (Lettre Majuscule )# " << endl << endl;
      }
      else{
        cout << endl << "TOUR DU JOUEUR NOIR (Lettre Minuscule) # "<< endl << endl;
      }


      while(!coordonneeonneeValide(origine)){
        cout << "Veuillez saisir les coordonneeonnées de la pièce : " << endl;
        cin >> origine;
        if(!coordonneeonneeValide(origine)){
            cout << "coordonneeonnées non valide !" << endl;
        }
        else{
            origX = toupper(origine[0])-64;
            origY = origine[1]-48;
        }
      }

      while(!coordonneeonneeValide(destination)){
        cout << "Veuillez saisir les coordonneeonnées de la case de dest :" << endl;
        cin >> destination;
        if(!coordonneeonneeValide(destination)){
            cout << "coordonneeonnées non valide ! " << endl;
        }
        else{
            destX = toupper(destination[0])-64;
            destY = destination[1]-48;
        }
      }

      Piece * p = e.getPiece(origX, origY);

      if(p != NULL && p -> mouvementValide(e,destX, destY)){
        cout << " " << endl;
        e.deplacer(p, destX, destY);
      }
      else{
        cout << " Erreur de déplacement " << endl;
      }

      e.affiche();

    }

    cout << "FIN"<< endl;

}
