/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"

using namespace std;

/**
 * Constructeur par défaut.
 * Initialise à vide l'echiquier.
 */
Echiquier::Echiquier()
{
  for (int i=0; i<64; i++)
    m_cases[i]=NULL;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* 
Echiquier::getPiece( int x, int y )
{
  if ((x>=1) && (x<=8) && (y>=1) && (y<=8))
    return m_cases[(x-1)+8*(y-1)];
  else
    return NULL;
}

  
/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool 
Echiquier::placer( Piece* p )
{
  if ( m_cases[(p->x()-1)+8*(p->y()-1)]==NULL
       && (p->x()>=1) && (p->x()<=8) && (p->y()>=1) && (p->y()<=8)
       && (p!=NULL) )
    {
      m_cases[(p->x()-1)+8*(p->y()-1)]=p;
      return true;
    }
  else
    return false;
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y. 
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool 
Echiquier::deplacer( Piece* p, int x, int y )
{
}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* 
Echiquier::enleverPiece( int x, int y )
{
  if ((x>=1) && (x<=8) && (y>=1) && (y<=8))
    {
      Piece *pt;
      pt=m_cases[(x-1)+8*(y-1)];
      m_cases[(x-1)+8*(y-1)]=NULL;
      return pt;
    }
  else return NULL;
}


/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void
Echiquier::affiche()
{
  cout << endl << "  12345678" << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; ++x )
	{
	  char c;
	  Piece* p = getPiece( x, y );
	  if ( p == 0 ) 
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
	  else
	    c = p->myCode(); // p->isWhite() ? 'B' : 'N';
	  cout << c;
	}
      cout << " " << y << endl;
    }
  cout << "  12345678" << endl;
}

  

