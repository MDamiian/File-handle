#include "pelicula.hpp"

using namespace std;

Pelicula::Pelicula() : titulo("-"), director("-"), duracion(0) { }

Pelicula::Pelicula(const Pelicula& p) : Pelicula() {
  titulo = p.titulo;
  director = p.director;
  duracion = p.duracion;
  }

string Pelicula::getTitulo() const {
  return titulo;
  }

string Pelicula::getDirector() const {
  return director;
  }

int Pelicula::getDuracion() const {
  return duracion;
  }

string Pelicula::toString() const
{
  string result;
  result+= titulo;
  result.resize(25, ' ');
  result+= '|';
  result+= director;
  result.resize(50, ' ');
  result+= '|';
  result+= to_string(duracion);
  result.resize(75, ' ');
  return result;
}

void Pelicula::setTitulo(const string& e) {
  titulo = e;
  }

void Pelicula::setDirector(const string& e) {
  director = e;
  }

void Pelicula::setDuracion(const int& e) {
  duracion = e;
  }

bool Pelicula::operator < (const Pelicula& p) const {
  return titulo < p.titulo;
  }

bool Pelicula::operator>(const Pelicula& p) const {
  return !(*this <= p);
  }

bool Pelicula::operator<=(const Pelicula& p) const {
  return *this < p or *this == p;
  }

bool Pelicula::operator>=(const Pelicula& p) const {
  return !(*this < p);
  }

bool Pelicula::operator==(const Pelicula& p) const {
  return titulo == p.titulo;
  }

bool Pelicula::operator!=(const Pelicula& p) const {
  return !(*this == p);
  }

istream& operator >> (istream& is, Pelicula& p) {
  string myInt;
  getline(is, p.titulo, '|');
  getline(is, p.director, '|');
  getline(is, myInt);
  p.duracion = atoi(myInt.c_str());
  return is;
  }

ostream& operator << (ostream& os, const Pelicula& p) {
  os << p.titulo
     << '|'
     << p.director
     << '|'
     << p.duracion << endl;
  return os;
  }
