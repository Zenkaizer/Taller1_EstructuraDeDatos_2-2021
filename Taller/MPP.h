#pragma once
#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;
/// <summary>
/// Corresponde a la clase Matriz poco poblada.
/// </summary>
class MPP
{
private:
	/// <summary>
	/// Corresponde a la lista de filas de la matriz.
	/// </summary>
	Nodo* listaFila;
	/// <summary>
	/// Corresponde a la lista de columnas de la matriz.
	/// </summary>
	Nodo* listaColumna;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	MPP();
	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="Corresponde a la fila del estudiante.">Fila</param>
	/// <param name="Corresponde a la columna del estudiante.">Columna</param>
	MPP(int fila, int columna);
	/// <summary>
	/// Destructor.
	/// </summary>
	~MPP() = default;
	/// <summary>
	/// Metodo que obtiene la lista fila de la matriz.
	/// </summary>
	/// <returns>Lista fila de la matriz.</returns>
	Nodo* getListaFila() { return this->listaFila; }
	/// <summary>
	/// Metodo que obtiene la lista columna de la matriz.
	/// </summary>
	/// <returns>Lista columna de la matriz.</returns>
	Nodo* getListaColumna() { return this->listaColumna; }
	/// <summary>
	/// Metodo que añade un estudiante a la MPP segun fila y columna.
	/// </summary>
	/// <param name="estudiante">Corresponde al Estudiante a ingresar.</param>
	/// <param name="fila">Corresponde a la fila del estudiante.</param>
	/// <param name="Corresponde a la columna del estudiante."></param>
	void añadirEstudiante(Estudiante* estudiante, int fila, int columna);
	/// <summary>
	/// Metodo que obtiene un estudiante por rut. 
	/// </summary>
	/// <param name="rut">Corresponde al rut del estudiante.</param>
	/// <returns>Estudiante por rut.</returns>
	Estudiante* buscarEstudiante(string rut);
	/// <summary>
	/// Metodo que obtiene un nodo de un estudiante.
	/// </summary>
	/// <param name="estudiante">Corresponde al estudiante.</param>
	/// <returns>Nodo del estudiante solicitado.</returns>
	Nodo* buscarNodoEstudiante(Estudiante* estudiante);
	/// <summary>
	/// Metodo que elimina a un estudiante por nodo.
	/// </summary>
	/// <param name="estudiante">Nodo a eliminar.</param>
	void eliminarEstudiante(Nodo* estudiante);
	/// <summary>
	/// Metodo que obtiene un estudiante por rut.
	/// </summary>
	/// <param name="rut">Rut del estudiante.</param>
	/// <returns>Estudiante segun rut.</returns>
	Estudiante* obtenerEstudiante(string rut);
	/// <summary>
	/// Metodo que obtiene un estudiante por posicion.
	/// </summary>
	/// <param name="fila">Corresponde a la fila del estudiante.</param>
	/// <param name="columna">Corresponde a la columna del estudiante.</param>
	/// <returns>Estudiante por posicion.</returns>
	Estudiante* obtenerEstudiantePosicion(int fila, int columna);
	/// <summary>
	/// Metodo que obtiene un nodo a partir de la fila y columna dada.
	/// </summary>
	/// <param name="fila">Corresponde a la fila del estudiante.</param>
	/// <param name="columna">Corresponde a la columna del estudiante.</param>
	/// <returns>Nodo por posicion.</returns>
	Nodo* obtenerNodoEstudiantePosicion(int fila, int columna);
	/// <summary>
	/// Metodo que filtra la matriz de datos con los estudiantes reprobados.
	/// </summary>
	void filtrarMatrizFiltrada();
};

