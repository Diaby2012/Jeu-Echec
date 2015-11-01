#include <iostream>
#include "Joueur.h"
#include "Piece.h"

using namespace std;

Joueur::~Joueur()
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      delete *p;
      p++;
    }
}

JoueurBlanc::JoueurBlanc() //: Joueur(true)
{

  Roi *pr = new Roi(true);
  Reine *pq = new Reine(true);
  Fou *pfl = new Fou(true,true);
  Fou *pfr = new Fou(true,false);
  Tour *ptl = new Tour(true,true);
  Tour *ptr = new Tour(true,false);
  Cavalier* cbl = new Cavalier(true, true);
  Cavalier* cbr = new Cavalier(true, false);

  m_pieces.push_back(pr);
  m_pieces.push_back(pq);
  m_pieces.push_back(pfl);
  m_pieces.push_back(pfr);
  m_pieces.push_back(ptl);
  m_pieces.push_back(ptr);
  m_pieces.push_back(cbl);
  m_pieces.push_back(cbr);

  for (int i=1; i<=8; i++)
    {
      Piece *p = new Piece(i,2,true); // Pions
      m_pieces.push_back(p);
    }

  // Cavaliers
  Piece *pcl = new Piece(2,1,true);
  m_pieces.push_back(pcl);
  Piece *pcr = new Piece(7,1,true);
  m_pieces.push_back(pcr);

  cout << "Constructeur Joueur Blanc" << endl;
}

JoueurNoir::JoueurNoir() //: Joueur(false)
{
  Roi *pr = new Roi(false);
  Reine *pq = new Reine(false);
  Fou *pfl = new Fou(false,true);
  Fou *pfr = new Fou(false,false);
  Tour *ptl = new Tour(false,true);
  Tour *ptr = new Tour(false,false);
  Cavalier* cnl = new Cavalier(false, true);
  Cavalier* cnr = new Cavalier(false, false);

  m_pieces.push_back(pr);
  m_pieces.push_back(pq);
  m_pieces.push_back(pfl);
  m_pieces.push_back(pfr);
  m_pieces.push_back(ptl);
  m_pieces.push_back(ptr);
  m_pieces.push_back(cnl);
  m_pieces.push_back(cnr);

  for (int i=1; i<=8; i++)
    {
      Piece *p = new Piece(i,7,false); // Pions
      m_pieces.push_back(p);
    }

  // Cavaliers
  Piece *pcl = new Piece(2,8,false);
  m_pieces.push_back(pcl);
  Piece *pcr = new Piece(7,8,false);
  m_pieces.push_back(pcr);

  cout << "Constructeur Joueur Noir" << endl;
}

Joueur::Joueur()
{
  //cout << "Constructeur Joueur par defaut" << endl;
}

Joueur::Joueur(bool white)
{

}

void
Joueur::placerPieces(Echiquier &e)
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      e.placer(*p);
      p++;
    }
}

void
Joueur::affiche(){
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      (*p)->affiche();
      p++;
    }
}

bool
Joueur::isWhite()
{
  return m_pieces[0]->isWhite();
}

vector<Piece*>
Joueur::getPieces()
{
  return m_pieces;
}

bool
Joueur::isMat()
{
  return false;
}

bool
Joueur::isEchec()
{
  return false;
}
