#include "Nodo.h"

Nodo::Nodo()
{
	this->estudiante = nullptr;
	this->nodoArriba = nullptr;
	this->nodoIzquierda = nullptr;
	this->fila = -1;
	this->columna = -1;
}

Nodo::Nodo(Estudiante* estudiante, int fila, int columna)
{
	this->estudiante = estudiante;
	this->nodoArriba = nullptr;
	this->nodoIzquierda = nullptr;
	this->fila = fila;
	this->columna = columna;
}

Nodo::~Nodo()
{
	this->estudiante->~Estudiante();
	this->nodoArriba = nullptr;
	this->nodoIzquierda = nullptr;
}
