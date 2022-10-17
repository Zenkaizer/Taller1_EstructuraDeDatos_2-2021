#pragma once
#include <string>
#include "Estudiante.h"
using namespace std;
/// <summary>
/// Clase encargada de los nodos del sistema.
/// </summary>
class Nodo
{
private:
	/// <summary>
	/// Estudiante en el nodo.
	/// </summary>
	Estudiante* estudiante;
	/// <summary>
	/// Nodo siguiente de la columna.
	/// </summary>
	Nodo* nodoArriba;
	/// <summary>
	/// Nodo siguiente de la fila.
	/// </summary>
	Nodo* nodoIzquierda;
	/// <summary>
	/// Numero de fila.
	/// </summary>
	int fila;
	/// <summary>
	/// Numero de columna.
	/// </summary>
	int columna;

public:
	/// <summary>
	/// Constructor de la clase Nodo.
	/// </summary>
	Nodo();
	/// <summary>
	/// Constructor de la clase Nodo.
	/// </summary>
	/// <param name="estudiante">Estudiante del sistema.</param>
	/// <param name="fila">Fila del estudiante.</param>
	/// <param name="columna">Columna del estudiante.</param>
	Nodo(Estudiante* estudiante, int fila, int columna);
	/// <summary>
	/// Destructor de la clase Nodo.
	/// </summary>
	~Nodo();
	/// <summary>
	/// Metodo que obtiene el estudiante del nodo.
	/// </summary>
	/// <returns>Estudiante del nodo.</returns>
	Estudiante* getEstudiante() { return this->estudiante; }
	/// <summary>
	/// Metodo que obtiene el nodo a la arriba del nodo.
	/// </summary>
	/// <returns>Nodo arriba al nodo.</returns>
	Nodo* getNodoArriba() { return this->nodoArriba; }
	/// <summary>
	/// Metodo que obtiene el nodo a la izquierda del nodo.
	/// </summary>
	/// <returns>Nodo izquierda al nodo.</returns>
	Nodo* getNodoIzquierda() { return this->nodoIzquierda; }
	/// <summary>
	/// Metodo que obtiene la fila del nodo.
	/// </summary>
	/// <returns>Fila del nodo.</returns>
	int getFila() { return this->fila; }
	/// <summary>
	/// Metodo que obtiene la columna del nodo.
	/// </summary>
	/// <returns>Columna del nodo.</returns>
	int getColumna() { return this->columna; }
	/// <summary>
	/// Metodo que cambia al estudiante del nodo.
	/// </summary>
	/// <param name="estudiante">Datos del estudiante.</param>
	void setEstudiante(Estudiante* estudiante) { this->estudiante = estudiante; }
	/// <summary>
	/// Metodo que cambia el nodo arriba del nodo.
	/// </summary>
	/// <param name="nodoArriba">Corresponde al nodo arriba.</param>
	void setNodoArriba(Nodo* nodoArriba) { this->nodoArriba = nodoArriba; }
	/// <summary>
	/// Metodo que cambia el nodo izquierda del nodo.
	/// </summary>
	/// <param name="nodoIzquierda">Corresponde al nodo izquierda.</param>
	void setNodoIzquierda(Nodo* nodoIzquierda) { this->nodoIzquierda = nodoIzquierda; }
	/// <summary>
	/// Metodo que cambia la fila del nodo.
	/// </summary>
	/// <param name="fila">Nueva fila del nodo.</param>
	void setFila(int fila) { this->fila = fila; }
	/// <summary>
	/// Metodo que cambia la columna del nodo.
	/// </summary>
	/// <param name="columna">Nueva columna del nodo.</param>
	void setColumna(int columna) { this->columna = columna; }
};