#ifndef ADMINISTRADOR_HPP_INCLUDED
#define ADMINISTRADOR_HPP_INCLUDED

#include <vector>
#include <fstream>
#include <string>
#include "pelicula.hpp"

class Administrador {
  private:
    std::vector<Pelicula> carrete;
    std::string nameFile = "peliculas.txt";
  public:
    void menu();
    void agregarPelicula(const Pelicula&);
    void mostrarPeliculas();
    void recuperarPelicula();
  };


#endif // ADMINISTRADOR_HPP_INCLUDED
