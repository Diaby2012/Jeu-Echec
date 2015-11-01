/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"
#include <vector>

using namespace std;

class Joueur
{
 protected:
  //Piece m_pieces[16];
  vector<Piece *> m_pieces;

 public:
  Joueur();
  Joueur(bool white);
  ~Joueur();
  void affiche();
  bool isWhite();
  void placerPieces(Echiquier &e);
  vector<Piece*> getPieces();
  bool isMat();
  bool isEchec();
};

class JoueurBlanc : public Joueur
{
 public:
  JoueurBlanc();
};

class JoueurNoir : public Joueur
{
 public:
  JoueurNoir();
};

#endif
