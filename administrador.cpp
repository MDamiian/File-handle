#include "administrador.hpp"

using namespace std;

void Administrador::menu() {
  string myString;
  char myOpcion;
  int myInt;
  Pelicula myPelicula;

  do {
    system("cls");

    cout << "***Menu principal***" << endl << endl
         << "1)Agregar pelicula" << endl
         << "2)Mostrar peliculas del vector" << endl
         << "3)Mostrar peliculas del archivo" << endl
         << "4)Salir" << endl
         << "Selecciona una opcion: ";
    cin >> myOpcion;
    cin.ignore();

    switch(myOpcion) {
      case '1':
        cout << "\nLlenando datos de la pelicula" << endl << endl;

        cout << "Titulo de la pelicula: ";
        getline(cin, myString);
        myPelicula.setTitulo(myString);

        cout << "Director de la pelicula: ";
        getline(cin, myString);
        myPelicula.setDirector(myString);

        cout << "Duracion de la pelicula: ";
        cin >> myInt;
        myPelicula.setDuracion(myInt);
        cin.ignore();

        agregarPelicula(myPelicula);

        cout << endl;
        system("pause");
        break;

      case '2':
        mostrarPeliculas();
        cout << endl;
        system("pause");
        break;

      case '3':
        recuperarPelicula();
        cout << endl;
        system("pause");
        break;

      case '4':
        break;
      }

    }
  while(myOpcion != '4');
  }

void Administrador::agregarPelicula(const Pelicula& myPelicula) {
  ofstream archivo;
  archivo.open(nameFile, ios::app);

  if(!archivo.is_open()) {
    cout << "\nFalla al escribir en el archivo" << endl;
    }

  else {
    archivo << myPelicula;
    archivo.close();
    carrete.push_back(myPelicula);
    cout << "\nPelicula agregada" << endl;
    }
  }

void Administrador::mostrarPeliculas() {
  cout << "\nMostrando peliculas" <<endl;
  if(carrete.size()==0) {
    cout << "\nNo hay peliculas agregadas" << endl;
    }
  else {
    for(Pelicula temp : carrete) {
      cout << temp.toString() << endl;
      }
    }
  }

void Administrador::recuperarPelicula() {
  ifstream archivo;
  Pelicula myPelicula;

  archivo.open(nameFile, ios::in);

  if(!archivo.is_open()) {
    cout << "\nFalla al leer el archivo" << endl;
    cout << "Asegurese que el archivo exista" << endl << endl;
    }
  else {
    cout << "\nPeliculas del archivo \"" << nameFile << "\"" << endl;
    while(archivo >> myPelicula) {
      cout << myPelicula;
      }
    archivo.close();
    }
  }
