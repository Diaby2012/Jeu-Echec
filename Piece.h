/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

// #include "Echiquier.h" // pb reference croisee
class Echiquier;

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece
{
protected:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  Piece(const Piece & autre);
  Piece & operator=(const Piece & autre);
  virtual ~Piece();
  Piece( int x, int y, bool white );
  void init( int x, int y, bool white );
  void move( int x, int y );
  virtual bool mouvementValide(Echiquier &e, int x, int y);
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  virtual char myCode() const;
};

class Roi : public Piece
{
 public:
  Roi(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode() const;
};

class Tour : virtual public Piece
{
public:
  Tour(bool white, bool pos);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode() const;
};

class Fou : virtual public Piece
{
public:
  Fou(bool white, bool pos);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode() const;
};

class Reine : public Tour, public Fou
{
public:
  Reine(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode() const;
};

class Cavalier : public Tour, public Fou{

public:
  Cavalier(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char codePiece();
};

class Pion : virtual public Piece{

private:
  bool premierDeplacement;

public:
  Pion(int x, int y, bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
};

#endif
