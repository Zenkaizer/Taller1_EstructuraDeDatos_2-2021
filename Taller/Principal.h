#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "Requerimientos.h"
using namespace std;
/// <summary>
/// Corresponde a la clase principal del sistema.
/// </summary>
class Principal
{
private:
	/// <summary>
	/// Corresponde al llamado al constructor de la clase Requerimientos.
	/// </summary>
	Requerimientos* requerimientos;
	/// <summary>
	/// Metodo encargado de leer el archivo de texto.
	/// </summary>
	void leerArchivos();
	/// <summary>
	/// Metodo que lleva el menu para cambiar la nota del estudiante.
	/// </summary>
	void registrarNota();
	/// <summary>
	/// Metodo que lleva el menu de generar estadisticas.
	/// </summary>
	void generarEstadisticas();
	/// <summary>
	/// Metodo que filtra la matriz del sistema.
	/// </summary>
	void filtrarMatriz();
	/// <summary>
	/// Metodo que escribe el archivo con los datos del sistema.
	/// </summary>
	void escribirArchivos();

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	Principal();
	/// <summary>
	/// Destructor.
	/// </summary>
	~Principal() = default;
	/// <summary>
	/// Metodo que lleva el menu principal del sistema.
	/// </summary>
	void menuPrincipal();
};