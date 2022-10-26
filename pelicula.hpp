#ifndef PELICULA_HPP_INCLUDED
#define PELICULA_HPP_INCLUDED

#include <iostream>

class Pelicula {
  private:

    std::string titulo;
    std::string director;
    int duracion;

  public:
    Pelicula();
    Pelicula(const Pelicula&);

    std::string getTitulo() const;
    std::string getDirector() const;
    int getDuracion() const;

    std::string toString() const;

    void setTitulo(const std::string&);
    void setDirector(const std::string&);
    void setDuracion(const int&);

    bool operator < (const Pelicula&) const;
    bool operator > (const Pelicula&) const;
    bool operator <= (const Pelicula&) const;
    bool operator >= (const Pelicula&) const;
    bool operator == (const Pelicula&) const;
    bool operator != (const Pelicula&) const;


    friend std::istream& operator >> (std::istream&, Pelicula&);
    friend std::ostream& operator << (std::ostream&, const Pelicula&);
  };

#endif // PELICULA_HPP_INCLUDED
