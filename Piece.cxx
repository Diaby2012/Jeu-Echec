/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"
#include "Echequier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

Piece::Piece()
{
  cout << " Constructeur" << endl;
}

Piece::~Piece()
{
  cout << "Destructeur" << endl;
}


Piece::Piece(const Piece & autre)
{
  // autre.m_x=1;
  m_x=autre.m_x;
  m_y=autre.m_y;
  m_white=autre.m_white;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_x=autre.m_x;
  m_y=autre.m_y;
  m_white=autre.m_white;
  return *this;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

Roi::Roi(bool white)
{
  m_x=5;
  m_y=white?1:8;
  m_white=white;
  cout << "Un Roi cree" << endl;
}

Reine::Reine(bool white) : Piece(4,white?1:8,white), Fou(white,true), Tour(white,true)
{
  cout << "Une Reine creee" << endl;
}

Fou::Fou(bool white, bool pos) : Piece(pos?6:3,white?1:8,white)
{
  cout << "Un Fou creee" << endl;
}

Tour::Tour(bool white, bool pos) : Piece(pos?8:1,white?1:8,white)
{
  cout << "Une Tour creee" << endl;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_x=autre.m_x;
  m_y=autre.m_y;
  m_white=autre.m_white;
  cout << "Une Piece affectee" << endl;
  return *this;
}

Piece::~Piece()
{
  cout << "Une Piece detruite" << endl;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  cout << "Une Piece creee specialisee" << endl;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  cout << "Une Piece initialisee" << endl;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Piece" << endl;
  return false;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Roi" << endl;
  return false;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Reine" << endl;
  return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y);
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Fou" << endl;
  return false;
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide Tour" << endl;
  return false;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack() const
{
  return !m_white;
}

void
Piece::affiche() const
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
}

char
Piece::myCode() const
{
  return m_white?'B':'N';
}

char
Roi::myCode() const
{
  return m_white?'R':'r';
}

char
Reine::myCode() const
{
  return m_white?'Q':'q';
}

char
Fou::myCode() const
{
  return m_white?'F':'f';
}

char
Tour::myCode() const
{
  return m_white?'T':'t';
}
